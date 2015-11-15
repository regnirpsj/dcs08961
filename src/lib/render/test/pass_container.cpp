// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/test/pass_container.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/context.hpp>
#include <render/pass/container.hpp>
#include <render/stage/null.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class context : public render::context::device {
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_render_base_test_pass_container_ctor)
{
  context c;
  
  using namespace render;
  
  pass::container p(c);

  p.stages += new stage::null(c);
  p.stages += new stage::null(c);
  
  BOOST_CHECK  (2 == p.stages->size());
  BOOST_MESSAGE(p);
}

BOOST_AUTO_TEST_CASE(test_render_base_test_pass_container_add_stage)
{
  context c;
  
  using namespace render;
  
  boost::intrusive_ptr<pass::container> p(new pass::container(c));

  p->stages += new stage::null(c);
  p->stages += new stage::null(c);
  
  BOOST_CHECK(2 == p->stages->size());

  p->stages = {};

  BOOST_REQUIRE_THROW(p->stages += p.get(), std::runtime_error);

  BOOST_CHECK(true == p->stages.get().empty());
}

BOOST_AUTO_TEST_CASE(test_render_base_test_pass_container_set_stages)
{
  context c;
  
  using namespace render;

  pass::container  p0(c);
  pass::container* p1(new pass::container(c));
  pass::container* p2(new pass::container(c));

  BOOST_CHECK(true == p0.stages.get().empty());

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  p0.stages.set({ p1, p2 });
#else
  p0.stages += p1;
  p0.stages += p2;
#endif
  
  BOOST_CHECK  (2 == p0.stages.get().size());
  BOOST_MESSAGE(p0 << '\n' << *p1 << '\n' << *p2 << '\n');
  
  pass::container* p3(new pass::container(c));
  pass::container* p4(new pass::container(c));

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  auto const old(p0.stages.set({ p3, p4 }));
#else
  auto const old(p0.stages.set(pass::container::stage_field_type::value_container_type()));
  p0.stages += p1;
  p0.stages += p2;
#endif
  
  BOOST_MESSAGE(p0 << '\n' << *p1 << '\n' << *p2 << '\n' << *p3 << '\n' << *p4 << '\n');
  BOOST_CHECK  (2 == p0.stages.get().size());
  BOOST_MESSAGE(p0 << '\n' << *p3 << '\n' << *p4 << '\n');
}
