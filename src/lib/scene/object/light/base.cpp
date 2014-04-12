// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/light/base.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/light/base.hpp"

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

    namespace light {
      
      // variables, exported
    
      // functions, exported

      /* explicit */
      base::rep::rep(bool a, glm::vec4 const& b, glm::vec3 const& c, glm::vec3 const& d,
                     glm::vec3 const& e, glm::vec3 const& f, glm::vec3 const& g, float h, float i)
        : position   (b),
          direction  (c),
          active     (a),
          ambient    (d),
          exponent   (h),
          diffuse    (e),
          cutoff     (i),
          specular   (f),
          pad0       (0),
          attenuation(g),
          pad1       (0)
      {   
        TRACE("scene::object::light::base::rep::rep");
      } 

      /* virtual */
      base::~base()
      {
        TRACE("scene::object::light::base::~base");
      }

      /* explicit */
      base::base(std::string const& a, rep const& b)
        : object::base  (a),
          representation(*this, "representation",
                         std::bind(&base::cb_get_rep_list, this),
                         std::bind(&base::cb_set_rep_list, this, std::placeholders::_1),
                         std::bind(&base::cb_add_rep,      this, std::placeholders::_1),
                         std::bind(&base::cb_sub_rep,      this, std::placeholders::_1)),
          active        (*this, "active",      b.active),
          ambient       (*this, "ambient",     b.ambient),
          diffuse       (*this, "diffuse",     b.diffuse),
          specular      (*this, "specular",    b.specular),
          attenuation   (*this, "attenuation", b.attenuation),
          rep_list_     (1, b)
      {   
        TRACE("scene::object::light::base::base");
      }

      void
      base::evaluate()
      {
        TRACE("scene::object::light::base::evaluate");
        
        object::base::evaluate();
      }
      
      void
      base::changed(field::base& f)
      {
        TRACE("scene::object::light::base::changed");
        
        if      (&f == &active)      { rep_list_[0].active      = active.get();      }
        else if (&f == &ambient)     { rep_list_[0].ambient     = ambient.get();     }
        else if (&f == &diffuse)     { rep_list_[0].diffuse     = diffuse.get();     }
        else if (&f == &specular)    { rep_list_[0].specular    = specular.get();    }
        else if (&f == &attenuation) { rep_list_[0].attenuation = attenuation.get(); }
        
        else {
          object::base::changed(f);
        }
      }

      base::rep_list_type const&
      base::cb_get_rep_list() const
      {
        TRACE("scene::object::light::base::cb_get_rep_list");

        return rep_list_;
      }
      
      base::rep_list_type
      base::cb_set_rep_list(rep_list_type const&)
      {
        TRACE("scene::object::light::base::cb_set_rep_list");

        return rep_list_;
      }

      bool
      base::cb_add_rep(rep const&)
      {
        TRACE("scene::object::light::base::cb_add_rep");

        return false;
      }

      bool
      base::cb_sub_rep(rep const&)
      {
        TRACE("scene::object::light::base::cb_sub_rep");

        return false;
      }

      bool
      operator==(base::rep const& lhs, base::rep const& rhs)
      {
        TRACE("scene::object::light::operator==(base::rep, base::rep)");
      
        return ((&lhs == &rhs) ||
                ((lhs.active      == rhs.active)      &&
                 (lhs.position    == rhs.position)    &&
                 (lhs.direction   == rhs.direction)   &&
                 (lhs.ambient     == rhs.ambient)     &&
                 (lhs.diffuse     == rhs.diffuse)     &&
                 (lhs.specular    == rhs.specular)    &&
                 (lhs.attenuation == rhs.attenuation) &&
                 (lhs.exponent    == rhs.exponent)    &&
                 (lhs.cutoff      == rhs.cutoff)));
      }        

      std::ostream&
      operator<<(std::ostream& os, base::rep const& a)
      {
        TRACE_NEVER("scene::object::operator<<(base::rep)");
      
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
             << "cut:" << a.cutoff
             << ']';
        }

        return os;
      }

    } // namespace light {
    
  } // namespace object {
  
} // namespace scene {
