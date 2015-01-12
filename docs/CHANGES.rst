===================================
Quicklook reST with Nim changes log
===================================

v0.4.5, ????-??-??
------------------

* `Moved rester module into lazy_rest babel package
  <https://github.com/gradha/quicklook-rest-with-nim/issues/42>`_. The usage
  of ``lazy_rest`` brings `several improvements
  <https://github.com/gradha/lazy_rest/blob/v0.2.0/docs/changes.rst>`_, with
  the most important being:

  * Avoid hanging on infinite recursive include directive.
  * Improved rendering of line numbered source blocks.

* `Updated Nimrod references to Nim
  <https://github.com/gradha/quicklook-rest-with-nim/issues/45>`_.
* `Upgraded nakefile with bb_nake
  <https://github.com/gradha/quicklook-rest-with-nim/issues/46>`_.
* `Added note about Yosemite problems
  <https://github.com/gradha/quicklook-rest-with-nim/issues/47>`_

v0.4.4, 2014-07-31
------------------

* `Changed default language syntax highlight based on rest directive
  <https://github.com/gradha/quicklook-rest-with-nim/issues/36>`_.
* `Fixed HTML code blocks not being escaped
  <https://github.com/gradha/quicklook-rest-with-nim/issues/38>`_.
* `Added code block syntax highlighting
  <https://github.com/gradha/quicklook-rest-with-nim/issues/20>`_.
* `Documented list of languages with syntax highlighting
  <https://github.com/gradha/quicklook-rest-with-nim/issues/40>`_.
* `Added rst example to binary distribution
  <https://github.com/gradha/quicklook-rest-with-nim/issues/39>`_.

v0.4.2, 2014-07-18
------------------

* `Added support for code directive
  <https://github.com/gradha/quicklook-rest-with-nim/issues/33>`_.
* `Uses local time in preview HTML
  <https://github.com/gradha/quicklook-rest-with-nim/issues/34>`_.
* `Added nake task to prepare binary zip for redistribution
  <https://github.com/gradha/quicklook-rest-with-nim/issues/30>`_.

v0.4.0, 2014-02-28
------------------

* `Added support for .nim files
  <https://github.com/gradha/quicklook-rest-with-nim/issues/15>`_.
* `Added external API to change templates at runtime
  <https://github.com/gradha/quicklook-rest-with-nim/issues/22>`_.
* `Updated git-flow notice about stable branch
  <https://github.com/gradha/quicklook-rest-with-nim/issues/23>`_.
* `Fixed binary compatibility due to global environ variable
  <https://github.com/gradha/quicklook-rest-with-nim/issues/27>`_.
* `Made change_rst_options() discardable
  <https://github.com/gradha/quicklook-rest-with-nim/issues/24>`_.
* `Avoids raising exceptions in C API calls
  <https://github.com/gradha/quicklook-rest-with-nim/issues/28>`_.

v0.2.1, 2013-12-20
------------------

* `Added stahp meme to docs
  <https://github.com/gradha/quicklook-rest-with-nim/issues/7>`_.
* `Added support for include directive
  <https://github.com/gradha/quicklook-rest-with-nim/issues/6>`_.
* `Use github releases for binaries
  <https://github.com/gradha/quicklook-rest-with-nim/issues/2>`_.
* `Noted down conspiracy against rst format
  <https://github.com/gradha/quicklook-rest-with-nim/issues/4>`_.

v0.2.0, 2013-12-14
------------------

* Initial release.
