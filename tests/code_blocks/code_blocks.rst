==================
Hello code blocks!
==================

Extension code-block
====================

This should be a `code block`:code: in Nimrod:

.. code-block::
    :number-lines: -33

    echo "Hey nimrod!"
    if a < b:
        # Blah blah
        echo "Cool, right?"

This should render as C:

.. code-block:: c
    :number-lines: 33

    printf("Ha ha\n");
    // Comment
    abort();

Standard code directive
=======================

Now comes a standard directive block:

.. code::
    :number-lines:

    10 print "awesome"
    20 goto 10

The following standard block can also use Nimrod syntax highlighting,
essentially duplicating the ``code-block`` extension:

.. code:: nimrod
    :number-lines: 42

    echo "Hey nimrod!"
    if a < b:
        # Blah blah
        echo "Cool, right?"

Trailing space code block?

.. code::
    :number-lines:

    10 print "awesome"
    20 goto 10
    
    

One line in java?

.. code:: java
    :number-lines:

    // Forever alone
