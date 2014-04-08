// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/value_multi.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_VALUE_MULTI_HPP)

#define UKACHULLDCS_08961_FIELD_VALUE_MULTI_HPP

// includes, system

#include <vector> // std::vector<>

// includes, project

#include <field/base.hpp>

namespace field {

  namespace value {

    class container;
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T>
    class multi : public base {

    public:

      typedef base                                      inherited;
      typedef inherited::container_type                 container_type;
      typedef std::vector<T>                            value_container_type;
      typedef typename value_container_type::value_type value_type;

      explicit multi(container_type&             /* container */,
                     std::string const&          /* name */,
                     value_container_type const& /* init */ = value_container_type());
      explicit multi(container_type&                   /* container */,
                     std::string const&                /* name */,
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

      value_container_type value_container_;
    
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace value {
  
} // namespace field {

#include <field/value_multi.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_VALUE_MULTI_HPP)
