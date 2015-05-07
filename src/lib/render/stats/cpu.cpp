// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stats/cpu.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/stats/cpu.hpp"

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

  namespace stats {
  
    // variables, exported
  
    // functions, exported

    /* virtual */
    cpu::data::~data()
    {
      TRACE("render::stats::cpu::data::~data");
    }
      
    /* virtual */ cpu::data&
    cpu::data::operator+=(data const&)
    {
      TRACE("render::stats::cpu::data::operator+=");

      return *this;
    }

    /* virtual */ void
    cpu::data::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::stats::cpu::data::print_on");

      os << "[render::stats::cpu::data]";
    }

    /* explicit */
    cpu::cpu(context& a)
      : base        (a),
        rate_timer_ (),
        rate_       (rate_timer_.lapse()),
        stamp_timer_(),
        stamp_      (stamp_timer_.lapse())
    {
      TRACE("render::stats::cpu::cpu");
    }

    /* virtual */
    cpu::~cpu()
    {
      TRACE("render::stats::cpu::~cpu");
    }

    /* virtual */ std::unique_ptr<base::data>
    cpu::fetch() const
    {
      TRACE("render::stats::cpu::fetch");

      base::fetch();

      static float const nano_to_sec(1000000000.0f);

      using std::chrono::duration_cast;
      using std::chrono::nanoseconds;
        
      cpu::data* result(new cpu::data);

      result->rate_in_hz = ((1.0f / duration_cast<nanoseconds>(rate_).count()) * nano_to_sec);
      result->time_in_ns = double(duration_cast<nanoseconds>(stamp_).count());
        
      return std::unique_ptr<base::data>(result);
    }

    /* virtual */ void
    cpu::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::stats::cpu::print_on");

      base::print_on(os);
    }

    /* virtual */ void
    cpu::start()
    {
      TRACE("render::stats::cpu::start");

      rate_timer_ .reset();
      stamp_timer_.reset();
    }

    /* virtual */ void
    cpu::stop()
    {
      TRACE("render::stats::cpu::stop");

      rate_  = rate_timer_ .lapse();
      stamp_ = stamp_timer_.lapse();

      rate_timer_.reset();
    }

    /* virtual */ bool
    cpu::done()
    {
      TRACE("render::stats::cpu::done");

      return true;
    }

    /* virtual */ void
    cpu::update(bool)
    {
      TRACE("render::stats::cpu::update");
    }
    
  } // namespace stats {
  
} // namespace render {
