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

// includes, project

#include <render/base/context.hpp>
#include <render/base/statistics.hpp>
#include <support/type_info.hpp>

#define UKACHULLDCS_USE_TRACE
// #undef UKACHULLDCS_USE_TRACE
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

      bool
      base::active() const
      {
        TRACE("render::base::stage::base::active(get)");
        
        return active_;
      }

      bool
      base::active(bool a)
      {
        TRACE("render::base::stage::base::active(set)");
        
        bool const result(active_);

        active_ = a;

        return result;
      }

      bool
      base::stats_enable() const
      {
        TRACE("render::base::stage::base::stats_enable(get)");
        
        return stats_enabled_;
      }

      bool
      base::stats_enable(bool a)
      {
        TRACE("render::base::stage::base::stats_enable(set)");

        bool const result(stats_enabled_);

        stats_enabled_ = a;

        return result;
      }
      
      /* virtual */ void
      base::execute()
      {
        TRACE("render::base::stage::base::execute");

        statistics::guard const sg(stats_, stats_enabled_);
        
        do_execute();
      }
    
      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::stage::base::print_on");

        os << '[' << ctx_ << ',' << ((active_) ? "" : "!") << "active," << stats_ << ']';
      }

      /* explicit */
      base::base(context& a, statistics::base& b)
        : support::printable (),
          support::refcounted(),
          ctx_               (a),
          active_            (true),
          stats_             (b),
          stats_enabled_     (false)
      {
        TRACE("render::base::stage::base::base");
      }

      /* virtual */ void
      base::do_execute()
      {
        TRACE("render::base::stage::base::do_execute");

        throw std::logic_error("pure virtual function "
                               "'render::base::stage::base::do_execute' called");
      }
      
    } // namespace stage {
        
  } // namespace base {
  
} // namespace render {
