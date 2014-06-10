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
//#include <iomanip>
#include <ostream>   // std::ostream

// includes, project

#include <field/connection/base.hpp>
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

  bool
  base::connection_add(connection::base* a)
  {
    TRACE("field::base::connection_add(connection::base)");

    bool result(false);
    auto found (std::find(connection_list_.begin(), connection_list_.end(), a));

    if (connection_list_.end() == found) {
      connection_list_.push_back(a);

      result = true;
    }
    
    return result;
  }
  
  bool
  base::connection_sub(connection::base* a)
  {
    TRACE("field::base::connection_sub(connection::base)");

    bool result(false);
    auto found (std::find(connection_list_.begin(), connection_list_.end(), a));

    if (connection_list_.end() != found) {
      connection_list_.erase(found);

      result = true;
    }

    return result;
  }
  
  /* virtual */ void
  base::print_on(std::ostream& os) const
  {
    TRACE_NEVER("field::base::print_on");

    using support::ostream::operator<<;
    
    os << '['
       << std::right << std::setw(16) << name_ << '@' << this
       << "->" << &container_ << ':' << last_change_ << ':' << connection_list_
       << ']';
  }
  
  /* explicit */
  base::base(container_type& a, std::string const& b)
    : container_      (a),
      name_           (b),
      last_change_    (support::clock::now()),
      connection_list_()
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

    last_change_ = support::clock::now();
    
    container_.changed(*this);
    
    notify();
  }
  
  void
  base::notify()
  {
    TRACE("field::base::notify");

    for (auto c : connection_list_) {
      if (connection::base::push == c->policy()) {
        c->update();
      }
    }
  }
  
} // namespace field {
