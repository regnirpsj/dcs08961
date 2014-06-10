// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field_connection_base.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "field/connection/base.hpp"

// includes, system

#include <ostream>   // std::ostream
#include <stdexcept> // std::logic_error

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

namespace field {

  namespace connection {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    base::~base()
    {
      TRACE("field::connection::base::~base");
    }
    
    base::update_policy const&
    base::policy() const
    {
      TRACE("field::connection::base::policy");

      return policy_;
    }

    /* virtual */ ::field::base const&
    base::destination() const
    {
      TRACE("field::connection::base::destination");

      throw std::logic_error("pure virtual function 'field::connection::base::destination' called");
    }
    
    /* virtual */ ::field::base const&
    base::source() const
    {
      TRACE("field::connection::base::source");

      throw std::logic_error("pure virtual function 'field::connection::base::source' called");
    }
    
    /* virtual */ void
    base::update()
    {
      TRACE("field::connection::base::update");

      throw std::logic_error("pure virtual function 'field::connection::base::update' called");
    }
    
    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("field::connection::base::print_on");

      os << '[' << policy_ << ']';
    }
    
    /* explicit */
    base::base(update_policy const& a)
      : support::printable(),
        policy_           (a)
    {
      TRACE("field::connection::base::base");
    }
    
    std::ostream&
    operator<<(std::ostream& os, base::update_policy const& a)
    {
      TRACE_NEVER("field::connection::operator<<(std::ostream, base::update_policy)");

      typename std::ostream::sentry const cerberus(os);

      if (cerberus) {
        switch (a) {
        case base::pull: os << "pull"; break;
        case base::push: os << "push"; break;
        }
      }
    
      return os;

    }
  
  } // namespace connection {
  
} // namespace field {
