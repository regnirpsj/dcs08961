// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
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

#include <field/base.hpp>

namespace field {

  namespace adapter {
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T>
    class single : public base {

    public:
      
      typedef base::container_type               container_type;
      typedef T                                  value_type;
      typedef std::function<T const& ()>         get_callback_type;
      typedef std::function<T        (T const&)> set_callback_type;
      
      explicit single(container_type&    /* container */,
                      std::string const& /* name */,
                      get_callback_type  /* get_cb */,
                      set_callback_type  /* set_cb */,
                      value_type const&  /* init */ = value_type());
      virtual ~single();

      virtual void print_on(std::ostream&) const;
      
      value_type const& get() const;
      value_type        set(value_type const&);

      operator value_type const& () const;
      single& operator=(value_type const&);
      
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
