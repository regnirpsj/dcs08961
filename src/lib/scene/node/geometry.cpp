// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/geometry.cpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/node/geometry.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <ostream>        // std::ostream

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
    geometry::attribute::attribute(glm::vec3 const& a, glm::vec3 const& b, glm::vec2 const& c,
                                   glm::vec4 const& d, glm::vec4 const& e)
      : position(a), normal(b), tcoord(c), tangent(d), color(e)
    {
      TRACE("scene::node::geometry::attribute::attribute");
    }
    
    /* virtual */
    geometry::~geometry()
    {
      TRACE("scene::node::geometry::~geometry");
    }

    /* virtual */ void
    geometry::accept(visitor::base& v)
    {
      TRACE("scene::node::geometry::accept");

      v.visit(*this);
    }
    
    void
    geometry::compute_bounds()
    {
      TRACE("scene::node::geometry::compute_bounds");

      bounds b(bounds::invalid);
      
      if (!attributes.get().empty()) {
        for (auto a : attributes.get()) {
          // glm::m[ax|in] return component-wise max/min, i.e. min([1,0,0], [0,1,-1]) -> [0,0,-1]
          b.min = glm::min(a.position, b.min);
          b.max = glm::max(a.position, b.max);
        }
      } else {
        b.min = b.max = glm::vec3(0.0);
      }

      b.valid = true;
      
      bbox = b;
    }

    /*
     * see [http://www.terathon.com/code/tangent.html]
     */
    void
    geometry::compute_tangents()
    {
      TRACE("scene::node::geometry::compute_tangents");

      auto&       attr_list(attributes.get());
      auto const& idx_list(indices.get());
      
      std::vector<std::pair<glm::vec3, glm::vec3>> tarray(idx_list.size());
        
      for (unsigned i(0); i < idx_list.size(); i += 3) {
        unsigned const i1(idx_list[i+0]);
        unsigned const i2(idx_list[i+1]);
        unsigned const i3(idx_list[i+2]);
        
        glm::vec3 const& v1(attr_list[i1].position);
        glm::vec3 const& v2(attr_list[i2].position);
        glm::vec3 const& v3(attr_list[i3].position);

        glm::vec2 const& w1(attr_list[i1].tcoord);
        glm::vec2 const& w2(attr_list[i2].tcoord);
        glm::vec2 const& w3(attr_list[i3].tcoord);
        
        float const x1(v2.x - v1.x);
        float const x2(v3.x - v1.x);
        float const y1(v2.y - v1.y);
        float const y2(v3.y - v1.y);
        float const z1(v2.z - v1.z);
        float const z2(v3.z - v1.z);
        
        float const s1(w2.x - w1.x);
        float const s2(w3.x - w1.x);
        float const t1(w2.y - w1.y);
        float const t2(w3.y - w1.y);
        
        float const     r   (1.0f / (s1 * t2 - s2 * t1));
        glm::vec3 const sdir((t2 * x1 - t1 * x2) * r,
                             (t2 * y1 - t1 * y2) * r,
                             (t2 * z1 - t1 * z2) * r);
        glm::vec3 const tdir((s1 * x2 - s2 * x1) * r,
                             (s1 * y2 - s2 * y1) * r,
                             (s1 * z2 - s2 * z1) * r);
        
        for (unsigned k(i); k < i + 3; ++k) {
          tarray[k].first  += sdir;
          tarray[k].second += tdir;
        }
      }

#if 0
      for (auto idx : idx_list) {
        auto&       a(attr_list[idx]);
        auto const& t(tarray[idx]);
        
        a.tangent.xyz = glm::normalize(t.first - a.normal * glm::dot(a.normal, t.first));
        a.tangent.w   = (0.0 > glm::dot(glm::cross(a.normal, t.first), t.second)) ? -1.0f : 1.0f;
      }
#else
#  pragma message("please fix 'scene::node::geometry::compute_tangents' implementation")
#endif
    }

    /* explicit */
    geometry::geometry(std::string const& a)
      : base      (a),
        attributes(*this, "attributes"),
        indices   (*this, "indices")
    {
      TRACE("scene::node::geometry::geometry");
    }
    
    std::ostream&
    operator<<(std::ostream& os, geometry::attribute const& a)
    {
      TRACE_NEVER("scene::node::operator<<(geometry::attribute const&)");
      
      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        glm::io::format_saver const iofs(os);

        os << glm::io::precision(2)
           << glm::io::width(1 + 2 + 1 + os.precision())
           << '['
           << "v:"  << a.position << ','
           << "n:"  << a.normal   << ','
           << "tc:" << a.tcoord   << ','
           << "t:"  << a.tangent  << ','
           << "c:"  << a.color
           << ']';
      }

      return os;
    }
    
  } // namespace node {
  
} // namespace scene {
