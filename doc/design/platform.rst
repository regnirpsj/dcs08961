.. -*- Mode:rst -*-

=======================
Platform-Design Choices
=======================

Variant A
---------

platform::application::base

  platform::posix::application

  platform::win32::application

  platform::winrt::application

platform::window::base

  platform::glut::window

  platform::win32::window::base

    platform::win32::window::simple

  platform::winrt::window::base

Variant B
---------
