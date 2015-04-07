// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/multi/base.inl                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_MULTI_BASE_INL)

#define UKACHULLDCS_08961_FIELD_MULTI_BASE_INL

// includes, system

#include <stdexcept> // std::logic_error
#include <typeinfo>

// includes, project

#include <support/io_utils.hpp>
#include <support/type_info.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

namespace field {

  namespace multi {
  
    // functions, inlined (inline)

    template <typename T, typename C>
    inline /* virtual */ void
    base<T,C>::print_on(std::ostream& os) const
    {
      TRACE_NEVER("field::multi::base::<" + support::demangle(typeid(T)) + "," +
                  support::demangle(typeid(C)) + ">::print_on");

      os << '[';

      inherited::print_on(os);

      using support::ostream::operator<<;
      
      os << ',' << get() << ']';
    }

    template <typename T, typename C>
    inline /* virtual */ typename base<T,C>::value_container_type const&
    base<T,C>::get() const
    {
      TRACE("field::multi::base::<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::get");

      throw std::logic_error("pure virtual function 'field::multi::base::<" +
                             support::demangle(typeid(T)) + "," +
                             support::demangle(typeid(C)) + ">::get' called");
    }

    template <typename T, typename C>
    inline /* virtual */ typename base<T,C>::value_container_type
    base<T,C>::set(value_container_type const&)
    {
      TRACE("field::multi::base::<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::set");

      throw std::logic_error("pure virtual function 'field::multi::base::<" +
                             support::demangle(typeid(T)) + "," +
                             support::demangle(typeid(C)) + ">::set(" +
                             support::demangle(typeid(T)) + " const&)' called");
    }

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
    template <typename T, typename C>
    inline /* virtual */ typename base<T,C>::value_container_type
    base<T,C>::set(std::initializer_list<value_type>)
    {
      TRACE("field::multi::base::<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::set");

      throw std::logic_error("pure virtual function 'field::multi::base::<" +
                             support::demangle(typeid(T)) + "," +
                             support::demangle(typeid(C)) + ">::set(std::initializer_list<" +
                             support::demangle(typeid(T)) + ">)' called");
    }
#endif
    
    template <typename T, typename C>
    inline /* virtual */ bool
    base<T,C>::add(value_type const&)
    {
      TRACE("field::multi::base::<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::add");

      throw std::logic_error("pure virtual function 'field::multi::base::<" +
                             support::demangle(typeid(T)) + "," +
                             support::demangle(typeid(C)) + ">::add' called");
    }
    
    template <typename T, typename C>
    inline /* virtual */ bool
    base<T,C>::sub(value_type const&)
    {
      TRACE("field::multi::base::<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::sub");

      throw std::logic_error("pure virtual function 'field::multi::base::<" +
                             support::demangle(typeid(T)) + "," +
                             support::demangle(typeid(C)) + ">::sub' called");
    }

    template <typename T, typename C>
    inline typename base<T,C>::value_container_type const&
    base<T,C>::operator*() const
    {
      TRACE_NEVER("field::multi::base::<" + support::demangle(typeid(T)) + "," +
                  support::demangle(typeid(C)) + ">::operator*");

      return get();
    }

    template <typename T, typename C>
    inline typename base<T,C>::value_container_type const*
    base<T,C>::operator->() const
    {
      TRACE_NEVER("field::multi::base::<" + support::demangle(typeid(T)) + "," +
                  support::demangle(typeid(C)) + ">::operator->");

      return &(get());
    }
    
    template <typename T, typename C>
    inline base<T,C>&
    base<T,C>::operator=(value_container_type const& a)
    {
      TRACE_NEVER("field::multi::base::<" + support::demangle(typeid(T)) + "," +
                  support::demangle(typeid(C)) + ">::operator=(" + support::demangle(typeid(T)) +
                  " const&)");

      set(a);

      return *this;
    }

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
    template <typename T, typename C>
    inline base<T,C>&
    base<T,C>::operator=(std::initializer_list<value_type> a)
    {
      TRACE_NEVER("field::multi::base::<" + support::demangle(typeid(T)) + "," +
                  support::demangle(typeid(C)) + ">::operator=(" +
                  ">::operator=(std::initializer_list<" + support::demangle(typeid(T)) + ">)");

      set(a);

      return *this;
    }
#endif
    
    template <typename T, typename C>
    inline base<T,C>&
    base<T,C>::operator+=(value_type const& a)
    {
      TRACE_NEVER("field::multi::base::<" + support::demangle(typeid(T)) + "," +
                  support::demangle(typeid(C)) + ">::operator+=");

      add(a);

      return *this;
    }
    
    template <typename T, typename C>
    inline base<T,C>&
    base<T,C>::operator-=(value_type const& a)
    {
      TRACE_NEVER("field::multi::base::<" + support::demangle(typeid(T)) + "," +
                  support::demangle(typeid(C)) + ">::operator-=");

      sub(a);

      return *this;
    }

    template <typename T, typename C>
    inline /* explicit */
    base<T,C>::base(container_type& a, std::string const& b)
      : inherited(a, b)
    {
      TRACE("field::multi::base::<" + support::demangle(typeid(T)) + "," +
            support::demangle(typeid(C)) + ">::base");
    }
    
  } // namespace multi {
  
} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_MULTI_BASE_INL)
