// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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
      setup::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::stage::setup::print_on");

        base::print_on(os);
      }

      /* explicit */
      setup::setup(context& a, statistics::base& b)
        : base(a, b)
      {
        TRACE("render::base::stage::setup::setup");
      }
      
      /* virtual */ void
      setup::do_execute()
      {
        TRACE("render::base::stage::setup::do_execute");
      }
      
    } // namespace stage {
        
  } // namespace base {
  
} // namespace render {
