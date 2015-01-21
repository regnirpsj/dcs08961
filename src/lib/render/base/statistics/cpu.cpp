// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/statistics/cpu.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/statistics/cpu.hpp"

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

    namespace statistics {
  
      // variables, exported
  
      // functions, exported

      /* virtual */
      cpu::data::~data()
      {
        TRACE("render::base::statistics::cpu::data::~data");
      }
      
      /* virtual */ cpu::data&
      cpu::data::operator+=(data const&)
      {
        TRACE("render::base::statistics::cpu::data::operator+=");

        return *this;
      }

      /* virtual */ void
      cpu::data::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::statistics::cpu::data::print_on");

        os << "[render::base::statistics::cpu::data]";
      }

      /* explicit */
      cpu::cpu(context& a)
        : base        (a),
          rate_timer_ (),
          rate_       (rate_timer_.lapse()),
          stamp_timer_(),
          stamp_      (stamp_timer_.lapse())
      {
        TRACE("render::base::statistics::cpu::cpu");
      }

      /* virtual */
      cpu::~cpu()
      {
        TRACE("render::base::statistics::cpu::~cpu");
      }

      /* virtual */ std::unique_ptr<base::data>
      cpu::fetch() const
      {
        TRACE("render::base::statistics::cpu::fetch");

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
        TRACE_NEVER("render::base::statistics::cpu::print_on");

        base::print_on(os);
      }

      /* virtual */ void
      cpu::start()
      {
        TRACE("render::base::statistics::cpu::start");

        rate_timer_ .reset();
        stamp_timer_.reset();
      }

      /* virtual */ void
      cpu::stop()
      {
        TRACE("render::base::statistics::cpu::stop");

        rate_  = rate_timer_ .lapse();
        stamp_ = stamp_timer_.lapse();

        rate_timer_.reset();
      }

      /* virtual */ bool
      cpu::done()
      {
        TRACE("render::base::statistics::cpu::done");

        return true;
      }

      /* virtual */ void
      cpu::update(bool)
      {
        TRACE("render::base::statistics::cpu::update");
      }
    
    } // namespace statistics {
    
  } // namespace base {
  
} // namespace render {
