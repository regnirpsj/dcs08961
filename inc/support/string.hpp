// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/string.hpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SUPPORT_STRING_HPP)

#define UKACHULLDCS_08961_SUPPORT_STRING_HPP

// includes, system

#include <string> // std::string, std::wstring

// includes, project

#include <support/export.h>

namespace support {
  
  // types, exported (class, enum, struct, union, typedef)
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)

  DCS08961_SUPPORT_EXPORT std::wstring string_to_wstring(std::string  const&);
  DCS08961_SUPPORT_EXPORT std::string  wstring_to_string(std::string  const&);
  DCS08961_SUPPORT_EXPORT std::string  wstring_to_string(std::wstring const&);
  
} // namespace support {

#endif // #if !defined(UKACHULLDCS_08961_SUPPORT_STRING_HPP)
