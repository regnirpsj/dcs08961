// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene_object_texture_shared.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_SHARED_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_SHARED_HPP

// includes, system

#include <string> // std::string

// includes, project

//#include <>

namespace gli {

  class storage;
  
} // namespace gli {

namespace scene {

  namespace object {

    namespace texture {
  
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)
      
      // functions, exported (extern)

      gli::storage load(std::string const& /* file name */);
      
    } // namespace texture {
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_SHARED_HPP)
