// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/fragment.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/shader/fragment.hpp"

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

  namespace shader {
    
    // variables, exported
  
    // functions, exported
    
    /* virtual */
    fragment::~fragment()
    {
      TRACE("render::shader::fragment::~fragment");
    }

    /* explicit */
    fragment::fragment(context::device& a)
      : base(a)
    {
      TRACE("render::shader::fragment::fragment");
    }
    
  } // namespace shader {
  
} // namespace render {
