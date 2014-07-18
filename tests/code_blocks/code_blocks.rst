==================
Hello code blocks!
==================

This should be a `code block`:code: in Nimrod:

.. code-block:: nimrod
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

Now comes a standard directive block:

.. code::
    :number-lines:

    10 print "awesome"
    20 goto 10
