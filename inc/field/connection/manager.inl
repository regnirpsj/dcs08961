// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/connection/manager.inl                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_MANAGER_INL)

#define UKACHULLDCS_08961_FIELD_CONNECTION_MANAGER_INL

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
  
  // functions, inlined (inline)

  template <typename T1, typename T2>
  inline bool
  connect(T1* const a, T2* const b, std::function<void (T1* const, T2* const)> c)
  {
    TRACE("field::connect<" + support::demangle(typeid(T1)) + "," + support::demangle(typeid(T2)) +
          ">");

    return connection::manager::instance->connect(a, b, std::bind(c, a, b));
  }

  template <typename T>
  inline bool
  disconnect(T const* const a)
  {
    TRACE("field::disconnect<" + support::demangle(typeid(T)) + ">");
    
    return connection::manager::instance->disconnect(a);
  }
  
} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_MANAGER_INL)
