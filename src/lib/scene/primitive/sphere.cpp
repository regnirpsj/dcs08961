// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/primitive/sphere.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/primitive/sphere.hpp"

// includes, system

#include <array>                 // std::array<>
#include <cmath>                 // std::abs, std::acos, std::atan2
#include <glm/gtc/constants.hpp> // glm::pi

// includes, project

#include <glm/gtx/limits.hpp>
#include <scene/primitive/octahedron.hpp>
#include <scene/visitor/base.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  glm::vec2
  calc_sphere_tcoords(glm::vec3 const& n)
  {
    TRACE("scene::primitive::sphere::<unnamed>::calc_sphere_tcoords");

    using float_type = glm::vec3::value_type;
    
    static float_type const pi(glm::pi<float_type>());
    
    float_type const t((pi - std::acos(n.x)) / pi);
    float_type       s(std::atan2(-n.z, n.x) - (pi / 2.0f));

    if (s <= -std::numeric_limits<glm::vec4>::epsilon()) {
      s += 2.0f * pi;
    }
    
    s /= 2.0f * pi;
    
    return glm::vec2(s, std::abs(t));
  }

  void
  add_point(glm::vec3 const& pnt, scene::node::geometry::attribute_list_type& alist)
  {
    TRACE("scene::primitive::sphere::<unnamed>::add_point");
    
    glm::vec3 const n(-glm::normalize(pnt));
    glm::vec3 const p(n.xyz() * -0.5f);

    using scene::node::geometry;
    
    alist.push_back(geometry::attribute(p, n, calc_sphere_tcoords(n)));
  }
  
  void
  subdivide_triangle(unsigned i1, unsigned i2, unsigned i3,
                     unsigned                                    depth,
                     scene::node::geometry::attribute_list_type& alist,
                     scene::node::geometry::index_list_type&     ilist,
                     unsigned&                                   z)
  {
    TRACE("scene::primitive::sphere::<unnamed>::subdivide_triangle");
    
    if (0 == depth) {
      ilist.push_back(i1);
      ilist.push_back(i2);
      ilist.push_back(i3);
    } else {
      glm::vec3 const p1(alist[i1].position);
      glm::vec3 const p2(alist[i2].position);
      glm::vec3 const p3(alist[i3].position);
      
      glm::vec3 const p12(p1 + ((p2 - p1) * 0.5f));
      glm::vec3 const p23(p2 + ((p3 - p2) * 0.5f));
      glm::vec3 const p31(p3 + ((p1 - p3) * 0.5f));

      unsigned const i12(z++);
      unsigned const i23(z++);
      unsigned const i31(z++);

      add_point(p12, alist);
      add_point(p23, alist);
      add_point(p31, alist);

      --depth;
      
      subdivide_triangle( i1, i12, i31, depth, alist, ilist, z);
      subdivide_triangle( i2, i23, i12, depth, alist, ilist, z);
      subdivide_triangle( i3, i31, i23, depth, alist, ilist, z);
      subdivide_triangle(i12, i23, i31, depth, alist, ilist, z);
    }
  }
  
} // namespace {

namespace scene {

  namespace primitive {
    
    // variables, exported

    /* static */ unsigned const sphere::dflt_subdivision(4);
    
    // functions, exported

    /* explicit */
    sphere::sphere(unsigned a)
      : node::geometry(),
        subdivision   (*this, "subdivision", a)
    {
      TRACE("scene::primitive::sphere::sphere");

      subdivision.touch();
    }
    
    /* virtual */ void
    sphere::accept(visitor::base& v)
    {
      TRACE("scene::primitive::sphere::accept");

      v.visit(*this);
    }

    /* virtual */ void
    sphere::do_changed(field::base& f)
    {
      TRACE("scene::primitive::do_changed");
      
      if (&f == &subdivision) {
        attribute_list_.clear();
        index_list_    .clear();

        octahedron const oct;
        
        for (auto const& a : oct.attributes.get()) { // why doesn't '*oct.attributes' work here?
          add_point(a.position, attribute_list_);
        }

        unsigned running_idx(unsigned((*oct.attributes).size()));
      
        for (unsigned i(0); i < (*oct.indices).size(); i += 3) {
          subdivide_triangle((*oct.indices)[i+0], (*oct.indices)[i+1], (*oct.indices)[i+2],
                             *subdivision, attribute_list_, index_list_, running_idx);
        }
      
        compute_bounds();
        compute_tangents();
      }

      else {
        node::geometry::do_changed(f);
      }
    }
    
  } // namespace primitive {
  
} // namespace scene {
