// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/event/base.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "event/event/base.hpp"

// includes, system

#include <cstdlib>   // std::abort
#include <ostream>   // std::ostream
#include <stdexcept> // std::logic_error

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
//#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace event {
  
  // variables, exported

  /* static */ base::time_source_function_type base::time_source_(&support::clock::now);
  
  // functions, exported

  /* static */ base::time_source_function_type
  base::time_source()
  {
    TRACE("event::base::time_source(get)");

    return time_source_;
  }
  
  /* static */ base::time_source_function_type
  base::time_source(time_source_function_type a)
  {
    TRACE("event::base::time_source(set)");

    time_source_function_type result(time_source_);
    
    time_source_ = a;

    return result;
  }

  /* virtual */
  base::~base()
  {
    TRACE("event::base::~base");
  }

  base::time_stamp_type const&
  base::time_stamp() const
  {
    TRACE("event::base::time_stamp(get)");

    return stamp_;
  }

  /* virtual */ void
  base::notify()
  {
    TRACE("event::base::notify");

    throw std::logic_error("logically pure virtual function 'event::base::notify' called");
  }

  /* virtual */ void
  base::print_on(std::ostream& os) const
  {
    TRACE_NEVER("event::base::print_on");

    os << '[' << stamp_ << ']';
  }

  /* explicit */
  base::base()
    : support::printable(),
      stamp_            (time_source_())
  {
    TRACE("event::base::base(dflt)");
  }

  /* explicit */
  base::base(base const& a)
    : support::printable(a),
      stamp_            (a.stamp_)
  {
    TRACE("event::base::base(cpy)");
  }

  /* explicit */
  base::base(base const&& a)
    : support::printable(a),
      stamp_            (a.stamp_)
  {
    TRACE("event::base::base(mov)");
  }

#if 0
  void
  base::operator=(base const&)
  {
    TRACE("event::base::operator=(cpy)");

    throw std::logic_error("logically pure virtual function 'event::base::operator=(cpy)' called");

    std::abort();
  }

  void
  base::operator=(base const&&)
  {
    TRACE("event::base::operator=(mov)");
    
    throw std::logic_error("logically pure virtual function 'event::base::operator=(mov)' called");
    
    std::abort();
  }
#endif
  
} // namespace event {
