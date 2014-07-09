// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/update_bounds.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_VISITOR_UPDATE_BOUNDS_HPP)

#define UKACHULLDCS_08961_SCENE_VISITOR_UPDATE_BOUNDS_HPP

// includes, system

//#include <>

// includes, project

#include <scene/visitor/dfs.hpp>

namespace scene {

  namespace visitor {
    
    // types, exported (class, enum, struct, union, typedef)

    class update_bounds : public dfs {

    public:

      explicit update_bounds();
      virtual ~update_bounds();

      virtual void visit(node::geometry&);
      virtual void visit(node::group&);
      virtual void visit(node::transform&);

      virtual void print_on(std::ostream&) const;
      
    private:

      virtual void visit(subject&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
  } // namespace visitor {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_VISITOR_UPDATE_BOUNDS_HPP)
