// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/statistics/gpu.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/statistics/gpu.hpp"

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
      gpu::data::~data()
      {
        TRACE("render::base::statistics::gpu::data::~data");
      }
      
      /* virtual */ gpu::data&
      gpu::data::operator+=(data const&)
      {
        TRACE("render::base::statistics::gpu::data::operator+=");

        return *this;
      }

      /* virtual */ void
      gpu::data::print_on(std::ostream&) const
      {
        TRACE_NEVER("render::base::statistics::gpu::data::print_on");
      }
      
      /* explicit */
      gpu::gpu(context& a)
        : base(a)
      {
        TRACE("render::base::statistics::gpu::gpu");
      }

      /* virtual */
      gpu::~gpu()
      {
        TRACE("render::base::statistics::gpu::~gpu");
      }

      /* virtual */ std::unique_ptr<base::data>
      gpu::fetch() const
      {
        TRACE("render::base::statistics::gpu::fetch");

        base::fetch();
        
        gpu::data* result(new gpu::data);
        
        return std::unique_ptr<base::data>(result);
      }
      
      /* virtual */ void
      gpu::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::statistics::gpu::print_on");

        base::print_on(os);
      }
      
      /* virtual */ void
      gpu::start()
      {
        TRACE("render::base::statistics::gpu::start");
      }
      
      /* virtual */ void
      gpu::stop()
      {
        TRACE("render::base::statistics::gpu::stop");
      }
      
      /* virtual */ bool
      gpu::done()
      {
        TRACE("render::base::statistics::gpu::done");
        
        return false;
      }
      
      /* virtual */ void
      gpu::update(bool)
      {
        TRACE("render::base::statistics::gpu::update");
      }
      
    } // namespace statistics {
    
  } // namespace base {
  
} // namespace render {
