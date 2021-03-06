// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene_object_material.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_MATERIAL_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_MATERIAL_HPP

// includes, system

#include <glm/glm.hpp> // glm::vec[3|4]
#include <iosfwd>      // std::ostream (fwd)

// includes, project

#include <field/adapter/single.hpp>
#include <scene/object/base.hpp>

namespace scene {

  namespace object {
    
    // types, exported (class, enum, struct, union, typedef)

    struct DCS08961_SCENE_EXPORT material : public base {

    public:

      struct rep {

      public:
        
        glm::vec3 ambient;
        float     refraction;
        glm::vec3 diffuse;
        float     shininess;
        glm::vec3 emission;
        float     alpha;
        glm::vec3 specular;
        bool      front;
        glm::vec3 transmission;
        bool      back;
        
        explicit rep(glm::vec3 const& /* ambient */      = glm::vec3(0.2, 0.2, 0.2),
                     glm::vec3 const& /* diffuse */      = glm::vec3(0.8, 0.8, 0.8),
                     glm::vec3 const& /* emission */     = glm::vec3(0.0, 0.0, 0.0),
                     glm::vec3 const& /* specular */     = glm::vec3(0.0, 0.0, 0.0),
                     glm::vec3 const& /* transmission */ = glm::vec3(0.0, 0.0, 0.0),
                     float            /* refr. index */  = 1.0,
                     float            /* shininess */    = 0.0,
                     float            /* alpha */        = 1.0,
                     bool             /* front */        = true,
                     bool             /* back */         = false);
      };

      static material const dflt_material;

      field::adapter::single<glm::vec3> ambient;
      field::adapter::single<glm::vec3> diffuse;
      field::adapter::single<glm::vec3> emission;
      field::adapter::single<glm::vec3> specular;
      field::adapter::single<glm::vec3> transmission;
      field::adapter::single<float>     refraction;
      field::adapter::single<float>     shininess;
      field::adapter::single<float>     alpha;
      field::adapter::single<bool>      front;
      field::adapter::single<bool>      back;
      
      explicit material(rep const& /* material rep */ = rep());

      operator rep const& () const;
      
    private:

      rep rep_;

      glm::vec3 const& cb_get_ambient     () const;
      glm::vec3        cb_set_ambient     (glm::vec3 const&);
      glm::vec3 const& cb_get_diffuse     () const;
      glm::vec3        cb_set_diffuse     (glm::vec3 const&);
      glm::vec3 const& cb_get_emission    () const;
      glm::vec3        cb_set_emission    (glm::vec3 const&);
      glm::vec3 const& cb_get_specular    () const;
      glm::vec3        cb_set_specular    (glm::vec3 const&);
      glm::vec3 const& cb_get_transmission() const;
      glm::vec3        cb_set_transmission(glm::vec3 const&);
      float const&     cb_get_refraction  () const;
      float            cb_set_refraction  (float const&);
      float const&     cb_get_shininess   () const;
      float            cb_set_shininess   (float const&);
      float const&     cb_get_alpha       () const;
      float            cb_set_alpha       (float const&);
      bool  const&     cb_get_front       () const;
      bool             cb_set_front       (bool const&);
      bool  const&     cb_get_back        () const;
      bool             cb_set_back        (bool const&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

    DCS08961_SCENE_EXPORT bool operator==(material::rep const&, material::rep const&);
    
    DCS08961_SCENE_EXPORT std::ostream& operator<<(std::ostream&, material::rep const&);
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_MATERIAL_HPP)
