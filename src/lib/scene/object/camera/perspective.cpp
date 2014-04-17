// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/camera/perspective.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/camera/perspective.hpp"

// includes, system

#include <glm/gtc/matrix_transform.hpp> // glm::perspectiveFov

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
      perspective::perspective(float a, viewport_type const& b, glm::vec2 const& c)
        : base(glm::perspectiveFov(a, b.width, b.height, c.x, c.y), b, c),
          fovy(*this, "fovy", a)
      {
        TRACE("scene::object::camera::perspective::perspective");
      }

      /* virtual */
      perspective::~perspective()
      {
        TRACE("scene::object::camera::perspective::~perspective");
      }

      /* virtual */ void
      perspective::do_changed(field::base& f)
      {
        TRACE("scene::object::camera::perspective::do_changed");

        if ((&f == &viewport) || (&f == &fovy)) {
          viewport_type const& vp(viewport.get());
          
          projection = glm::perspectiveFov(fovy.get(),
                                           vp.width,    vp.height,
                                           near_far_.x, near_far_.y);
        }

        else {
          base::do_changed(f);
        }
      }
      
    } // namespace camera {
    
  } // namespace object {
  
} // namespace scene {
