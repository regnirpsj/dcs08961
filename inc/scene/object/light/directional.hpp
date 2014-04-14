// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/light/directional.hpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_DIRECTIONAL_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_DIRECTIONAL_HPP

// includes, system

// #include <>

// includes, project

#include <scene/object/light/base.hpp>

namespace scene {

  namespace object {

    namespace light {
      
      // types, exported (class, enum, struct, union, typedef)

      struct directional : virtual public base {

      public:      

        typedef base::rep rep;
      
        static directional const dflt_light;

        field::value::single<glm::vec3> direction; ///< light direction
      
        explicit directional();
      
      protected:
        
        virtual void do_changed(field::base&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace light {
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_DIRECTIONAL_HPP)
