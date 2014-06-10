// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/connection/base.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_BASE_HPP)

#define UKACHULLDCS_08961_FIELD_CONNECTION_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <support/printable.hpp>

namespace field {

  class base;
  
  namespace connection {

    // types, exported (class, enum, struct, union, typedef)
    
    class base : public support::printable {

    public:

      enum update_policy { pull, push, };
      
      virtual ~base();

      update_policy const& policy() const;

      virtual ::field::base const& destination() const =0;
      virtual ::field::base const& source() const      =0;
      virtual void                 update()            =0;
      
      virtual void print_on(std::ostream&) const;

    protected:

      update_policy policy_;
      
      explicit base(update_policy const&);
      
    };

    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

    std::ostream& operator<<(std::ostream&, base::update_policy const&);
    
  } // namespace connection {
  
} // namespace field {

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_BASE_HPP)
