// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/light_source.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/light_source.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <ostream>        // std::ostream

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
    
    // functions, exported

    /* explicit */
    light_source::rep::rep(bool a, glm::vec4 const& b, glm::vec3 const& c, glm::vec3 const& d,
                           glm::vec3 const& e, glm::vec3 const& f, glm::vec3 const& g, float h,
                           float i, glm::vec2 const& j, glm::uvec2 const& k)
      : position(b), direction(c), active(a), ambient(d), exponent(h), diffuse(e), cutoff(i),
        specular(f), pad0(), attenuation(g), pad1(), size(j), samples(k)
    {   
      TRACE("scene::object::light_source::rep::rep");
    } 

    /* virtual */
    light_source::~light_source()
    {
      TRACE("scene::object::light_source::~light_source");
    }

    light_source::operator light_source::rep const& () const
    {
      TRACE("scene::object::light_source::operator light_source::rep const&");
      
      return rep_;
    }

    /* explicit */
    light_source::light_source(std::string const& a, rep const& b)
      : base       (a),
        active     (*this, "active",
                    std::bind(&light_source::cb_get_active, this),
                    std::bind(&light_source::cb_set_active, this, std::placeholders::_1),
                    b.active),
        ambient    (*this, "ambient",
                    std::bind(&light_source::cb_get_ambient, this),
                    std::bind(&light_source::cb_set_ambient, this, std::placeholders::_1),
                    b.ambient),
        diffuse    (*this, "diffuse",
                    std::bind(&light_source::cb_get_diffuse, this),
                    std::bind(&light_source::cb_set_diffuse, this, std::placeholders::_1),
                    b.diffuse),
        specular   (*this, "specular",
                    std::bind(&light_source::cb_get_specular, this),
                    std::bind(&light_source::cb_set_specular, this, std::placeholders::_1),
                    b.specular),
        attenuation(*this, "attenuation",
                    std::bind(&light_source::cb_get_attenuation, this),
                    std::bind(&light_source::cb_set_attenuation, this, std::placeholders::_1),
                    b.attenuation),
        rep_       (b)
    {   
      TRACE("scene::object::light_source::light_source");
    }
    
    bool
    light_source::cb_get_active() const
    {
      TRACE("scene::object::light_source::cb_get_active");
      
      return rep_.active;
    } 
    
    bool
    light_source::cb_set_active(bool a)
    {
      TRACE("scene::object::light_source::cb_set_active");
      
      bool const result(rep_.active);
      
      rep_.active = a;

      return result;
    }
    
    glm::vec3 const&
    light_source::cb_get_ambient() const
    {
      TRACE("scene::object::light_source::cb_get_ambient");
      
      return rep_.ambient;
    } 
    
    glm::vec3
    light_source::cb_set_ambient(glm::vec3 const& a)
    {
      TRACE("scene::object::light_source::cb_set_ambient");
      
      glm::vec3 const result(rep_.ambient);
      
      rep_.ambient = a;

      return result;
    }
    
    glm::vec3 const&
    light_source::cb_get_diffuse() const
    {
      TRACE("scene::object::light_source::cb_get_diffuse");
      
      return rep_.diffuse;
    } 
    
    glm::vec3
    light_source::cb_set_diffuse(glm::vec3 const& a)
    {
      TRACE("scene::object::light_source::cb_set_diffuse");
      
      glm::vec3 const result(rep_.diffuse);

      rep_.diffuse = a;

      return result;
    }
    
    glm::vec3 const&
    light_source::cb_get_specular() const
    {
      TRACE("scene::object::light_source::cb_get_specular");
      
      return rep_.specular;
    }
    
    glm::vec3
    light_source::cb_set_specular(glm::vec3 const& a)
    {
      TRACE("scene::object::light_source::cb_set_specular");

      glm::vec3 const result(rep_.specular);

      rep_.specular = a;

      return result;
    }

    glm::vec3 const&
    light_source::cb_get_attenuation() const
    {
      TRACE("scene::object::light_source::cb_get_attenuation");
      
      return rep_.attenuation;
    } 
    
    glm::vec3
    light_source::cb_set_attenuation(glm::vec3 const& a)
    {
      TRACE("scene::object::light_source::cb_set_attenuation");
      
      glm::vec3 const result(rep_.attenuation);
      
      rep_.attenuation = a;

      return result;
    }

    bool
    operator==(light_source::rep const& lhs, light_source::rep const& rhs)
    {
      TRACE("scene::object::operator==(light_source::rep, light_source::rep)");
      
      return ((&lhs == &rhs) ||
              ((lhs.active      == rhs.active)      &&
               (lhs.position    == rhs.position)    &&
               (lhs.direction   == rhs.direction)   &&
               (lhs.ambient     == rhs.ambient)     &&
               (lhs.diffuse     == rhs.diffuse)     &&
               (lhs.specular    == rhs.specular)    &&
               (lhs.attenuation == rhs.attenuation) &&
               (lhs.exponent    == rhs.exponent)    &&
               (lhs.cutoff      == rhs.cutoff)      &&
               (lhs.size        == rhs.size)        &&
               (lhs.samples     == rhs.samples)));
    }        

    std::ostream&
    operator<<(std::ostream& os, light_source::rep const& a)
    {
      TRACE_NEVER("scene::object::operator<<(light_source::rep)");
      
      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        os << '['
           << ((a.active) ? "" : "!") << "active,"
           << "pos:" << a.position    << ','
           << "dir:" << a.direction   << ','
           << "La:"  << a.ambient     << ','
           << "Ld:"  << a.diffuse     << ','
           << "Ls:"  << a.specular    << ','
           << "att:" << a.attenuation << ','
           << "exp:" << a.exponent    << ','
           << "cut:" << a.cutoff      << ','
           << "siz:" << a.size        << ','
           << "smp:" << a.samples
           << ']';
      }

      return os;
    }
    
  } // namespace object {
  
} // namespace scene {
