// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/positional_light.cpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/positional_light.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

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

namespace scene {

  namespace object {
    
    // variables, exported

    /* static */ positional_light const positional_light::dflt_light("dflt_positional_light");
    
    // functions, exported
    
    /* explicit */
    positional_light::positional_light(std::string const& a, rep const& b)
      : light_source(a, b),
        position    (*this, "position",
                     std::bind(&positional_light::cb_get_position, this),
                     std::bind(&positional_light::cb_set_position, this, std::placeholders::_1),
                     b.position)
    {   
      TRACE("scene::object::positional_light::positional_light");
    }
    
    glm::vec4 const&
    positional_light::cb_get_position() const
    {
      TRACE("scene::object::positional_light::cb_get_position");
      
      return rep_.position;
    } 
    
    glm::vec4
    positional_light::cb_set_position(glm::vec4 const& a)
    {
      TRACE("scene::object::positional_light::cb_set_position");
      
      glm::vec4 const result(rep_.position);

      rep_.position = a;

      return result;
    }
    
  } // namespace object {
  
} // namespace scene {
