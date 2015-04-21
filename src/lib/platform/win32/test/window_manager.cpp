// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/test/window_manger.cpp                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <memory>         // std::unique_ptr<>

// includes, project

#include <platform/win32/io.hpp>
#include <platform/win32/window/manager.hpp>
#include <platform/win32/window/simple.hpp>
#include <support/io_utils.hpp>

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

BOOST_AUTO_TEST_CASE(test_platform_win32_window_manager_count)
{
  using namespace platform::win32;
  
  std::unique_ptr<window::simple> s(new window::simple("test_platform_win32_window_manager_count"));
  
  BOOST_CHECK(s);
  BOOST_CHECK(1 == window::manager::count());
}

BOOST_AUTO_TEST_CASE(test_platform_win32_window_manager_all)
{
  using namespace platform::win32;
  
  std::unique_ptr<window::simple> s(new window::simple("test_platform_win32_window_manager_all"));
  
  BOOST_CHECK(s);
  
  std::vector<signed> const l(window::manager::all());
  
  BOOST_CHECK(1 == l.size());
  
  for(auto i : l) {
    std::ostringstream ostr;
    
    ostr << reinterpret_cast<HWND>(i);
    
    BOOST_MESSAGE(ostr.str() << '\n');
  }
}

BOOST_AUTO_TEST_CASE(test_platform_win32_window_manager_displays)
{
  using namespace platform::win32;
  
  window::manager::display_list_type const l(window::manager::display_list());
  
  BOOST_CHECK(!l.empty());
  
  for(auto i : l) {
    std::ostringstream ostr;
    
    using platform::win32::operator<<;
    using support::ostream::operator<<;
    
    ostr << '[' << i.first << ",\n";
    
    for (auto j : i.second) {
      ostr << ' ' << j << '\n';
    }

    ostr << ']';
    
    BOOST_MESSAGE(ostr.str() << '\n');
  }
}

BOOST_AUTO_TEST_CASE(test_platform_win32_window_manager_monitors)
{
  using namespace platform::win32;
  
  window::manager::monitor_list_type const l(window::manager::monitor_list());
  
  BOOST_CHECK(!l.empty());
  
  for(auto i : l) {
    std::ostringstream ostr;
    
    using platform::win32::operator<<;
    using support::ostream::operator<<;
    
    ostr << '[' << i << ']';
    
    BOOST_MESSAGE(ostr.str() << '\n');
  }
}
