// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/local_light.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_LOCAL_LIGHT_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_LOCAL_LIGHT_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <scene/node/group.hpp>
#include <scene/object/light/directional.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT local_light : public group {

    public:

      typedef group                                     subject_inherited;
      typedef boost::intrusive_ptr<object::light::base> source_ptr_type;
      
      field::value::single<source_ptr_type> source;
      
      explicit local_light();

      virtual void accept(visitor::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_LOCAL_LIGHT_HPP)
