// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/connection/simple.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_SIMPLE_HPP)

#define UKACHULLDCS_08961_FIELD_CONNECTION_SIMPLE_HPP

// includes, system

//#include <>

// includes, project

#include <field/connection/base.hpp>

namespace field {

  namespace connection {

    // types, exported (class, enum, struct, union, typedef)

    template <typename T1, typename T2 = T1>
    class simple : public base {

    public:

      typedef T1                  source_type;
      typedef T2                  destination_type;
      typedef base::update_policy update_policy;
      
      explicit simple(source_type const&, destination_type&,
                      update_policy const& = update_policy::push);
      virtual ~simple();
      
      virtual void update();
      
      virtual void print_on(std::ostream&) const;

    protected:

      source_type const& src_;
      destination_type&  dst_;
      
    };

    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
  } // namespace connection {
  
} // namespace field {

#include <field/connection/simple.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_SIMPLE_HPP)
