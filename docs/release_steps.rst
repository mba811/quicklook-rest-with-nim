====================================
What to do for a new public release?
====================================

* Create new milestone with version number.
* Create new dummy issue `Release versionname` and assign to that milestone.
* git flow release start versionname (versionname without v).
* Update version numbers:

  * Modify `../README.rst <../README.rst>`_.
  * Modify `../nim/rester.nim <../nim/rester.nim>`_.
  * Update `CHANGES.rst <CHANGES.rst>`_ with list of changes and
    version/number.

* ``git commit -av`` into the release branch the version number changes.
* Regenerate the C sources and commit again a separate one.
* git flow release finish versionname (the tagname is versionname without v).
* Move closed issues from `future milestone` to the release milestone.
* Push all to git: ``git push origin master develop --tags``.
* Open Xcode project.

  * Build the ``Nimrod rst lib`` target, make sure git doesn't show changes,
    otherwise the previous C sources generation step failed.
  * Build the ``Quicklook reStructuredText`` target.
  * Select the product and reveal it in Finder.
  * Compress into a zip the binary.
  * Attach the binary to the appropriate release at
    `https://github.com/gradha/quicklook-rest-with-nimrod/releases
    <https://github.com/gradha/quicklook-rest-with-nimrod/releases>`_.
* Increase version numbers, at least maintenance (stable version + 0.1.1):

  * Modify `../README.rst <../README.rst>`_.
  * Modify `../nim/rester.nim <../nim/rester.nim>`_.
  * Add to `CHANGES.rst <CHANGES.rst>`_ development version with unknown
    date.

* ``git commit -av`` into develop with *Bumps version numbers for develop
  branch. Refs #release issue*.
* Close the dummy release issue.
* Announce at `http://forum.nimrod-lang.org/t/317
  <http://forum.nimrod-lang.org/t/317>`_.
