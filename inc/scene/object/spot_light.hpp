// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/spot_light.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_SPOT_LIGHT_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_SPOT_LIGHT_HPP

// includes, system

//#include <>

// includes, project

#include <scene/object/directional_light.hpp>
#include <scene/object/positional_light.hpp>

namespace scene {

  namespace object {
    
    // types, exported (class, enum, struct, union, typedef)

    struct spot_light : public directional_light,
                        public positional_light {

    public:      

      typedef light_source::rep rep;
      
      static spot_light const dflt_light;

      field::adapter::single<float> exponent;
      field::adapter::single<float> cutoff;
      
      explicit spot_light(std::string const& /* name */,
                          rep const&         /* rep */ = rep());
      
    protected:

      float cb_get_exponent() const;
      float cb_set_exponent(float);
      float cb_get_cutoff  () const;
      float cb_set_cutoff  (float);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_SPOT_LIGHT_HPP)
