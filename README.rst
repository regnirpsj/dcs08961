===============
dcs08961 README
===============

:Author: Jan P Springer <regnirpsj@gmail.com>

.. contents::

.. _Boost:              http://www.boost.org/
.. _CMake:              http://www.cmake.org/
.. _DirectX:            http://msdn.microsoft.com/en-us/library/windows/desktop/ee663274%28v=vs.85%29.aspx
.. _Doxygen:            http://www.doxygen.org/
.. _GLI:                http://gli.g-truc.net/
.. _GLM:                http://glm.g-truc.net/
.. _OGLplus:            http://oglplus.org/
.. _OpenGL:             http://opengl.org/
.. _University of Hull: http://www2.hull.ac.uk/science/computer_science.aspx

Introduction
============

``dcs08961`` is an infrastructure project to support the ``08961 Real-Time Graphics`` module at the ``Department of Computer Science, `University of Hull`_``.

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
 $> cmake --build . --target install

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

- `Boost`_
- `GLM`_/`GLI`_
- `OGLplus`_
- `DirectX`_

Acknowledgements
================

[to be written]

License
=======

Copyright 2014-2015 `University of Hull`_. Distributed under the LGPLv2.1 (see the accompanying file LICENSE).
