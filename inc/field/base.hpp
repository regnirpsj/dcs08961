// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/base.hpp                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_BASE_HPP)

#define UKACHULLDCS_08961_FIELD_BASE_HPP

// includes, system

#include <string> // std::string

// includes, project

#include <support/chrono.hpp>
#include <support/printable.hpp>
#include <field/export.h>

namespace field {

  class container;
  
  // types, exported (class, enum, struct, union, typedef)

  class DCS08961_FIELD_EXPORT base : public support::printable {

  public:

    using container_type = ::field::container;
    using time_point     = support::clock::time_point;
    
    container_type const& container() const;
    std::string const&    name() const;
    time_point const&     last_change() const;
    
    void touch();
    
    virtual void print_on(std::ostream&) const;
    
  protected:

    container_type& container_;
    std::string     name_;
    time_point      last_change_;
    
    explicit base(container_type&, std::string const&);
    virtual ~base() =0;

    void changed();
    void notify();
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace field {

#endif // #if !defined(UKACHULLDCS_08961_FIELD_BASE_HPP)
