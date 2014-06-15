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

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp> 
using boost::test_tools::output_test_stream;

BOOST_AUTO_TEST_CASE(test_field_connection_manager_print)
{
  using namespace field;

  connection::manager::lease cml;
  
  BOOST_CHECK(&cml);
  BOOST_MESSAGE(cml->status());
  
  {
    test::container_single<bool> c;
    value::single<bool>          f1(c, "f1");
    value::single<bool>          f2(c, "f2");
    value::single<bool>          f3(c, "f3");

    BOOST_CHECK( connect(&f1, &f2));
    BOOST_CHECK(!connect(&f1, &f2));
    BOOST_CHECK( connect(&f1, &f3));

    f1.touch();
    
    BOOST_MESSAGE(cml->status());
    
    {
      BOOST_CHECK(!connect(&f3, &f3));
      
      value::single<bool> f4(c, "f4");
      
      BOOST_CHECK( connect(&f3, &f4));
      BOOST_CHECK(!connect(&f4, &f3));

      test::container_single<float> cf;
      value::single<float>          f5(cf, "f5");

      BOOST_CHECK( connect(&f5, &f3));
      BOOST_CHECK(!connect(&f3, &f5));

      f3.touch();
      f5.touch();
      
      BOOST_MESSAGE(cml->status());
    }

    {
      test::container_single<float> cf;
      value::multi<float>           f6(cf, "f6");

      std::function<void (value::multi<float>* const, value::single<bool>* const)> upd_f6_f3 =
        connection::update::average<value::multi<float>,value::single<bool>>;
      
      BOOST_CHECK( connect(&f6, &f3, upd_f6_f3));

      std::function<void (value::single<bool>* const, value::multi<float>* const)> upd_f3_f6 =
                    connection::update::append<value::single<bool>,value::multi<float>>;
      
      BOOST_CHECK(!connect(&f3, &f6, upd_f3_f6));

      f6.touch();
      
      BOOST_MESSAGE(cml->status());
    }

    BOOST_MESSAGE(cml->status());
  }
  
  BOOST_MESSAGE(cml->status());
}
