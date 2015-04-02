.. -*- Mode:rst -*-

=======================
Platform-Design Choices
=======================

Variant A
---------

platform

  application

    class base

    posix

      class application

    win32

      class base
      class console
      class windows

    winrt

      class base
      class desktop
      class store
      class universal

  window

    class base

    glut

      class base
      class simple

    win32

      class base
      class simple

    winrt

      class base
      class simple

Variant B
---------
