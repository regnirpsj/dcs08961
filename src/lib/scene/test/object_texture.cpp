// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

#include <scene/object/textures.hpp>
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

typedef boost::mpl::list<scene::object::texture::d1,
                         scene::object::texture::d2,
                         scene::object::texture::d3> tex_types_fill;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_scene_object_texture_ctor_fill, T, tex_types_fill)
{
  T const t;

  BOOST_CHECK(true);
  
  BOOST_MESSAGE(support::demangle(typeid(T)) << ':' << t);
}

typedef boost::mpl::list<scene::object::texture::d2> tex_types_file;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_scene_object_texture_ctor_file, T, tex_types_file)
{
#if defined(WIN32)
  static std::string const prefix("c:/tools/gli/gli-git");
#else
  static std::string const prefix("/home/jsd/Projects/others/gli-git");
#endif
  
  std::array<std::string const, 3> const file_list = {
    {
      prefix + "/data/array_r8_unorm.dds",
      prefix + "/data/cube_rgba8_unorm.dds",
      prefix + "/data/test.dds",
    }
  };

  for (auto const& f : file_list) {
    T const t(f);
    
    BOOST_CHECK(!t.empty());
    
    BOOST_MESSAGE(support::demangle(typeid(T)) << ':' << t);
  }
}
