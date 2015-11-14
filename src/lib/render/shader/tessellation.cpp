// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/tessellation.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/shader/tessellation.hpp"

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

    namespace tessellation {
      
      // variables, exported
  
      // functions, exported

      /* virtual */
      control::~control()
      {
        TRACE("render::shader::tessellation::control::~control");
      }

      /* explicit */
      control::control(device::context& a)
        : base(a)
      {
        TRACE("render::shader::tessellation::control::control");
      }

      /* virtual */
      evaluation::~evaluation()
      {
        TRACE("render::shader::tessellation::evaluation::~evaluation");
      }

      /* explicit */
      evaluation::evaluation(device::context& a)
        : base(a)
      {
        TRACE("render::shader::tessellation::evaluation::evaluation");
      }
      
    } // namespace tessellation {
    
  } // namespace shader {
  
} // namespace render {
