// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/base.cpp                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "field/base.hpp"

// includes, system

#include <iomanip>
#include <ostream> // std::ostream

// includes, project

#include <field/container.hpp>

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
  
  // variables, exported
  
  // functions, exported

  container const&
  base::container() const
  {
    TRACE("field::base::container(get)");

    return container_;
  }

  std::string const&
  base::name() const
  {
    TRACE("field::base::name(get)");

    return name_;
  }

  void
  base::touch()
  {
    TRACE("field::base::touch");

    changed();
  }
  
  /* virtual */ void
  base::print_on(std::ostream& os) const
  {
    TRACE_NEVER("field::base::print_on");

    os << '['
       << std::right << std::setw(16) << name_ << '@' << this << "->" << &container_
       << ']';
  }
  
  /* explicit */
  base::base(container_type& a, std::string const& b)
    : container_(a),
      name_     (b)
  {
    TRACE("field::base::base");

    container_.add(this);
  }
  
  /* virtual */
  base::~base()
  {
    TRACE("field::base::~base");

    container_.sub(this);
  }

  void
  base::changed()
  {
    TRACE("field::base::changed");

    container_.changed(*this);
    
    notify();
  }
  
  void
  base::notify()
  {
    TRACE("field::base::notify");
  }
  
} // namespace field {
