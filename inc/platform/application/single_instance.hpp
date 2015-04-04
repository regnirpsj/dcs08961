// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/application/single_instance.hpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_APPLICATION_SINGLE_INSTANCE_HPP)

#define UKACHULLDCS_08961_PLATFORM_APPLICATION_SINGLE_INSTANCE_HPP

// includes, system

// #include <>

// includes, project

#include <platform/application/base.hpp>

namespace platform {

  namespace application {
  
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_PLATFORM_EXPORT single_instance : public base {

    public:
      
      static bool initialized();
      
    protected:

      static single_instance* instance_;
      
      explicit single_instance(command_line const&);
      virtual ~single_instance();

      virtual void print_on(std::ostream&) const;
    
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
  } // namespace application {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_APPLICATION_SINGLE_INSTANCE_HPP)
