// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture/d2.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_D2_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_D2_HPP

// includes, system

#include <gli/gli.hpp> // gli::texture?D
#include <string>      // std::string

// includes, project

#include <scene/object/texture/base.hpp>

namespace scene {

  namespace object {

    namespace texture {
      
      // types, exported (class, enum, struct, union, typedef)

      class d2 : public base {

      public:

        explicit d2(glm::uvec2 const&  /* size */  = default_size.xy(),
                    glm::uvec4 const&  /* color */ = default_color);
        explicit d2(std::string const& /* file */);
        virtual ~d2();

        virtual bool empty() const;
      
      private:

        gli::texture2D tdata_;
        
      };
      
      // variables, exported (extern)
      
      // functions, inlined (inline)
      
      // functions, exported (extern)

    } // namespace texture {

  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_D2_HPP)
