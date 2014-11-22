// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture/d1.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_D1_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_D1_HPP

// includes, system

#include <gli/gli.hpp> // gli::texture?D

// includes, project

#include <scene/object/texture/base.hpp>

namespace scene {

  namespace object {

    namespace texture {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_SCENE_EXPORT d1 : public base {

      public:

        explicit d1(unsigned const&   /* size */  = default_size.x,
                    glm::uvec4 const& /* color */ = default_color);
        virtual ~d1();

        virtual bool empty() const;
      
      private:

        gli::texture1D tdata_;
        
      };
      
      // variables, exported (extern)
      
      // functions, inlined (inline)
      
      // functions, exported (extern)

    } // namespace texture {

  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_D1_HPP)
