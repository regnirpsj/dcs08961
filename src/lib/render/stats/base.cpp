// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stats/base.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/stats/base.hpp"

// includes, system

//#include <>

// includes, project

#include <render/stats/cpu.hpp>

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

  namespace stats {
  
    // variables, exported

    // functions, exported

    /* virtual */
    base::data::~data()
    {
      TRACE("render::stats::base::data::~data");
    }
      
    /* virtual */ base::data&
    base::data::operator+=(base::data const&)
    {
      TRACE("render::stats::base::data::operator+=");

      return *this;
    }

    /* virtual */ void
    base::data::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::stats::base::data::print_on");

      os << "[render::stats::base::data]";
    }
      
    /* virtual */
    base::~base()
    {
      TRACE("render::stats::base::~base");
    }

    /* virtual */ std::unique_ptr<base::data>
    base::fetch() const
    {
      TRACE("render::stats::base::fetch");
        
      const_cast<base*>(this)->update();
        
      return std::unique_ptr<base::data>(new base::data);
    }
      
    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::stats::base::print_on");

      os << *(fetch());
    }

    /* explicit */
    base::base(context&)
      : boost::noncopyable(),
        support::printable(),
        updated_          (true)
    {
      TRACE("render::stats::base::base");
    }

    /* virtual */ void
    base::start()
    {
      TRACE("render::stats::base::start");
    }

    /* virtual */ void
    base::stop()
    {
      TRACE("render::stats::base::stop");
    }

    /* virtual */ bool
    base::done()
    {
      TRACE("render::stats::base::done");

      return false;
    }
      
    /* virtual */ void
    base::update(bool force_update)
    {
      TRACE("render::stats::base::update");

      if (!updated_ || force_update) {
        updated_ = done();
      }
    }
      
    /* explicit */
    guard::guard(base& a, bool b)
      : boost::noncopyable(),
        stats_            (a),
        enabled_          (b)
    {
      TRACE("render::stats::guard::guard");

      if (enabled_) {
        stats_.start();
      }
    }
      
    guard::~guard()
    {
      TRACE("render::stats::guard::~guard");

      if (enabled_) {
        static bool force_update(true);
          
        stats_.stop  ();
        stats_.update(force_update);
      }
    }
    
  } // namespace stats {
  
} // namespace render {
