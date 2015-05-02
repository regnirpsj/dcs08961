// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2013-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/loader/obj.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_SCENE_LOADER_OBJ_HPP)

#define UKACHULLDCS_SCENE_LOADER_OBJ_HPP

// includes, system

#include <iosfwd>       // std::istream, std::ostream (fwd decl)
#include <string>       // std::string
#include <forward_list> // std::forward_list<>

// includes, project

// #include <>

namespace scene {

  namespace node {

    class group;
    
  } // namespace node
  
  namespace file {

    namespace obj {
      
      // types, exported (class, enum, struct, union, typedef)

      using path_list_type = std::forward_list<std::string>;
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      node::group* load(std::istream&, path_list_type const& = path_list_type());
      node::group* load(std::string const&, path_list_type const& = path_list_type());
      bool         save(std::ostream&,      node::group*);
      bool         save(std::string const&, node::group*);
      
    } // namespace obj {
    
  } // namespace file {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_SCENE_LOADER_OBJ_HPP)
