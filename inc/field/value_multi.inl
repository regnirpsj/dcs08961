// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/value_multi.inl                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_VALUE_MULTI_INL)

#define UKACHULLDCS_08961_FIELD_VALUE_MULTI_INL

// includes, system

#include <algorithm> // std::find<>
#include <ostream>   // std::ostream

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

  namespace value {
    
    // functions, inlined (inline)

    template <typename T>
    inline /* explicit */
    multi<T>::multi(container_type& a, std::string const& b, value_container_type const& c)
      : base(a, b), value_container_(c)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) +
            ">::multi(value_container_type)");
    }

    template <typename T>
    inline /* explicit */
    multi<T>::multi(container_type& a, std::string const& b, std::initializer_list<value_type> c)
      : base(a, b), value_container_(c)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) +
            ">::multi(std::initializer_list<" + support::demangle(typeid(T)) + ">)");
    }
  
    template <typename T>
    inline /* virtual */
    multi<T>::~multi()
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + ">::~multi");
    }

    template <typename T>
    inline /* virtual */ void
    multi<T>::print_on(std::ostream& os) const
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + ">::print_on");

      os << '[';

      base::print_on(os);

      using support::ostream::operator<<;
      
      os << ',' << value_container_ << "]";
    }
  
    template <typename T>
    inline typename multi<T>::value_container_type const&
    multi<T>::get() const
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + ">::get");

      return value_container_;
    }
  
    template <typename T>
    inline typename multi<T>::value_container_type
    multi<T>::set(value_container_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + ">::set(value_container_type)");

      value_container_type const result(value_container_);
    
      value_container_ = a;

      changed();

      return result;
    }

    template <typename T>
    inline typename multi<T>::value_container_type
    multi<T>::set(std::initializer_list<value_type> a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + ">::set" +
            "(std::initializer_list<" + support::demangle(typeid(T)) + ">)");

      value_container_type const result(value_container_);
    
      value_container_ = a;

      changed();

      return result;
    }
  
    template <typename T>
    inline bool
    multi<T>::add(value_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + ">::add");

      bool       result(false);
      auto const found(std::find(value_container_.begin(), value_container_.end(), a));

      if (value_container_.end() == found) {
        value_container_.push_back(a);

        changed();

        result = true;
      }

      return result;
    }
    
    template <typename T>
    inline bool
    multi<T>::sub(value_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + ">::sub");

      bool       result(false);
      auto const found(std::find(value_container_.begin(), value_container_.end(), a));

      if (value_container_.end() != found) {
        value_container_.erase(found);
        
        changed();

        result = true;
      }

      return result;
    }

    template <typename T>
    inline multi<T>::operator multi<T>::value_container_type const& () const
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) +
            ">::operator value_container_type const&");

      return get();
    }
    
    template <typename T>
    inline multi<T>&
    multi<T>::operator=(value_container_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) +
            ">::operator=(value_container_type const&)");

      set(a);
      
      return *this;
    }
    
    template <typename T>
    inline multi<T>&
    multi<T>::operator=(std::initializer_list<value_type> a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) +
            ">::operator=(std::initializer_list<value_type>)");

      set(a);
      
      return *this;
    }
    
    template <typename T>
    inline multi<T>&
    multi<T>::operator+=(value_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + ">::operator+=");

      add(a);
      
      return *this;
    }
    
    template <typename T>
    inline multi<T>&
    multi<T>::operator-=(value_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + ">::operator-=");

      sub(a);
      
      return *this;
    }
    
  } // namespace value {

} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_VALUE_MULTI_INL)
