// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/window.cpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/window.hpp"

// includes, system

//#include <>

// includes, project

#include <render/base/pass/container.hpp>

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

  namespace base {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    window::~window()
    {
      TRACE("render::base::window::~window");
    }
    
    /* explicit */
    window::window()
      : field::container(),
        passes          (*this, "passes")
    {
      TRACE("render::base::window::window");
    }
    
    /* virtual */ void
    window::render()
    {
      TRACE("render::base::window::render");

      for (auto p : passes.get()) {
        p->execute();
      }
    }
    
    /* virtual */ void
    window::resize(glm::ivec2 const& a)
    {
      TRACE("render::base::window::resize");

      for (auto p : passes.get()) {
        p->resize(a);
      }
    }
    
  } // namespace base {
  
} // namespace render {
