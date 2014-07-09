// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/cull.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/visitor/cull.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::io::*
#include <ostream>        // std::ostream

// includes, project

#include <scene/node/camera.hpp>
#include <scene/node/geometry.hpp>
#include <scene/node/group.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  bool
  visible(scene::node::camera const& a, scene::node::base const& b)
  {
    auto const& mvp    (a.object.get()->projection.get() * a.view.get() * b.absolute_xform());
    auto const& frustum(a.object.get()->frustum.get());
    bool result(true);
    
    if (!frustum.contains(glm::vec3(mvp * glm::vec4(b.bbox.get().min, 1)).xyz()) &&
        !frustum.contains(glm::vec3(mvp * glm::vec4(b.bbox.get().max, 1)).xyz())) {
      result = false;
    }
    
    return result;
  }
  
} // namespace {

namespace scene {

  namespace visitor {

    // variables, exported
  
    // functions, exported

    /* explicit */
    cull::cull(node::camera const& a, visible_list_type& b)
      : dfs          (),
        camera_      (a),
        visible_list_(b)
    {
      TRACE("scene::visitor::cull::cull");

      visible_list_.clear();
    }
    
    /* virtual */
    cull::~cull()
    {
      TRACE("scene::visitor::cull::~cull");
    }
    
    /* virtual */ void
    cull::visit(node::geometry& a)
    {
      TRACE("scene::visitor::cull::visit(node::geometry)");

      if (visible(camera_, a)) {
        visible_list_.insert(&a);
      }
    }
    
    /* virtual */ void
    cull::visit(node::group& a)
    {
      TRACE("scene::visitor::cull::visit(node::group)");

      if (visible(camera_, a)) {
        dfs::visit(a);
      }
    }
    
    /* virtual */ void
    cull::print_on(std::ostream& os) const
    {
      TRACE_NEVER("scene::visitor::cull::print_on");

      dfs::print_on(os);
    }
          
    /* virtual */ void
    cull::visit(subject&)
    {
      TRACE("scene::visitor::cull::visit(subject)");
    }
    
  } // namespace visitor {
  
} // namespace scene {

