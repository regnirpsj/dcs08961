// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/pass/gui.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/pass/gui.hpp"

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
      gui::~gui()
      {
        TRACE("render::base::pass::gui::~gui");
      }
      
      /* virtual */ void
      gui::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::pass::gui::print_on");

        base::print_on(os);
      }

      /* virtual */ void
      gui::do_execute()
      {
        TRACE("render::base::pass::gui::do_execute");
      }
      
    } // namespace pass {
    
  } // namespace base {
  
} // namespace render {
