// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/draw.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/stage/draw.hpp"

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

  namespace base {

    namespace stage {
      
      // variables, exported
  
      // functions, exported

      /* virtual */
      draw::~draw()
      {
        TRACE("render::base::stage::draw::~draw");
      }

      /* explicit */
      draw::draw(context& a)
        : base(a)
      {
        TRACE("render::base::stage::draw::draw");

        name = "[render::base::stage::draw]";
      }

      /* virtual */ void
      draw::do_resize(glm::ivec2 const&)
      {
        TRACE("render::base::stage::draw::do_resize");
      }
      
    } // namespace stage {
    
  } // namespace base {
  
} // namespace render {
