// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/print.hpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_VISITOR_PRINT_HPP)

#define UKACHULLDCS_08961_SCENE_VISITOR_PRINT_HPP

// includes, system

//#include <>

// includes, project

#include <scene/visitor/bfs.hpp>
#include <scene/visitor/dfs.hpp>

namespace scene {

  namespace visitor {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT print : public bfs,
                                        public dfs {

    public:

      enum class order { bfs, dfs, };
    
      explicit print(std::ostream&, order = order::dfs);
      virtual ~print();

      virtual void visit(node::base&);
      virtual void visit(node::group&);
      
      virtual void print_on(std::ostream&) const;
      
    private:
    
      std::ostream& os_;
      order         order_;
      unsigned      indent_;
      char          crlf_;
      
      virtual void visit(subject&);
      
      template <typename T> void visit_helper(T&);
    
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace visitor {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_VISITOR_PRINT_HPP)
