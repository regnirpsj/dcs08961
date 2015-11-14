// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/test/stage_setup.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/context.hpp>
#include <render/stage/setup.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  template <typename T>
  class state : public T {

  public:

    using inherited = T;

    explicit state(render::device::context& a)
      : inherited(a)
    {
      inherited::name = "[" + support::demangle(typeid(T)) + "]";
    }

  private:

    virtual void do_activate()
    {}

  };

  using blend         = state<render::state::blend>;
  using depth_stencil = state<render::state::depth_stencil>;
  using raster        = state<render::state::raster>;
  using sampler       = state<render::state::sampler>;
  
  class program : public render::shader::program {

  public:

    explicit program(render::device::context& a)
      : render::shader::program(a)
    {}

  private:

    virtual void do_compile()
    {}
    
    virtual void do_link()
    {}
    
  };
  
  class setup_stage : public render::stage::setup {

  public:

    explicit setup_stage(render::device::context& a)
      : render::stage::setup(a)
    {}

  private:

    virtual void do_execute(render::swap::context&)
    {}

    virtual void do_resize(glm::ivec2 const&)
    {}
    
  };

  class context : public render::device::context {
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_render_base_test_stage_setup_ctor)
{
  context     c;
  setup_stage s(c);

  s.state_blend         = new blend        (c);
  s.state_depth_stencil = new depth_stencil(c);
  s.state_raster        = new raster       (c);
  s.state_sampler       = new sampler      (c);
  s.shader_program      = new program      (c);
  
  BOOST_CHECK  (true);
  BOOST_MESSAGE(s);
}
