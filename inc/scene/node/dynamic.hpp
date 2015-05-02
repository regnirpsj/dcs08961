// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/dynamic.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_DYNAMIC_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_DYNAMIC_HPP

// includes, system

// #include <>

// includes, project

#include <scene/node/transform.hpp>
#include <support/chrono.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT dynamic : public transform {

    public:

      using subject_inherited = transform;
      using time_point        = support::clock::time_point;

      field::value::single<time_point> update;
      
      virtual ~dynamic() =0;
      
      virtual void accept(visitor::base&);

    protected:

      time_point last_update_;
      
      explicit dynamic();
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_DYNAMIC_HPP)
