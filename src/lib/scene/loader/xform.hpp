// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/loader/xform.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_LOADER_XFORM_HPP)

#define UKACHULLDCS_08961_SCENE_LOADER_XFORM_HPP

// includes, system

#include <string> // std::string

// includes, project

// #include <>

namespace scene {

  namespace node {

    class group;
    
  } // namespace node

  namespace file {

    namespace xform {
      
      // types, exported (class, enum, struct, union, typedef)
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      node::group* load(std::string const&);
      bool         save(std::string const&, node::group*);
      
    } // namespace xform {
    
  } // namespace file {

} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_LOADER_XFORM_HPP)
