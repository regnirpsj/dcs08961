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

BOOST_AUTO_TEST_CASE(test_field_connection_manager_print)
{
  using namespace field;

  connection::manager::lease cml;
  
  BOOST_CHECK(&cml);

  {
    test::container_single<bool> c;
    value::single<bool>          f1(c, "f1");
    value::single<bool>          f2(c, "f2");
    value::single<bool>          f3(c, "f3");

    BOOST_CHECK( cml->connect(&f1, &f2));
    BOOST_CHECK(!cml->connect(&f1, &f2));
    BOOST_CHECK( cml->connect(&f1, &f3));

    cml->print_on(std::cout); std::cout << std::endl;
    
    {
      BOOST_CHECK(!cml->connect(&f3, &f3));
      
      value::single<bool> f4(c, "f4");
      
      BOOST_CHECK( cml->connect(&f3, &f4));
      BOOST_CHECK(!cml->connect(&f4, &f3));
      
      cml->print_on(std::cout); std::cout << std::endl;
    }

    cml->print_on(std::cout); std::cout << std::endl;
  }
  
  cml->print_on(std::cout); std::cout << std::endl;
}
