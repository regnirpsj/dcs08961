// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  window/test/base.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

// #include <>

// includes, project

#include <window/base.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class derived : public window::base {

  public:

    explicit derived(std::string const a)
      : window::base(a)
    {
      TRACE("window::base::<unnamed>::derived::derived");
    }

    virtual ~derived()
    {
      TRACE("window::base::<unnamed>::derived::~derived");
    }
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_window_base_derived_ctor)
{
  {
    derived const w("stack alloc'd");
    
    BOOST_CHECK(&w);
    BOOST_MESSAGE(w);
  }

  {
    std::unique_ptr<window::base> const w(new derived("heap alloc'd"));
    
    BOOST_CHECK(w);
    BOOST_MESSAGE(*w);
  }
}
