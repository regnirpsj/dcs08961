// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/base.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/visitor/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <stdexcept>      // std::logic_error

// includes, project

#include <scene/nodes.hpp>
#include <scene/primitives.hpp>
#include <scene/visitor/subject.hpp>

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

    /* virtual */
    base::~base()
    {
      TRACE("scene::visitor::base::~base");
    }

    /* virtual */ void
    base::visit(node::base& a)
    {
      TRACE("scene::visitor::base::visit(node::base)");
      
      visit_base(a);
    }
    
    /* virtual */ void
    base::visit(node::camera& a)
    {
      TRACE("scene::visitor::base::visit(node::camera)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(node::dynamic& a)
    {
      TRACE("scene::visitor::base::visit(node::dynamic)");

      visit_base(a);
    }
    
    /* virtual */ void
    base::visit(node::geometry& a)
    {
      TRACE("scene::visitor::base::visit(node::geometry)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(node::global_light& a)
    {
      TRACE("scene::visitor::base::visit(node::global_light)");

      visit_base(a);
    }
    
    /* virtual */ void
    base::visit(node::group& a)
    {
      TRACE("scene::visitor::base::visit(node::group)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(node::local_light& a)
    {
      TRACE("scene::visitor::base::visit(node::local_light)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(node::material_group& a)
    {
      TRACE("scene::visitor::base::visit(node::material_group)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(node::mesh& a)
    {
      TRACE("scene::visitor::base::visit(node::mesh)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(node::rotor& a)
    {
      TRACE("scene::visitor::base::visit(node::rotor)");

      visit_base(a);
    }
    
    /* virtual */ void
    base::visit(node::select& a)
    {
      TRACE("scene::visitor::base::visit(node::select)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(node::transform& a)
    {
      TRACE("scene::visitor::base::visit(node::transform)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(node::translator& a)
    {
      TRACE("scene::visitor::base::visit(node::translator)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(primitive::cube& a)
    {
      TRACE("scene::visitor::base::visit(primitive::cube)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(primitive::cylinder& a)
    {
      TRACE("scene::visitor::base::visit(primitive::cylinder)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(primitive::icosahedron& a)
    {
      TRACE("scene::visitor::base::visit(primitive::icosahedron)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(primitive::octahedron& a)
    {
      TRACE("scene::visitor::base::visit(primitive::octahedron)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(primitive::sphere& a)
    {
      TRACE("scene::visitor::base::visit(primitive::sphere)");

      visit_base(a);
    }

    /* virtual */ void
    base::visit(primitive::tetrahedron& a)
    {
      TRACE("scene::visitor::base::visit(primitive::tetrahedron)");

      visit_base(a);
    }
    
    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("scene::visitor::base::print_on");

      os << '[' << "'scene::visitor::base::print_on' not yet implemented" << ']';
    }

    /* explicit */
    base::base()
      : printable()
    {
      TRACE("scene::visitor::base::base");
    }
    
    /* virtual */ void
    base::visit(subject&)
    {
      TRACE("scene::visitor::base::visit(subject)");
      
      throw std::logic_error("pure virtual function 'scene::visitor::base::visit(subject)' called");
    }
    
  } // namespace visitor {
  
} // namespace scene {
