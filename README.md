aoladder_contraction
====================

The aoladder contraction super-instruction is to be accelerated.

To do this, the super-instruction, a fortran file, has been isolated and stubs have been created to mimic the behavior of the SIP.

To Compile & Run
----------------

Please download the Google Tests v1.7 (http://googletest.googlecode.com/files/gtest-1.7.0.zip)

Unzip it into the root directory of this project.

Use CMake:
* In the aoladder_contraction directory, make a build directory, call it BUILD (or anything else) and cd into it
  mkdir BUILD && cd BUILD
* cmake ../
* make


Known Issues
------------
This will run with a C++ compiler that supports std::default_random_engine
The intel compiler on HiPerGator is compatible with gcc 4.4.6 which doesn't support said random engine.
On HiperGator, use gcc/4.7.2

