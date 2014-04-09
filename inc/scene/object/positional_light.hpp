// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/positional_light.hpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_POSITIONAL_LIGHT_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_POSITIONAL_LIGHT_HPP

// includes, system

// #include <>

// includes, project

#include <scene/object/light_source.hpp>

namespace scene {

  namespace object {
    
    // types, exported (class, enum, struct, union, typedef)

    struct positional_light : virtual public light_source {

    public:      

      typedef light_source::rep rep;
      
      static positional_light const dflt_light;

      field::adapter::single<glm::vec4> position;
      
      explicit positional_light(std::string const& /* name */,
                                rep const&         /* rep */ = rep());
      
    protected:

      glm::vec4 const& cb_get_position() const;
      glm::vec4        cb_set_position(glm::vec4 const&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_POSITIONAL_LIGHT_HPP)
