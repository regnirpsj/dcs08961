// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/value/single.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_VALUE_SINGLE_HPP)

#define UKACHULLDCS_08961_FIELD_VALUE_SINGLE_HPP

// includes, system

// #include <>

// includes, project

#include <field/single/base.hpp>

namespace field {

  namespace value {
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T>
    class single : public ::field::single::base<T> {

    public:

      typedef ::field::single::base<T>           inherited;
      typedef typename inherited::container_type container_type;
      typedef typename inherited::value_type     value_type;
    
      explicit single(container_type&    /* container */,
                      std::string const& /* name */,
                      value_type const&  /* init */ = value_type());
      virtual ~single();
    
      virtual value_type const& get() const;
      virtual value_type        set(value_type const&);

      using inherited::operator*;
      using inherited::operator=;
      
    private:

      value_type value_;
    
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace value {

} // namespace field {

#include <field/value/single.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_VALUE_SINGLE_HPP)
