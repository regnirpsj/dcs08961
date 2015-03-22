// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/test/shared.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_EVENT_TEST_SHARED_HPP)

#define UKACHULLDCS_08961_EVENT_TEST_SHARED_HPP

// includes, system

//#include <>

// includes, project

#include <event/event/event.hpp>

#define UKACHULLDCS_USE_TRACE
//#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace event {

  namespace test {
    
    // types, exported (class, enum, struct, union, typedef)

    class simple : public event<simple> {

    public:

      explicit simple()
        : event<simple>()
      {
        TRACE("event::test::simple::simple(dflt)");
      }
    
      explicit simple(simple const& a)
        : event<simple>(a)
      {
        TRACE("event::test::simple::simple(cpy)");
      }
    
      explicit simple(simple const&& a)
        : event<simple>(std::move(a))
      {
        TRACE("event::test::simple::simple(mov)");
      }
    
      virtual void notify()
      {
        TRACE("event::test::simple::notify");
      }
    
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)

    base::time_stamp_type
    get_time()
    {
      return support::clock::now();
    }
    
    // functions, exported (extern)

  } // namespace test {
  
} // namespace event {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_EVENT_TEST_SHARED_HPP)
