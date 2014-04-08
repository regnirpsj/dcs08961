// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/adapter_multi.hpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_MULTI_HPP)

#define UKACHULLDCS_08961_FIELD_ADAPTER_MULTI_HPP

// includes, system

#include <functional> // std::function<>
#include <vector>     // std::vector<>

// includes, project

#include <field/base.hpp>

namespace field {

  namespace adapter {
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T>
    class multi : public base {

    public:

      typedef base                                                         inherited;
      typedef inherited::container_type                                    container_type;
      typedef std::vector<T>                                               value_container_type;
      typedef typename value_container_type::value_type                    value_type;
      typedef std::function<std::vector<T> const& ()>                      get_callback_type;
      typedef std::function<std::vector<T>        (std::vector<T> const&)> set_callback_type;
      typedef std::function<bool (T const&)>                               add_callback_type;
      typedef std::function<bool (T const&)>                               sub_callback_type;
      
      explicit multi(container_type&             /* container */,
                     std::string const&          /* name */,
                     get_callback_type           /* get_cb */,
                     set_callback_type           /* set_cb */,
                     add_callback_type           /* add_cb */,
                     sub_callback_type           /* sub_cb */,
                     value_container_type const& /* init */ = value_container_type());
      explicit multi(container_type&                   /* container */,
                     std::string const&                /* name */,
                     get_callback_type                 /* get_cb */,
                     set_callback_type                 /* set_cb */,
                     add_callback_type                 /* add_cb */,
                     sub_callback_type                 /* sub_cb */,
                     std::initializer_list<value_type> /* init */);
      virtual ~multi();

      virtual void print_on(std::ostream&) const;
      
      value_container_type const& get() const;
      value_container_type        set(value_container_type const&);
      value_container_type        set(std::initializer_list<value_type>);
      bool                        add(value_type const&);
      bool                        sub(value_type const&);

      operator value_container_type const& () const;
      multi& operator=(value_container_type const&);
      multi& operator=(std::initializer_list<value_type>);
      multi& operator+=(value_type const&);
      multi& operator-=(value_type const&);
      
    private:

      get_callback_type get_value_;
      set_callback_type set_value_;
      add_callback_type add_value_;
      sub_callback_type sub_value_;
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace adapter {
  
} // namespace field {

#include <field/adapter_multi.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_MULTI_HPP)
