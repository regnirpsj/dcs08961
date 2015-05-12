// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/pass/standard.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/ogl/pass/standard.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <render/ogl/context.hpp>

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

  namespace ogl {

    namespace pass {
      
      // variables, exported
  
      // functions, exported

      /* explicit */
      standard::standard(ogl::context& a)
        : render::pass::base(a),
          setup_            (a),
          clear_            (a),
          draw_             (a),
          swap_             (a)
      {
        TRACE("render::ogl::pass::standard::standard");
      }
      
      /* virtual */
      standard::~standard()
      {
        TRACE("render::ogl::pass::standard::~standard");
      }

      /* virtual */ void
      standard::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::ogl::pass::standard::print_on");

        render::pass::base::print_on(os);

        os << "\b,\n"
           << setup_ << ",\n"
           << clear_ << ",\n"
           << draw_  << ",\n"
           << swap_
           << ']';
      }
      
      /* virtual */ void
      standard::do_execute()
      {
        TRACE("render::ogl::pass::standard::do_execute");

        setup_.execute();
        clear_.execute();
        draw_. execute();
        swap_. execute();
      }

      /* virtual */ void
      standard::do_resize(glm::ivec2 const& a)
      {
        TRACE("render::ogl::pass::standard::do_resize");

        setup_.resize(a);
        clear_.resize(a);
        draw_. resize(a);
        swap_. resize(a);
      }
      
    } // namespace pass {
        
  } // namespace ogl {
    
} // namespace render {
