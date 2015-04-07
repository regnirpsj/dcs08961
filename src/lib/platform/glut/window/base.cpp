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
#include <functional>     // std::bind<>, std::placeholders::*
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
      
      /* explicit */
      base::base(std::string const& a, rect const& b)
        : platform::window::base(a, b),
          id                    (*this, "id",
                                 std::bind(&base::cb_get_id, this),
                                 std::bind(&base::cb_set_id, this, std::placeholders::_1)),
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
          throw std::runtime_error("GLUT initialization error in <platform::glut::window::base>");
        }
        
        // glewExperimental = true;
    
        if (GLEW_OK != ::glewInit()) {
          throw std::runtime_error("GLEW initialization error in <platform::glut::window::base>");
        }

        flush_gl_errors(std::cerr);

        ::glutDisplayFunc     (&base::cb_display);
        ::glutEntryFunc       (&base::cb_entry);
        ::glutIdleFunc        (&base::cb_idle);
        ::glutWindowStatusFunc(&base::cb_window_status);
        
        window::manager::add(id_, this);
      }

      /* virtual */ void
      base::do_changed(field::base& f)
      {
        TRACE("platform::glut::window::base::do_changed" + exec_context(this));

        if      (&f == &title) {
          ::glutSetWindowTitle(title.get().c_str());
          ::glutSetIconTitle  (title.get().c_str());
        }

        else if (&f == &position) {
          if (glm::ivec2(::glutGet(GLUT_WINDOW_X),
                         ::glutGet(GLUT_WINDOW_Y)) != *position) {
            ::glutPositionWindow(position->x, position->y);
          }
        }
        
        else if (&f == &size) {
          if (glm::ivec2(::glutGet(GLUT_WINDOW_WIDTH),
                         ::glutGet(GLUT_WINDOW_HEIGHT)) != *size) {
            ::glutReshapeWindow(size->x, size->y);
          }
        }
          
        else {
          platform::window::base::do_changed(f);
        }
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

          // find the next glut window and make it current else 'glutMainLoop*' will operate on the
          // window removed by 'glutDestroyWindow', except if no window is around anymore
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
        TRACE_NEVER("platform::glut::window::base::cb_display");

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

      signed const&
      base::cb_get_id() const
      {
        TRACE_NEVER("platform::glut::window::base::cb_get_id");

        return id_;
      }
      
      signed
      base::cb_set_id(signed const&)
      {
        TRACE_NEVER("platform::glut::window::base::cb_set_id");

        return id_;
      }

      /* explicit */
      guard::guard()
        : boost::noncopyable(),
          id_               (-1)
      {
        TRACE("platform::glut::window::guard::guard");

        if (!platform::glut::application::base::initialized()) {
          throw std::runtime_error("<platform::glut::window::guard> requires an initialized "
                                   "instance of <platform::glut::application::base>");
        }

        id_ = ::glutGetWindow();
      }
      
      guard::~guard()
      {
        TRACE("platform::glut::window::guard::~guard");

        ::glutSetWindow(id_);
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
