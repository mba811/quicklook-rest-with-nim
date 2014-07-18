import rester, strutils, os

proc process(filename: string) =
  # Converts the rst to html.
  let target = filename.change_file_ext(".html")
  target.write_file(safe_rst_file_to_html(filename))

proc test() =
  for path in walk_files("*.rst"):
    process(path)

when isMainModule:
  test()
  echo "Test finished successfully"
