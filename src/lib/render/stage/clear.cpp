// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/clear.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/stage/clear.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

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

  namespace stage {
      
    // variables, exported
  
    // functions, exported

    /* virtual */
    clear::~clear()
    {
      TRACE("render::stage::clear::~clear");
    }

    /* explicit */
    clear::clear(device::context& a)
      : base         (a),
        color        (*this, "color",         true),
        color_value  (*this, "color_value",   glm::vec4(0,0,0,0)),
        depth        (*this, "depth",         true),
        depth_value  (*this, "depth_value",   1),
        stencil      (*this, "stencil",       false),
        stencil_value(*this, "stencil_value", 0)
    {
      TRACE("render::stage::clear::clear");

      name = "[render::stage::clear]";
    }

    /* virtual */ void
    clear::do_resize(glm::ivec2 const&)
    {
      TRACE("render::stage::clear::do_resize");
    }
      
  } // namespace stage {
  
} // namespace render {
