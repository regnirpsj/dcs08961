// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/connection/update.inl                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_UPDATE_INL)

#define UKACHULLDCS_08961_FIELD_CONNECTION_UPDATE_INL

// includes, system

#include <numeric> // std::accumulate

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

  namespace connection {

    namespace update {
      
      // functions, inlined (inline)

      template <typename T1, typename T2>
      inline void
      assign(T1* const s, T2* const d)
      {
        TRACE("field::connection::update::assign<" + support::demangle(typeid(T1)) + "," +
              support::demangle(typeid(T2)) + ">");
        
        d->set(s->get());
      }

      template <typename T1, typename T2>
      inline void
      average(T1* const s, T2* const d)
      {
        TRACE("field::connection::update::average<" + support::demangle(typeid(T1)) + "," +
              support::demangle(typeid(T2)) + ">");

        if (!s->get().empty()) {
          d->set(std::accumulate(s->get().begin(), s->get().end(), typename T1::value_type()) /
                 s->get().size());
        } else {
          d->set(typename T1::value_type());
        }
      }
      
      template <typename T1, typename T2>
      inline void
      append(T1* const s, T2* const d)
      {
        TRACE("field::connection::update::append<" + support::demangle(typeid(T1)) + "," +
              support::demangle(typeid(T2)) + ">");
        
        d->add(s->get());
      }

      template <typename T1, typename T2>
      inline void
      prepend(T1* const s, T2* const d)
      {
        TRACE("field::connection::update::prepend<" + support::demangle(typeid(T1)) + "," +
              support::demangle(typeid(T2)) + ">");
        
        typename T2::value_container_type tmp(d->get());

        tmp.insert(s->get(), tmp.begin());

        d->set(tmp);
      }
      
    } // namespace update {
    
  } // namespace connection {
  
} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_UPDATE_INL)
