// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/camera/orthographic.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/camera/orthographic.hpp"

// includes, system

#include <glm/gtc/matrix_transform.hpp> // glm::ortho
#include <glm/gtx/io.hpp>               // glm::operator<<

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
      orthographic::orthographic(viewport_type const& a, glm::vec2 const& b)
        : base(glm::ortho(a.x, a.x + a.width, a.y, a.y + a.height, b.x, b.y), a, b)
      {
        TRACE("scene::object::camera::orthographic::orthographic");
      }

      /* virtual */
      orthographic::~orthographic()
      {
        TRACE("scene::object::camera::orthographic::~orthographic");
      }

      /* virtual */ void
      orthographic::do_changed(field::base& f)
      {
        TRACE("scene::object::camera::orthographic::do_changed");

        if (&f == &viewport) {
          viewport_type const& vp(viewport.get());

          frustum_    = compute_frustum(vp, glm::vec2(frustum_.near, frustum_.far));
          projection_ = glm::ortho(vp.x, vp.x + vp.width, vp.y, vp.y + vp.height,
                                   frustum_.near, frustum_.far);
        }

        else {
          base::do_changed(f);
        }
      }
      
    } // namespace camera {
    
  } // namespace object {
  
} // namespace scene {
