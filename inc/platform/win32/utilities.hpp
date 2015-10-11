// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/utilities.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_UTILITIES_HPP)

#define UKACHULLDCS_08961_PLATFORM_WIN32_UTILITIES_HPP

// includes, system

#include <string>    // std::string
#include <windows.h> // win32 stuff

// includes, project

//#include <>

namespace platform {
  
  namespace win32 {
  
    // types, exported (class, enum, struct, union, typedef)

    // variables, exported (extern)

    // functions, inlined (inline)

    template <class T> T  window_long (HWND, signed);
    template <class T> T  window_long (HWND, T, signed);
  
    template <class T> T* window_long_ptr(HWND, signed);
    template <class T> T* window_long_ptr(HWND, T*, signed);

    template <class T> T  class_long (HWND, signed);
    template <class T> T  class_long (HWND, T, signed);
  
    template <class T> T* class_long_ptr(HWND, signed);
    template <class T> T* class_long_ptr(HWND, T*, signed);

    // functions, exported (extern)

    std::string wm_message_string(unsigned);
    std::string module_path(HMODULE module);
    std::string last_error_message();
    
  } // namespace win32 {
  
} // namespace platform {

#include <platform/win32/utilities.inl>

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_UTILITIES_HPP)
