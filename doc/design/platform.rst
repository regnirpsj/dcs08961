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

      class base

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

platform

  application

    class base

  posix

    application

      class base

  win32

    application

      class base
      
      class console
      
      class windows

  winrt

    application

      class base
      
      class desktop
      
      class store
      
      class universal

  window

    class base

  glut

    window

      class base
      
      class simple

  win32

    window

      class base
      
      class simple

  winrt

    window

      class base
      
      class simple
