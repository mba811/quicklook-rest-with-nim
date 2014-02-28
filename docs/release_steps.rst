====================================
What to do for a new public release?
====================================

* Create new milestone with version number. The version number for stable
  releases has to have an even minor and maintenance value and always greater
  than the development version number.
* Create new dummy issue `Release versionname` and assign to that milestone.
* Annotate the release issue with the Nimrod commit used to compile sources,
  and Xcode version too.
* ``git flow release start versionname`` (versionname without v).
* Update version numbers:

  * Modify `../README.rst <../README.rst>`_ (s/development/stable/).
  * Modify `../nim/rester.nim <../nim/rester.nim>`_.
  * Update `CHANGES.rst <CHANGES.rst>`_ with list of changes and
    version/number.

* ``git commit -av`` into the release branch the version number changes.
* Regenerate the C sources:

  * Make sure the `environ global variable access
    <https://github.com/gradha/quicklook-rest-with-nimrod/issues/27>`_ is done
    correctly, either by patching Nimrod's ``os`` module or updating to a newer
    version which doesn't have the issue.
  * Commit regenerated sources as separate commit.

* ``git flow release finish versionname`` (the tagname is versionname without
  v).
* Move closed issues to the release milestone.
* Push all to git: ``git push origin master stable --tags``.
* Open Xcode project.

  * Build the ``Nimrod rst lib`` target, make sure git doesn't show changes,
    otherwise the previous C sources generation step failed. `Beware of the
    environ`.
  * Build the ``Quicklook reStructuredText`` target.
  * Select the product and reveal it in Finder.
  * Compress into a zip the binary.
  * Attach the binary to the appropriate release at
    `https://github.com/gradha/quicklook-rest-with-nimrod/releases
    <https://github.com/gradha/quicklook-rest-with-nimrod/releases>`_.
* Increase version numbers, at least maintenance (stable version + 0.0.1):

  * Modify `../README.rst <../README.rst>`_.
  * Modify `../nim/rester.nim <../nim/rester.nim>`_.
  * Add to `CHANGES.rst <CHANGES.rst>`_ development version with unknown
    date.

* ``git commit -av`` into ``master`` with *Bumps version numbers for
  development version. Refs #release issue*.
* Close the dummy release issue.
* Announce at `http://forum.nimrod-lang.org/t/317
  <http://forum.nimrod-lang.org/t/317>`_.
