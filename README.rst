===============
dcs08961 README
===============

:Author: Jan P Springer <regnirpsj@gmail.com>

.. contents::

.. _OpenGL: http://opengl.org/
.. _OGLplus: http://oglplus.org/
.. _CMake: http://www.cmake.org/
.. _Doxygen: http://www.doxygen.org/

Introduction
============

``dcs08961`` is an infrastructure project to support the ``08961 Real-Time Graphics`` module at the ``Department of Computer Science, University of Hull``.

Building and Installation
=========================

Quick Setup
-----------

::

linux::

 $> cd <src-dir-created-by-git-clone>
 $> mkdir build && cd build
 $> cmake -DCMAKE_INSTALL_PREFIX=../install ..
 $> cmake --build . --clean-first
 $> cmake --build . --target test_all

windows::

 $> cd <src-dir-created-by-git-clone>
 $> mkdir build && cd build
 $> cmake -DCMAKE_INSTALL_PREFIX=../install ..
 $> cmake --build . --clean-first -- /nologo /v:q
 $> cmake --build . --target test_all -- /nologo /v:q
 $> cmake --build . --target install -- /nologo /v:q

Overview
--------

[to be written]

Requirements
------------

[to be written]

Acknowledgements
================

[to be written]

License
=======

Copyright 2014  University of Hull. Distributed under the LGPLv2.1 (see the accompanying file LICENSE).

