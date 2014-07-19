// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/test/glut.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

//#include <>

#include "../glut.hpp"

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class application : public glut::application {

  public:

    void display()
    {
    }

    void reshape(glm::ivec2 const&)
    {
    }
    
  } instance;
  
  // variables, internal
  
  // functions, internal

} // namespace {

// functions, exported

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_app_common_glut_application_instance)
{
  BOOST_CHECK(application::instance());
}

BOOST_AUTO_TEST_CASE(test_app_common_glut_application_run)
{
  int   argc(1);
  char* argv[] = { "dummy" };
  
  BOOST_CHECK(EXIT_SUCCESS == application::exception_handled(argc, argv));
}
