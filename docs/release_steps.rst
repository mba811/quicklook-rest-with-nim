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
* git flow release finish versionname (the tagname is versionname without v).
* Move closed issues from `future milestone` to the release milestone.
* Push all to git: ``git push origin master develop --tags``.
* Increase version numbers, at least maintenance (stable version + 0.1.1):

  * Modify `../README.rst <../README.rst>`_.
  * Modify `../nim/rester.nim <../nim/rester.nim>`_.
  * Add to `CHANGES.rst <CHANGES.rst>`_ development version with unknown
    date.

* ``git commit -av`` into develop with *Bumps version numbers for develop
  branch. Refs #release issue*.
* Close the dummy release issue.
* Announce at
  `http://forum.nimrod-code.org/ <http://forum.nimrod-code.org/>`_.
