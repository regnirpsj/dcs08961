// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/test/api.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>    // std::array<>
#include <typeinfo> // typeid usage

// includes, project

#include <render/d3d.hpp>
#include <render/interface.hpp>
#include <render/null.hpp>
#include <render/ogl.hpp>

// #include <>

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

BOOST_AUTO_TEST_CASE(test_render_api_variants)
{
  std::array<render::api::type const, 3> const variant = {
    {
      render::api::type::d3d,
      render::api::type::null,
      render::api::type::ogl,
    }
  };

  for (unsigned i(0); i < variant.size(); ++i) {
    render::api::type const v(variant[i]);
    
    BOOST_CHECK(v == variant[i]);
    BOOST_MESSAGE(v);
  }
}

#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

typedef boost::mpl::list<//render::context<render::api::type::d3d>,
                         //render::context<render::api::type::ogl>,
                         render::context<render::api::type::null>
                         > context_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_context, T, context_types)
{
  T ctx;
    
  BOOST_CHECK  (&ctx);
  BOOST_MESSAGE("ctx  :" << ctx << " (" << T::api_type << ')');
}

#if 0
typedef boost::mpl::list<//render::pass::container<render::api::type::d3d>,
                         //render::pass::container<render::api::type::ogl>,
                         render::pass::container<render::api::type::null>
                         > pass_container_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_pass_container, T, pass_container_types)
{
  T c;
    
  BOOST_CHECK  (&c);
  BOOST_MESSAGE(c << " (" << T::api_type << ')');
}
#endif

typedef boost::mpl::list<//render::stage::clear<render::api::type::d3d>,
                         //render::stage::clear<render::api::type::ogl>,
                         render::stage::clear<render::api::type::null>
                         > stage_clear_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_stage_clear, T, stage_clear_types)
{
  typedef typename render::context<T::api_type> context_type;
  typedef T                                     clr_stage_type;

  context_type   ctx;
  clr_stage_type clr(ctx);
    
  BOOST_CHECK  (&clr);
  BOOST_MESSAGE("clear:" << clr << " (" << T::api_type << ')');
}

typedef boost::mpl::list<//render::stage::draw<render::api::type::d3d>,
                         //render::stage::draw<render::api::type::ogl>,
                         render::stage::draw<render::api::type::null>
                         > stage_draw_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_stage_draw, T, stage_draw_types)
{
  typedef typename render::context<T::api_type> context_type;
  typedef T                                     drw_stage_type;

  context_type   ctx;
  drw_stage_type drw(ctx);
    
  BOOST_CHECK  (&drw);
  BOOST_MESSAGE("draw :" << drw << " (" << T::api_type << ')');
}

typedef boost::mpl::list<//render::stage::swap<render::api::type::d3d>,
                         //render::stage::swap<render::api::type::ogl>,
                         render::stage::swap<render::api::type::null>
                         > stage_swap_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_stage_swap, T, stage_swap_types)
{
  typedef typename render::context<T::api_type> context_type;
  typedef T                                     swp_stage_type;

  context_type   ctx;
  swp_stage_type swp(ctx);
    
  BOOST_CHECK  (&swp);
  BOOST_MESSAGE("swap :" << swp << " (" << T::api_type << ')');
}
