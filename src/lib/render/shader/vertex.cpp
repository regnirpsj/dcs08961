// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/vertex.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/shader/vertex.hpp"

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
    vertex::~vertex()
    {
      TRACE("render::shader::vertex::~vertex");
    }

    /* explicit */
    vertex::vertex(context& a)
      : base(a)
    {
      TRACE("render::shader::vertex::vertex");
    }
    
  } // namespace shader {
  
} // namespace render {
