// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/connection_manager.cpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

// #include <>

// includes, project

#include <field/connection/manager.hpp>
#include <field/container.hpp>
#include <field/value/multi.hpp>
#include <field/value/single.hpp>
#include <shared.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)  
  
  // variables, internal
  
  // functions, internal

  template <typename T1, typename T2>
  std::function<void (T1* const, T2* const)>
  make_function(T1 const&, T2 const&, void (*f)(T1* const, T2* const))
  {
    return f;
  }
  
} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_field_connection_manager_print)
{
  using namespace field;

  connection::manager::lease cml;
  
  BOOST_CHECK(&cml);
  BOOST_TEST_MESSAGE(cml->status());
  
  {
    test::container_single<unsigned> c;
    value::single<unsigned>          f1(c, "f1");
    value::single<signed>            f2(c, "f2");
    value::single<unsigned>          f3(c, "f3");

    BOOST_CHECK( connect(&f1, &f2));
    BOOST_CHECK(!connect(&f1, &f2));
    BOOST_CHECK( connect(&f1, &f3));

    f1.touch();
    
    BOOST_TEST_MESSAGE(cml->status());
    
    {
      BOOST_CHECK(!connect(&f3, &f3));
      
      value::single<unsigned> f4(c, "f4");
      
      BOOST_CHECK( connect(&f3, &f4));
      BOOST_CHECK(!connect(&f4, &f3));

      test::container_single<float> cf;
      value::single<float>          f5(cf, "f5");

      BOOST_CHECK( connect(&f5, &f3));
      BOOST_CHECK(!connect(&f3, &f5));

      f3.touch();
      f5.touch();
      
      BOOST_TEST_MESSAGE(cml->status());
    }

    {
      using connection::update::average;
      using connection::update::append;
      
      test::container_single<float> cf;
      value::multi<float>           f6(cf, "f6");
      
      BOOST_CHECK( connect(&f6, &f3, make_function(f6, f3, average)));
      BOOST_CHECK(!connect(&f3, &f6, make_function(f3, f6, append)));

      f6.touch();
      
      BOOST_TEST_MESSAGE(cml->status());
    }

    BOOST_TEST_MESSAGE(cml->status());
  }
  
  BOOST_TEST_MESSAGE(cml->status());
}
