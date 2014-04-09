// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/spot_light.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/spot_light.hpp"

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

    /* static */ spot_light const spot_light::dflt_light("dflt_spot_light");
    
    // functions, exported
    
    /* explicit */
    spot_light::spot_light(std::string const& a, rep const& b)
      : light_source     (a, b),
        directional_light(a, b),
        positional_light (a, b),
        exponent         (*this, "exponent",
                          std::bind(&spot_light::cb_get_exponent, this),
                          std::bind(&spot_light::cb_set_exponent, this, std::placeholders::_1),
                          b.exponent),
        cutoff           (*this, "cutoff",
                          std::bind(&spot_light::cb_get_cutoff, this),
                          std::bind(&spot_light::cb_set_cutoff, this, std::placeholders::_1),
                          b.cutoff)
    {
      TRACE("scene::object::spot_light::spot_light");
    }

    float
    spot_light::cb_get_exponent() const
    {
      TRACE("scene::object::spot_light::cb_get_exponent");
      
      return rep_.exponent;
    } 
    
    float
    spot_light::cb_set_exponent(float a)
    {
      TRACE("scene::object::spot_light::cb_set_exponent");
      
      float const result(rep_.exponent);

      rep_.exponent = a;

      return result;
    }
    
    float
    spot_light::cb_get_cutoff() const
    {
      TRACE("scene::object::spot_light::cb_get_cutoff");
      
      return rep_.cutoff;
    }
    
    float
    spot_light::cb_set_cutoff(float a)
    {
      TRACE("scene::object::spot_light::cb_set_cutoff");

      float const result(rep_.cutoff);

      rep_.cutoff = a;

      return result;
    }
    
  } // namespace object {
  
} // namespace scene {
