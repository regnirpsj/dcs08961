// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/cull.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_VISITOR_CULL_HPP)

#define UKACHULLDCS_08961_SCENE_VISITOR_CULL_HPP

// includes, system

#include <iosfwd> // std::ostream (fwd)

// includes, project

#include <scene/visitor/dfs.hpp>

namespace scene {

  namespace visitor {
    
    // types, exported (class, enum, struct, union, typedef)

    class cull : public dfs {

    public:
    
      explicit cull(node::camera const&);
      virtual ~cull();

      virtual void visit(node::geometry&);
      virtual void visit(node::group&);
      
      virtual void print_on(std::ostream&) const;
      
    private:

      node::camera const& camera_;
      
      virtual void visit(subject&);
    
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace visitor {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_VISITOR_CULL_HPP)
