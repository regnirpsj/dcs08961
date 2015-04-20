// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/window/rect.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_WINDOW_RECT_HPP)

#define UKACHULLDCS_08961_PLATFORM_WIN32_WINDOW_RECT_HPP

// includes, system

#include <windows.h> // win32 stuff

// includes, project

#include <platform/window/rect.hpp>

namespace platform {

  namespace win32 {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT rect : public platform::window::rect {

      public:

        explicit rect(RECT const& /* l/t/r/b */);

        operator RECT () const;

        rect& operator=(RECT const&);

      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace window {

  } // namespace win32 {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_WINDOW_RECT_HPP)
