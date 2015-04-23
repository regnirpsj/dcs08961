// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/adapter/single.inl                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_SINGLE_INL)

#define UKACHULLDCS_08961_FIELD_ADAPTER_SINGLE_INL

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

  namespace adapter {
    
    // functions, inlined (inline)

    template <typename T>
    inline /* explicit */
    single<T>::single(container_type& a, std::string const& b,
                      get_callback_type c, set_callback_type d)
      : inherited (a, b),
        get_value_(c),
        set_value_(d)
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::single");
    }

    template <typename T>
    inline /* virtual */
    single<T>::~single()
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::~single");
    }
    
    template <typename T>
    inline /* virtual */ typename single<T>::value_type const&
    single<T>::get() const
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::get");

      return get_value_();
    }
    
    template <typename T>
    inline /* virtual */ typename single<T>::value_type
    single<T>::set(value_type const& a)
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::set");

      value_type const result(set_value_(a));

      inherited::changed();

      return result;
    }
    
  } // namespace adapter {

} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_SINGLE_INL)
