// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/pass/base.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/pass/base.hpp"

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

  namespace pass {
      
    // variables, exported
  
    // functions, exported

    /* virtual */
    base::~base()
    {
      TRACE("render::pass::base::~base");
    }
      
    /* explicit */
    base::base(context::device& a)
      : stage::base(a)
    {
      TRACE("render::pass::base::base");
    }
      
  } // namespace pass {
  
} // namespace render {
