// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glx/io.hpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLX_IO_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLX_IO_HPP

// includes, system

#include <GL/glxew.h> // GLXContext
#include <iosfwd>     // std::ostream (fwd decl)

// includes, project

#include <platform/export.h>

namespace platform {

  namespace glx {
    
    // types, exported (class, enum, struct, union, typedef)

    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
    DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, Display const&);
    DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, GLXContext const&);
    DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, XVisualInfo const&);
    
  } // namespace glx {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLX_IO_HPP)
