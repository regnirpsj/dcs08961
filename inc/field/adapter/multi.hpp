// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/adapter/multi.hpp                                                         */
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

#include <field/multi/base.hpp>

namespace field {

  namespace adapter {
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T, typename C = std::vector<T>>
    class multi : public ::field::multi::base<T,C> {

    public:

      typedef ::field::multi::base<T,C>                inherited;
      typedef typename inherited::container_type       container_type;
      typedef typename inherited::value_container_type value_container_type;
      typedef typename inherited::value_type           value_type;
      typedef std::function<C const& ()>               get_callback_type;
      typedef std::function<C (C const&)>              set_callback_type;
      typedef std::function<bool (T const&)>           add_callback_type;
      typedef std::function<bool (T const&)>           sub_callback_type;
      
      explicit multi(container_type&    /* container */,
                     std::string const& /* name */,
                     get_callback_type  /* get_cb */,
                     set_callback_type  /* set_cb */,
                     add_callback_type  /* add_cb */,
                     sub_callback_type  /* sub_cb */);
      virtual ~multi();
      
      virtual value_container_type const& get() const;
      virtual value_container_type        set(value_container_type const&);
#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
      virtual value_container_type        set(std::initializer_list<value_type>);
#endif
      virtual bool                        add(value_type const&);
      virtual bool                        sub(value_type const&);

      using inherited::operator*;
      using inherited::operator=;
      using inherited::operator+=;
      using inherited::operator-=;
        
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

#include <field/adapter/multi.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_MULTI_HPP)
