// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/window.cpp                                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/window.hpp"

// includes, system

//#include <>

// includes, project

#include <render/pass/container.hpp>

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
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    window::~window()
    {
      TRACE("render::window::~window");
    }
    
    /* explicit */
    window::window(std::string const& a, device::context* b)
      : field::container(),
        title           (*this, "title", a),
        passes          (*this, "passes"),
        dev_ctx_        (b),
        swp_ctx_        (nullptr)
    {
      TRACE("render::window::window");
    }
    
    /* virtual */ void
    window::render(unsigned frames)
    {
      TRACE("render::window::render");

      while (0 < frames) {
        for (auto& p : passes.get()) {
          p->execute(*swp_ctx_);
        }

        --frames;
      }
    }
    
    /* virtual */ void
    window::resize(glm::ivec2 const& a)
    {
      TRACE("render::window::resize");

      for (auto& p : passes.get()) {
        p->resize(a);
      }
    }
  
} // namespace render {
