// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

      using inherited      = ::field::single::base<T>;
      using container_type = typename inherited::container_type;
      using value_type     = typename inherited::value_type;
    
      explicit single(container_type&    /* container */,
                      std::string const& /* name      */,
                      value_type const&  /* init      */ = value_type());
      explicit single(container_type&    /* container */,
                      std::string const& /* name      */,
                      value_type&&       /* init      */);
      virtual ~single();
    
      virtual value_type const& get() const;
      virtual value_type        set(value_type const&);
      virtual value_type        set(value_type&&);
      
      //using inherited::operator*;
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
