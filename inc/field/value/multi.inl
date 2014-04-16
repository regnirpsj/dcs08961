// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/value/multi.inl                                                           */
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

    template <typename T, typename C>
    inline /* explicit */
    multi<T,C>::multi(container_type& a, std::string const& b, value_container_type const& c)
      : base(a, b), value_container_(c)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::multi(value_container_type)");
    }

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
    template <typename T, typename C>
    inline /* explicit */
    multi<T,C>::multi(container_type& a, std::string const& b, std::initializer_list<value_type> c)
      : base(a, b), value_container_(c)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::multi(std::initializer_list<" +
            support::demangle(typeid(T)) + ">)");
    }
#endif
    
    template <typename T, typename C>
    inline /* virtual */
    multi<T,C>::~multi()
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::~multi");
    }

    template <typename T, typename C>
    inline /* virtual */ void
    multi<T,C>::print_on(std::ostream& os) const
    {
      TRACE_NEVER("field::value::multi<" + support::demangle(typeid(T)) + "," +
                  support::demangle(typeid(C)) + ">::print_on");

      os << '[';

      base::print_on(os);

      using support::ostream::operator<<;
      
      os << ',' << value_container_ << "]";
    }
  
    template <typename T, typename C>
    inline typename multi<T,C>::value_container_type const&
    multi<T,C>::get() const
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::get(const)");

      return value_container_;
    }

    template <typename T, typename C>
    inline typename multi<T,C>::value_container_type&
    multi<T,C>::get()
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::get");

      return value_container_;
    }
    
    template <typename T, typename C>
    inline typename multi<T,C>::value_container_type
    multi<T,C>::set(value_container_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::set(value_container_type)");

      value_container_type const result(value_container_);
    
      value_container_ = a;

      changed();

      return result;
    }

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
    template <typename T, typename C>
    inline typename multi<T,C>::value_container_type
    multi<T,C>::set(std::initializer_list<value_type> a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::set" +
            "(std::initializer_list<" + support::demangle(typeid(T)) + ">)");

      value_container_type const result(value_container_);
    
      value_container_ = a;

      changed();

      return result;
    }
#endif
    
    template <typename T, typename C>
    inline bool
    multi<T,C>::add(value_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::add");

      bool       result(false);
      auto const found(std::find(value_container_.begin(), value_container_.end(), a));

      if (value_container_.end() == found) {
        value_container_.insert(value_container_.end(), a);

        changed();

        result = true;
      }

      return result;
    }
    
    template <typename T, typename C>
    inline bool
    multi<T,C>::sub(value_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::sub");

      bool       result(false);
      auto const found(std::find(value_container_.begin(), value_container_.end(), a));

      if (value_container_.end() != found) {
        value_container_.erase(found);
        
        changed();

        result = true;
      }

      return result;
    }

    template <typename T, typename C>
    inline multi<T,C>::operator /*multi<T,C>::*/value_container_type const& () const
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::operator value_container_type const&");

      return get();
    }

    template <typename T, typename C>
    inline multi<T,C>::operator /*multi<T,C>::*/value_container_type& ()
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::operator value_container_type&");

      return get();
    }
    
    template <typename T, typename C>
    inline multi<T,C>&
    multi<T,C>::operator=(value_container_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::operator=(value_container_type const&)");

      set(a);
      
      return *this;
    }

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
    template <typename T, typename C>
    inline multi<T,C>&
    multi<T,C>::operator=(std::initializer_list<value_type> a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::operator=(std::initializer_list<value_type>)");

      set(a);
      
      return *this;
    }
#endif
    
    template <typename T, typename C>
    inline multi<T,C>&
    multi<T,C>::operator+=(value_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::operator+=");

      add(a);
      
      return *this;
    }
    
    template <typename T, typename C>
    inline multi<T,C>&
    multi<T,C>::operator-=(value_type const& a)
    {
      TRACE("field::value::multi<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::operator-=");

      sub(a);
      
      return *this;
    }
    
  } // namespace value {

} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_VALUE_MULTI_INL)
