// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/transform.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/node/transform.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <scene/visitor/base.hpp>

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

  namespace node {
    
    // variables, exported
    
    // functions, exported

    /* explicit */
    transform::transform(std::string const& a, glm::mat4 const& b)
      : group(a),
        xform(*this, "xform", b)
    {
      TRACE("scene::node::transform::transform");
    }
    
    /* virtual */ void
    transform::accept(visitor::base& v)
    {
      TRACE("scene::node::transform::accept");

      v.visit(*this);
    }

    /* virtual */ glm::mat4
    transform::absolute_xform() const
    {
      TRACE("scene::node::transform::absolute_xform");

      glm::mat4 result(xform.get());
      
      if (nullptr != parent_) {
        result = parent_->absolute_xform() * result;
      } 

      return result;
    }

    /* virtual */ void
    transform::do_changed(field::base& f)
    {
      TRACE("scene::node::transform::do_changed");

      if      (&f == &xform) {
        invalidate_bounds();
      }

      else {
        group::do_changed(f);
      }
    }
    
  } // namespace node {
  
} // namespace scene {
