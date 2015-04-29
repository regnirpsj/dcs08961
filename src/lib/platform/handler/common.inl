// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/common.inl                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_COMMON_INL)

#define UKACHULLDCS_08961_PLATFORM_HANDLER_COMMON_INL

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

namespace platform {

  namespace handler {
  
    // functions, inlined (inline)

    template <typename T>
    inline void
    update_queue(std::deque<T>& q, T const& e, unsigned l)
    {
      TRACE("platform::handler::update_queue<" + support::demangle(typeid(T)) + ">");

      if (0 < l) {
        q.push_back(e);

        if (q.size() > l) {
          q.pop_front();
        }
      }
    }
    
  } // namespace handler {
  
} // namespace platform {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_COMMON_INL)
