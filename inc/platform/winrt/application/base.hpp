// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/winrt/application/base.hpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WINRT_APPLICATION_BASE_HPP)

#define UKACHULLDCS_08961_PLATFORM_WINRT_APPLICATION_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <platform/application/single_instance.hpp>

namespace platform {

  namespace winrt {

    namespace application {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT base : public platform::application::single_instance {
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace application {

  } // namespace winrt {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WINRT_APPLICATION_BASE_HPP)
