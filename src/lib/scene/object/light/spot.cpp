// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/light/spot.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/light/spot.hpp"

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

  scene::object::light::base::rep const dflt_rep(false,
                                                 glm::vec4(0.0, 0.0,  1.0, 1.0),
                                                 glm::vec3(0.0, 0.0, -1.0),
                                                 glm::vec3(0.0, 0.0,  0.0),
                                                 glm::vec3(1.0, 1.0,  1.0),
                                                 glm::vec3(1.0, 1.0,  1.0),
                                                 glm::vec3(1.0, 0.0,  0.0),
                                                 0.0,
                                                 180.0);
  
  // functions, internal

} // namespace {

namespace scene {

  namespace object {

    namespace light {
      
      // variables, exported

      /* static */ spot const spot::dflt_light("dflt_spot_light");
    
      // functions, exported
    
      /* explicit */
      spot::spot(std::string const& a)
        : base       (a, dflt_rep),
          directional(a),
          positional (a),
          exponent   (*this, "exponent", dflt_rep.exponent),
          cutoff     (*this, "cutoff",   dflt_rep.cutoff)
      {   
        TRACE("scene::object::light::spot::spot");
      }
    
      void
      spot::evaluate()
      {
        TRACE("scene::object::light::spot::evaluate");
        
        directional::evaluate();
        positional::evaluate();
      }
      
      void
      spot::changed(field::base& f)
      {
        TRACE("scene::object::light::spot::changed");
        
        if      (&f == &exponent) { rep_list_[0].exponent = exponent.get(); }
        else if (&f == &cutoff)   { rep_list_[0].cutoff   = cutoff.get();   }
        
        else {
          directional::changed(f);
          positional::changed(f);
        }
      }

    } // namespace light {
    
  } // namespace object {
  
} // namespace scene {
