// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/base.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glut/window/base.hpp"

// includes, system

// needs to be first!!!
#include <GL/glew.h>      // GLEWContext, ::glew*

#include <GL/freeglut.h>  // ::glut*
#include <glm/gtx/io.hpp> // glm::operator<< (field::container::print_on)
#include <iomanip>        // std::setfill, std::setw
#include <iostream>       // std::cerr
#include <stdexcept>      // std::logic_error

// includes, project

#include <platform/glut/application/base.hpp>
#include <platform/glut/window/manager.hpp>
#include <window/helper.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal
  
} // namespace {

namespace platform {

  namespace glut {

    namespace window {
  
      // variables, exported

      /* static */ base::rect const base::dflt_rect(100, 100, 800, 600);
      
      // functions, exported

      /* virtual */
      base::~base()
      {
        TRACE("platform::glut::window::base::~base" + exec_context(this));

        close();
      }
      
      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("platform::glut::window::base::print_on" + exec_context(this));

        platform::window::base::print_on(os);
      }
      
      /* explicit */
      base::base(std::string const& a, rect const& b)
        : platform::window::base(a, b),
          id_                   (-1)
      {
        TRACE("platform::glut::window::base::base" + exec_context(this));

        if (!platform::glut::application::base::initialized()) {
          throw std::runtime_error("<platform::glut::window::base> (and derived types) require an "
                                   "initialized instance of <platform::glut::application::base>");
        }
        
        ::glutInitWindowPosition(position->x,  position->y);
        ::glutInitWindowSize    (size->x,      size->y);
    
        if (0 >= (id_ = ::glutCreateWindow(title.get().c_str()))) {
          throw std::runtime_error("GLUT initialization error");
        }
        
        // glewExperimental = true;
    
        if (GLEW_OK != ::glewInit()) {
          throw std::runtime_error("GLEW initialization error");
        }

        flush_gl_errors(std::cerr);

        ::glutDisplayFunc     (&base::cb_display);
        ::glutEntryFunc       (&base::cb_entry);
        ::glutIdleFunc        (&base::cb_idle);
        ::glutWindowStatusFunc(&base::cb_window_status);
        
        window::manager::add(id_, this);
      }

      /* virtual */ void
      base::close()
      {
        TRACE("platform::glut::window::base::close" + exec_context(this));

        if (window::manager::get(id_)) {
#if 0
          {
            std::cout << "platform::glut::window::base::close" << exec_context(this) << ": "
                      << "closing window #" << id_
                      << '\n';
          }
#endif
          
          window::manager::sub(id_);

          ::glutDestroyWindow(id_);

          for (auto id : window::manager::all()) {
            if (id != id_) {
              ::glutSetWindow(id);

              break;
            }
          }
        }
      }
      
      /* virtual */ void
      base::display()
      {
        TRACE("platform::glut::window::base::display" + exec_context(this));

        throw std::logic_error("pure virtual function "
                               "'platform::glut::window::base::display' called");
      }
      
      /* virtual */ void
      base::entry(signed)
      {
        TRACE("platform::glut::window::base::entry" + exec_context(this));
      }
      
      /* virtual */ void
      base::idle()
      {
        TRACE("platform::glut::window::base::idle" + exec_context(this));

        ::glutPostWindowRedisplay(id_);
      }

      /* virtual */ void
      base::status(signed)
      {
        TRACE("platform::glut::window::base::status" + exec_context(this));

        ::glutPostWindowRedisplay(id_);
      }      
      
      /* static */ void
      base::cb_display()
      {
        TRACE("platform::glut::window::base::cb_display");

        base* w(static_cast<base*>(window::manager::get(::glutGetWindow())));

        if (w) {
          w->display();
        }
      }
      
      /* static */ void
      base::cb_entry(signed a)
      {
        TRACE("platform::glut::window::base::cb_entry");

        base* w(static_cast<base*>(window::manager::get(::glutGetWindow())));

        if (w) {
          w->entry(a);
        }
      }
      
      /* static */ void
      base::cb_idle()
      {
        TRACE("platform::glut::window::base::cb_idle");

        base* w(static_cast<base*>(window::manager::get(::glutGetWindow())));

        if (w) {
          w->idle();
        }
      }
      
      /* static */ void
      base::cb_window_status(signed a)
      {
        TRACE("platform::glut::window::base::cb_window_status");

        base* w(static_cast<base*>(window::manager::get(::glutGetWindow())));

        if (w) {
          w->status(a);
        }
      }
      
      /* static */ void
      flush_gl_errors(std::ostream& os)
      {
        TRACE("platform::glut::window::flush_gl_errors");

        unsigned error(::glGetError());

        if (GL_NO_ERROR != error) {
          do {
            os << "GL error: "
               << ::glewGetErrorString(error)
               << " ("
               <<                                                  error << "|0x"
               << std::hex << std::setfill('0') << std::setw(4) << error
               << ")\n";
          } while (GL_NO_ERROR != (error = ::glGetError()));
        }
      }
      
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
