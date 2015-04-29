// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/multi/base.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_MULTI_BASE_HPP)

#define UKACHULLDCS_08961_FIELD_MULTI_BASE_HPP

// includes, system

#include <vector> // std::vector<>

// includes, project

#include <field/base.hpp>

namespace field {

  namespace multi {
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T, typename C = std::vector<T>>
    class base : public ::field::base {

    public:
      
      using inherited            = ::field::base;
      using container_type       = inherited::container_type;
      using value_container_type = C;
      using value_type           = T;

      virtual void print_on(std::ostream&) const;
    
      virtual value_container_type const& get() const                            =0;
      virtual value_container_type        set(value_container_type const&)       =0;
#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
      virtual value_container_type        set(std::initializer_list<value_type>) =0;
#endif
      virtual bool                        add(value_type const&)                 =0;
      virtual bool                        sub(value_type const&)                 =0;

      value_container_type const& operator* () const;
      value_container_type const* operator->() const;
      base&                       operator= (value_container_type const&);
#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
      base&                       operator= (std::initializer_list<value_type>);
#endif
      base&                       operator+=(value_type const&);
      base&                       operator-=(value_type const&);
      
    protected:

      explicit base(container_type&    /* container */,
                    std::string const& /* name      */);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace multi {
  
} // namespace field {

#include <field/multi/base.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_MULTI_BASE_HPP)
