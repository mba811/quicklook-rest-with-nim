================================================
QuickLook reST with Nim syntax highlight support
================================================

The `QuickLook render plugin for ReST
<https://github.com/gradha/quicklook-rest-with-nim>`_ supports syntax highlight
in code blocks. If the specified language is supported by `Nim's highlite
module <http://nim-lang.org/highlite.html>`_ they will be rendered statically
in Nim, generating plain HTML+CSS. Unsupported languages will use the `Prism
syntax highlighter <http://prismjs.com>`_. This increases the size of the
generated HTML and may not be as precise as a proper syntax highlighter, but
seems to work overall pretty well.

The list of languages supported natively by Nim is:

.. include:: nim_supported_langs_list.rst

The list of supported languages through prism.js is:

.. include:: prism_supported_langs_list.rst

