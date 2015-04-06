// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/config.hpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_CONFIG_HPP)

#define UKACHULLDCS_08961_PLATFORM_CONFIG_HPP

// includes, system

#include <boost/system/api_config.hpp> // BOOST_POSIX_API || BOOST_WINDOWS_API

// includes, project

//#include <>

// macros

#if defined(_MSC_VER) && (_MSC_VER < 1900)
#  define noexcept
#endif

#if defined(_MSC_VER) && (_MSC_VER < 1900)
#  undef __min
#endif

namespace platform {
  
  // types, exported (class, enum, struct, union, typedef)

  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_CONFIG_HPP)
