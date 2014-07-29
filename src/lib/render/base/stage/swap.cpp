// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/swap.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/stage/swap.hpp"

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
      swap::~swap()
      {
        TRACE("render::base::stage::swap::~swap");
      }

      /* virtual */ void
      swap::execute()
      {
        TRACE("render::base::stage::swap::execute");
      }
    
      /* virtual */ void
      swap::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::stage::swap::print_on");

        base::print_on(os);
      }

    } // namespace stage {
        
  } // namespace base {
  
} // namespace render {
