// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/connection_transform.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <field/connection/transform.hpp>
#include <field/value/multi.hpp>
#include <field/value/single.hpp>
#include <shared.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  template <typename T1, typename T2 = T1>
  class assign {

  public:

    T1 operator()(T2 const& a)
    {
      return a;
    }
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_connection_transform_single, T, field::test::single_types)
{
  using namespace field;
  
  test::container_single<T>               c;
  value::single<T> const                  f1(c, "f1");
  value::single<T>                        f2(c, "f2");

  typedef value::single<T> field_type;
  typedef assign<T>        xform_type;
  
  connection::transform<field_type,field_type,xform_type> r(f1, f2, xform_type());

  r.update();
  
  BOOST_CHECK(f2.get() == f1.get());
  BOOST_MESSAGE(r);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_connection_transform_multi, T, field::test::multi_types)
{
  using namespace field;
  
  test::container_multi<T>               c;
  value::multi<T> const                  f1(c, "f1");
  value::multi<T>                        f2(c, "f2");

  typedef value::multi<T>                                   field_type;
  typedef assign<typename field_type::value_container_type> xform_type;
  
  connection::transform<field_type,field_type,xform_type> r(f1, f2, xform_type());

  r.update();
  
  BOOST_CHECK(f2.get() == f1.get());
  BOOST_MESSAGE(r);
}
