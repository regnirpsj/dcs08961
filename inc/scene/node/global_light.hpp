// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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
#include <scene/object/light/base.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT global_light : public base {

    public:

      using subject_inherited = base;
      using source_ptr_type   = boost::intrusive_ptr<object::light::base>;
      
      field::value::single<source_ptr_type> source; ///< source
      
      explicit global_light();

      virtual void accept(visitor::base&);

    protected:

      virtual void do_changed(field::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_GLOBAL_LIGHT_HPP)
