// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/update_bounds.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/visitor/update_bounds.hpp"

// includes, system

#include <array>          // std::array<>
#include <glm/gtx/io.hpp> // glm::io::*

// includes, project

#include <scene/node/geometry.hpp>
#include <scene/node/group.hpp>
#include <scene/node/transform.hpp>

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

  namespace visitor {
    
    // variables, exported
  
    // functions, exported

    /* explicit */
    update_bounds::update_bounds()
      : dfs()
    {
      TRACE("scene::visitor::update_bounds::update_bounds");
    }
    
    /* virtual */
    update_bounds::~update_bounds()
    {
      TRACE("scene::visitor::update_bounds::~update_bounds");
    }

    /* virtual */ void
    update_bounds::visit(node::geometry& a)
    {
      TRACE("scene::visitor::update_bounds::visit(node::geometry)");

      if (!a.bbox.get().valid) {
        a.compute_bounds();
      }
    }
    
    /* virtual */ void
    update_bounds::visit(node::group& a)
    {
      TRACE("scene::visitor::update_bounds::visit(node::group)");

      if (!a.bbox.get().valid && !a.children.get().empty()) {
        dfs::visit(a);

        auto result(node::base::bounds::invalid);

        for (auto const& c : a.children.get()) {
          auto const& b(c->bbox.get());

          // std::cout << "result:" << result << ", other:" << b << std::endl;
          
          // glm::m[ax|in] return component-wise max/min, i.e. min([1,0,0], [0,1,-1]) -> [0,0,-1]
          result.min = glm::min(b.min, result.min);
          result.max = glm::max(b.max, result.max);  
        }

        result.valid = true;
        
        a.bbox.set(result);
      }
    }

    /* virtual */ void
    update_bounds::visit(node::transform& a)
    {
      TRACE("scene::visitor::update_bounds::visit(node::transform)");

      if (!a.bbox.get().valid && !a.children.get().empty()) {
        visit_base(a);

        auto const& b(a.bbox.get());
        auto const& m(a.xform.get());

        std::array<glm::vec3 const, 8> const corners = {
          {
            glm::vec3(b.min.x, b.min.y, b.min.z),
            glm::vec3(b.min.x, b.min.y, b.max.z),
            glm::vec3(b.min.x, b.max.y, b.min.z),
            glm::vec3(b.min.x, b.max.y, b.max.z),
            glm::vec3(b.max.x, b.min.y, b.min.z),
            glm::vec3(b.max.x, b.max.y, b.min.z),
            glm::vec3(b.max.x, b.min.y, b.max.z),
            glm::vec3(b.max.x, b.max.y, b.max.z),
          }
        };
        
        auto result(node::base::bounds::invalid);
        
        for (auto const& c : corners) {
          glm::vec3 const tmp((m * glm::vec4(c, 1.0f)).xyz());
          
          // std::cout << "result:" << result << ", other:" << tmp << std::endl;
          
          // glm::m[ax|in] return component-wise max/min, i.e. min([1,0,0], [0,1,-1]) -> [0,0,-1]
          result.min = glm::min(tmp, result.min);
          result.max = glm::max(tmp, result.max);  
        }

        result.valid = true;
        
        // std::cout << "old:" << a.bbox() << ", new:" << result << '\n';

        a.bbox.set(result);
      }
    }

    /* virtual */ void
    update_bounds::print_on(std::ostream& os) const
    {
      TRACE("scene::visitor::update_bounds::print_on");

      dfs::print_on(os);
    }

    /* virtual */ void
    update_bounds::visit(subject&)
    {
      TRACE("scene::visitor::update_bounds::visit(subject)");
    }
    
  } // namespace visitor {
  
} // namespace scene {
