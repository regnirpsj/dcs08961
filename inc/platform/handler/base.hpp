// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/base.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_BASE_HPP)

#define UKACHULLDCS_08961_PLATFORM_HANDLER_BASE_HPP

// includes, system

// #include <>

// includes, project

#include <platform/export.h>
#include <support/printable.hpp>

namespace platform {

  namespace handler {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_PLATFORM_EXPORT base : public support::printable {

    public:

      static unsigned const dflt_queue_max_length; // == 3
          
      virtual ~base() =0;

    protected:

      explicit base();
        
    };

    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace handler {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_BASE_HPP)
