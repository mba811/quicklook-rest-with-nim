import packages/docutils/rstgen, os, packages/docutils/rst, strutils,
  parsecfg, subexes, strtabs, streams, times

proc loadConfig(filename: string): PStringTable =
  result = newStringTable(modeStyleInsensitive)
  var f = newFileStream(filename, fmRead)
  if f != nil:
    var p: TCfgParser
    open(p, f, filename)
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
    echo("cannot open: " & filename)

proc doit(filename: string): string =

  let
    parse_options = {roSupportRawDirective}
    config = loadConfig("nimdoc.cfg")
  var
    GENERATOR: TRstGenerator
    HAS_TOC: bool

  proc myFindFile(filename: string): string =
    # we don't find any files in online mode:
    result = ""

  GENERATOR.initRstGenerator(outHtml, config, filename, parse_options,
    myFindFile, rst.defaultMsgHandler)

  # Parse the result.
  var RST = rstParse(readFile(filename), filename, 1, 1, HAS_TOC, parse_options)
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

when isMainModule:
  writeFile("out.html", doit("test.rst"))
