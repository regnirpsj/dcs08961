// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture/d3.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_D3_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_D3_HPP

// includes, system

#include <gli/gli.hpp> // gli::texture?D

// includes, project

#include <scene/object/texture/base.hpp>

namespace scene {

  namespace object {

    namespace texture {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_SCENE_EXPORT d3 : public base {

      public:

        explicit d3(glm::uvec3 const& /* size */  = default_size.xyz(),
                    glm::uvec4 const& /* color */ = default_color);
        explicit d3(std::string const& /* file */);
        virtual ~d3();

        virtual bool empty() const;
      
      private:

        gli::texture3D tdata_;
        
      };
      
      // variables, exported (extern)
      
      // functions, inlined (inline)
      
      // functions, exported (extern)

    } // namespace texture {

  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_D3_HPP)
