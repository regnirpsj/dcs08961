// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/test/context.cpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/context.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class dcontext : public render::device::context {

  public:

    explicit dcontext()
      : render::device::context()
    {}
    
  };

  class scontext : public render::swap::context {

  public:

    explicit scontext()
      : render::swap::context()
    {}
    
  };

  class dscontext : public render::device::context,
                    public render::swap::context {

  public:

    explicit dscontext()
      : render::device::context(),
        render::swap::context  ()
    {}

    virtual void print_on(std::ostream& os) const
    {
      render::device::context::print_on(os);
      render::swap::context::print_on  (os);
    }
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_render_base_test_device_context_ctor)
{
  dcontext const c;
  
  BOOST_CHECK  (true);
  BOOST_MESSAGE(c);
}

BOOST_AUTO_TEST_CASE(test_render_base_test_swap_context_ctor)
{
  scontext const c;
  
  BOOST_CHECK  (true);
  BOOST_MESSAGE(c);
}

BOOST_AUTO_TEST_CASE(test_render_base_test_device_and_swap_context_ctor)
{
  dscontext const c;
  
  BOOST_CHECK  (true);
  BOOST_MESSAGE(c);
}
