import nake, os, times, osproc, htmlparser, xmltree, strtabs, strutils,
  rester

let
  rst_files = @["docs"/"debugging_quicklook", "docs"/"release_steps",
    "docs"/"CHANGES", "LICENSE", "README", "docindex"]

proc rst2html(filename: string): bool =
  let output = safe_rst_file_to_html(filename)
  if output.len > 0:
    writeFile(filename.changeFileExt("html"), output)
    result = true
  #var d: TRstGenerator
  #initRstGenerator(d, outHtml, config, filename,
  #  {roSupportRawDirective}, nil, rst.defaultMsgHandler)
  #var
  #  dummyHasToc = false
  #  rst = rstParse(s, filename, 0, 1, dummyHasToc, options)
  #  result = ""
  #renderRstToOut(d, rst, result)
  #writeFile(filename.changeFileExt("html"), result)

proc change_rst_links_to_html(html_file: string) =
  ## Opens the file, iterates hrefs and changes them to .html if they are .rst.
  let html = loadHTML(html_file)
  var DID_CHANGE: bool

  for a in html.findAll("a"):
    let href = a.attrs["href"]
    if not href.isNil:
      let (dir, filename, ext) = splitFile(href)
      if cmpIgnoreCase(ext, ".rst") == 0:
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

task "doc", "Generates export API docs for for the modules":
  # Generate html files from the rst docs.
  for rst_file, html_file in all_rst_files():
    if not html_file.needs_refresh(rst_file): continue
    if not rst2html(rst_file):
      quit("Could not generate html doc for " & rst_file)
    else:
      change_rst_links_to_html(html_file)
      echo rst_file & " -> " & html_file
  echo "All done"

task "check_doc", "Validates rst format for a subset of documentation":
  for rst_file, html_file in all_rst_files():
    echo "Testing ", rst_file
    let (output, exit) = execCmdEx("rst2html.py " & rst_file & " > /dev/null")
    if output.len > 0 or exit != 0:
      echo "Failed python processing of " & rst_file
      echo output

task "clean", "Removes temporal files, mainly":
  for path in walkDirRec("."):
    let (dir, name, ext) = splitFile(path)
    if ext == ".html":
      echo "Removing ", path
      path.removeFile()
