===============================
Examples of syntax highlighting
===============================

CSS
====

Empty rule

.. code:: css

    *{} * {} p {}
    ul,
    ol {}

Simple rule

.. code:: css

    p { color: red; }

Important rule

.. code:: css

    p { color: red !important; }

@ rule

.. code:: css

    @media screen and (min-width: 100px) {}

LESS variable

.. code:: css

    @main-color: red;
    .foo {
      background: @main-color;
    }

Comment

.. code:: css

    /* Simple comment here */

String

.. code:: css

    content: 'foo';
URL

.. code:: css

    content: url(foo.png);


JavaScript
==========

Variable assignment

.. code:: javascript

    var foo = "bar", baz = 5;

Operators

.. code:: javascript

    (1 + 2 * 3)/4 >= 3 && 4 < 5 || 6 > 7

Indented code

.. code:: javascript

    if (true) {
    	while (true) {
    		doSomething();
    	}
    }
Regex with slashes

.. code:: javascript

    var foo = /([^/])\/(\\?.|\[.+?])+?\/[gim]{0,3}/g;

Regex that ends with double slash

.. code:: javascript

    var bar = /\/\*[\w\W]*?\*\//g;

Single line comments & regexes

.. code:: javascript

    // http://lea.verou.me
    var comment = /\/\*[\w\W]*?\*\//g;

Link in comment

.. code:: javascript

    // http://lea.verou.me
    /* http://lea.verou.me */

Nested strings

.. code:: javascript

    var foo = "foo", bar = "He \"said\" 'hi'!"

Strings inside comments

.. code:: javascript

    // "foo"
    /* "foo" */

Strings with slashes

.. code:: javascript

    env.content + '</' + env.tag + '>'
    var foo = "/" + "/";
    var foo = "http://prismjs.com"; // Strings are strings and comments are comments ;)

Regex inside single line comment

.. code:: javascript

    // hey, /this doesn’t fail!/ :D

Two or more division operators on the same line

.. code:: javascript

    var foo = 5 / 6 / 7;

A division operator on the same line as a regex

.. code:: javascript

    var foo = 1/2, bar = /a/g;
    var foo = /a/, bar = 3/4;


Java
====

Java Language Keywords. Actually, this part of the test will be highlighted by
the Nimrod highlight module since java **is** supported. Though maybe that's
not such a good idea…

.. code:: java

    abstract continue for        new       switch
    assert   default  goto       package   synchronized
    boolean  do       if         private   this
    break    double   implements protected throw
    byte     else     import     public    throws
    case     enum     instanceof return    transient
    catch    extends  int        short     try
    char     final    interface  static    void
    class    finally  long       strictfp  volatile
    const    float    native     super     while

Operators

.. code:: java

    // postfix
    expr++ expr--
    // unary
    ++expr --expr +expr -expr ~ !
    // multiplicative
    * / %
    // additive
    + -
    // shift
    << >> >>>
    // relational
    < > <= >= instanceof
    // equality
    == !=
    // bitwise AND
    &
    // bitwise exclusive OR
    ^
    // bitwise inclusive OR
    |
    // logical AND
    &&
    // logical OR
    ||
    // ternary
    ? :
    // assignment
    = += -= *= /= %= &= ^= |= <<= >>= >>>=
	
Simple class example

.. code:: java

    package com.prismjs;

    import java.io.*;

    @SuppressWarnings("unchecked")
    public class PrismJS {

        public static Integer test = 0;

        /**
         * Javadoc style comment
         *
         * @param args
         */
        public static void main(String[] args) {
            // Let's create some variables
            int numArgs = args.length;
            Integer a = 0x1;
            String test = "" + "Hello" + " \"World\"!";
            double dvalue = 1.23;
            int optest = 0;
            optest += 321 - 45 * 1247 / 425 % 123;

            /*
             * Multiline comment
             */
            for (int i = 0; i < numArgs; i++) {
                // Simple line comment
                System.out.println("Arg value= " + args[i]);
            }

            do {
                System.out.println("Do while ok!");
            } while (false);
        }
    }

As you can notice String keyword is not highlighted because it's not a Java
language keyword (cf. Java Language Keywords). The main reason is that String
is not a primitive type such as int but a class type like Integer.


Coffeescript
============

Variable assignment

.. code:: coffeescript

    foo = "bar"

Operators

.. code:: coffeescript

    (1 + 2 * 3)/4 >= 3 && 4 < 5 || 6 > 7

Indented code

.. code:: coffeescript

    if true
        while true
            doSomething()
	
Regex with slashes

.. code:: coffeescript

    var foo = /([^/])\/(\\?.|\[.+?])+?\/[gim]{0,3}/g;

Single line comments

.. code:: coffeescript

    # This is a comment

Link in comment

.. code:: coffeescript

    # http://lea.verou.me
    ###
    Block Comment
    ### 

Nested strings

.. code:: coffeescript

    var foo = "foo", bar = "He \"said\" 'hi'!"

String inside comment

.. code:: coffeescript

    # "foo"

Strings with slashes

.. code:: coffeescript

    env.content + '</' + env.tag + '>'
    var foo = "/" + "/";

Two or more division operators on the same line

.. code:: coffeescript

    foo = 5 / 6 / 7;

A division operator on the same line as a regex

.. code:: coffeescript

    foo = 1/2, bar = /a/g;
    foo = /a/, bar = 3/4;

A function

.. code:: coffeescript

    _buttonClick: (a, b) ->
        @hide()
	
An Object

.. code:: coffeescript

    code = {
        css: "Cascading Style Sheets"
        cs: "CoffeeScript"
    }
	
Class Definition

.. code:: coffeescript

    class CoffeeScript extends Prism.Javascript


HTTP
====

Request Examples
----------------

A simple HTTP GET request:

.. code:: http

    GET https://example.tld/v1/:serviceName/users.json?sort=:sortMethod HTTP/1.1

Here is an HTTP POST with a body:

.. code:: http

    POST https://example.tld/v1/:serviceName/users.json HTTP/1.1
    Content-Type: application/json

    {
        "names": ["test1", "test2"],
        "version": 1.0
    }

Response Examples
-----------------

JSON response body:

.. code:: http

    HTTP/1.1 200 OK
    Content-Type: application/json
    X-Response-Time: 6ms

    {
        "users": [
            {
                "name": "John",
                "points": 24
            },
            {
                "name": "Lea",
                "points": 15
            }
        ]
    }

XML response body:

.. code:: http

    HTTP/1.1 200 OK
    Content-Type: application/xml
    X-Response-Time: 10ms

    <root>
        <status code="0">
            Successful
        </status>
    </root>
