// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

#include <glm/gtc/matrix_transform.hpp> // glm::infinitePerspective, glm::perspectiveFov
#include <glm/gtx/io.hpp>               // glm::operator<<

// includes, project

#include <glm/gtx/limits.hpp>
#include <glm/gtx/utilities.hpp>

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

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1900))
      /* static */ float const perspective::default_fovy(60_deg);
#else
      /* static */ float const perspective::default_fovy(float(60 _deg));
#endif
      
      // functions, exported

      /* explicit */
      perspective::perspective(float a, viewport_type const& b, glm::vec2 const& c)
        : base(matrix_type(), b, c),
          fovy(*this, "fovy", a)
      {
        TRACE("scene::object::camera::perspective::perspective");

        viewport.touch(); // force 'projection_' update in 'do_changed'
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

          frustum_ = compute_frustum(vp, glm::vec2(frustum_.near, frustum_.far));

          if (std::numeric_limits<glm::vec2>::infinity() == frustum_.far) {
            projection_ = glm::infinitePerspective(fovy.get(),
                                                   vp.width / vp.height,
                                                   frustum_.near);
          } else {
            projection_ = glm::perspectiveFov(fovy.get(),
                                              vp.width, vp.height,
                                              frustum_.near, frustum_.far);
          }
        }
        
        else {
          base::do_changed(f);
        }
      }
      
    } // namespace camera {
    
  } // namespace object {
  
} // namespace scene {
