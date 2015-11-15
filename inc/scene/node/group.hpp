// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/group.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_GROUP_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_GROUP_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <field/adapter/multi.hpp>
#include <scene/node/base.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT group : public base {
      
    public:

      using subject_inherited   = base;
      using children_field_type = field::adapter::multi<boost::intrusive_ptr<base>>;
      
      children_field_type children; ///< children

      explicit group();
      virtual ~group();
      
      virtual void accept(visitor::base&);

    protected:
      
      using children_list_type = children_field_type::value_container_type;
      using children_type      = children_field_type::value_type;

      children_list_type children_list_;
      
    private:
      
      children_list_type const& cb_get_children() const;
      children_list_type        cb_set_children(children_list_type const&);
      bool                      cb_add_child   (children_type const&);
      bool                      cb_sub_child   (children_type const&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_GROUP_HPP)
