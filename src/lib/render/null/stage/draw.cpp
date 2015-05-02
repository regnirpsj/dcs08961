// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/stage/draw.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/null/stage/draw.hpp"

// includes, system

//#include <>

// includes, project

#include <render/null/context.hpp>
#include <scene/nodes.hpp>
#include <scene/visitors.hpp>
#include <statistics.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class light_visitor : public scene::visitor::dfs {

    typedef render::null::stage::draw::light_list_type light_list_type;

  public:

    explicit light_visitor(light_list_type& a)
      : scene::visitor::dfs(),
        light_list_        (a)
    {
      TRACE("render::null:stage::draw::<unnamed>::light_visitor::light_visitor");
    }

  private:

    light_list_type& light_list_;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Woverloaded-virtual"

    virtual void visit(scene::node::global_light& a)
    {
      TRACE("render::null:stage::draw::<unnamed>::light_visitor::visit"
            "(scene::node::global_light&)");
      
      for (auto l : a.source.get()->representation.get()) {
        light_list_.push_back(l);
      }      
    }

#pragma clang diagnostic pop
    
    virtual void visit(scene::visitor::subject&)
    {
      TRACE_NEVER("render::null:stage::draw::<unnamed>::light_visitor::visit"
                  "(scene::visitor::subject&)");
    }

  };

  class material_visitor : public scene::visitor::dfs {

    typedef render::null::stage::draw::material_list_type material_list_type;

  public:

    explicit material_visitor(material_list_type& a)
      : scene::visitor::dfs(),
        material_list_     (a)
    {
      TRACE("render::null:stage::draw::<unnamed>::material_visitor::material_visitor");
    }

  private:

    material_list_type& material_list_;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Woverloaded-virtual"

    virtual void visit(scene::node::material_group& a)
    {
      TRACE("render::null:stage::draw::<unnamed>::material_visitor::visit"
            "(scene::node::material_group&)");

      material_list_.push_back(static_cast<scene::object::material::rep>(*a.material.get()));
    }
    
#pragma clang diagnostic pop
    
    virtual void visit(scene::visitor::subject&)
    {
      TRACE_NEVER("render::null:stage::draw::<unnamed>::material_visitor::visit"
                  "(scene::visitor::subject&)");
    }

  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

namespace render {

  namespace null {

    namespace stage {
      
      // variables, exported
  
      // functions, exported

      /* explicit */
      draw::draw(scene::node::group* a, scene::node::camera* b)
        : render::base::stage::draw(context::dflt, a, b, stats::dflt),
          scene_bbox_changed_      (!a->bbox->valid),
          light_list_              (),
          material_list_           ()
      {
        TRACE("render::null:stage::draw::draw");
      }
      
      /* virtual */
      draw::~draw()
      {
        TRACE("render::null:stage::draw::~draw");
      }

      /* virtual */ void
      draw::do_execute()
      {
        TRACE("render::null:stage::draw::do_execute");
        
        render::base::stage::draw::do_execute();

        scene_bbox_changed_ = !scene_->bbox->valid;

        if (scene_bbox_changed_) {
          {
            scene::visitor::update_bounds v;

            scene_->accept(v);
          }
        }
        
        {
          light_list_.clear();

          light_visitor v(light_list_);

          scene_->accept(v);
        }

        {
          material_list_.clear();

          material_visitor v(material_list_);

          scene_->accept(v);
        }
      }

    } // namespace stage {
    
  } // namespace null {
  
} // namespace render {
