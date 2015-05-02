// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/light/area.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_AREA_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_AREA_HPP

// includes, system

//#include <>

// includes, project

#include <scene/object/light/spot.hpp>

namespace scene {

  namespace object {

    namespace light {
      
      // types, exported (class, enum, struct, union, typedef)

      struct DCS08961_SCENE_EXPORT area : public spot {

      public:      

        using rep = base::rep;
      
        static area const dflt_light;

        field::value::single<glm::uvec2> size;    ///< size.xy
        field::value::single<glm::uvec2> samples; ///< samples.xy
      
        explicit area();
      
      protected:

        virtual void do_evaluate();
        virtual void do_changed(field::base&);

      private:

        rep  rep_;
        bool rebuild_;

        void rebuild();
        
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace light {
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_LIGHT_AREA_HPP)
