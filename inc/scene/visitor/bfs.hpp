// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/vistor/bfs.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_VISTOR_BFS_HPP)

#define UKACHULLDCS_08961_SCENE_VISTOR_BFS_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <queue>                   // std::queue<>

// includes, project

#include <scene/visitor/base.hpp>

namespace scene {

  namespace visitor {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT bfs : virtual public base {

    public:
      
      virtual ~bfs() =0;
      
      virtual void visit(node::group&);
      
      virtual void print_on(std::ostream&) const;      

    protected:

      using node_queue_type = std::queue<boost::intrusive_ptr<node::base>>;

      node_queue_type node_queue_;
      
      explicit bfs();

      virtual void flush();
      
    private:

      virtual void visit(subject&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace visitor {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_VISTOR_BFS_HPP)
