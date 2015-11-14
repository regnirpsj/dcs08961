// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/test/shader_program.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/context.hpp>
#include <render/shader/program.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  template <typename T>
  class shader : public T {

  public:

    using inherited = T;
    
    explicit shader(render::device::context& a)
      : inherited(a)
    {
      inherited::name = "[" + support::demangle(typeid(T)) + "]";
    }

  private:

    virtual void do_activate()
    {}
    
  };

  using vs  = shader<render::shader::vertex>;
  using tcs = shader<render::shader::tessellation::control>;
  using tes = shader<render::shader::tessellation::evaluation>;
  using gs  = shader<render::shader::geometry>;
  using fs  = shader<render::shader::fragment>;

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
  
  class context : public render::device::context {
  };
  
  // variables, internal
  
  // functions, internal
  
} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_render_test_shader_program_ctor)
{
  context c;
  program p(c);

  p.vertex_shader    = new vs (c);
  p.tess_ctrl_shader = new tcs(c);
  p.tess_eval_shader = new tes(c);
  p.geometry_shader  = new gs (c);
  p.fragment_shader  = new fs (c);
  
  BOOST_CHECK  (true);
  BOOST_MESSAGE(p);
}
