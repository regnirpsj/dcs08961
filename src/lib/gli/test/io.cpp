// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  gli/test/io.cpp                                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

// x#include <>

// includes, project

#include <gli/gtx/io.hpp>
#include <support/type_info.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

typedef boost::mpl::list<gli::texture1D,
                         gli::texture2D,
                         gli::texture3D> tex_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_gli_gtx_io, T, tex_types)
{
  using namespace gli;
  
  T const t(FORMAT_RGBA8_UNORM, typename T::texelcoord_type(1));

  BOOST_CHECK(!t.empty());
  
  BOOST_MESSAGE(support::demangle(typeid(T)) << ':'
                << glm::io::precision(0) << glm::io::width(0 + 2 + 0 + 0)
                << t);
}
