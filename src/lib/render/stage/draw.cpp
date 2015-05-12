// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/draw.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/stage/draw.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <scene/node/camera.hpp>
#include <scene/node/group.hpp>

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
    draw::~draw()
    {
      TRACE("render::stage::draw::~draw");
    }

    /* explicit */
    draw::draw(context& a)
      : base  (a),
        camera(*this, "camera", nullptr),
        scene (*this, "scene",  nullptr)
    {
      TRACE("render::stage::draw::draw");

      name = "[render::stage::draw]";
    }

    /* virtual */ void
    draw::do_resize(glm::ivec2 const&)
    {
      TRACE("render::stage::draw::do_resize");
    }
      
  } // namespace stage {
  
} // namespace render {
