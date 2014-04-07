// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/container.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "field/container.hpp"

// includes, system

#include <algorithm> // std::find<>
#include <ostream>   // std::ostream
#include <typeinfo>  // typeid

// includes, project

#include <field/base.hpp>
#include <support/type_info.hpp>

#define DCSHULLACUK_USE_TRACE
#undef DCSHULLACUK_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace field {
  
  // variables, exported
  
  // functions, exported

  /* virtual */ void
  container::touch()
  {
    TRACE("field::container::touch");

    // schedule_for_evaluation();
  }

  /* virtual */ void
  container::print_on(std::ostream& os) const
  {
    TRACE_NEVER("field::container::print_on");

    std::string prefix(/* support::trace::prefix().length() */ 0, ' ');
      
    os << prefix << '['
       << support::demangle(typeid(*this)) << '@' << this << ',';

    prefix += ' ';
      
    for (auto f : field_list_) {
      os << '\n' << prefix << *f;
    }
      
    os << '\n' << ']';
  }
  
  /* explicit */
  container::container()
    : field_list_()
  {
    TRACE("field::container::container");
  }

  /* virtual */
  container::~container()
  {
    TRACE("field::container::~container");
  }
  
  /* virtual */ void
  container::evaluate()
  {
    TRACE("field::container::evaluate");
  }

  /* virtual */ void
  container::changed(base&)
  {
    TRACE("field::container::changed");
  }
  
  void
  container::add(base* a)
  {
    TRACE("field::container::add");

    field_list_.insert(a);
  }
  
  void
  container::sub(base* a)
  {
    TRACE("field::container::sub");

    field_list_.erase(a);
  }
  
} // namespace field {
