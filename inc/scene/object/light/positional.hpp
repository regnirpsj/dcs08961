// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/light/positional.hpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_POSITIONAL_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_POSITIONAL_HPP

// includes, system

// #include <>

// includes, project

#include <scene/object/light/base.hpp>

namespace scene {

  namespace object {

    namespace light {
      
      // types, exported (class, enum, struct, union, typedef)

      struct positional : virtual public base {

      public:      

        typedef base::rep rep;
      
        static positional const dflt_light;

        field::value::single<glm::vec3> position; ///< light position (in wc?)
      
        explicit positional(std::string const& /* name */);
      
      protected:

        void evaluate();
        void changed(field::base&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace light {
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_POSITIONAL_HPP)
