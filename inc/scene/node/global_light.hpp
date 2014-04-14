// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/global_light.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_GLOBAL_LIGHT_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_GLOBAL_LIGHT_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <scene/node/base.hpp>
#include <scene/object/light/directional.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class global_light : public base {

    public:

      typedef base subject_inherited;

      field::value::single<boost::intrusive_ptr<object::light::base>> source;
      
      explicit global_light(std::string const& /* name */);

      virtual void accept(visitor::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_GLOBAL_LIGHT_HPP)
