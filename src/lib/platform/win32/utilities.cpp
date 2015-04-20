// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/utilities.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/win32/utilities.hpp"

// includes, system

#include <sstream>   // ostringstream
#include <stdexcept> // std::runtime_error
#include <vector>    // std::vector<>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace platform {
  
  namespace win32 {
  
    // variables, exported
  
    // functions, exported

    /**
     * see [http://msdn.microsoft.com/en-us/library/windows/desktop/ms683197(v=vs.85).aspx]
     */
    std::string
    module_path(HMODULE module)
    {
      TRACE("platform::win32::module_path");
      
      std::vector<char> path(MAX_PATH);
      unsigned          len (::GetModuleFileNameA(module, &path[0], unsigned(path.size())));

      while (len == path.size()) {
        path.resize(path.size() * 2);
        path.clear ();
      
        len = ::GetModuleFileNameA(module, &path[0], unsigned(path.size()));
      }

      if (0 == len) {
        throw std::runtime_error("GetModuleFileNameA() failed!");
      }
    
      return std::string(path.begin(), path.begin() + len);
    }

    /**
     *
     */
    std::string
    last_error_message()
    {
      TRACE("platform::win32::last_error_message");
    
      static unsigned const format_flags(FORMAT_MESSAGE_ALLOCATE_BUFFER | 
                                         FORMAT_MESSAGE_FROM_SYSTEM |
                                         FORMAT_MESSAGE_IGNORE_INSERTS);
    
      unsigned const lerr(::GetLastError());
      char*          msg_buf;
      unsigned       msg_len(::FormatMessage(format_flags,
                                             nullptr,
                                             lerr,
                                             MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                                             reinterpret_cast<LPTSTR>(&msg_buf), 0,
                                             nullptr));
    
      std::ostringstream ostr;
    
      ostr << '(' << lerr << '|' << std::string(msg_buf, msg_buf+msg_len-2) << ')';
    
      ::LocalFree(msg_buf);

      return ostr.str();
    }
    
  } // namespace win32 {
  
} // namespace platform {
