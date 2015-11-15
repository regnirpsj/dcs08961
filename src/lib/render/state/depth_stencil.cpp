// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/state/depth_stencil.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/state/depth_stencil.hpp"

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

  namespace state {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    depth_stencil::~depth_stencil()
    {
      TRACE("render::state::depth_stencil::~depth_stencil");
    }    

    /* explicit */
    depth_stencil::depth_stencil(context::device& a)
      : base(a)
    {
      TRACE("render::state::depth_stencil::depth_stencil");
    }
    
  } // namespace state {
  
} // namespace render {
