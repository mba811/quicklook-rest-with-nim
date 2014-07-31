==================
Hello code blocks!
==================

Extension code-block
====================

This should be a `code block`:code: in HTML, but fail due to lack of HTML
rendering:

.. code-block:: html

    <html><body>
    <h1>Title</h1>
    <p>Hey yo</p>
    </body></html>

This should render without syntax highlight, uses explicit none language.

.. code-block:: none

    <html><body>
    <h1>Title</h1>
    <p>Hey yo</p>
    </body></html>

No parameter should render this as nimrod code.

.. code-block::

    <html><body>
    <h1>Title</h1>
    <p>Hey yo</p>
    </body></html>

With numbers!

.. code-block::
    :number-lines:

    <html><body>
    <h1>Title</h1>
    <p>Hey yo</p>
    </body></html>

Standard code directive
=======================

Same as before but using the code directive:

.. code:: html

    <html><body>
    <h1>Title</h1>
    <p>Hey yo</p>
    </body></html>

Another dupe:

.. code:: none

    <html><body>
    <h1>Title</h1>
    <p>Hey yo</p>
    </body></html>

No parameter should render this as plain text:

.. code::

    <html><body>
    <h1>Title</h1>
    <p>Hey yo</p>
    </body></html>

With numbers!

.. code::
    :number-lines:

    <html><body>
    <h1>Title</h1>
    <p>Hey yo</p>
    </body></html>
