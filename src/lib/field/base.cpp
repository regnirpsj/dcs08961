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

#include <algorithm> // std::find<>
#include <ostream>   // std::ostream
#include <stdexcept> // std::logic_error

// includes, project

#include <field/connection/manager.hpp>
#include <field/container.hpp>
#include <support/io_utils.hpp>

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

    using support::ostream::operator<<;
    
    os << '['
       << std::right << std::setw(16) << name_ << '@' << this
       << "->" << &container_ << ':' << last_change_
       << ']';
  }
  
  /* explicit */
  base::base(container_type& a, std::string const& b)
    : container_      (a),
      name_           (b),
      last_change_    (support::clock::now())
  {
    TRACE("field::base::base");

    if (name_.empty()) {
      throw std::logic_error("field names cannot be empty!");
    }
    
    container_.add(this);
  }
  
  /* virtual */
  base::~base()
  {
    TRACE("field::base::~base");

    connection::manager::instance->disconnect(this);
    
    container_.sub(this);
  }

  void
  base::changed()
  {
    TRACE("field::base::changed");

    last_change_ = support::clock::now();
    
    container_.changed(*this);
    
    notify();
  }
  
  void
  base::notify()
  {
    TRACE("field::base::notify");

    connection::manager::instance->update(this);
  }
  
} // namespace field {
