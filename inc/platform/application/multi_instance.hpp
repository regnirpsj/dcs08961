// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/application/multi_instance.hpp                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_APPLICATION_MULTI_INSTANCE_HPP)

#define UKACHULLDCS_08961_PLATFORM_APPLICATION_MULTI_INSTANCE_HPP

// includes, system

// #include <>

// includes, project

#include <platform/application/base.hpp>

namespace platform {

  namespace application {
  
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_PLATFORM_EXPORT multi_instance : public base {

    protected:

      explicit multi_instance(command_line const&);
      virtual ~multi_instance();
    
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
  } // namespace application {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_APPLICATION_MULTI_INSTANCE_HPP)
