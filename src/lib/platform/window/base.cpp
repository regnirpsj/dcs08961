// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/window/base.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/window/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<  (field::container::print_on)

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

namespace platform {

  namespace window {
  
    // variables, exported
  
    // functions, exported
    
    /* explicit */
    base::base(std::string const& a, rect const& b)
      : boost::noncopyable(),
        field::container  (),
        title             (*this, "title",    a),
        position          (*this, "position", glm::ivec2(b.x, b.y)),
        size              (*this, "size",     glm::ivec2(b.w, b.h))
    {
      TRACE("platform::window::base::base");
    }
    
  } // namespace window {
  
} // namespace platform {
