import bb_nake, bb_os, times, osproc, htmlparser, xmltree, strtabs, strutils,
  md5, sequtils, algorithm, lazy_rest, lazy_rest_pkg/lhighlite

const
  version_str = "0.4.5"
  public_name = "QuickLook reStructuredText"
  dist_dir = "dist"
  xarchive_ext = ".xcarchive"
  environ_c_file = "external"/
    "lazy_rest-0.2.0-c-sources-macosx-amd64-release"/"os.c"
  zip_base = dist_dir/"quicklook-rest-with-nim-" & version_str
  xarchive_generator_path =
    "Products"/"Library"/"QuickLook"/public_name & ".qlgenerator"
  xcodebuild_exe = "xcodebuild"
  zip_exe = "zip"
  dist_readme = "docs"/"dist"/"readme.rst"
  dist_example = "docs"/"dist"/"example.rst"
  prism_js_start = "languages="
  prism_js_out = "docs"/"prism_supported_langs_list.rst"
  prism_blacklist = ["clike", "css-extras", "php-extras"]
  nim_list_out = "docs"/"nim_supported_langs_list.rst"
  nim_blacklist = ["none"]

let
  rst_files = concat(@["docs"/"debugging_quicklook", "docs"/"release_steps",
    "docs"/"CHANGES", "LICENSE", "README", "docindex",
    "docs"/"supported_languages"],
    map_it([dist_example, dist_readme], string, it.change_file_ext("")))


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


proc prism_js_in(): string =
  ## Returns the path to the prism js file.
  ##
  ## This will be a path to the lazy_rest embedded file, which is presumed to
  ## be the same as the one used by the external pregenerated C sources. If
  ## something goes wrong, this proc will quit.
  #prism_js_in = "nim"/"prism.js"
  let (output, code) = exec_cmd_ex("nimble path lazy_rest")
  if code != 0:
    quit("Warning, ``nimble path lazy_rest`` returned non zero!")

  for raw_line in output.split_lines:
    let dir = raw_line.strip
    if dir.exists_dir:
      result = dir/"resources"/"prism.js"
      if result.exists_file:
        return
      else:
        quit("Didn't find " & result)

  quit("No sensible value returned by nimble?")


proc update_lang_list() =
  # Special proc which generates a specific rst file for inclusion.
  #
  # The proc takes the prism.js file and reads the first line which has a
  # speciic URL request format. From this the list of supported language is
  # recovered and some entries which don't make sense are stripped.
  #
  # For the nim list the constants from the highlight module are dumped
  # inconditionally.
  var langs = filter_it(@sourceLanguageToStr, not (it in nim_blacklist))
  langs.sort(system.cmp)
  langs.map_it("* " & it & "\n")
  nim_list_out.write_file(langs.join)

  if not prism_js_out.needs_refresh(prism_js_in()): return

  assert prism_js_in().exists_file
  #let THE WEIRD BUG CRASHING DEVEL
  #  buffer = read_file(prism_js_in())
  #  line = to_seq(lines(buffer))[0]
  let
    line = to_seq(lines(prism_js_in()))[0]
    first = line.find(prism_js_start) + prism_js_start.len
    last = line.find(" ", first)

  langs = line[first .. <last].split('+')

  # Remove bad items.
  langs = filter_it(langs, not (it in prism_blacklist))
  langs.sort(system.cmp)
  langs.map_it("* " & it & "\n")
  prism_js_out.write_file(langs.join)


proc doc() =
  update_lang_list()

  # Generate html files from the rst docs.
  for rst_file, html_file in all_rst_files():
    if not html_file.needs_refresh(rst_file): continue
    if not rst2html(rst_file):
      quit("Could not generate html doc for " & rst_file)
    else:
      change_rst_links_to_html(html_file)
      echo rst_file & " -> " & html_file


proc check_doc() =
  for rst_file, html_file in all_rst_files():
    echo "Testing ", rst_file
    let (output, exit) = execCmdEx("rst2html.py " & rst_file & " > /dev/null")
    if output.len > 0 or exit != 0:
      echo "Failed python processing of " & rst_file
      echo output

proc clean() =
  prism_js_out.remove_file
  for path in dot_walk_dir_rec("."):
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
    "-v" & version_str & xarchive_ext
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
  dest_archive.pack_dir(do_remove = false)

  # Prepare zip directory.
  zip_base.create_dir
  let dest_generator = zip_base/extract_filename(xarchive_generator_path)
  move_file(dest_archive/xarchive_generator_path, dest_generator)

  doAssert dest_generator.exists_dir
  dest_archive.remove_dir

  # Generate instructions.
  let dist_readme_html = dist_readme.rst_file_to_html
  write_file(zip_base/"readme.html", dist_readme_html)
  write_file(zip_base/"example.rst", dist_example.read_file)

  # Archive.
  zip_base.pack_dir
  when defined(macosx): shell("open " & dist_dir)

  echo """

Add the following notes to the release info:

[See the changes log](https://github.com/gradha/quicklook-rest-with-nim/blob/v$1/docs/CHANGES.rst).

Binary MD5 checksums:""" % [version_str]
  for filename in walk_files(dist_dir/"*.zip"):
    let v = filename.read_file.get_md5
    echo "* ``", v, "`` ", filename.extract_filename


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
  doc()
  dist()
