// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/value_single.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <field/value/single.hpp>
#include <shared.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_value_single_container, T, field::test::single_types)
{
  using namespace field;
  
  test::container_single<T> c;
  value::single<T> const    f(c, "f");

  BOOST_CHECK(&c == &f.container());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_value_single_name, T, field::test::single_types)
{
  using namespace field;
  
  test::container_single<T> c;
  value::single<T> const    f(c, "f");

  BOOST_CHECK("f" == f.name());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_value_single_last_change, T, field::test::single_types)
{
  using namespace field;
  
  test::container_single<T> c;
  value::single<T> const    f(c, "f");

  BOOST_CHECK(support::clock::now() > f.last_change());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_value_single_get, T, field::test::single_types)
{
  using namespace field;
  
  test::container_single<T> c;
  value::single<T> const    f(c, "f");

  BOOST_CHECK(T() == f.get());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_value_single_set, T, field::test::single_types)
{
  using namespace field;
  
  test::container_single<T> c;
  value::single<T>          f(c, "f");
  
  BOOST_CHECK(T() == f.set(T()));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_value_single_op_dereference, T, field::test::single_types)
{
  using namespace field;
  
  test::container_single<T> c;
  value::single<T> const    f(c, "f");

  BOOST_CHECK(T() == *f);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_value_single_op_assign, T, field::test::single_types)
{
  using namespace field;
  
  test::container_single<T> c;
  value::single<T>          f(c, "f");
  
  BOOST_CHECK(T() == *(f = T()));
}
