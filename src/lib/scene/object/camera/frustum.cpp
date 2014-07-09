// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/camera/frustum.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/camera/frustum.hpp"

// includes, system

#include <ostream> // std::ostream

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

namespace scene {

  namespace object {

    namespace camera {
      
      // variables, exported
    
      // functions, exported

      /* explicit */
      frustum::frustum(float a, float b, float c, float d, float e, float f)
        : left(a), right(b), bottom(c), top(d), near(e), far(f)
      { 
        TRACE("scene::object::camera::frustum::frustum");
      }

      std::ostream&
      operator<<(std::ostream& os, frustum const& a)
      {
        TRACE_NEVER("scene::object::camera::operator<<(frustum)");
        
        std::ostream::sentry const cerberus(os);

        if (cerberus) {
          os << '['
             << "l:" << a.left   << ','
             << "r:" << a.right  << ','
             << "b:" << a.bottom << ','
             << "t:" << a.top    << ','
             << "n:" << a.near   << ','
             << "f:" << a.far
             << ']'; 
        }

        return os;
      }

      bool
      frustum::contains(glm::vec3 const&) const
      {
        TRACE("scene::object::camera::frustum::contains");

        bool result(false);

        return result;
      }
      
    } // namespace camera {
    
  } // namespace object {
  
} // namespace scene {
