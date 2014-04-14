// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/translator.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/node/translator.hpp"

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
    translator::translator(glm::vec3 const& a)
      : dynamic  (),
        direction(*this, "direction", glm::normalize(a)),
        speed    (*this, "speed",     glm::length(a))
    {
      TRACE("scene::node::translator::translator(glm::vec3)");
    }
    
    /* explicit */
    translator::translator(float a, glm::vec3 const& b)
      : dynamic  (),
        direction(*this, "direction", glm::normalize(b)),
        speed    (*this, "speed",     a)
    {
      TRACE("scene::node::translator::translator(float,glm::vec3)");
    }

    /* virtual */ void
    translator::accept(visitor::base& v)
    {
      TRACE("scene::node::translator::accept");

      v.visit(*this);
    }

    /* virtual */ void
    translator::do_changed(field::base& f)
    {
      TRACE("scene::node::translator::");

      if      (&f == &direction) {
      }

      else if (&f == &speed) {
      }

      else {
        dynamic::do_changed(f);
      }
    }
    
  } // namespace node {
  
} // namespace scene {
