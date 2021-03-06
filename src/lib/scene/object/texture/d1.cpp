// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture/d1.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/texture/d1.hpp"

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
      d1::d1(unsigned const& a, glm::uvec4 const& b)
        : base  (),
          tdata_(gli::FORMAT_RGBA8_UNORM_PACK32, gli::texture1D::texelcoord_type(a))
      {   
        TRACE("scene::object::d1::d1");
      
        fill(tdata_, glm::u8vec4(b));
      } 
    
      /* explicit */
      d1::d1(std::string const& a)
        : base  (),
          tdata_(load(a))
      {   
        TRACE("scene::object::d1::d1(file)");
      
        if (!empty()) {
          name = a;
        } 
      }
      
      /* virtual */
      d1::~d1()
      {
        TRACE("scene::object::d1::~d1");
      } 
    
      /* virtual */ bool
      d1::empty() const
      {
        TRACE("scene::object::d1::empty");
      
        return tdata_.empty();
      }
      
    } // namespace texture {

  } // namespace object {
  
} // namespace scene {
