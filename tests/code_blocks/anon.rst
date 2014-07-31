================
Anonymous blocks
================

Let's see how this goes, the field should be ignored::

    :number-lines: -33

    echo "Hey nimrod!"
    if a < b:
        # Blah blah
        echo "Cool, right?"

This should **NOT** render as C, or anything, for the matter::

    printf("Ha ha\n");
    // Comment
    abort();

Or::

    10 print "awesome"
    20 goto 10
