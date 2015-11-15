// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/swap.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/stage/swap.hpp"

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

  namespace stage {
      
    // variables, exported
    
    // functions, exported

    /* virtual */
    swap::~swap()
    {
      TRACE("render::stage::swap::~swap");
    }

    /* explicit */
    swap::swap(context::device& a)
      : base          (a),
        sync_to_vblank(*this, "sync_to_vblank", true)
    {
      TRACE("render::stage::swap::swap");

      name = "[render::stage::swap]";
    }

    /* virtual */ void
    swap::do_resize(glm::ivec2 const&)
    {
      TRACE("render::stage::swap::do_resize");
    }
      
  } // namespace stage {
  
} // namespace render {
