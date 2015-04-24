// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glx/test/window_manger.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <memory>         // std::unique_ptr<>

// includes, project

#include <platform/glx/io.hpp>
#include <platform/glx/window/manager.hpp>
#include <platform/glx/window/simple.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_glx_window_manager_count)
{
  using namespace platform::glx;
  
  std::unique_ptr<window::simple> s(new window::simple("test_platform_glx_window_manager_count"));
  
  BOOST_CHECK(s);
  BOOST_CHECK(1 == window::manager::count());
}

BOOST_AUTO_TEST_CASE(test_platform_glx_window_manager_all)
{
  using namespace platform::glx;
  
  std::unique_ptr<window::simple> s(new window::simple("test_platform_glx_window_manager_all"));
  
  BOOST_CHECK(s);
  
  std::vector<window::manager::id_type> const l(window::manager::all());
  
  BOOST_CHECK(1 == l.size());

  for(auto i : l) {
    std::ostringstream ostr;
    
    ostr << reinterpret_cast<GLXContext>(i);
    
    BOOST_MESSAGE(ostr.str() << '\n');
  }
}
