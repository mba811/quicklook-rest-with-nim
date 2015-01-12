======================
QuickLook ReST example
======================

Thank you for trying `QuickLook reST with Nim
<https://github.com/gradha/quicklook-rest-with-nim>`_! This is a simple
``.rst`` example file provided for you to test the plugin.  As you have seen,
``.rst`` files can have hyperlinks, like http://google.com/.  You can also
include images, even if they are from the `interblag <http://xkcd.com/181/>`_!

.. image:: http://gradha.github.io/i/Feed-icon.svg

Don't try to click that RSS icon, though, it's just an image (OS X versions
previous to Mavericks won't include network resources, so you will get a
placeholder icon).  By the way, this plugin has been written in the `Nim
programming language <http://nim-lang.org>`_. See how awesome Nim code looks:

.. code:: nim
    :number-lines:

    # compute average line length
    var count = 0
    var sum = 0
    
    for line in stdin.lines:
      count += 1
      sum += line.len
    
    echo "Average line length: ",
      if count > 0: sum / count else: 0

And now, a word from `our sponsors <http://www.elhaso.es>`_\… just kidding!
Well, remember that if you find an ``.rst`` file which doesn't render well (or
at all, oops!) you can drop me a note at
https://github.com/gradha/quicklook-rest-with-nim/issues. Full ``.rst`` spec
support is still far away, but if you tell me what is failing for you I might
be able to fix that first.

Enjoy!
