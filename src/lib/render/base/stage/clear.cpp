// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/clear.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/stage/clear.hpp"

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
      clear::~clear()
      {
        TRACE("render::base::stage::clear::~clear");
      }

      /* virtual */ void
      clear::execute()
      {
        TRACE("render::base::stage::clear::execute");
      }
    
      /* virtual */ void
      clear::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::stage::clear::print_on");

        base::print_on(os);
      }

    } // namespace stage {
        
  } // namespace base {
  
} // namespace render {
