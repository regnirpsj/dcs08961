// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/vistor/dfs.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_VISTOR_DFS_HPP)

#define UKACHULLDCS_08961_SCENE_VISTOR_DFS_HPP

// includes, system

//#include <>

// includes, project

#include <scene/visitor/base.hpp>

namespace scene {

  namespace visitor {
    
    // types, exported (class, enum, struct, union, typedef)

    class dfs : virtual public base {

    public:
      
      virtual ~dfs() =0;
      
      virtual void visit(node::group&);
      
      virtual void print_on(std::ostream&) const;      

    protected:

      explicit dfs();

    private:

      virtual void visit(subject&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace visitor {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_VISTOR_DFS_HPP)
