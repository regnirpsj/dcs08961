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

#include <render/context.hpp>
#include <render/d3d.hpp>
#include <render/null.hpp>
#include <render/ogl.hpp>
#include <render/pass.hpp>
#include <render/stage.hpp>

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

typedef boost::mpl::list<render::stage<render::api::type::d3d>,
                         render::stage<render::api::type::null>,
                         render::stage<render::api::type::ogl>> stage_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_stage, T, stage_types)
{
  T c;
    
  BOOST_CHECK(&c);
  BOOST_MESSAGE(c << " (" << T::api_type << ')');
}

typedef boost::mpl::list<render::pass<render::api::type::d3d>,
                         render::pass<render::api::type::null>,
                         render::pass<render::api::type::ogl>> pass_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_render_api_variants_pass, T, pass_types)
{
  T c;
    
  BOOST_CHECK(&c);
  BOOST_MESSAGE(c << " (" << T::api_type << ')');
}
