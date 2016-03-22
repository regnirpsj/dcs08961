// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/base.inl                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_EVENT_BASE_INL)

#define UKACHULLDCS_08961_EVENT_BASE_INL

// includes, system

#include <stdexcept> // std::logic_error

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if 1 // defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace event {

  template <typename T>
  /* static */ typename base<T>::time_source_function_type
  base<T>::time_source_ = &support::clock::now;
  
  // functions, inlined (inline)

  template <typename T>
  inline /* static */ typename base<T>::time_source_function_type
  base<T>::time_source()
  {
    TRACE("event::base<" + support::demangle(typeid(T)) + ">::time_source(get)");
    
    return time_source_;
  }
    
  template <typename T>
  inline /* static */ typename base<T>::time_source_function_type
  base<T>::time_source(time_source_function_type a)
  {
    TRACE("event::base<" + support::demangle(typeid(T)) + ">::time_source(set)");
    
    time_source_function_type const result(time_source_);
    
    time_source_ = a;
    
    return result;
  }
  
  template <typename T>
  inline /* virtual */
  base<T>::~base()
  {
    TRACE("event::base<" + support::demangle(typeid(T)) + ">::~base");
  }

  template <typename T>
  inline typename base<T>::time_point const&
  base<T>::stamp() const
  {
    TRACE("event::base<" + support::demangle(typeid(T)) + ">::stamp");
    
    return stamp_;
  }

  template <typename T>
  inline /* explicit */
  base<T>::base(bool a)
    : stamp_(time_source_()),
      async_(a)
  {
    TRACE("event::base<" + support::demangle(typeid(T)) + ">::base(dflt)");
  }
    
  template <typename T>
  inline /* explicit */
  base<T>::base(base const& a)
    : stamp_(a.stamp_),
      async_(a.async_)
  {
    TRACE("event::base<" + support::demangle(typeid(T)) + ">::base(cpy)");
  }

  template <typename T>
  inline void
  base<T>::operator=(base const&)
  {
    TRACE("event::base<" + support::demangle(typeid(T)) + ">::operator=");

    throw std::logic_error("unimplemented function 'event::base<" + support::demangle(typeid(T)) +
                           ">::operator=' called");
  }

  template <typename T>
  inline /* virtual */
  async<T>::~async() 
  {
    TRACE("event::async<" + support::demangle(typeid(T)) + ">::~async");
  }

  template <typename T>
  inline /* explicit */
  async<T>::async()
    : base<T>(true)
  {
    TRACE("event::async<" + support::demangle(typeid(T)) + ">::async");
  }

  template <typename T>
  inline /* virtual */
  sync<T>::~sync() 
  {
    TRACE("event::sync<" + support::demangle(typeid(T)) + ">::~sync");
  }

  template <typename T>
  inline /* explicit */
  sync<T>::sync()
    : base<T>(true)
  {
    TRACE("event::sync<" + support::demangle(typeid(T)) + ">::sync");
  }
  
} // namespace event {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_EVENT_BASE_INL)
