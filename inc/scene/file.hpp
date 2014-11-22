// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/file.hpp                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_FILE_HPP)

#define UKACHULLDCS_08961_SCENE_FILE_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <string>                // std::string

// includes, project

#include <scene/export.h>

namespace scene {

  namespace node {

    class group;

  } // namespace node

  namespace file {
    
    // types, exported (class, enum, struct, union, typedef)
    
    enum class type {
      detect
    };
    
    class DCS08961_SCENE_EXPORT handler : private boost::noncopyable {

    public:
      
      static DCS08961_SCENE_EXPORT node::group* load(std::string const& /* name */,
                                                     type               /* type */ = type::detect);
      static DCS08961_SCENE_EXPORT bool         save(std::string const& /* name */,
                                                     node::group*       /* scene */,
                                                     type               /* type */ = type::detect);
                               
    };                         

    // variables, exported (extern)

    // functions, inlined (inline)

    // functions, exported (extern)

  } // namespace file {

} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_FILE_HPP)
