// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
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

#include <list>   // std::list<>
#include <string> // std::string

// includes, project

#include <support/chrono.hpp>
#include <support/printable.hpp>

namespace field {

  class container;

  namespace connection {

    class base;
    
  } // namespace connection {
  
  // types, exported (class, enum, struct, union, typedef)

  class base : public support::printable {

  public:

    typedef ::field::container container_type;
    
    container_type const& container() const;
    std::string const&    name() const;
    
    void touch();

    bool connection_add(connection::base*);
    bool connection_sub(connection::base*);
    
    virtual void print_on(std::ostream&) const;
    
  protected:

    typedef std::list<connection::base*> connection_list_type;
    
    container_type&            container_;
    std::string                name_;
    support::clock::time_point last_change_;
    connection_list_type       connection_list_;
    
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
