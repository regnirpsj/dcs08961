// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/adapter/single.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_SINGLE_HPP)

#define UKACHULLDCS_08961_FIELD_ADAPTER_SINGLE_HPP

// includes, system

#include <functional> // std::function<>

// includes, project

#include <field/single/base.hpp>

namespace field {

  namespace adapter {
    
    // types, exported (class, enum, struct, union, typedef)
    
    template <typename T>
    class single : public ::field::single::base<T> {

    public:

      using inherited         = ::field::single::base<T>;
      using container_type    = typename inherited::container_type;
      using value_type        = typename inherited::value_type;
      using get_callback_type = std::function<T const& ()>;
      using set_callback_type = std::function<T        (T const&)>;
      
      explicit single(container_type&    /* container */,
                      std::string const& /* name */,
                      get_callback_type  /* get_cb */,
                      set_callback_type  /* set_cb */);
      virtual ~single();
      
      virtual value_type const& get() const;
      virtual value_type        set(value_type const&);

      using inherited::operator*;
      using inherited::operator=;
      
    private:

      get_callback_type get_value_;
      set_callback_type set_value_;
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace adapter {
  
} // namespace field {

#include <field/adapter/single.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_SINGLE_HPP)
