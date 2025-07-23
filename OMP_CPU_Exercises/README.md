

This directory contains exercises and solutions for a hands-on
OpenMP course.  Information about these programs can be found
in the comments and in the slides from the course.

To use these programs, copy the appropriate "def" file into
"make.def".  For example on a linux system running the gnu 
compilers, I'd type

  cp linux_gnu.def make.def

Then build the programs and test them

   make test

The solutions directory uses the same make.def file so to build
the solutions, just type "make test".  The directory Challenge_Problems
contains additional exercises for more advanced students.  These
have not been as carefully tested and may have problems building
and running on some systems.
