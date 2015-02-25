// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  window/base.cpp                                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "window/base.hpp"

// includes, system

#include <glm/gtx/io.hpp>

// includes, project

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

namespace window {
  
  // variables, exported
  
  // functions, exported

  /* virtual */
  base::~base()
  {
    TRACE("window::base::~base");
  }
    
  /* explicit */
  base::base(std::string const&  a, glm::i16vec2 const& b, glm::i16vec2 const& c)
    : field::container(),
      title           (*this, "title",    a),
      position        (*this, "position", b),
      size            (*this, "size",     c)
  {
    TRACE("window::base::base");
  }
  
} // namespace window {
