// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/connection_simple.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <field/connection/simple.hpp>
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

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_connection_simple_single, T, field::test::single_types)
{
  using namespace field;

  {
    test::container_single<T>            c;
    value::single<T> const               f1(c, "f1");
    value::single<T>                     f2(c, "f2");
    connection::simple<value::single<T>> r (f1, f2);

    r.update();
  
    BOOST_CHECK(f2.get() == f1.get());
    BOOST_MESSAGE(&r << ':' << r);
  }

  {
    test::container_single<T> c;
    value::single<T>          f1(c, "f1");
    value::single<T>          f2(c, "f2");

    typedef connection::simple<value::single<T>> connection_type;

    connection_type* r(new connection_type(f1, f2));
    
    BOOST_CHECK(f1.connection_add(r));
    BOOST_CHECK(!f1.connection_add(r));
    
    f1.touch();
    
    BOOST_CHECK(f2.get() == f1.get());

    BOOST_MESSAGE(r << ':' << *r);

    BOOST_CHECK(f1.connection_sub(r));

    delete r;
  }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_connection_simple_multi, T, field::test::multi_types)
{
  using namespace field;

  {
    test::container_multi<T>            c;
    value::multi<T> const               f1(c, "f1");
    value::multi<T>                     f2(c, "f2");
    connection::simple<value::multi<T>> r (f1, f2);

    r.update();
  
    BOOST_CHECK(f2.get() == f1.get());
    BOOST_MESSAGE(&r << ':' << r);
  }

  {
    test::container_multi<T> c;
    value::multi<T>          f1(c, "f1");
    value::multi<T>          f2(c, "f2");

    typedef connection::simple<value::multi<T>> connection_type;

    connection_type* r(new connection_type(f1, f2));
    
    BOOST_CHECK(f1.connection_add(r));
    BOOST_CHECK(!f1.connection_add(r));
    
    f1.touch();
    
    BOOST_CHECK(f2.get() == f1.get());

    BOOST_MESSAGE(r << ':' << *r);

    BOOST_CHECK(f1.connection_sub(r));

    delete r;
  }
}
