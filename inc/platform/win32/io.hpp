// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/io.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_IO_HPP)

#define UKACHULLDCS_08961_PLATFORM_WIN32_IO_HPP

// includes, system

#include <iosfwd>    // std::ostream (fwd)
#include <windows.h> // win32 stuff

// includes, project

//#include <>

namespace platform {
  
  namespace win32 {
  
    // types, exported (class, enum, struct, union, typedef)

    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

    std::ostream& operator<<(std::ostream&, DEVMODE const&);
    std::ostream& operator<<(std::ostream&, DISPLAY_DEVICE const&);
    std::ostream& operator<<(std::ostream&, LUID const&);
    std::ostream& operator<<(std::ostream&, MONITORINFOEX const&);
    std::ostream& operator<<(std::ostream&, HWND const&);
    std::ostream& operator<<(std::ostream&, RECT const&);
    
  } // namespace win32 {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_IO_HPP)
