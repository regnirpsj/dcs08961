// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/connection_update.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <field/connection/update.hpp>
#include <field/value/multi.hpp>
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

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_connection_update_single, T, field::test::single_types)
{
  using namespace field;

  typedef test::container_single<T> container_type;
  typedef value::single<T>          field_type;

  container_type c;
  field_type     f(c, "f");

  BOOST_CHECK(T() == f.get());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_connection_update_multi, T, field::test::multi_types)
{
  using namespace field;

  typedef test::container_multi<T> container_type;
  typedef value::multi<T>          field_type;

  container_type c;
  field_type     f(c, "f");

  BOOST_CHECK(0 == f.get().size());
}
