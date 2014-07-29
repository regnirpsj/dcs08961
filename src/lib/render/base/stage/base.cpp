// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/base.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/stage/base.hpp"

// includes, system

#include <stdexcept> // std::logic_error
#include <typeinfo>  // typeid usage

// includes, project

#include <support/type_info.hpp>

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
      base::~base()
      {
        TRACE("render::base::stage::base::~base");
      }

      /* virtual */ void
      base::execute()
      {
        TRACE("render::base::stage::base::execute");

        throw std::logic_error("pure virtual function 'render::base::stage::base::execute' called");
      }
    
      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::stage::base::print_on");

        os << '[' << support::demangle(typeid(*this)) << ']';
      }

      /* explicit */
      base::base()
        : support::printable (),
          support::refcounted()
      {
        TRACE("render::base::stage::base::base");
      }
      
    } // namespace stage {
        
  } // namespace base {
  
} // namespace render {
