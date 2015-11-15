// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/null.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/stage/null.hpp"

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

  namespace stage {
      
    // variables, exported
  
    // functions, exported

    /* explicit */
    null::null(context::device& a)
      : base(a)
    {
      TRACE("render::stage::null::null");

      name = "[render::stage::null]";
    }

    /* virtual */
    null::~null()
    {
      TRACE("render::stage::null::~null");
    }
      
    /* virtual */ void
    null::do_execute(context::swap&)
    {
      TRACE("render::stage::null::do_execute");
    }
      
    /* virtual */ void
    null::do_resize(glm::ivec2 const&)
    {
      TRACE("render::stage::null::do_resize");
    }
      
  } // namespace stage {
  
} // namespace render {
