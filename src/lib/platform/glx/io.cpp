// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glx/io.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glx/io.hpp"

// includes, system

#include <boost/io/ios_state.hpp> // boost::io::ios_all_save
#include <iomanip>                // std::hex
#include <ostream>                // std::ostream

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

  namespace glx {
  
    // variables, exported
  
    // functions, exported

    std::ostream&
    operator<<(std::ostream& os, Display const& a)
    {
      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        boost::io::ios_all_saver const ias(os);
        
        os << '['
           << "@" << std::hex << reinterpret_cast<void const*>(&a)
           << ']';
      }

      return os;
    }

    std::ostream&
    operator<<(std::ostream& os, GLXContext const& a)
    {
      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        boost::io::ios_all_saver const ias(os);
        
        os << '['
           << "@" << std::hex << reinterpret_cast<void const*>(a)
           << ']';
      }

      return os;
    }

    std::ostream&
    operator<<(std::ostream& os, XVisualInfo const& a)
    {
      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        boost::io::ios_all_saver const ias(os);
        
        os << '['
           << "@" << std::hex << reinterpret_cast<void const*>(&a)
           << ']';
      }

      return os;
    }
    
  } // namespace glx {
  
} // namespace platform {
