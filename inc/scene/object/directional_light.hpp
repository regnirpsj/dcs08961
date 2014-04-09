// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/directional_light.hpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_DIRECTIONAL_LIGHT_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_DIRECTIONAL_LIGHT_HPP

// includes, system

// #include <>

// includes, project

#include <scene/object/light_source.hpp>

namespace scene {

  namespace object {
    
    // types, exported (class, enum, struct, union, typedef)

    struct directional_light : virtual public light_source {

    public:      

      typedef light_source::rep rep;
      
      static directional_light const dflt_light;

      field::adapter::single<glm::vec3> direction;
      
      explicit directional_light(std::string const& /* name */,
                                 rep const&         /* rep */ = rep());
      
    protected:

      glm::vec3 const& cb_get_direction() const;
      glm::vec3        cb_set_direction(glm::vec3 const&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_DIRECTIONAL_LIGHT_HPP)
