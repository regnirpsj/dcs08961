// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture/d2.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/texture/d2.hpp"

// includes, system

//#include <>

// includes, project

#include <object/texture/fill.hpp>
#include <object/texture/load.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace scene {

  namespace object {

    namespace texture {
  
      // variables, exported
  
      // functions, exported

      /* explicit */
      d2::d2(glm::uvec2 const& a, glm::uvec4 const& b)
        : base  (),
          tdata_(1, gli::RGBA8_UNORM, gli::texture2D::dim_type(a.x, a.y))
      {   
        TRACE("scene::object::d2::d2");
      
        fill(tdata_, glm::u8vec4(b));
      } 

      /* explicit */
      d2::d2(std::string const& a)
        : base  (),
          tdata_(load(a))
      {   
        TRACE("scene::object::d2::d2(file)");
      
        if (!empty()) {
          name = a;
        } 
      }
      
      /* virtual */
      d2::~d2()
      {
        TRACE("scene::object::d2::~d2");
      } 
    
      /* virtual */ bool
      d2::empty() const
      {
        TRACE("scene::object::d2::empty");
      
        return tdata_.empty();
      }
      
    } // namespace texture {

  } // namespace object {
  
} // namespace scene {
