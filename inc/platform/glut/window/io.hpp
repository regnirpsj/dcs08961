// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/io.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_IO_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_IO_HPP

// includes, system

#include <iosfwd> // std::ostream (fwd decl)

// includes, project

#include <platform/export.h>
#include <platform/window/utilities.hpp>

namespace platform {

  namespace glut {

    namespace window {
      
      // types, exported (class, enum, struct, union, typedef)
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      DCS08961_PLATFORM_EXPORT
      std::ostream& operator<<(std::ostream&, platform::window::frame_record_t const&);

      DCS08961_PLATFORM_EXPORT
      std::ostream& operator<<(std::ostream&, platform::window::keyboard_record_t const&);

      DCS08961_PLATFORM_EXPORT
      std::ostream& operator<<(std::ostream&, platform::window::mouse_record_t const&);

    } // namespace window {

  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_IO_HPP)
