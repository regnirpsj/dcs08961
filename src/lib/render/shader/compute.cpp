// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/compute.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/shader/compute.hpp"

// includes, system

#include <stdexcept> // std::logic_error

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace render {

  namespace shader {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    compute::~compute()
    {
      TRACE("render::shader::compute::~compute");
    }
    
    void
    compute::dispatch(glm::uvec3 const& a)
    {
      TRACE("render::shader::compute::dispatch");

      do_dispatch(a);
    }
    
    /* explicit */
    compute::compute(context& a)
      : base(a)
    {
      TRACE("render::shader::compute::compute");
    }

    /* virtual */ void
    compute::do_activate()
    {
      TRACE("render::shader::compute::do_activate");
    }
    
    /* virtual */ void
    compute::do_dispatch(glm::uvec3 const&)
    {
      TRACE("render::shader::compute::do_dispatch");
      
      throw std::logic_error("pure virtual function 'render::shader::compute::do_dispatch' called");
    }
    
  } // namespace shader {
  
} // namespace render {
