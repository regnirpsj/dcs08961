// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/light/spot.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_SPOT_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_SPOT_HPP

// includes, system

//#include <>

// includes, project

#include <scene/object/light/directional.hpp>
#include <scene/object/light/positional.hpp>

namespace scene {

  namespace object {

    namespace light {
      
      // types, exported (class, enum, struct, union, typedef)

      struct DCS08961_SCENE_EXPORT spot : public directional,
                                          public positional {

      public:      

        typedef base::rep rep;
      
        static spot const dflt_light;

        field::value::single<float> exponent; ///< spot exponent [0,127]
        field::value::single<float> cutoff;   ///< spot cutoff   [0,90]|180
      
        explicit spot();
      
      protected:

        virtual void do_evaluate();
        virtual void do_changed(field::base&);
        
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace light {
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_SPOT_HPP)
