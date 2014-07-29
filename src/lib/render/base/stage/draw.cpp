// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
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

      /* virtual */ void
      draw::execute()
      {
        TRACE("render::base::stage::draw::execute");
      }
    
      /* virtual */ void
      draw::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::stage::draw::print_on");

        base::print_on(os);
      }

    } // namespace stage {
        
  } // namespace base {
  
} // namespace render {
