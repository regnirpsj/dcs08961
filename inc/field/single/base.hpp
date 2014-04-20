// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/single/base.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_SINGLE_BASE_HPP)

#define UKACHULLDCS_08961_FIELD_SINGLE_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <field/base.hpp>

namespace field {

  namespace single {
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T>
    class base : public ::field::base {

    public:

      typedef ::field::base             inherited;
      typedef inherited::container_type container_type;
      typedef T                         value_type;

      virtual void print_on(std::ostream&) const;
    
      virtual value_type const& get() const            =0;
      virtual value_type        set(value_type const&) =0;
      
      value_type const& operator*() const;
      base&             operator=(value_type const&);

    protected:

      explicit base(container_type&    /* container */,
                    std::string const& /* name */);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace single {
  
} // namespace field {

#include <field/single/base.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_SINGLE_BASE_HPP)
