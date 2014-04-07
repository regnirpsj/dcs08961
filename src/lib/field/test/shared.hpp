// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/shared.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_TEST_SHARED_HPP)

#define UKACHULLDCS_08961_FIELD_TEST_SHARED_HPP

// includes, system

#include <boost/mpl/list.hpp> // boost::mpl::list<>
#include <string>             // std::string

// includes, project

#include <field/container.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace field {
  
  namespace test {
  
    // types, exported (class, enum, struct, union, typedef)

    class container : public field::container {
    };

    typedef boost::mpl::list<
      bool
      ,signed   char
      ,unsigned char
      ,char16_t
      ,char32_t
      ,signed   short
      ,unsigned short
      ,signed   int
      ,unsigned int
      ,signed   long int
      ,unsigned long int
      ,signed   long long int
      ,unsigned long long int
      ,float
      ,double
      ,long double
      ,std::string
      > types;
  
    // variables, exported (extern)
  
    // functions, inlined (inline)

    template <typename T>
    inline T const&
    getter() 
    {
      TRACE("field::test:getter<" + support::demangle(typeid(T)) + ">");

      static T value;
      
      return value;
    }

    template <typename T>
    inline T
    setter(T const& a) 
    {
      TRACE("field::test:setter<" + support::demangle(typeid(T)) + ">");

      static T value;

      T const result(value);

      value = a;
      
      return result;
    }
    
    // functions, exported (extern)
  
  } // namespace test {

} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_TEST_SHARED_HPP)
