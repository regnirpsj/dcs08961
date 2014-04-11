// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/value_single.inl                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_VALUE_SINGLE_INL)

#define UKACHULLDCS_08961_FIELD_VALUE_SINGLE_INL

// includes, system

#include <ostream> // std::ostream

// includes, project

// #include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace field {

  namespace value {
    
    // functions, inlined (inline)

    template <typename T>
    inline /* explicit */
    single<T>::single(container_type& a, std::string const& b, value_type const& c)
      : base(a, b), value_(c)
    {
      TRACE("field::value::single<" + support::demangle(typeid(T)) + ">::single");
    }

    template <typename T>
    inline /* virtual */
    single<T>::~single()
    {
      TRACE("field::value::single<" + support::demangle(typeid(T)) + ">::~single");
    }

    template <typename T>
    inline /* virtual */ void
    single<T>::print_on(std::ostream& os) const
    {
      TRACE_NEVER("field::value::single<" + support::demangle(typeid(T)) + ">::print_on");

      os << '[';

      base::print_on(os);

      os << ',' << value_ << ']';
    }
  
    template <typename T>
    inline typename single<T>::value_type const&
    single<T>::get() const
    {
      TRACE("field::value::single<" + support::demangle(typeid(T)) + ">::get(const)");
    
      return value_;
    }

    template <typename T>
    inline typename single<T>::value_type&
    single<T>::get()
    {
      TRACE("field::value::single<" + support::demangle(typeid(T)) + ">::get");
    
      return value_;
    }
    
    template <typename T>
    inline typename single<T>::value_type
    single<T>::set(value_type const& a)
    {
      TRACE("field::value::single<" + support::demangle(typeid(T)) + ">::set");

      value_type const result(value_);
    
      value_ = a;

      changed();

      return result;
    }

    template <typename T>
    inline single<T>::operator single<T>::value_type const& () const
    {
      TRACE("field::value::single<" + support::demangle(typeid(T)) + ">::operator " +
            "value_type const&");
      
      return get();
    }

    template <typename T>
    inline single<T>::operator single<T>::value_type& ()
    {
      TRACE("field::value::single<" + support::demangle(typeid(T)) + ">::operator " +
            "value_type&");
      
      return get();
    }
    
    template <typename T>
    inline single<T>&
    single<T>::operator=(value_type const& a)
    {
      TRACE("field::value::single<" + support::demangle(typeid(T)) + ">::operator=");

      set(a);
      
      return *this;
    }
    
  } // namespace value {
  
} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_VALUE_SINGLE_INL)
