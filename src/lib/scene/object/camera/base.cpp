// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/camera/base.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/camera/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

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

      /* virtual */
      base::~base()
      {
        TRACE("scene::object::camera::base::~base");
      }

      /* explicit */
      base::base(matrix_type const& a, viewport_type const& b, glm::vec2 const& c)
        : object::base(),
          projection  (*this, "projection", a),
          viewport    (*this, "viewport",   b),
          near_far_   (c)
      {
        TRACE("scene::object::camera::base::base");
      }

      /* virtual */ void
      base::do_changed(field::base& f)
      {
        TRACE("scene::object::camera::base::do_changed");

        if      (&f == &projection) {}
        else if (&f == &viewport)   {}

        else {
          object::base::do_changed(f);
        }
      }
      
    } // namespace camera {
    
  } // namespace object {
  
} // namespace scene {
