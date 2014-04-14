// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/select.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_SELECT_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_SELECT_HPP

// includes, system

// #include <>

// includes, project

#include <scene/node/group.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class select : public group {

    public:

      typedef group subject_inherited;

      field::value::single<unsigned> index;
      
      explicit select();

      virtual void accept(visitor::base&);

    protected:

      virtual void do_changed(field::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_SELECT_HPP)
