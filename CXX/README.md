Project Euler - C++ 
=======================

These exercises are a single CMake project.

Building
--------
To build, run
```
mkdir build
cd build
cmake ..
make
```

Documentation
-------------
Documentation requires Doxygen, Sphinx, Breathe, and Exhale. To view HTML
documentation, load `build/docs/doxygen/html/index.html` or
`build/docs/sphinx/index.html` in your web browser. Doxygen is more
complete but Sphinx looks better. Sphinx has difficulty with function overloads.
Sphinx formatting directives appear unformatted in Doxygen.

Testing
-------
Tests require Catch2, which will be automatically downloaded from GitHub. To run tests,
execute `ctest` from the build directory. The `tests` directory has `euler_test` and
`utils_tests/euler_utils_tests` for more granular testing.

The tests for the problems are usually simply the one given in the description and then
the correct answer, once known. Utility functions have more extensive tests.

Running
-------
Currently, only tests are supported.

Reminder
--------
If you use these to cheat on the exercises, you're only cheating yourself.
