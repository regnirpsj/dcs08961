// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
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

      /* explicit */
      swap::swap(context& a)
        : base(a)
      {
        TRACE("render::base::stage::swap::swap");

        name = "[render::base::stage::swap]";
      }

      /* virtual */ void
      swap::do_resize(glm::ivec2 const&)
      {
        TRACE("render::base::stage::swap::do_resize");
      }
      
    } // namespace stage {
    
  } // namespace base {
  
} // namespace render {
