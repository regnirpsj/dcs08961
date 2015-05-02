// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

      struct DCS08961_SCENE_EXPORT positional : virtual public base {

      public:      

        using rep = base::rep;
      
        static positional const dflt_light;

        field::value::single<glm::vec3> position; ///< light position (in wc?)
      
        explicit positional();
      
      protected:
        
        virtual void do_changed(field::base&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace light {
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_POSITIONAL_HPP)
