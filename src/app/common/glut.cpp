// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/glut.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "glut.hpp"

// includes, system

// needs to be first!!!
#include <GL/glew.h>                 // ::glew*

#include <GL/freeglut.h>             // ::glut*
#include <cstdlib>                   // EXIT_[SUCCESS|FAILURE]
#include <glm/gtx/io.hpp>            // glm::io::*
#include <iomanip>                   // std::setfill, std::setw
#include <oglplus/config/gl.hpp>     // 

#include <stdexcept>                 // std::logic_error

// includes, project

#include <support/chrono_io.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  template <typename T>
  inline void
  update_queue(std::deque<T>& q, T const& e, unsigned l)
  {
    q.push_back(e);

    if (q.size() > l) {
      q.pop_front();
    }
  }
  
} // namespace {

namespace glut {
  
  // variables, exported
  
  // functions, exported

  /* virtual */ signed
  application::run()
  {
    TRACE("glut::application::run");
    
    ::glutMainLoop();
    
    return EXIT_SUCCESS;
  }

  /* virtual */ void
  application::print_on(std::ostream& os) const
  {
    TRACE_NEVER("glut::application::print_on");

    support::application::single_instance::print_on(os);
    
    os << "\b,"
       << "[frame:";

    if (!frameq_.empty()) {
      typedef std::chrono::duration<double> dsec;
      
      auto const f((2 <= frameq_.size()) ? frameq_[frameq_.size() - 2] : frameq_.back());
      
      os << std::fixed
         << std::right
         << std::setprecision(3)
         << std::setfill('0')
         << std::setw(5) << f.counter << ','
         << std::chrono::duration_fmt(std::chrono::symbol)
         << std::chrono::duration_cast<dsec>(f.duration) << ','
         << std::setprecision(2)
         << (1.0 / std::chrono::duration_cast<dsec>(f.duration).count()) << " Hz";
    } else {
      os << "<no values>";
    }

    os << "],[kbd:";
    
    if (!keyboardq_.empty()) {
      auto const& k(keyboardq_.back());
      std::string tmp;
      
      if (GLUT_ACTIVE_ALT   & k.modifier) { tmp += "ALT|";   }
      if (GLUT_ACTIVE_CTRL  & k.modifier) { tmp += "CTRL|";  }
      if (GLUT_ACTIVE_SHIFT & k.modifier) { tmp += "SHIFT|"; }

      if (tmp.empty()) {
        tmp = "[NONE]";
      } else {
        tmp.pop_back();
        
        tmp = "[" + tmp + "]";
      }
      
      os << static_cast<unsigned char>(k.key - '\0') << ',' << tmp;
    } else {
      os << "<no values>";
    }
    
    os << "],[mouse:";

    if (!mouseq_.empty()) {
      auto const& m(mouseq_.back());

      using glm::io::operator<<;
      
      os << glm::io::width(4)
         << m.button << ','
         << m.state << ','
         << m.pos;
    } else {
      os << "<no values>";
    }

    {
      using glm::io::operator<<;
      
      os << "],[win:"
         << glm::io::width(4)
         << window_.id << ','
         << (window_.fullscreen ? "fullscreen" : "windowed") << ','
         << window_.pos << ','
         << window_.size << ','
         << window_.title
         << "]]";
    }
  }
  
  /* explicit */
  application::application(int argc, char* argv[])
    : support::application::single_instance(argc, argv),
      queue_max_                           (7),
      frameq_                              (),
      keyboardq_                           (),
      mouseq_                              (),
      window_                              ({ -1, false, glm::ivec2(-1,-1), glm::ivec2(800,600),
                                              "<window title>" })
  {
    TRACE("glut::application::application");

    ::glutInit              (&argc, argv);
    ::glutInitDisplayMode   (GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
    ::glutInitWindowPosition(window_.pos.x, window_.pos.y);
    ::glutInitWindowSize    (window_.size.x, window_.size.y);

    if (0 >= (window_.id = ::glutCreateWindow(window_.title.c_str()))) {
      throw std::runtime_error("GLUT initialization error");
    }
    
    if (GLEW_OK != ::glewInit()) {
      throw std::runtime_error("GLEW initialization error");
    }

    ::glGetError();

    ::glutDisplayFunc      (&application::display_cb);
    ::glutIdleFunc         (&application::idle_cb);
    ::glutKeyboardFunc     (&application::keyboard_cb);
    ::glutMouseFunc        (&application::mouse_cb);
    ::glutMotionFunc       (&application::motion_cb);
    ::glutPassiveMotionFunc(&application::passive_cb);
    ::glutReshapeFunc      (&application::reshape_cb);
    ::glutSpecialFunc      (&application::special_cb);

    ::glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
                    GLUT_ACTION_GLUTMAINLOOP_RETURNS);

    support::application::single_instance::cmdline_process(argc, argv);
  }

  /* virtual */
  application::~application()
  {
    TRACE("glut::application::~application");

#if 0
    if (0 < window_.id) {
      ::glutDestroyWindow(window_.id);

      window_.id = -1;
    }
#endif
  }

  /* virtual */ void
  application::frame_render_one()
  {
    TRACE("glut::application::frame_render_one");

    throw std::logic_error("pure virtual function 'glut::application::frame_render_one' called");
  }
  
  /* virtual */ void
  application::frame_render_post()
  {
    TRACE("glut::application::frame_render_post");

    ::glutSwapBuffers();

    if (!frameq_.empty()) {
      static support::clock::duration const base60hz(std::chrono::nanoseconds(16666600));
      
      support::clock::duration       limit  (base60hz);
      support::clock::duration const current(support::clock::now() - frameq_.back().stamp);
      
      while (limit < current) {
        limit += base60hz;
      }
      
      support::sleep(limit - current);
    }
  }
  
  /* virtual */ void
  application::frame_render_pre()
  {
    TRACE("glut::application::frame_render_pre");

    frame_info_t current({ 1, support::clock::now(), std::chrono::nanoseconds(0) });

    if (!frameq_.empty()) {
      auto& prev(frameq_.back());

      current.counter += prev.counter;
      prev.duration    = current.stamp - prev.stamp;
    }
    
    update_queue(frameq_, current, queue_max_);
  }
  
  /* virtual */ void
  application::idle()
  {
    TRACE("glut::application::idle");

    ::glutPostRedisplay();
  }

  /* virtual */ void
  application::keyboard(unsigned char key, glm::ivec2 const&)
  {
    TRACE("glut::application::keyboard");

    switch (key) {
    case 0x1B: // ESC
      ::glutLeaveMainLoop();
      break;

    case 'f': // fullscreen toggle
      {
        window_.fullscreen = !window_.fullscreen;
        
        if (!window_.fullscreen) {
          ::glutReshapeWindow(window_.size.x, window_.size.y);
        } else {
          ::glutFullScreen();
        }
      }
      break;
      
    default:
      break;
    }
  }

  /* virtual */ void
  application::mouse(signed, signed, glm::ivec2 const&)
  {
    TRACE("glut::application::keyboard");
  }  

  /* virtual */ void
  application::reshape(glm::ivec2 const&)
  {
    TRACE("glut::application::reshape");

    throw std::logic_error("pure virtual function 'glut::application::reshape' called");
  }
  
  /* virtual */ void
  application::display()
  {
    TRACE("glut::application::display");

    frame_render_pre ();
    frame_render_one ();
    frame_render_post();
  }  

  /* static */ void
  application::display_cb()
  {
    TRACE("glut::application::display_cb");

    static_cast<application*>(instance_)->display();
  }

  /* static */ void
  application::idle_cb()
  {
    TRACE("glut::application::idle_cb");

    static_cast<application*>(instance_)->idle();
  }
  
  /* static */ void
  application::keyboard_cb(unsigned char key, signed x, signed y)
  {
    TRACE("glut::application::keyboard_cb");

    application* app(static_cast<application*>(instance_));

    update_queue(app->keyboardq_, { key, ::glutGetModifiers() }, app->queue_max_);
    
    app->keyboard(key, glm::ivec2(x, y));
  }

  /* static */ void
  application::motion_cb(signed, signed)
  {
    TRACE("glut::application::motion_cb");
  }

  /* static */ void
  application::mouse_cb(signed btn, signed state, signed x, signed y)
  {
    TRACE("glut::application::mouse_cb");

    application* app(static_cast<application*>(instance_));

    update_queue(app->mouseq_, { btn, state,  glm::ivec2(x, y) }, app->queue_max_);
    
    app->mouse(btn, state, glm::ivec2(x, y));
  }
  
  /* static */ void
  application::passive_cb(signed, signed)
  {
    TRACE("glut::application::passive_cb");
  }

  /* static */ void
  application::reshape_cb(signed w, signed h)
  {
    TRACE("glut::application::reshape_cb");

    application* app(static_cast<application*>(instance_));

    if (!app->window_.fullscreen) {
      app->window_.pos  = glm::ivec2(::glutGet(GLUT_WINDOW_X), ::glutGet(GLUT_WINDOW_Y));
      app->window_.size = glm::ivec2(w, h);
    }
    
    app->reshape(app->window_.size);
  }

  /* static */ void
  application::special_cb(signed key, signed x, signed y)
  {
    TRACE("glut::application::special_cb");

    application* app(static_cast<application*>(instance_));

    update_queue(app->keyboardq_, { key, ::glutGetModifiers() }, app->queue_max_);
    
    static_cast<application*>(instance_)->keyboard(key, glm::ivec2(x, y));
  }
  
} // namespace glut {
