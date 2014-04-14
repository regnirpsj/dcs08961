// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/base.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_BASE_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_BASE_HPP

// includes, system

#include <string> // std::string

// includes, project

#include <field/container.hpp>
#include <field/value/single.hpp>
#include <support/refcounted.hpp>

namespace scene {

  namespace object {
    
    // types, exported (class, enum, struct, union, typedef)

    class base : public field::container,
                 public support::refcounted {

    public:

      field::value::single<std::string> name;
      
      virtual ~base() =0;
      
      virtual void print_on(std::ostream&) const;
      
    protected:
      
      explicit base();
      
      virtual void do_changed(field::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace object {

} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_BASE_HPP)
