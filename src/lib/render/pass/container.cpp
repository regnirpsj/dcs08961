// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/pass/container.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/pass/container.hpp"

// includes, system

//#include <>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal
  
} // namespace {

namespace render {

  namespace pass {
      
    // variables, exported
  
    // functions, exported

    /* explicit */
    container::container(device::context& a)
      : base  (a),
        stages(*this, "stages")
    {
      TRACE("render::pass::container::container");

      name = "[render::pass::container]";
    }

    /* virtual */
    container::~container()
    {
      TRACE("render::pass::container::~container");
    }
      
    /* virtual */ void
    container::do_execute(swap::context& a)
    {
      TRACE("render::pass::container::do_execute");

      for (auto& s : stages.get()) {
        s->execute(a);
      }
    }

    /* virtual */ void
    container::do_resize(glm::ivec2 const& a)
    {
      TRACE("render::pass::container::do_resize");

      for (auto& s : stages.get()) {
        s->resize(a);
      }
    }
      
  } // namespace pass {
  
} // namespace render {
