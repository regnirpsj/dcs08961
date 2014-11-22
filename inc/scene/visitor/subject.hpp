// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/subject.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_VISITOR_SUBJECT_HPP)

#define UKACHULLDCS_08961_SCENE_VISITOR_SUBJECT_HPP

// includes, system

//#include <>

// includes, project

#include <scene/export.h>

namespace scene {

  namespace visitor {

    class base;
    
    // types, exported (class, enum, struct, union, typedef)

    /**
     * \brief a visitor-subject base class
     *
     * a visitor-subject base class to inherit from if handling of a type by visitors is required.
     * derived types need to implement \c accept, usually like this:
     *
     * <code>
     *  class subject_derived : public scene::visitor::subject {
     *
     *  public:
     *
     *    virtual void accept(visitor::base& v)
     *    {
     *      v.visit(*this);
     *    }
     *  };
     * </code>
     *
     * application usage is usually like this:
     *
     * <code>
     *  {
     *    some_visitor v;
     *
     *    subject_derived.accept(v);
     *  }
     * </code>
     */
    class DCS08961_SCENE_EXPORT subject {

    public:

      virtual ~subject() =0;
      
      virtual void accept(visitor::base&) =0;
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace visitor {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_VISITOR_SUBJECT_HPP)
