// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/primitive/tetrahedron.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/primitive/tetrahedron.hpp"

// includes, system

#include <array> // std::array<>

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

  void
  make_tetrahedron(scene::node::geometry::attribute_list_type& attr_list,
                   scene::node::geometry::index_list_type&     index_list)
  {
    TRACE("scene::primitive::tetrahedron::<unnamed>::make_tetrahedron");
    
    // right-handed coordinate system assumed
    static std::array<glm::vec3, 4> const points = {
      {
        glm::vec3(-0.5, -0.5,  0.5),
        glm::vec3( 0.5, -0.5,  0.5),
        glm::vec3( 0.0, -0.5, -0.5),
        glm::vec3( 0.0,  0.5,  0.0),
      }
    };

    static std::array<std::array<float, 2>, 3> const tcoords = {
      {
        { { 0.0, 0.0 } },
        { { 1.0, 0.0 } },
        { { 0.5, 0.5 } },
      }
    };
    
    static std::array<std::array<unsigned, 3>, 4> const indices = {
      {
        // i_p1, i_p2, i_p3
        { { 3, 0, 1 } },
        { { 1, 2, 3 } },
        { { 3, 2, 0 } },
        { { 0, 2, 1 } },
      }
    };
    
    unsigned idx_count(0);

    for (auto const& idx : indices) {
      glm::vec3 const& p1(points[idx[0]]);
      glm::vec3 const& p2(points[idx[1]]);
      glm::vec3 const& p3(points[idx[2]]);
      glm::vec3 const  n (glm::normalize(glm::cross(p1 - p2, p3 - p2)));

      using scene::node::geometry;
      
      attr_list.push_back(geometry::attribute(p1, n, glm::vec2(tcoords[0][0], tcoords[0][1])));
      attr_list.push_back(geometry::attribute(p2, n, glm::vec2(tcoords[1][0], tcoords[1][1])));
      attr_list.push_back(geometry::attribute(p3, n, glm::vec2(tcoords[2][0], tcoords[2][1])));

      index_list.push_back(idx_count++);
      index_list.push_back(idx_count++);
      index_list.push_back(idx_count++);
    }
  }
  
} // namespace {

namespace scene {

  namespace primitive {
    
    // variables, exported
    
    // functions, exported

    /* explicit */
    tetrahedron::tetrahedron()
      : node::geometry()
    {
      TRACE("scene::primitive::tetrahedron::tetrahedron");

      make_tetrahedron(attribute_list_, index_list_);

      compute_bounds();
      compute_tangents();
    }
    
    /* virtual */ void
    tetrahedron::accept(visitor::base& v)
    {
      TRACE("scene::primitive::tetrahedron::accept");

      v.visit(*this);
    }
    
  } // namespace primitive {
  
} // namespace scene {
