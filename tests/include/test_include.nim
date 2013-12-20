import rester

when isMainModule:
  echo "Testing the first one, this should be easy."
  writeFile("simple_include_01.html",
    safe_rst_file_to_html("simple_include_01.rst"))

  echo "Ok, now testing simple recursion, use Ctrl+C to escape…"
  writeFile("recursion_base.html",
    safe_rst_file_to_html("recursion_base.rst"))

  echo "Ok, now the complex trick, cyclick recursion…"
  writeFile("complex_recursion_a.html",
    safe_rst_file_to_html("complex_recursion_a.rst"))

