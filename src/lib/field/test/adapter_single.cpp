// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/adapter_single.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <field/adapter_single.hpp>
#include <shared.hpp>

// internal unnamed namespace

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_single_get, T, field::test::types)
{
  TRACE("adapter_single_get<" + support::demangle(typeid(T)) + ">");
  
  field::test::container          c;
  field::adapter::single<T> const f(c, "f",
                                    std::bind(field::test::getter<T>),
                                    std::bind(field::test::setter<T>, std::placeholders::_1));

  BOOST_CHECK(T() == f.get());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_single_set, T, field::test::types)
{
  TRACE("adapter_single_set<" + support::demangle(typeid(T)) + ">");
  
  field::test::container    c;
  field::adapter::single<T> f(c, "f",
                              std::bind(field::test::getter<T>),
                              std::bind(field::test::setter<T>, std::placeholders::_1));
  
  BOOST_CHECK(T() == f.set(T()));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_single_op_convert, T, field::test::types)
{
  TRACE("adapter_single_op_convert<" + support::demangle(typeid(T)) + ">");
  
  field::test::container          c;
  field::adapter::single<T> const f(c, "f",
                                    std::bind(field::test::getter<T>),
                                    std::bind(field::test::setter<T>, std::placeholders::_1));

  BOOST_CHECK(T() == static_cast<T>(f));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_single_op_assign, T, field::test::types)
{
  TRACE("adapter_single_op_assign<" + support::demangle(typeid(T)) + ">");
  
  field::test::container    c;
  field::adapter::single<T> f(c, "f",
                              std::bind(field::test::getter<T>),
                              std::bind(field::test::setter<T>, std::placeholders::_1));
  
  BOOST_CHECK(T() == static_cast<T>(f = T()));
}
