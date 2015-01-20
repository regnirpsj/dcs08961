// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/pass/container.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/null/pass/container.hpp"

// includes, system

//#include <>

// includes, project

#include <render/null/context.hpp>
#include <statistics.hpp>

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

  namespace null {

    namespace pass {
      
      // variables, exported
  
      // functions, exported

      /* explicit */
      container::container()
        : render::base::pass::container(context::dflt, stats::dflt)
      {
        TRACE("render::null:pass::container::container(dflt)");
      }

      /* explicit */
      container::container(std::initializer_list<base_type*> const& a)
        : render::base::pass::container(context::dflt, stats::dflt, a)
      {
        TRACE("render::null:pass::container::container(std::initializer_list)");
      }
      
      /* virtual */
      container::~container()
      {
        TRACE("render::null:pass::container::~container");
      }

      /* virtual */ void
      container::do_execute()
      {
        TRACE("render::null:pass::container::do_execute");
        
        render::base::pass::container::do_execute();
      }
      
    } // namespace pass {
    
  } // namespace null {
  
} // namespace render {
