// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/adapter_multi.inl                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_MULTI_INL)

#define UKACHULLDCS_08961_FIELD_ADAPTER_MULTI_INL

// includes, system

#include <ostream> // std::ostream

// includes, project

#include <support/io_utils.hpp>

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
    multi<T>::multi(container_type& a, std::string const& b,
                    get_callback_type c, set_callback_type d,
                    add_callback_type e, sub_callback_type f,
                    value_container_type const& g)
      : base(a, b), get_value_(c), set_value_(d), add_value_(e), sub_value_(f)
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) +
            ">::multi(value_container_type)");

      set_value_(g);
    }

    template <typename T>
    inline /* explicit */
    multi<T>::multi(container_type& a, std::string const& b,
                    get_callback_type c, set_callback_type d,
                    add_callback_type e, sub_callback_type f,
                    std::initializer_list<value_type> g)
      : base(a, b), get_value_(c), set_value_(d), add_value_(e), sub_value_(f)
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) +
            ">::multi(std::initializer_list<" + support::demangle(typeid(T)) + ">)");

      set_value_(g);
    }

    template <typename T>
    inline /* virtual */
    multi<T>::~multi()
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) + ">::~multi");
    }

    template <typename T>
    inline /* virtual */ void
    multi<T>::print_on(std::ostream& os) const
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) + ">::print_on");

      os << '[';

      base::print_on(os);

      using support::ostream::operator<<;
      
      os << ',' << get_value_() << "]";
    }
    
    template <typename T>
    inline typename multi<T>::value_container_type const&
    multi<T>::get() const
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) + ">::get");

      return get_value_();
    }
  
    template <typename T>
    inline typename multi<T>::value_container_type
    multi<T>::set(value_container_type const& a)
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) +
            ">::set(value_container_type)");

      value_container_type const result(set_value_(a));

      changed();

      return result;
    }

    template <typename T>
    inline typename multi<T>::value_container_type
    multi<T>::set(std::initializer_list<value_type> a)
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) +
            ">::set(std::initializer_list<" + support::demangle(typeid(T)) + ">)");

      value_container_type const result(set_value_(a));

      changed();

      return result;
    }
  
    template <typename T>
    inline bool
    multi<T>::add(value_type const& a)
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) + ">::add");

      bool const result(add_value_(a));

      if (result) {
        changed();
      }

      return result;
    }
    
    template <typename T>
    inline bool
    multi<T>::sub(value_type const& a)
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) + ">::sub");

      bool const result(sub_value_(a));

      if (result) {
        changed();
      }

      return result;
    }

    template <typename T>
    inline multi<T>::operator multi<T>::value_container_type const& () const
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) + ">::operator " +
            "value_container_type const&");

      return get();
    }
    
    template <typename T>
    inline multi<T>&
    multi<T>::operator=(value_container_type const& a)
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) + ">::operator=" +
            "(value_container_type const&)");

      set(a);
      
      return *this;
    }
    
    template <typename T>
    inline multi<T>&
    multi<T>::operator=(std::initializer_list<value_type> a)
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) + ">::operator=" +
            "(std::initializer_list<value_type>)");

      set(a);
      
      return *this;
    }
    
    template <typename T>
    inline multi<T>&
    multi<T>::operator+=(value_type const& a)
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) + ">::operator+=");

      add(a);
      
      return *this;
    }
    
    template <typename T>
    inline multi<T>&
    multi<T>::operator-=(value_type const& a)
    {
      TRACE("field::adapter::multi<" + support::demangle(typeid(T)) + ">::operator-=");

      sub(a);
      
      return *this;
    }

  } // namespace adapter {
  
} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_ADAPTER_MULTI_INL)
