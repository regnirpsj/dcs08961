// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/base.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/stage/base.hpp"

// includes, system

#include <stdexcept> // std::logic_error

// includes, project

#include <render/stats/cpu.hpp>
#include <support/io_utils.hpp>

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

    /* virtual */
    base::~base()
    {
      TRACE("render::stage::base::~base");
    }
      
    void
    base::execute()
    {
      TRACE("render::stage::base::execute");

      stats::guard const sg(stats_execute_);
      
      do_execute();
    }

    void
    base::resize(glm::ivec2 const& a)
    {
      TRACE("render::stage::base::resize");

      stats::guard const sg(stats_resize_);
      
      do_resize(a);
    }
    
    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::stage::base::print_on");

      field::container::print_on(os);
    }

    /* explicit */
    base::base(context& a, stats::base& b, stats::base& c)
      : field::container   (),
        support::refcounted(),
        active             (*this, "active", true),
        name               (*this, "name",   "[render::stage::base]"),
        ctx_               (a),
        stats_execute_     (b),
        stats_resize_      (c)
    {
      TRACE("render::stage::base::base");
    }

    /* virtual */ void
    base::do_execute()
    {
      TRACE("render::stage::base::do_execute");

      throw std::logic_error("pure virtual function 'render::stage::base::do_execute' called");
    }

    /* virtual */ void
    base::do_resize(glm::ivec2 const&)
    {
      TRACE("render::stage::base::do_resize");

      throw std::logic_error("pure virtual function 'render::stage::base::do_resize' called");
    }
      
  } // namespace stage {
  
} // namespace render {
