// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/area_light.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_AREA_LIGHT_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_AREA_LIGHT_HPP

// includes, system

//#include <>

// includes, project

#include <scene/object/spot_light.hpp>

namespace scene {

  namespace object {
    
    // types, exported (class, enum, struct, union, typedef)

    struct area_light : public spot_light {

    public:      

      typedef light_source::rep rep;
      
      static area_light const dflt_light;

      field::adapter::single<glm::vec2>  size;
      field::adapter::single<glm::uvec2> samples;
      
      explicit area_light(std::string const& /* name */,
                          rep const&         /* rep */ = rep());
      
    protected:

      glm::vec2 const&  cb_get_size   () const;
      glm::vec2         cb_set_size   (glm::vec2 const&);
      glm::uvec2 const& cb_get_samples() const;
      glm::uvec2        cb_set_samples(glm::uvec2 const&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_AREA_LIGHT_HPP)
