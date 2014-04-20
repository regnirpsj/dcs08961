// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/single/base.inl                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_SINGLE_BASE_INL)

#define UKACHULLDCS_08961_FIELD_SINGLE_BASE_INL

// includes, system

#include <stdexcept> // std::logic_error
#include <typeinfo>

// includes, project

#include <support/type_info.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

namespace field {

  namespace single {
  
    // functions, inlined (inline)

    template <typename T>
    inline /* virtual */ void
    base<T>::print_on(std::ostream& os) const
    {
      TRACE("field::single::base::<" + support::demangle(typeid(T)) + ">::print_on");

      os << '[';

      inherited::print_on(os);

      os << ',' << get() << ']';
    }

    template <typename T>
    inline /* virtual */ typename base<T>::value_type const&
    base<T>::get() const
    {
      TRACE("field::single::base::<" + support::demangle(typeid(T)) + ">::get");

      throw std::logic_error("pure virtual function 'field::single::base::<" +
                             support::demangle(typeid(T)) + ">::get' called");
    }

    template <typename T>
    inline /* virtual */ typename base<T>::value_type
    base<T>::set(value_type const&)
    {
      TRACE("field::single::base::<" + support::demangle(typeid(T)) + ">::set");

      throw std::logic_error("pure virtual function 'field::single::base::<" +
                             support::demangle(typeid(T)) + ">::set' called");
    }

    template <typename T>
    inline typename base<T>::value_type const&
    base<T>::operator*() const
    {
      TRACE("field::single::base::<" + support::demangle(typeid(T)) + ">::operator*");

      return get();
    }

    template <typename T>
    inline base<T>&
    base<T>::operator=(value_type const& a)
    {
      TRACE("field::single::base::<" + support::demangle(typeid(T)) + ">::operator=");

      set(a);

      return *this;
    }

    template <typename T>
    inline /* explicit */
    base<T>::base(container_type& a, std::string const& b)
      : inherited(a, b)
    {
      TRACE("field::single::base::<" + support::demangle(typeid(T)) + ">::base");
    }
    
  } // namespace single {
  
} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_SINGLE_BASE_INL)
