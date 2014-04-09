// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/light_source.hpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_SOURCE_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_SOURCE_HPP

// includes, system

#include <glm/glm.hpp> // glm::vec[3|4]
#include <iosfwd>      // std::ostream (fwd)

// includes, project

#include <field/adapter_single.hpp>
#include <scene/object/base.hpp>

namespace scene {

  namespace object {
    
    // types, exported (class, enum, struct, union, typedef)

    struct light_source : public base {

    public:
      
      struct rep {

      public:
        
        glm::vec4  position;
        glm::vec3  direction;
        bool       active;
        glm::vec3  ambient;
        float      exponent;
        glm::vec3  diffuse;
        float      cutoff;
        glm::vec3  specular;
        float      pad0;
        glm::vec3  attenuation;
        float      pad1;
        glm::vec2  size;
        glm::uvec2 samples;
        
        explicit rep(bool              /* active */           = false,
                     glm::vec4 const&  /* position */         = glm::vec4(0.0, 0.0,  1.0, 0.0),
                     glm::vec3 const&  /* spot direction */   = glm::vec3(0.0, 0.0, -1.0),
                     glm::vec3 const&  /* ambient */          = glm::vec3(0.0, 0.0,  0.0),
                     glm::vec3 const&  /* diffuse */          = glm::vec3(1.0, 1.0,  1.0),
                     glm::vec3 const&  /* specular */         = glm::vec3(1.0, 1.0,  1.0),
                     glm::vec3 const&  /* attenuation */      = glm::vec3(1.0, 0.0,  0.0),
                     float             /* spot exponent */    = 0.0,
                     float             /* spot cutoff */      = 180.0/*_deg*/,
                     glm::vec2 const&  /* area size */        = glm::vec2(0.0, 0.0),
                     glm::uvec2 const& /* area samples */     = glm::uvec2(1, 1));
      
      };

      field::adapter::single<bool>      active;
      field::adapter::single<glm::vec3> ambient;
      field::adapter::single<glm::vec3> diffuse;
      field::adapter::single<glm::vec3> specular;
      field::adapter::single<glm::vec3> attenuation;

      virtual ~light_source() =0;
      
      operator rep const& () const;
      
    protected:

      rep rep_;

      explicit light_source(std::string const& /* name */,
                            rep const&         /* rep */ = rep());
      
      bool             cb_get_active     () const;
      bool             cb_set_active     (bool);
      glm::vec3 const& cb_get_ambient    () const;
      glm::vec3        cb_set_ambient    (glm::vec3 const&);
      glm::vec3 const& cb_get_diffuse    () const;
      glm::vec3        cb_set_diffuse    (glm::vec3 const&);
      glm::vec3 const& cb_get_specular   () const;
      glm::vec3        cb_set_specular   (glm::vec3 const&);
      glm::vec3 const& cb_get_attenuation() const;
      glm::vec3        cb_set_attenuation(glm::vec3 const&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

    bool operator==(light_source::rep const&, light_source::rep const&);
    
    std::ostream& operator<<(std::ostream&, light_source::rep const&);
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_SOURCE_HPP)
