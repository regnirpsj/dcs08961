// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/connection/transform.inl                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_TRANSFORM_INL)

#define UKACHULLDCS_08961_FIELD_CONNECTION_TRANSFORM_INL

// includes, system

//#include <>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace field {

  namespace connection {
    
    // functions, inlined (inline)

    template <typename T1, typename T2, typename C>
    inline /* explicit */
    transform<T1,T2,C>::transform(source_type const& a, destination_type& b, transform_type c,
                                  update_policy const& d)
      : simple<T1,T2>(a,b,d),
        transform_   (c)
    {
      TRACE("field::connection::transform<" +
            support::demangle(typeid(T1)) + "," + support::demangle(typeid(T2)) + "," +
            support::demangle(typeid(C)) + ">::transform");
    }
    
    template <typename T1, typename T2, typename C>
    inline /* virtual */
    transform<T1,T2,C>::~transform()
    {
      TRACE("field::connection::transform<" +
            support::demangle(typeid(T1)) + "," + support::demangle(typeid(T2)) + "," +
            support::demangle(typeid(C)) + ">::~transform");
    }
      
    template <typename T1, typename T2, typename C>
    inline /* virtual */ void
    transform<T1,T2,C>::update()
    {
      TRACE("field::connection::transform<" +
            support::demangle(typeid(T1)) + "," + support::demangle(typeid(T2)) + "," +
            support::demangle(typeid(C)) + ">::update");
      
      simple<T1,T2>::dst_.set(transform_(simple<T1,T2>::src_.get()));
    }
    
  } // namespace connection {
  
} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_TRANSFORM_INL)
