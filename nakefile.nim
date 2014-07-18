import nake, os, times, osproc, htmlparser, xmltree, strtabs, strutils,
  rester

const
  rester_src = "nim"/"rester.nim"
  public_name = "QuickLook reStructuredText"
  dist_dir = "dist"
  xarchive_ext = ".xcarchive"
  environ_c_file = "nim"/"generated_nimrod"/"stdlib_os.c"
  zip_base = dist_dir/"quicklook-rest-with-nimrod-" & rester.version_str
  xarchive_generator_path =
    "Products"/"Library"/"QuickLook"/public_name & ".qlgenerator"
  zip_name = "QuickLook.reStructuredText.qlgenerator.zip"
  xcodebuild_exe = "xcodebuild"
  zip_exe = "zip"
  quick_readme = "docs"/"dist"/"readme.rst"

let
  rst_files = @["docs"/"debugging_quicklook", "docs"/"release_steps",
    "docs"/"CHANGES", "LICENSE", "README", "docindex",
    quick_readme.change_file_ext("")]

proc copyDirWithPermissions*(source, dest: string) =
  ## Copies a directory from `source` to `dest`. If this fails, `EOS` is raised.
  createDir(dest)
  for kind, path in walkDir(source):
    var noSource = path.substr(source.len()+1)
    case kind
    of pcFile:
      copyFileWithPermissions(path, dest / noSource)
    of pcDir:
      copyDirWithPermissions(path, dest / noSource)
    else: discard

proc rst2html(filename: string): bool =
  let output = safe_rst_file_to_html(filename)
  if output.len > 0:
    writeFile(filename.changeFileExt("html"), output)
    result = true

proc change_rst_links_to_html(html_file: string) =
  ## Opens the file, iterates hrefs and changes them to .html if they are .rst.
  let html = loadHTML(html_file)
  var DID_CHANGE: bool

  for a in html.findAll("a"):
    let href = a.attrs["href"]
    if not href.isNil:
      let (dir, filename, ext) = splitFile(href)
      if ext == ".rst" or ext == ".nim":
        a.attrs["href"] = dir / filename & ".html"
        DID_CHANGE = true

  if DID_CHANGE:
    writeFile(html_file, $html)

proc needs_refresh(target: string, src: varargs[string]): bool =
  assert len(src) > 0, "Pass some parameters to check for"
  var targetTime: float
  try:
    targetTime = toSeconds(getLastModificationTime(target))
  except EOS:
    return true

  for s in src:
    let srcTime = toSeconds(getLastModificationTime(s))
    if srcTime > targetTime:
      return true


iterator all_rst_files(): tuple[src, dest: string] =
  for rst_name in rst_files:
    var r: tuple[src, dest: string]
    r.src = rst_name & ".rst"
    # Ignore files if they don't exist, babel version misses some.
    if not r.src.existsFile:
      echo "Ignoring missing ", r.src
      continue
    r.dest = rst_name & ".html"
    yield r

proc doc() =
  # Generate html files from the rst docs.
  for rst_file, html_file in all_rst_files():
    if not html_file.needs_refresh(rst_file): continue
    if not rst2html(rst_file):
      quit("Could not generate html doc for " & rst_file)
    else:
      change_rst_links_to_html(html_file)
      echo rst_file & " -> " & html_file

  if not shell("nimrod doc --verbosity:0", rester_src):
    quit("Could not generate HTML API doc for " & rester_src)

proc check_doc() =
  for rst_file, html_file in all_rst_files():
    echo "Testing ", rst_file
    let (output, exit) = execCmdEx("rst2html.py " & rst_file & " > /dev/null")
    if output.len > 0 or exit != 0:
      echo "Failed python processing of " & rst_file
      echo output

proc clean() =
  for path in walkDirRec("."):
    let (dir, name, ext) = splitFile(path)
    if ext == ".html":
      echo "Removing ", path
      path.removeFile()


proc dist() =
  ## Builds the distribution files.
  # Verify that environ patch is present in C source code.
  assert environ_c_file.read_file.find("_NSGetEnviron") > 0

  assert xcodebuild_exe.len > 0, "No xcodebuild command found"
  echo "Building archive…"
  let dest_archive = dist_dir/public_name &
    "-v" & rester.version_str & xarchive_ext
  dist_dir.remove_dir
  dist_dir.create_dir

  # Build archive. From http://stackoverflow.com/a/20905823/172690.
  let
    exec_options = {poStdErrToStdOut, poUsePath, poEchoCmd}
    output = exec_process(xcodebuild_exe, args = ["archive",
      "-scheme", public_name, "-archivePath", dest_archive],
      options = exec_options)
  if output.find("ARCHIVE SUCCEEDED") < 0:
    quit("Error building archive\n\n" & output)
  doAssert dest_archive.exists_dir, output
  doAssert exists_dir(dest_archive/xarchive_generator_path)

  # Package xarchive into a zip.
  let zip_xarchive = public_name & xarchive_ext & ".zip"
  with_dir dist_dir:
    discard exec_process(zip_exe, args = ["-9r", zip_xarchive,
      dest_archive.extract_filename], options = exec_options)
  doAssert exists_file(dist_dir/zip_xarchive)

  # Prepare zip directory.
  zip_base.create_dir
  let dest_generator = zip_base/extract_filename(xarchive_generator_path)
  copy_dir_with_permissions(dest_archive/xarchive_generator_path,
    dest_generator)
  doAssert dest_generator.exists_dir

  # Generate instructions.
  let quick_readme_html = quick_readme.rst_file_to_html
  write_file(zip_base/"readme.html", quick_readme_html)

  # Archive.
  with_dir dist_dir:
    discard exec_process(zip_exe, args = ["-9r", zip_name,
      zip_base.extract_filename], options = exec_options)
  doAssert exists_file(dist_dir/zip_name)

  echo "Did make it"
  discard exec_cmd("open " & dist_dir)


task "doc", "Generates export API docs for for the modules":
  doc()
  echo "All done"

task "check_doc", "Validates rst format for a subset of documentation":
  check_doc()
  echo "All docs checked"

task "clean", "Removes temporal files, mainly":
  clean()
  echo "All files cleaned"

task "dist", "Build distribution packages for GitHub":
  dist()
  echo "Distribution files produced"
