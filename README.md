aoladder_contraction
====================

The aoladder contraction super-instruction is to be accelerated.

To do this, the super-instruction, a fortran file, has been isolated and stubs have been created to mimic the behavior of the SIP.

To Compile & Run
----------------

Please download the Google Tests v1.7 (http://googletest.googlecode.com/files/gtest-1.7.0.zip)

Unzip it into the root directory of this project.
Cd into the resulting gtest-1.7.0 folder.
Configure it as: ```./configure --without-pthread```
And ```make``` it.

Then ```make``` the aoladder_contraction project.


