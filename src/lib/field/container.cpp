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
#include <support/io_utils.hpp>
#include <support/type_info.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class default_container_manager : public field::container::manager {

  public:

    virtual ~default_container_manager()
    {
      TRACE("field::container::<unnamed>::default_container_manager::~default_container_manager");
    }
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

namespace field {
  
  // variables, exported

  /* static */ std::unique_ptr<container::manager> container::mgr(new default_container_manager);
    
  // functions, exported
  
  /* virtual */
  container::manager::~manager()
  {
    TRACE("field::container::manager::~manager");
  }

  /* virtual */ void
  container::manager::print_on(std::ostream& os) const
  {
    TRACE_NEVER("field::container::manager::print_on");

    using support::ostream::operator<<;
      
    os << container_list_;
  }

  /* virtual */ bool
  container::manager::schedule(container* a)
  {
    TRACE("field::container::manager::schedule");

    bool       result(false);
    auto const found(std::find(container_list_.begin(), container_list_.end(), a));

    if (mgr->container_list_.end() == found) {
      container_list_.push_back(a);

      result = true;
    }

    return result;
  }
  
  /* virtual */ bool
  container::manager::unschedule(container* a)
  {
    TRACE("field::container::manager::unschedule");

    bool       result(false);
    auto const found(std::find(container_list_.begin(), container_list_.end(), a));

    if (mgr->container_list_.end() != found) {
      container_list_.erase(found);

      result = true;
    }

    return result;
  }
  
  /* virtual */ void
  container::touch()
  {
    TRACE("field::container::touch");

    mgr->schedule(this);
  }
  
  /* virtual */ void
  container::print_on(std::ostream& os) const
  {
    TRACE_NEVER("field::container::print_on");

    std::string prefix(0, ' ');
      
    os << prefix << '['
       << support::demangle(typeid(*this)) << '@' << this << ',';

    prefix += ' ';
      
    for (auto f : field_list_) {
      os << '\n' << prefix << std::boolalpha << *f;
    }
      
    os << '\n'
       << prefix << "mgr:" << *mgr
       << ']';
  }
  
  /* explicit */
  container::container()
    : support::printable(),
      field_list_       ()
  {
    TRACE("field::container::container");
  }

  /* virtual */
  container::~container()
  {
    TRACE("field::container::~container");

    mgr->unschedule(this);
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

    touch();
  }
  
  void
  container::add(base* a)
  {
    TRACE("field::container::add");

    auto const found(std::find(field_list_.begin(), field_list_.end(), a));

    if (field_list_.end() == found) {
      field_list_.push_back(a);
    } else {
      throw std::logic_error("unable to register the same field twice!");
    }
  }
  
  void
  container::sub(base* a)
  {
    TRACE("field::container::sub");

    auto const found(std::find(field_list_.begin(), field_list_.end(), a));

    if (field_list_.end() != found) {
      field_list_.erase(found);
    } else {
      throw std::logic_error("unable to unregister non-existent field");
    }
  }
  
} // namespace field {
