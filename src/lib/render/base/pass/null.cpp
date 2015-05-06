// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
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

#include <stdexcept> // std::logic_error

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

      /* explicit */
      null::null(context& a)
        : base(a)
      {
        TRACE("render::base::pass::null::null");

        name = "[render::base::pass::null]";
      }
      
      /* virtual */
      null::~null()
      {
        TRACE("render::base::pass::null::~null");
      }

      /* virtual */ void
      null::do_execute()
      {
        TRACE("render::base::pass::null::do_execute");
      }

      /* virtual */ void
      null::do_resize(glm::ivec2 const&)
      {
        TRACE("render::base::pass::null::do_resize");
      }
      
    } // namespace pass {
    
  } // namespace base {
  
} // namespace render {
