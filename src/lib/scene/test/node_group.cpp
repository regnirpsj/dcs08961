// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/node_group.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::io::*

// includes, project

#include <scene/node/group.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_scene_node_group_ctor)
{
  using namespace scene::node;
  
  group const g;
  
  BOOST_CHECK(true == g.children.get().empty());
  BOOST_MESSAGE(glm::io::precision(1) << glm::io::width(1 + 1 + 1 + 1)
                << g << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_node_group_set_children)
{
  using namespace scene::node;
  
  group  g0;
  group* g1(new group);
  group* g2(new group);

  BOOST_CHECK(true == g0.children.get().empty());

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
  g0.children.set({ g1, g2 });
#else
  g0.children += g1;
  g0.children += g2;
#endif
  BOOST_CHECK(2 == g0.children.get().size());

  BOOST_MESSAGE(glm::io::precision(1) << glm::io::width(1 + 1 + 1 + 1)
                << g0 << '\n' << *g1 << '\n' << *g2 << '\n');
  
  group* g3(new group);
  group* g4(new group);

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
  auto const old(g0.children.set({ g3, g4 }));
#else
  auto const old(g0.children.set(group::children_field_type::value_container_type()));
  g0.children += g1;
  g0.children += g2;
#endif
  
  BOOST_MESSAGE(glm::io::precision(1) << glm::io::width(1 + 0 + 1 + 1)
                << g0 << '\n' << *g1 << '\n' << *g2 << '\n' << *g3 << '\n' << *g4 << '\n');
  
  BOOST_CHECK(2 == g0.children.get().size());
  
  BOOST_MESSAGE(glm::io::precision(1) << glm::io::width(0 + 0 + 1 + 1)
                << g0 << '\n' << *g3 << '\n' << *g4 << '\n');
}
