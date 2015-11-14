// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/context.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/ogl/context.hpp"

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

  namespace ogl {
      
    // variables, exported
  
    // functions, exported

    /* explicit */
    context::context()
      : render::device::context(),
        render::swap::context  ()
    {
      TRACE("render::ogl::context::context");
    }
    
    /* virtual */
    context::~context()
    {
      TRACE("render::ogl::context::~context");
    }
      
    /* virtual */ void
    context::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::ogl::context::print_on");

      render::device::context::print_on(os);
      render::swap::context::print_on  (os);
      
      os << "\b,"
         << "render::ogl::context"
         << ']';
    }
    
  } // namespace ogl {
    
} // namespace render {
