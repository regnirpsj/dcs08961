// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/statistics/base.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/statistics/base.hpp"

// includes, system

#include <ostream> // std::ostream

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
      base::data::~data()
      {
        TRACE("render::base::statistics::base::data::~data");
      }
      
      /* virtual */ base::data&
      base::data::operator+=(base::data const&)
      {
        TRACE("render::base::statistics::base::data::operator+=");

        return *this;
      }

      /* virtual */ void
      base::data::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::statistics::base::data::print_on");

        os << "[render::base::statistics::base::data]";
      }
      
      /* virtual */
      base::~base()
      {
        TRACE("render::base::statistics::base::~base");
      }

      /* virtual */ std::unique_ptr<base::data>
      base::fetch() const
      {
        TRACE("render::base::statistics::base::fetch");
        
        const_cast<base*>(this)->update();
        
        return std::unique_ptr<base::data>(new base::data);
      }
      
      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::statistics::base::print_on");

        os << *(fetch());
      }

      /* explicit */
      base::base(context&)
        : boost::noncopyable(),
          support::printable(),
          updated_          (true)
      {
        TRACE("render::base::statistics::base::base");
      }

      /* virtual */ void
      base::start()
      {
        TRACE("render::base::statistics::base::start");
      }

      /* virtual */ void
      base::stop()
      {
        TRACE("render::base::statistics::base::stop");
      }

      /* virtual */ bool
      base::done()
      {
        TRACE("render::base::statistics::base::done");

        return false;
      }
      
      /* virtual */ void
      base::update(bool force_update)
      {
        TRACE("render::base::statistics::base::update");

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
        TRACE("render::base::statistics::guard::guard");

        if (enabled_) {
          stats_.start();
        }
      }
      
      guard::~guard()
      {
        TRACE("render::base::statistics::guard::~guard");

        if (enabled_) {
          static bool force_update(true);
          
          stats_.stop  ();
          stats_.update(force_update);
        }
      }
      
    } // namespace statistics {
    
  } // namespace base {
  
} // namespace render {
