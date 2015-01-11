=====================================
QuickLook reST with Nim release steps
=====================================

* Create new milestone with version number (``vXXX``) at
  https://github.com/gradha/quicklook-rest-with-nim/milestones.
* Create new dummy issue `Release versionname` and assign to that milestone.
* Annotate the release issue with the Nim commit used to compile sources,
  and Xcode version too.
* ``git flow release start versionname`` (versionname without v).
* Update version numbers:

  * Modify `README.rst <../README.rst>`_ (s/development/stable/).
  * Modify `nakefile.nim <../nakefile.nim>`_.
  * Modify `quicklook-rest-with-nim.nimble
    <../quicklook-rest-with-nim.nimble>`_.
  * Update `docs/CHANGES.rst <CHANGES.rst>`_ with list of changes and
    version/number.

* ``git commit -av`` into the release branch the version number changes.
* ``git flow release finish versionname`` (the tagname is versionname without
  v). When specifying the tag message, copy and paste a text version of the
  changes log into the message. Add rst item markers.
* Move closed issues to the release milestone.
* Prepare distribution binaries:

  * Run ``nake dist`` to build distribution zip files.
  * Push all to git: ``git push origin master stable --tags``.
  * Attach the binary to the appropriate release at
    `https://github.com/gradha/quicklook-rest-with-nim/releases
    <https://github.com/gradha/quicklook-rest-with-nim/releases>`_. Describe
    the release with the command line info containing md5 checksums.

* Increase version numbers, at least maintenance (stable version + 0.0.1):

  * Modify `README.rst <../README.rst>`_.
  * Modify `nakefile.nim <../nakefile.nim>`_.
  * Modify `quicklook-rest-with-nim.nimble
    <../quicklook-rest-with-nim.nimble>`_.
  * Add to `docs/CHANGES.rst <CHANGES.rst>`_ development version with unknown
    date.

* ``git commit -av`` into ``master`` with *Bumps version numbers for
  development version. Refs #release issue*.
* ``git push origin master stable --tags``.
* Close the dummy release issue and related milestone.
* Announce at `http://forum.nim-lang.org/t/317
  <http://forum.nim-lang.org/t/317>`_.
* Contact quicklookplugins to update
  http://www.quicklookplugins.com/2014/07/20/restructuredtext-rest/, or maybe
  just add a comment saying there is a new version.
