// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/stats/gpu.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/ogl/stats/gpu.hpp"

// includes, system

//#include <>

// includes, project

#include <render/ogl/context.hpp>

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

  namespace ogl {

    namespace stats {
      
      // variables, exported
  
      // functions, exported

      /* virtual */
      gpu::data::~data()
      {
        TRACE("render::ogl::stats::gpu::data::~data");
      }
      
      /* virtual */ gpu::data&
      gpu::data::operator+=(data const&)
      {
        TRACE("render::ogl::stats::gpu::data::operator+=");

        return *this;
      }

      /* virtual */ void
      gpu::data::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::ogl::stats::gpu::data::print_on");

        os << "[" << rate_in_hz << "Hz," << time_in_ns << "ns]";
      }
      
      /* explicit */
      gpu::gpu(ogl::context& a)
        : render::stats::base(a),
          rate_timer_        (),
          rate_              (rate_timer_.lapse()),
          stamp_timer_       (),
          stamp_             (stamp_timer_.lapse())
      {
        TRACE("render::ogl::stats::gpu::gpu");
      }
      
      /* virtual */
      gpu::~gpu()
      {
        TRACE("render::ogl::stats::gpu::~gpu");
      }

      /* virtual */ std::unique_ptr<render::stats::base::data>
      gpu::fetch() const
      {
        TRACE("render::ogl::stats::gpu::fetch");

        base::fetch();

        static float const nano_to_sec(1000000000.0f);

        using std::chrono::duration_cast;
        using std::chrono::nanoseconds;
        
        gpu::data* result(new gpu::data);

        result->rate_in_hz = ((1.0f / duration_cast<nanoseconds>(rate_).count()) * nano_to_sec);
        result->time_in_ns = double(duration_cast<nanoseconds>(stamp_).count());
        
        return std::unique_ptr<render::stats::base::data>(result);
      }

      /* virtual */ void
      gpu::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::ogl::stats::gpu::print_on");

        base::print_on(os);
      }

      /* virtual */ void
      gpu::start()
      {
        TRACE("render::ogl::stats::gpu::start");

        rate_timer_ .reset();
        stamp_timer_.reset();
      }

      /* virtual */ void
      gpu::stop()
      {
        TRACE("render::ogl::stats::gpu::stop");

        rate_  = rate_timer_ .lapse();
        stamp_ = stamp_timer_.lapse();

        rate_timer_.reset();
      }

      /* virtual */ bool
      gpu::done()
      {
        TRACE("render::ogl::stats::gpu::done");

        return true;
      }

      /* virtual */ void
      gpu::update(bool)
      {
        TRACE("render::ogl::stats::gpu::update");
      }
      
    } // namespace stats {
        
  } // namespace ogl {
    
} // namespace render {
