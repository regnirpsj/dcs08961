// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
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
      base::~base()
      {
        TRACE("render::base::stage::base::~base");
      }
      
      void
      base::apply()
      {
        TRACE("render::base::stage::base::apply");

        do_apply();
      }

      void
      base::resize(glm::ivec2 const& a)
      {
        TRACE("render::base::stage::base::resize");

        resize(a);
      }
    
      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::stage::base::print_on");

        field::container::print_on(os);
      }

      /* explicit */
      base::base(context& a)
        : field::container   (),
          support::refcounted(),
          active             (*this, "active", true),
          name               (*this, "name",   "[render::base::stage::base]"),
          ctx_               (a)
      {
        TRACE("render::base::stage::base::base");
      }

      /* virtual */ void
      base::do_apply()
      {
        TRACE("render::base::stage::base::do_apply");

        throw std::logic_error("pure virtual function 'render::base::stage::base::do_apply' "
                               "called");
      }

      /* virtual */ void
      base::do_resize(glm::ivec2 const&)
      {
        TRACE("render::base::stage::base::do_resize");

        throw std::logic_error("pure virtual function 'render::base::stage::base::do_resize' "
                               "called");
      }
      
    } // namespace stage {
    
  } // namespace base {
  
} // namespace render {
