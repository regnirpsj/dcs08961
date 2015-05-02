// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/draw.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/stage/draw.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <scene/nodes.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace render {

  namespace base {

    namespace stage {
      
      // variables, exported
  
      // functions, exported
      
      /* virtual */
      draw::~draw()
      {
        TRACE("render::base::stage::draw::~draw");
      }
    
      /* virtual */ void
      draw::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::stage::draw::print_on");

        os << '[';
        
        base::print_on(os);

        os << ','
#if defined(UKACHULLDCS_USE_TRACE)
           << *scene_  << ',' << *camera_
#else
           << "root:" << scene_  << ",camera:" <<  camera_
#endif
           << ']';
      }

      /* explicit */
      draw::draw(context& a, scene::node::group* b, scene::node::camera* c, statistics::base& d)
        : base   (a, d),
          scene_ (b),
          camera_(c)
      {
        TRACE("render::base::stage::draw::draw");

        assert(nullptr != scene_.get());
        assert(nullptr != camera_.get());
      }

      /* virtual */ void
      draw::do_execute()
      {
        TRACE("render::base::stage::draw::do_execute");
      }
      
    } // namespace stage {
        
  } // namespace base {
  
} // namespace render {
