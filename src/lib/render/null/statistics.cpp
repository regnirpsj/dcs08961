// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  proto.cpp                                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "statistics.hpp"

// includes, system

// #include <>

// includes, project

#include <render/null/context.hpp>

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
  
    // variables, exported

    /* static */ stats stats::dflt;
    
    // functions, exported

    /* virtual */
    stats::data::~data()
    {
      TRACE("render::base::statistics::stats::data::~data");
    }
      
    /* virtual */ stats::data&
    stats::data::operator+=(data const&)
    {
      TRACE("render::base::statistics::stats::data::operator+=");

      return *this;
    }

    /* virtual */ void
    stats::data::print_on(std::ostream&) const
    {
      TRACE_NEVER("render::base::statistics::stats::data::print_on");
    }
    
    /* explicit */
    stats::stats()
      : render::base::statistics::base(context::dflt),
        render::base::statistics::cpu (context::dflt),
        render::base::statistics::gpu (context::dflt)
    {
      TRACE("render::null:stats::stats");
    }

    /* virtual */
    stats::~stats()
    {
      TRACE("render::null:stats::~stats");
    }

    /* virtual */ std::unique_ptr<render::base::statistics::base::data>
    stats::fetch() const
    {
      TRACE("render::null:stats::fetch");

      return std::unique_ptr<render::base::statistics::base::data>(new stats::data);
    }
    
    /* virtual */ void
    stats::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::null::stats::print_on");
      
      render::base::statistics::cpu::print_on(os);
      render::base::statistics::gpu::print_on(os);
    }

    /* virtual */ void
    stats::start()
    {
      TRACE("render::null::stats::start");

      render::base::statistics::cpu::start();
      render::base::statistics::gpu::start();
    }

    /* virtual */ void
    stats::stop()
    {
      TRACE("render::null::stats::stop");

      render::base::statistics::cpu::stop();
      render::base::statistics::gpu::stop();
    }

    /* virtual */ bool
    stats::done()
    {
      TRACE("render::null::stats::done");

      bool result(false);

      result |= render::base::statistics::cpu::done();
      result |= render::base::statistics::gpu::done();
      
      return result;
    }

    /* virtual */ void
    stats::update(bool a)
    {
      TRACE("render::null::stats::update");

      render::base::statistics::cpu::update(a);
      render::base::statistics::gpu::update(a);
    }
    
  } // namespace null {
  
} // namespace render {
