// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene_object_texture_fill.hpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_FILL_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_FILL_HPP

// includes, system

//#include <>

// includes, project

// #include <>

namespace scene {

  namespace object {

    namespace texture {
  
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)

      template <typename T, typename C>
      void fill(T& /* target */, C const& /* proto */);
      
      // functions, exported (extern)
  
    } // namespace texture {
    
  } // namespace object {
  
} // namespace scene {

#include <object/texture/fill.inl>

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_FILL_HPP)
