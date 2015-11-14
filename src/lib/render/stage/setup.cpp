// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/setup.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/stage/setup.hpp"

// includes, system

//#include <>

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

  template <typename T>
  inline std::ostream&
  operator<<(std::ostream& os, boost::intrusive_ptr<T> const& a)
  {
    typename std::ostream::sentry const cerberus(os);
    
    if (cerberus) {
      if (a) {
        os << *(a.get());
      } else {
        os << a.get();
      }
    }
    
    return os;
  }
  
} // namespace {

namespace render {

  namespace stage {
      
    // variables, exported
  
    // functions, exported

    /* virtual */
    setup::~setup()
    {
      TRACE("render::stage::setup::~setup");
    }

    /* explicit */
    setup::setup(device::context& a)
      : base               (a),
        state_blend        (*this, "state_blend",         nullptr),
        state_depth_stencil(*this, "state_depth_stencil", nullptr),
        state_raster       (*this, "state_raster",        nullptr),
        state_sampler      (*this, "state_sampler",       nullptr),
        shader_program     (*this, "shader_program",      nullptr)
    {
      TRACE("render::stage::setup::setup");

      name = "[render::stage::setup]";
    }
      
  } // namespace stage {
  
} // namespace render {
