// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/adapter_single.inl                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_SINGLE_INL)

#define UKACHULLDCS_08961_FIELD_ADAPTER_SINGLE_INL

// includes, system

#include <ostream> // std::ostream

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
                      get_callback_type c, set_callback_type d,
                      value_type const& e)
      : base(a, b), get_value_(c), set_value_(d)
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::single");

      set_value_(e);
    }

    template <typename T>
    inline /* virtual */
    single<T>::~single()
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::single");
    }

    template <typename T>
    inline /* virtual */ void
    single<T>::print_on(std::ostream& os) const
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::print_on");

      os << '[';
      
      base::print_on(os);
      
      os << ',' << get_value_() << ']';
    }
    
    template <typename T>
    inline typename single<T>::value_type const&
    single<T>::get() const
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::get");

      return get_value_();
    }

    template <typename T>
    inline typename single<T>::value_type
    single<T>::set(value_type const& a)
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::set");

      value_type const result(set_value_(a));

      changed();

      return result;
    }

    template <typename T>
    inline single<T>::operator single<T>::value_type const& () const
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::operator " +
            "value_type const&");
      
      return get();
    }

    template <typename T>
    inline single<T>&
    single<T>::operator=(value_type const& a)
    {
      TRACE("field::adapter::single<" + support::demangle(typeid(T)) + ">::operator=");

      set(a);
      
      return *this;
    }
    
  } // namespace adapter {

} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_SINGLE_INL)
