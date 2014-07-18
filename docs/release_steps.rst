========================================
QuickLook reST with Nimrod release steps
========================================

* Create new milestone with version number (``vXXX``) at
  https://github.com/gradha/quicklook-rest-with-nimrod/issues/milestones.
* Create new dummy issue `Release versionname` and assign to that milestone.
* Annotate the release issue with the Nimrod commit used to compile sources,
  and Xcode version too.
* ``git flow release start versionname`` (versionname without v).
* Update version numbers:

  * Modify `README.rst <../README.rst>`_ (s/development/stable/).
  * Modify `nim/rester.nim <../nim/rester.nim>`_.
  * Update `docs/CHANGES.rst <CHANGES.rst>`_ with list of changes and
    version/number.

* ``git commit -av`` into the release branch the version number changes.
* Regenerate the C sources:

  * Make sure the `environ global variable access
    <https://github.com/gradha/quicklook-rest-with-nimrod/issues/27>`_ is done
    correctly, either by patching Nimrod's ``os`` module or updating to a newer
    version which doesn't have the issue.
  * Commit regenerated sources as separate commit if needed.

* ``git flow release finish versionname`` (the tagname is versionname without
  v). When specifying the tag message, copy and paste a text version of the
  changes log into the message. Add rst item markers.
* Move closed issues to the release milestone.
* Prepare distribution binaries:

  * Open Xcode project.
  * Build the ``Nimrod rst lib`` target, make sure git doesn't show changes,
    otherwise the previous C sources generation step failed. `Beware of the
    environ`.
  * Close Xcode and run ``nake dist`` to build distribution zip files.
  * Push all to git: ``git push origin master stable --tags``.
  * Attach the binary to the appropriate release at
    `https://github.com/gradha/quicklook-rest-with-nimrod/releases
    <https://github.com/gradha/quicklook-rest-with-nimrod/releases>`_. Describe
    the release with the command line info containing md5 checksums.

* Increase version numbers, at least maintenance (stable version + 0.0.1):

  * Modify `README.rst <../README.rst>`_.
  * Modify `nim/rester.nim <../nim/rester.nim>`_.
  * Add to `docs/CHANGES.rst <CHANGES.rst>`_ development version with unknown
    date.

* ``git commit -av`` into ``master`` with *Bumps version numbers for
  development version. Refs #release issue*.
* ``git push origin master stable --tags``.
* Close the dummy release issue and related milestone.
* Announce at `http://forum.nimrod-lang.org/t/317
  <http://forum.nimrod-lang.org/t/317>`_.
