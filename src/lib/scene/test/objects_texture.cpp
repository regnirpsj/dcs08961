// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/obects_texture.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>    // std::array<>
#include <typeinfo> // typeid usage

// includes, project

// #include <gli/gtx/io.hpp>
#include <scene/object/texture.hpp>
#include <support/type_info.hpp>

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
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

typedef boost::mpl::list<scene::object::texture_1d,
                         scene::object::texture_2d,
                         scene::object::texture_3d> tex_types_fill;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_ctor_fill, T, tex_types_fill)
{
  static std::string const n("tex0");
  
  T const t(n);

  BOOST_CHECK(n == t.name.get());
  
  BOOST_MESSAGE(support::demangle(typeid(T)) << ':' << t);
}

typedef boost::mpl::list<scene::object::texture_2d> tex_types_file;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_ctor_file, T, tex_types_file)
{
#if defined(WIN32)
  static std::string const prefix("c:/tools/gli/gli-git");
#else
  static std::string const prefix("/home/jsd/Projects/others/gli-git");
#endif
  
  std::array<std::string const, 3> const file_list = {
    {
      prefix + "/test_bc1.dds",
      prefix + "/test_dxt1.dds",
      prefix + "/test_rgb8.dds",
    }
  };

  for (auto const& f : file_list) {
    T const t(f, f);
    
    BOOST_CHECK(f == t.name.get());
    
    BOOST_MESSAGE(support::demangle(typeid(T)) << ':' << t);
  }
}
