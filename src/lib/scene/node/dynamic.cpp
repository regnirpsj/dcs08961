// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/dynamic.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/node/dynamic.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <scene/visitor/base.hpp>
#include <support/chrono_io.hpp>

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

    /* virtual */
    dynamic::~dynamic()
    {
      TRACE("scene::node::dynamic::~dynamic");
    }
    
    /* virtual */ void
    dynamic::accept(visitor::base& v)
    {
      TRACE("scene::node::dynamic::accept");

      v.visit(*this);
    }
    
    /* explicit */
    dynamic::dynamic(std::string const& a)
      : transform   (a),
        update      (*this, "update", support::clock::now()),
        last_update_(update.get())
    {
      TRACE("scene::node::dynamic::dynamic");
    }
    
  } // namespace node {
  
} // namespace scene {
