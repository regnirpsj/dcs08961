// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/state/blend.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/state/blend.hpp"

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
    blend::~blend()
    {
      TRACE("render::state::blend::~blend");
    }    

    /* explicit */
    blend::blend(device::context& a)
      : base(a)
    {
      TRACE("render::state::blend::blend");
    }
    
  } // namespace state {
  
} // namespace render {
