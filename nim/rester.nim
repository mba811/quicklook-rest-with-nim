import packages/docutils/rstgen, os, packages/docutils/rst, strutils,
  parsecfg, subexes, strtabs, streams, times, cgi

const
  rest_config = slurp("nimdoc.cfg")
  versionStr* = "0.3.1" ## Module version as a string.
  versionInt* = (major: 0, minor: 3, maintenance: 1) ## \
  ## Module version as an integer tuple.
  ##
  ## Major versions changes mean a break in API backwards compatibility, either
  ## through removal of symbols or modification of their purpose.
  ##
  ## Minor version changes can add procs (and maybe default parameters). Minor
  ## odd versions are development/git/unstable versions. Minor even versions
  ## are public stable releases.
  ##
  ## Maintenance version changes mean I'm not perfect yet despite all the kpop
  ## I watch.


proc loadConfig(): PStringTable =
  result = newStringTable(modeStyleInsensitive)
  var f = newStringStream(rest_config)
  if f != nil:
    var p: TCfgParser
    open(p, f, "static slurped config")
    while true:
      var e = next(p)
      case e.kind
      of cfgEof:
        break
      of cfgSectionStart:   ## a ``[section]`` has been parsed
        nil
      of cfgKeyValuePair:
        result[e.key] = e.value
      of cfgOption:
        echo("command: " & e.key & ": " & e.value)
      of cfgError:
        echo(e.msg)
    close(p)
  else:
    echo("cannot load config from slurped contents")

proc do_rst_file_to_html(filename: string): string =
  ## Converts a filename with rest content into a string with HTML tags.
  let
    parse_options = {roSupportRawDirective}
    config = loadConfig()
    content = readFile(filename)
  var
    GENERATOR: TRstGenerator
    HAS_TOC: bool

  proc myFindFile(filename: string): string =
    # we don't find any files in online mode:
    result = ""

  GENERATOR.initRstGenerator(outHtml, config, filename, parse_options,
    myFindFile, rst.defaultMsgHandler)

  # Parse the result.
  var RST = rstParse(content, filename, 1, 1, HAS_TOC, parse_options)
  RESULT = newStringOfCap(30_000)

  # Render document into HTML chunk.
  var MOD_DESC = newStringOfCap(30_000)
  GENERATOR.renderRstToOut(RST, MOD_DESC)
  #GENERATOR.modDesc = toRope(MOD_DESC)

  let last_mod = getGMTime(filename.getLastModificationTime())
  var title = GENERATOR.meta[metaTitle]
  #if title.len < 1: title = filename.split_path.tail

  # Now finish by adding header, CSS and stuff.
  result = subex(config["doc.file"]) % ["title", title,
    "date", last_mod.format("yyyy-MM-dd"), "time", last_mod.format("HH:MM"),
    "content", MOD_DESC]

proc rst_file_to_html(filename: string): string =
  ## Wrapper over do_rst_file_to_html to catch exceptions.
  ##
  ## If something bad happens, it tries to show the error for debugging.
  try:
    result = do_rst_file_to_html(filename)
  except:
    let
      e = getCurrentException()
      msg = getCurrentExceptionMsg()
      content = readFile(filename).XMLEncode
    result = "<html><body><b>Sorry! Error parsing " & filename.XMLEncode &
      " with version " & versionStr &
      """.</b><p>If possible please report it at <a href="""" &
      """https://github.com/gradha/quicklook-rest-with-nimrod/issues">""" &
      "https://github.com/gradha/quicklook-rest-with-nimrod/issues</a>" &
      "<p>" & repr(e).XMLEncode & " with message '" &
      msg.XMLEncode & "'</p><p>Displaying raw contents of file anyway:</p>" &
      "<p><tt>" & content.replace("\n", "<br>") & "</tt></p></body></html>"

var last_conversion: string

proc txt_to_rst*(input_filename: cstring): int {.exportc.}=
  ## Converts the input filename.
  ##
  ## The conversion is stored in internal global variables. The proc returns
  ## the number of bytes required to store the generated HTML, which you can
  ## obtain using the global accessor getHtml passing a pointer to the buffer.
  ##
  ## The returned value doesn't include the typical C null terminator.
  last_conversion = rst_file_to_html($input_filename)
  result = last_conversion.len


proc get_global_html*(output_buffer: pointer) {.exportc.} =
  ## Copies the result of txt_to_rst into output_buffer.
  ##
  ## If output_buffer doesn't contain the bytes returned by txt_to_rst, you
  ## will pay that dearly!
  if last_conversion.isNil:
    quit("Uh oh, wrong API usage")
  copyMem(output_buffer, addr(last_conversion[0]), last_conversion.len)


#when isMainModule:
#  writeFile("out.html", rst_file_to_html("test.rst"))
