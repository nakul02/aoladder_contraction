cmake_minimum_required (VERSION 2.6)

project (aoladder_contraction)

enable_language(Fortran)

add_executable(
    aoladder_contraction_test;
    main.cpp;
    aoladder_contraction_3.F;
    lookup_shell.f;
    sip_interface.fh;
    sip_interface.cpp;
    sip_interface.h;
    constants.h;
    imemory.h;
    )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
