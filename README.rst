==============================
QuickLook reST with Nim readme
==============================

`Quick Look <https://en.wikipedia.org/wiki/QuickLook>`_ is a quick preview
feature developed by Apple. `ReST, or reStructuredText
<http://docutils.sourceforge.net>`_ is a text processing system for
transforming plaintext documentation into other formats. `Nim is a programming
language <http://nim-lang.org>`_. And now that I've introduced everybody, this
project is a fusion of all of them to provide a reST QuickLook viewer
implemented in Nim.

There are alternative python implementations like
`https://github.com/cluther/qlrest <https://github.com/cluther/qlrest>`_, which
somehow started from the `markdown QuickLook plugin
<https://github.com/toland/qlmarkdown>`_. However I dislike the python
versions for two reasons:

1. Python installations are very brittle, any change in python or its packages
   can make rendering stop. The last three MacOSX updates broke my python
   programs and required fetching newer versions from the internet. That's not
   a very good way to treat users. Instead, this plugin is statically compiled,
   no changes on your system should break it.
2. .. image:: docs/python_stahp_300.jpg
      :align: right

   Performance. Processing this very readme file with python on my machine
   takes 0.5 seconds, but 0.02 seconds with Nim (as measured from the
   command line in a non reproducible test). Do believe me, python is slow,
   maybe you should `stop using it <http://knowyourmeme.com/memes/stahp>`_ and
   pick a better language.  By the way, the animal on the right is Nim's
   mascot, a `badass honey badger
   <http://www.youtube.com/watch?v=4r7wHMg5Yjg>`_. Nim doesn't care about
   your Python being slow and eats it fearlessly.


The MarkDown Conspiracy
=======================

Have you noticed that markdown seems present just about everywhere? On the
other hand, rst not so much. Why, I wonder? Let's check github for the existing
`qlrest plugins <https://github.com/cluther/qlrest>`_. So I go to
`https://github.com <https://github.com>`_ and type in the search box
**qlrest**:

.. image:: docs/qlrest_matches.png
   :align: center

Huh? Weird. How come there is no match for other qlrest repositories? Maybe a
search for **qlmark** won't work?

.. image:: docs/qlmark_matches.png
   :align: center

Ah, that's interesting. So markdown is found, but rest not. Well, that's
clearly it, Mulder told me it's `a conspiracy
<http://motherboard.vice.com/read/porn-companies-are-going-after-github>`_
against the rst format. Other arguments like the rst implementation being
python rather than C, or the spec sucking, pale in comparison with Big Brother
not allowing you even to *think* in rst.

Madness.

Digression: you can view gihub on mobile devices but the *desktop* version
can't resize below 1000px width. That's another conspiracy there waiting to be
uncovered… the conspiracy of web designers who suck…


License
=======

`MIT license <LICENSE.rst>`_.


Installation
============

From source code
----------------

Check out the repository and open the project file with Xcode. The project has
been tested on MacOSX 10.8 and Xcode 5.0.2. You don't need anything else, since
the project includes the pre generated C files by Nim. Simply select the
QuickLook target and build it. Once built, right click on the
``Product->QuickLook reStructuredText.qlgenerator`` and select ``Show in
Finder``. Now you can move that plugin somewhere useful, like
``~/Library/QuickLook`` and run ``qlmanage -r`` to reset Quick Look or
logout/reboot/whatever. **NOTE**: On OSX 10.10 Yosemite the plugin won't work
from your home directory, you **have** to install it into
``/Library/QuickLook`` until this issue is fixed.

Now you can press space on ``rst`` or ``rest`` files from the Finder and if
everything goes well you should see an HTML preview. Note that this version of
the software is incomplete, and some files might not render for example due to
missing directives. Please report them with the `issue tracker
<https://github.com/gradha/quicklook-rest-with-nim/issues>`_.

Binary installation
-------------------

If you trust binaries and random strangers on the internet, you can go to
`https://github.com/gradha/quicklook-rest-with-nim/releases
<https://github.com/gradha/quicklook-rest-with-nim/releases>`_ and download any
of the ``.zip`` files attached to a specific release. They contain just the
plugin which you can move to ``~/Library/QuickLook``.  **NOTE**: On OSX 10.10
Yosemite the plugin won't work from your home directory, you **have** to
install it into ``/Library/QuickLook`` until this issue is fixed.  After that,
run ``qlmanage -r`` to reset Quick Look or logout/reboot/whatever and you
should be able to see ``.rst`` and ``.nim`` files as rendered HTML.

The plugin should work on all MacOSX versions since Snow Leopard (10.6), though
on Snow Leopard it seems to have threading issues where the first attempt to
display the file will show a processing spinner forever and won't show the
actual rendered version until you close the QuickLook window and open it again.
The plugin is forced to run on the main thread, so I don't know what's wrong.
If you know, please tell me!


Changes
=======

This is development version 0.4.5. For a list of changes see the
`docs/CHANGES.rst file <docs/CHANGES.rst>`_. The software is not complete,
expect bugs and `report them
<https://github.com/gradha/quicklook-rest-with-nim/issues>`_.


Code blocks syntax highlight
============================

When code blocks are found which specify a programming language, if the
language is supported by `Nim's highlite module
<http://nim-lang.org/highlite.html>`_ they will be rendered statically in Nim,
generating plain HTML+CSS. Unsupported languages will use the `Prism syntax
highlighter <http://prismjs.com>`_. This increases the size of the generated
HTML and may not be as precise as a proper syntax highlighter, but seems to
work overall pretty well. You can read the list of supported languages in
`docs/supported_languages.rst <docs/supported_languages.rst>`_.


Plans for the future
====================

* Support for all `reST directives
  <http://docutils.sourceforge.net/docs/ref/rst/directives.html>`_. Also known
  as "yeah it doesn't adhere to the spec fully but that's because the spec
  sucks".
* More automatic install from within Xcode.
* Binary install through DMG files.
* Customizable CSS for previewed HTML.
* Reimplement something like `Pygments <http://pygments.org>`_ for code block
  syntax highlighting.


Git branches
============

This project uses the `git-flow branching model
<https://github.com/nvie/gitflow>`_ with reversed defaults. Stable releases are
tracked in the ``stable`` branch. Development happens in the default ``master``
branch.


Feedback
========

You can send me feedback through `GitHub's issue tracker
<https://github.com/gradha/quicklook-rest-with-nim/issues>`_. I also take a
look from time to time to `Nim's forum <http://forum.nim-lang.org>`_
where you can talk to other Nim programmers.
