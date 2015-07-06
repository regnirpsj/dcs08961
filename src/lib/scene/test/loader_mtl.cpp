// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/loader_mtl.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>          // std::array<>
#include <glm/gtx/io.hpp> // glm::io::*

// includes, project

#include <loader/mtl.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  std::array<std::string const, 3> const materials = {
    {
      { "# Wavefront material file\n" },
      
      { "newmtl coating_black\n"
        "Ka 0.150000 0.150000 0.150000\n"
        "Kd 0.082353 0.082353 0.082353\n"
        "Ks 0.016471 0.016471 0.016471\n"
        "illum 2\n"
        "Ns 8\n" },
      
      { "newmtl seats\n"
        "#Ka 0.150000 0.150000 0.150000\n"
        "#Kd 0.480392 0.480392 0.431372\n"
        "#Ks 0.096078 0.096078 0.086274\n"
        "#illum 2\n"
        "#Ns 8\n"
        "Ka 0.150000 0.150000 0.150000\n"
        "Kd 1 1 1\n"
        "Ks 0.226471 0.226471 0.226471\n"
        "illum 2\n"
        "Ns 8\n"
        "map_Kd leather_coarse.png\n" },
    }
  };
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_scene_loader_mtl_size)
{
  std::stringstream str;

  for (auto m : materials) {
    str << m << '\n';
  }

  // 'mtl::load' returns list of materials + dflt material
  BOOST_CHECK(materials.size() == scene::file::mtl::load(str).size());
}

BOOST_AUTO_TEST_CASE(test_scene_loader_mtl_properties)
{
  std::stringstream str;

  for (auto m : materials) {
    str << m << '\n';
  }

  using namespace scene::file;

  mtl::list_type const result(mtl::load(str));
  
  BOOST_CHECK("coating_black"                         == result[1]->name.get());
  BOOST_CHECK(glm::vec3(0.150000, 0.150000, 0.150000) == result[1]->ambient.get());
  BOOST_CHECK(glm::vec3(0.082353, 0.082353, 0.082353) == result[1]->diffuse.get());
  BOOST_CHECK(glm::vec3(0.016471, 0.016471, 0.016471) == result[1]->specular.get());
  BOOST_CHECK(8                                       == result[1]->shininess.get());
}
