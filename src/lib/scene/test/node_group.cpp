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

BOOST_AUTO_TEST_CASE(node_group_ctor)
{
  using namespace scene::node;
  
  group const g("group");
  
  BOOST_CHECK(true == g.children.get().empty());

  //glm::io::format_saver const iofs(std::cout);
  BOOST_MESSAGE(glm::io::precision(1) << glm::io::width(1 + 1 + 1 + 1)
                << g << '\n');
}

BOOST_AUTO_TEST_CASE(node_group_set_children)
{
  using namespace scene::node;
  
  group  g0("grp0");
  group* g1(new group("grp1"));
  group* g2(new group("grp2"));

  BOOST_CHECK(true == g0.children.get().empty());
  
  g0.children.set({ g1, g2 });
  
  BOOST_CHECK(2 == g0.children.get().size());

  BOOST_MESSAGE(glm::io::precision(1) << glm::io::width(1 + 1 + 1 + 1)
                << g0 << '\n' << *g1 << '\n' << *g2 << '\n');
  
  group* g3(new group("grp3"));
  group* g4(new group("grp4"));
  
  auto const old(g0.children.set({ g3, g4 }));

  BOOST_MESSAGE(glm::io::precision(1) << glm::io::width(1 + 0 + 1 + 1)
                << g0 << '\n' << *g1 << '\n' << *g2 << '\n' << *g3 << '\n' << *g4 << '\n');
  
  BOOST_CHECK(2 == g0.children.get().size());
  
  BOOST_MESSAGE(glm::io::precision(1) << glm::io::width(0 + 0 + 1 + 1)
                << g0 << '\n' << *g3 << '\n' << *g4 << '\n');
}
