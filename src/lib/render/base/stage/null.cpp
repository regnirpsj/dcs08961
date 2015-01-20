// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/null.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/stage/null.hpp"

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

      /* explicit */
      null::null(context& a, statistics::base& b)
        : base(a, b)
      {
        TRACE("render::base::stage::null::null");
      }
      
      /* virtual */
      null::~null()
      {
        TRACE("render::base::stage::null::~null");
      }

      /* virtual */ void
      null::execute()
      {
        TRACE("render::base::stage::null::execute");
      }
    
      /* virtual */ void
      null::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::stage::null::print_on");

        base::print_on(os);
      }

    } // namespace stage {
        
  } // namespace base {
  
} // namespace render {
