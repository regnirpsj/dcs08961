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

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <iosfwd>                  // std::ostream (fwd)
#include <unordered_set>           // std::unordered_set<>

// includes, project

#include <scene/visitor/dfs.hpp>
#include <support/hasher.hpp>

namespace scene {

  namespace visitor {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT cull : public dfs {

    public:

      typedef std::unordered_set<boost::intrusive_ptr<node::geometry>> visible_list_type;
      
      explicit cull(node::camera const&, visible_list_type&);
      virtual ~cull();

      virtual void visit(node::geometry&);
      virtual void visit(node::group&);
      
      virtual void print_on(std::ostream&) const;
      
    private:

      node::camera const& camera_;
      visible_list_type&  visible_list_;
      
      virtual void visit(subject&);
    
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace visitor {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_VISITOR_CULL_HPP)
