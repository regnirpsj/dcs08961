// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/io.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glut/io.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <ostream>        // std::ostream

// includes, project

#include <support/chrono_io.hpp>

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

  namespace glut {
    
    // variables, exported
  
    // functions, exported

    std::ostream& operator<<(std::ostream& os, frame_record_t const& a)
    {
      TRACE_NEVER("platform::glut::operator<<(frame_record_t)");

      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        os << '['
           << a.counter << ','
           << a.delta_t << ','
           << a.stamp
           << ']';
      }

      return os;
    }
    
    std::ostream& operator<<(std::ostream& os, mouse_record_t const& a)
    {
      TRACE_NEVER("platform::glut::operator<<(mouse_record_t)");

      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        os << '['
           << a.button   << ','
           << a.state    << ','
           << a.modifier << ','
           << a.pos      << ','
           << a.stamp
           << ']';
      }

      return os;
    }
    
    std::ostream& operator<<(std::ostream& os, keyboard_record_t const& a)
    {
      TRACE_NEVER("platform::glut::operator<<( )");

      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        os << '['
           << a.key      << ','
           << a.state    << ','
           << a.modifier << ','
           << a.pos      << ','
           << a.stamp
           << ']';
      }

      return os;
    }
    
  } // namespace glut {
  
} // namespace platform {
