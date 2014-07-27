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
#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>            // glm::io::*
#include <glm/gtx/transform.hpp>
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

  /* static */ void
  application::flush_gl_errors(std::ostream& os)
  {
    TRACE("glut::application::flush_gl_errors");

    unsigned error(::glGetError());
    
    if (GL_NO_ERROR != error) {
      do {
        os << "GL error: "
           << ::glewGetErrorString(error)
           << " ("
           <<                                                  error << "|0x"
           << std::hex << std::setfill('0') << std::setw(4) << error 
           << ')'
           << std::endl;
      } while (GL_NO_ERROR != (error = ::glGetError()));
    }
  }
  
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

    using glm::io::operator<<;
    
    os << "\b,"
       << "[camera"
       << camera_.xform
       << "\n],[frame:";

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
      
      os << glm::io::width(4)
         << m.button << ','
         << m.state << ','
         << m.pos;
    } else {
      os << "<no values>";
    }

    os << "],[proj],[win:"
       << glm::io::width(4)
       << window_.id << ','
       << (window_.fullscreen ? "fullscreen" : "windowed") << ','
       << window_.pos << ','
       << window_.size
       << "]]";

    os << std::flush;
  }
  
  /* explicit */
  application::application(int argc, char* argv[])
    : inherited  (argc, argv),
      queue_max_ (4),
      frameq_    (),
      keyboardq_ (),
      mouseq_    (),
      camera_    ({ glm::mat4() }),
      projection_({ glm::mat4(), 53.0, glm::vec2(0.01, 100.0) }),
      window_    ({ -1, false, glm::ivec2(90,40), glm::ivec2(1440,900), false })
  {
    TRACE("glut::application::application");

    {
      namespace po = boost::program_options;

      po::options_description common("Command-Line Options");
        
      common.add_options()
        ("file,f",
         po::value(&input_files_)->composing(),
         "input file(s)\n"
         "positional arguments are accumulated as input files");

      cmdline_options_    .add(common);
      cmdline_positionals_.add("file", -1);
      
      support::application::single_instance::cmdline_process(argc, argv);
    }
    
    ::glutInit              (&argc, argv);
    ::glutInitDisplayMode   (GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
    ::glutInitWindowPosition(window_.pos.x,  window_.pos.y);
    ::glutInitWindowSize    (window_.size.x, window_.size.y);
    
    if (0 >= (window_.id = ::glutCreateWindow(argv[0]))) {
      throw std::runtime_error("GLUT initialization error");
    }

    // glewExperimental = true;
    
    if (GLEW_OK != ::glewInit()) {
      throw std::runtime_error("GLEW initialization error");
    }

    flush_gl_errors(std::cerr);

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
  }
  
  /* virtual */
  application::~application()
  {
    TRACE("glut::application::~application");

#if 0
    if (0 < window_.id) {
      ::glutDestroyWindow(window_.id); window_.id = -1;
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

    if (window_.show_stats && (1 < frameq_.size())) {  
      std::deque<support::clock::duration> durations;

      for (unsigned i(0); i < (frameq_.size() - 1); ++i) {
        // unfortunately, 'std::adjacent_difference' will not work because it would require to
        // assign a timepoint to a duration (for the first element)
        durations.push_back(frameq_[i+1].stamp - frameq_[i].stamp);
      }

      support::clock::duration const avg(std::accumulate(durations.begin(), durations.end(),
                                                         std::chrono::nanoseconds(0)) /
                                         durations.size());

      typedef std::chrono::duration<double> dsec;
        
      std::cout << std::right
                << std::fixed
                << std::setfill(' ')
                << std::setw(4)
                << std::setprecision(1)
                << "fps: "   << (1.0 / std::chrono::duration_cast<dsec>(durations.back()).count())
                << " (avg: " << (1.0 / std::chrono::duration_cast<dsec>(avg).count()) << ')'
                << std::endl;
    }
    
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
        (window_.fullscreen = !window_.fullscreen) ? ::glutFullScreen() : ::glutLeaveFullScreen();
      }
      break;

    case 's':
      {
        window_.show_stats = !window_.show_stats;
      }
      break;
      
    default:
      break;
    }
  }

  /* virtual */ void
  application::mouse(signed, signed, glm::ivec2 const&)
  {
    TRACE("glut::application::mouse");
  }  

  /* virtual */ void
  application::reshape(glm::ivec2 const& size)
  {
    TRACE("glut::application::reshape");

    projection_.xform = glm::perspective(projection_.fovy_degree * 3.1415f / 180.f,
                                         float(size.x) / float(size.y),
                                         projection_.near_far.x, projection_.near_far.y);
  }

  /* virtual */ void
  application::special(signed key, glm::ivec2 const&)
  {
    TRACE("glut::application::special");

    switch (key) {
    case GLUT_KEY_DOWN:
    case GLUT_KEY_LEFT:
    case GLUT_KEY_PAGE_DOWN:
    case GLUT_KEY_PAGE_UP:
    case GLUT_KEY_RIGHT:
    case GLUT_KEY_UP:
      {
        switch (::glutGetModifiers()) {
        case GLUT_ACTIVE_ALT: // translate
          {
            float factor(0.05);

            switch (::glutGetModifiers()) {
            case GLUT_ACTIVE_CTRL:  factor *= 4.0; break;
            case GLUT_ACTIVE_SHIFT: factor *= 8.0; break;
            default:                               break;
            }
          
            glm::vec3 incr;
          
            switch (key) {
            case GLUT_KEY_DOWN:      incr.y -= factor; break;
            case GLUT_KEY_LEFT:      incr.x -= factor; break;
            case GLUT_KEY_PAGE_DOWN: incr.z += factor; break;
            case GLUT_KEY_PAGE_UP:   incr.z -= factor; break;
            case GLUT_KEY_RIGHT:     incr.x += factor; break;
            case GLUT_KEY_UP:        incr.y += factor; break;
            }
            
            camera_.xform *= glm::translate(incr);
          }
          break;
          
        default: // rotate
          {
            float angle(1.0);

            switch (::glutGetModifiers()) {
            case GLUT_ACTIVE_CTRL:  angle *=  5.0; break;
            case GLUT_ACTIVE_SHIFT: angle *= 10.0; break;
            default:                                break;
            }
          
            glm::vec3 axis;
          
            switch (key) {
            case GLUT_KEY_DOWN:  axis.x -= 1; break;
            case GLUT_KEY_LEFT:  axis.y += 1; break;
            case GLUT_KEY_RIGHT: axis.y -= 1; break;
            case GLUT_KEY_UP:    axis.x += 1; break;
            }
            
            switch (key) {
            case GLUT_KEY_PAGE_DOWN:
            case GLUT_KEY_PAGE_UP:
              break;

            default:
              camera_.xform *= glm::rotate(angle * 3.1415f / 180.f, axis);
              break;
            }
          }
          break;
        }
      }
      break;
      
    default:
      break;
    }
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

    glm::ivec2 const size(w, h);
    
    if (!app->window_.fullscreen) {
      app->window_.pos  = glm::ivec2(::glutGet(GLUT_WINDOW_X), ::glutGet(GLUT_WINDOW_Y));
      app->window_.size = size;
    }
    
    app->reshape(size);
  }

  /* static */ void
  application::special_cb(signed key, signed x, signed y)
  {
    TRACE("glut::application::special_cb");

    application* app(static_cast<application*>(instance_));

    update_queue(app->keyboardq_, { key, ::glutGetModifiers() }, app->queue_max_);
    
    static_cast<application*>(instance_)->special(key, glm::ivec2(x, y));
  }

  void
  print_std_error_common(std::exception& ex, std::ostream& os, std::string const& prefix)
  {
    TRACE_NEVER("glut::print_std_error_common");
    
    os << prefix << '\n'
       << "Message: '" << ex.what() << "'"
       << std::endl;
  }
  
  void
  print_error_common(oglplus::Error& error, std::ostream& os, std::string const& prefix)
  {
    TRACE_NEVER("glut::print_error_common");

    os << prefix << '\n';
    
    if (error.SourceFile()) {
      os << "Source file: '" << error.SourceFile() << "'\n";
    }

    if (error.SourceLine()) {
      os << "Source line: " << error.SourceLine() << '\n';
    }

    if (error.SourceFunc()) {
      os << "Source function: '" << error.SourceFunc() << "'\n";
    }
    
    print_std_error_common(error, os, prefix);
    
    if (error.GLFunc()) {
      os << "GL function: '";

      if (error.GLLib()) {
        os << error.GLLib();
      }

      os << error.GLFunc() << "'\n";
    }

    if (error.EnumParam() || error.EnumParamName()) {
      os << "GL constant: ";
      if (error.EnumParamName()) {
        os << "'" << error.EnumParamName() << "'";
      } else {
        os << "(0x" << std::hex << error.EnumParam() << ")";
      }
      os << '\n';
    }

    if (error.BindTarget() || error.TargetName()){
      os << "Binding point: ";
      if (error.TargetName()) {
        os << "'" << error.TargetName() << "'";
      } else {
        os << "(0x" << std::hex << error.BindTarget() << ")";
      }
      os << '\n';
    }

    if (error.ObjectTypeName() || error.ObjectType()) {
      os << "Object type: ";
      if (error.ObjectTypeName()) {
        os << "'" << error.ObjectTypeName() << "'";
      } else {
        os << "(0x" << std::hex << error.ObjectType() << ")";
      }
      os << '\n';
    }

    if ((!error.ObjectDesc().empty()) || (0 <= error.ObjectName())) {
      os << "Object: ";
      if (!error.ObjectDesc().empty()) {
        os << "'" << error.ObjectDesc() << "'";
      } else {
        os << "(" << error.ObjectName() << ")";
      }
      os << '\n';
    }

    if (error.SubjectTypeName() || error.SubjectType()) {
      os << "Subject type: ";
      if (error.SubjectTypeName()) {
        os << "'" << error.SubjectTypeName() << "'";
      } else {
        os << "(0x" << std::hex << error.SubjectType() << ")";
      }
      os << '\n';
    }

    if ((!error.SubjectDesc().empty()) || (0 <= error.SubjectName())) {
      os << "Subject: ";
      if (!error.SubjectDesc().empty()) {
        os << "'" << error.SubjectDesc() << "'";
      } else {
        os << "(" << error.SubjectName() << ")";
      }
      os << '\n';
    }

    if (error.Identifier()) {
      os << "Identifier: '" << error.Identifier() << "'\n";
    }

    if (0 <= error.Index()) {
      os << "Index: (" << error.Index() << ")\n";
    }

    if (0 != error.Value()) {
      os << "Value: (" << error.Value() << ")\n";
    }

    if (0 != error.Limit()) {
      os << "Limit: (" << error.Limit() << ")\n";
    }

    if (!error.Log().empty()) {
      os << "Log:\n" << error.Log() << '\n';
    }

    os << std::flush;
  }
  
} // namespace glut {
