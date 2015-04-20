===============
dcs08961 README
===============

:Author: Jan P Springer <regnirpsj@gmail.com>

.. contents::

.. _Boost:                          http://www.boost.org/
.. _CMake:                          http://www.cmake.org/
.. _Department of Computer Science: http://www2.hull.ac.uk/science/computer_science.aspx
.. _DirectX:                        http://msdn.microsoft.com/en-us/library/windows/desktop/ee663274%28v=vs.85%29.aspx
.. _Doxygen:                        http://www.doxygen.org/
.. _FreeGLUT:                       http://freeglut.sourceforge.net/
.. _GLEW:                           http://glew.sourceforge.net/
.. _GLI:                            http://gli.g-truc.net/
.. _GLM:                            http://glm.g-truc.net/
.. _OGLplus:                        http://oglplus.org/
.. _OpenGL:                         http://opengl.org/
.. _The University of Hull:         http://www.hull.ac.uk/
.. _cmake-modules:                  http://github.com/regnirpsj/cmake-modules

Introduction
============

``dcs08961`` is an (experimental) infrastructure project to support the ``08961 Real-Time Graphics`` module at the `Department of Computer Science`_, `The University of Hull`_.

Building and Installation
=========================

Quick Setup
-----------

::

Linux::

 $> cd <src-dir-created-by-git-clone>
 $> mkdir build && cd build
 $> cmake -DCMAKE_INSTALL_PREFIX=../install ..
 $> cmake --build . --clean-first
 $> cmake --build . --target test_all
 $> cmake --build . --target install

Windows::

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

Mandatory:
- `Boost`_
- `cmake-modules`_
- `GLM`_/`GLI`_
- `OGLplus`_/`GLEW`_/`FreeGLUT`_
- `DirectX`_

Optional:
- `Doxygen`_

Acknowledgements
================

[to be written]

License
=======

Copyright 2014-2015 `The University of Hull`_. Distributed under the LGPLv2.1 (see the accompanying file LICENSE).
