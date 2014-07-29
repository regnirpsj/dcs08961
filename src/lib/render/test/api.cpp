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

typedef boost::mpl::list<render::context<render::api::type::d3d>,
                         render::context<render::api::type::null>,
                         render::context<render::api::type::ogl>> context_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_context, T, context_types)
{
  T c;
    
  BOOST_CHECK(&c);
  BOOST_MESSAGE(c << " (" << T::api_type << ')');
}

typedef boost::mpl::list<render::pass::container<render::api::type::d3d>,
                         render::pass::container<render::api::type::null>,
                         render::pass::container<render::api::type::ogl>> pass_container_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_pass_container, T, pass_container_types)
{
  T c;
    
  BOOST_CHECK(&c);
  BOOST_MESSAGE(c << " (" << T::api_type << ')');
}

typedef boost::mpl::list<render::stage::clear<render::api::type::d3d>,
                         render::stage::clear<render::api::type::null>,
                         render::stage::clear<render::api::type::ogl>> stage_clear_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_stage_clear, T, stage_clear_types)
{
  T c;
    
  BOOST_CHECK(&c);
  BOOST_MESSAGE(c << " (" << T::api_type << ')');
}

typedef boost::mpl::list<render::stage::draw<render::api::type::d3d>,
                         render::stage::draw<render::api::type::null>,
                         render::stage::draw<render::api::type::ogl>> stage_draw_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_stage_draw, T, stage_draw_types)
{
  T c;
    
  BOOST_CHECK(&c);
  BOOST_MESSAGE(c << " (" << T::api_type << ')');
}

typedef boost::mpl::list<render::stage::swap<render::api::type::d3d>,
                         render::stage::swap<render::api::type::null>,
                         render::stage::swap<render::api::type::ogl>> stage_swap_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_stage_swap, T, stage_swap_types)
{
  T c;
    
  BOOST_CHECK(&c);
  BOOST_MESSAGE(c << " (" << T::api_type << ')');
}
