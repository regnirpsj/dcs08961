// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/setup.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/stage/setup.hpp"

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
      setup::~setup()
      {
        TRACE("render::base::stage::setup::~setup");
      }

      /* virtual */ void
      setup::execute()
      {
        TRACE("render::base::stage::setup::execute");
      }
    
      /* virtual */ void
      setup::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::stage::setup::print_on");

        base::print_on(os);
      }

    } // namespace stage {
        
  } // namespace base {
  
} // namespace render {
