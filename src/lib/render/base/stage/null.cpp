// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/null.cpp                                                     */
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

      /* virtual */
      null::~null()
      {
        TRACE("render::base::stage::null::~null");
      }

      /* explicit */
      null::null(context& a)
        : base(a)
      {
        TRACE("render::base::stage::null::null");

        name = "[render::base::stage::null]";
      }

      /* virtual */ void
      null::do_apply()
      {
        TRACE("render::base::stage::null::do_apply");
      }
      
      /* virtual */ void
      null::do_resize(glm::ivec2 const&)
      {
        TRACE("render::base::stage::null::do_resize");
      }
      
    } // namespace stage {
    
  } // namespace base {
  
} // namespace render {
