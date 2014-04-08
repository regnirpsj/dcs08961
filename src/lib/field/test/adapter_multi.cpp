// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/adapter_multi.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <field/adapter_multi.hpp>
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

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_multi_get, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>                     c;
  adapter::multi<typename T::value_type> const f(c, "f",
                                                 std::bind(&test::container_multi<T>::cb_get, c),
                                                 std::bind(&test::container_multi<T>::cb_set, c,
                                                           std::placeholders::_1),
                                                 std::bind(&test::container_multi<T>::cb_add, c,
                                                           std::placeholders::_1),
                                                 std::bind(&test::container_multi<T>::cb_sub, c,
                                                           std::placeholders::_1));

  BOOST_CHECK(T() == f.get());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_multi_set, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>               c;
  adapter::multi<typename T::value_type> f(c, "f",
                                           std::bind(&test::container_multi<T>::cb_get, c),
                                           std::bind(&test::container_multi<T>::cb_set, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_add, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_sub, c,
                                                     std::placeholders::_1));
  
  BOOST_CHECK(T() == f.set(T()));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_multi_add, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>               c;
  adapter::multi<typename T::value_type> f(c, "f",
                                           std::bind(&test::container_multi<T>::cb_get, c),
                                           std::bind(&test::container_multi<T>::cb_set, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_add, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_sub, c,
                                                     std::placeholders::_1));

  BOOST_CHECK(f.add(typename T::value_type()));
  
  BOOST_CHECK(1 == f.get().size());
  BOOST_MESSAGE(f.get().size());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_multi_sub, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>               c;
  adapter::multi<typename T::value_type> f(c, "f",
                                           std::bind(&test::container_multi<T>::cb_get, c),
                                           std::bind(&test::container_multi<T>::cb_set, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_add, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_sub, c,
                                                     std::placeholders::_1),
                                           T(2));

  BOOST_CHECK(f.sub(typename T::value_type()));
  BOOST_CHECK(1 == f.get().size());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_multi_set_initlist, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>               c;
  adapter::multi<typename T::value_type> f(c, "f",
                                           std::bind(&test::container_multi<T>::cb_get, c),
                                           std::bind(&test::container_multi<T>::cb_set, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_add, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_sub, c,
                                                     std::placeholders::_1));
  
  BOOST_CHECK(T() == f.set({ }));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_multi_op_convert, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>                     c;
  adapter::multi<typename T::value_type> const f(c, "f",
                                                 std::bind(&test::container_multi<T>::cb_get, c),
                                                 std::bind(&test::container_multi<T>::cb_set, c,
                                                           std::placeholders::_1),
                                                 std::bind(&test::container_multi<T>::cb_add, c,
                                                           std::placeholders::_1),
                                                 std::bind(&test::container_multi<T>::cb_sub, c,
                                                           std::placeholders::_1));

  BOOST_CHECK(T() == static_cast<T>(f));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_multi_op_assign, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>               c;
  adapter::multi<typename T::value_type> f(c, "f",
                                           std::bind(&test::container_multi<T>::cb_get, c),
                                           std::bind(&test::container_multi<T>::cb_set, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_add, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_sub, c,
                                                     std::placeholders::_1));
  
  BOOST_CHECK(T() == static_cast<T>(f = T()));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_multi_op_assign_initlist, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>               c;
  adapter::multi<typename T::value_type> f(c, "f",
                                           std::bind(&test::container_multi<T>::cb_get, c),
                                           std::bind(&test::container_multi<T>::cb_set, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_add, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_sub, c,
                                                     std::placeholders::_1));
  
  BOOST_CHECK(T() == static_cast<T>(f = { }));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_multi_op_add, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>               c;
  adapter::multi<typename T::value_type> f(c, "f",
                                           std::bind(&test::container_multi<T>::cb_get, c),
                                           std::bind(&test::container_multi<T>::cb_set, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_add, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_sub, c,
                                                     std::placeholders::_1));

  f += typename T::value_type();
  
  BOOST_CHECK(1 == f.get().size());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(adapter_multi_op_sub, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>               c;
  adapter::multi<typename T::value_type> f(c, "f",
                                           std::bind(&test::container_multi<T>::cb_get, c),
                                           std::bind(&test::container_multi<T>::cb_set, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_add, c,
                                                     std::placeholders::_1),
                                           std::bind(&test::container_multi<T>::cb_sub, c,
                                                     std::placeholders::_1),
                                           T(2));

  f -= typename T::value_type();
  
  BOOST_CHECK(1 == f.get().size());
}
