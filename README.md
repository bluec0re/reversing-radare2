Development
===========

Dependencies
------------

- C-Compiler (gcc, clang, visual studio)
- cmake

Adding a new challenge
----------------------

    $ cd sources
    $ ./new_challenge.sh
    $ cd challenge$NUM

Start developing


Compiling
---------

gcc or clang

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

Visual Studio

    C> mkdir build
    C> cd build
    C> cmake -G "Visual Studio" ..

Open solution files in visual studio
