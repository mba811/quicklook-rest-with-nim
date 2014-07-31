======================
QuickLook ReST example
======================

Thank you for trying `QuickLook render plugin for ReST
<https://github.com/gradha/quicklook-rest-with-nimrod>`_! This is a simple
``.rst`` example file provided for you to test the plugin.
As you have seen, ``.rst`` files can have hyperlinks, like http://google.com/.
You can also include images, even if they are from the `interblag
<http://xkcd.com/181/>`_!

.. image:: http://gradha.github.io/i/Feed-icon.svg

Don't try to click that RSS icon, though, it's just an image.  By the way, this
plugin has been written in the `Nimrod programming language
<http://nimrod-lang.org>`_. See how awesome Nimrod code looks:

.. code:: nimrod
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
https://github.com/gradha/quicklook-rest-with-nimrod/issues. Full ``.rst`` spec
support is still far away, but if you tell me what is failing for you I might
be able to fix that first.

Enjoy!
