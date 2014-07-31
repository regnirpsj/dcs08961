// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/pass/null.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/pass/null.hpp"

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

    namespace pass {
      
      // variables, exported
  
      // functions, exported

      /* virtual */
      null::~null()
      {
        TRACE("render::base::pass::null::~null");
      }
        
      /* virtual */ void
      null::execute()
      {
        TRACE("render::base::pass::null::execute");
      }
      
      /* virtual */ void
      null::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::pass::null::print_on");

        base::print_on(os);
      }
      
    } // namespace pass {
    
  } // namespace base {
  
} // namespace render {
