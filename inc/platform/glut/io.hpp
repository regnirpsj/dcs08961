// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/io.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_IO_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLUT_IO_HPP

// includes, system

#include <iosfwd> // std::ostream (fwd decl)

// includes, project

#include <platform/glut/utilities.hpp>

namespace platform {

  namespace glut {
  
    // types, exported (class, enum, struct, union, typedef)
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

    std::ostream& operator<<(std::ostream&, frame_record_t const&);
    std::ostream& operator<<(std::ostream&, mouse_record_t const&);
    std::ostream& operator<<(std::ostream&, keyboard_record_t const&);
    
  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_IO_HPP)
