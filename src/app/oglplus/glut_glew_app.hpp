// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/glut_glew_app.hpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLUT_GLEW_APP_HPP)

#define UKACHULLDCS_08961_APP_OGLPLUS_GLUT_GLEW_APP_HPP

// includes, system

// needs to be first!!!
#include <GL/glew.h>                 // ::glew*

#include <GL/freeglut.h>             // ::glut*
#include <boost/noncopyable.hpp>     // boost::noncopyable
#include <cstdlib>                   // EXIT_SUCCESS
#include <glm/glm.hpp>               // glm::uvec2
#include <iostream>                  // std::c[err|out]
#include <oglplus/config/gl.hpp>     // 
#include <oglplus/error/program.hpp> //
#include <oglplus/error/limit.hpp>   //
#include <string>                    // std::string

// includes, project

#include <support/chrono.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace oglplus {
  
  // types, exported (class, enum, struct, union, typedef)

  class standalone : private boost::noncopyable {

  public:

    standalone()
      : boost::noncopyable(),
        frame_counter_    (0),
        frame_duration_   (),
        key_              (),
        mouse_last_       (0, 0),
        mouse_now_        (0, 0),
        size_             (800, 600),
        time_last_        (support::clock::now())
    {
      TRACE("oglplus::standalone::standalone");
    }

    virtual ~standalone()
    {
      TRACE("oglplus::standalone::~standalone");
    }

    void handle_key_press(unsigned char k, glm::uvec2 const& p)
    {
      TRACE("oglplus::standalone::handle_key_press");

      key_ = k;
      handle_mouse_move(p);
    }
    
    void handle_mouse_move(glm::uvec2 const& p)
    {
      TRACE("oglplus::standalone::handle_mouse_move");

      mouse_last_ = mouse_now_;
      mouse_now_  = p;
    }
    
    void handle_resize(glm::uvec2 const& s)
    {
      TRACE("oglplus::standalone::handle_resize");

      size_ = s;
    }

    void handle_update()
    {
      TRACE("oglplus::standalone::handle_update");

      auto const now(support::clock::now());

      frame_duration_ = now - time_last_;
      time_last_      = now;
      
      ++frame_counter_;
    }
    
    virtual void key_press()
    {
      TRACE("oglplus::standalone::key_press");
    }
    
    virtual void motion()
    {
      TRACE("oglplus::standalone::motion");
    }
    
    virtual void passive_motion()
    {
      TRACE("oglplus::standalone::passive_motion");
    }
    
    virtual void render()  =0;
    virtual void reshape() =0;

    virtual void startup(glm::uvec2 const& s)
    {
      TRACE("oglplus::standalone::startup");
      
      handle_resize(s);
      reshape();

      handle_mouse_move(size_ / unsigned(2));
      handle_mouse_move(size_ / unsigned(2));
      passive_motion();

      time_last_ = support::clock::now();
    
      handle_update();
    }
    
  protected:

    unsigned                   frame_counter_;
    support::clock::duration   frame_duration_;
    unsigned                   key_;
    glm::uvec2                 mouse_last_;
    glm::uvec2                 mouse_now_;
    glm::uvec2                 size_;
    support::clock::time_point time_last_;
    
  };

  template <typename T>
  class standalone_singleton : private boost::noncopyable {

  public:

    standalone_singleton()
      : boost::noncopyable()
    {
      TRACE("oglplus::standalone_singleton::standalone_singleton");
      
      assert(!instance());

      instance() = new T;
    }

    ~standalone_singleton()
    {
      TRACE("oglplus::standalone_singleton::~standalone_singleton");
      
      delete instance();
    }
    
    static void close()
    {
      TRACE("oglplus::standalone_singleton::close");
      
      assert(instance());

      delete instance();

      instance() = nullptr;
    }

    static void display()
    {
      TRACE("oglplus::standalone_singleton::display");
      
      assert(instance());

      instance()->handle_update();
      instance()->render();
      
      ::glutSwapBuffers();
    }

    static void keyboard(unsigned char k, signed x, signed y)
    {
      TRACE("oglplus::standalone_singleton::keyboard");
      
      switch (k) {
      case 0x1B: // ESC
        {
          ::glutLeaveMainLoop();
          
          std::exit(EXIT_SUCCESS);
        }
        break;

      default:
        {
          assert(instance());

          instance()->handle_key_press(k, glm::uvec2(x, y));
          instance()->key_press();
        }
      }
    }
    
    static void motion(signed x, signed y)
    {
      TRACE("oglplus::standalone_singleton::motion");
      
      assert(instance());

      instance()->handle_mouse_move(glm::uvec2(x, y));
      instance()->motion();
    }

    static void passive_motion(signed x, signed y)
    {
      TRACE("oglplus::standalone_singleton::passive_motion");
      
      assert(instance());

      instance()->handle_mouse_move(glm::uvec2(x, y));
      instance()->passive_motion();
    }
    
    static void reshape(signed w, signed h)
    {
      TRACE("oglplus::standalone_singleton::reshape");
      
      assert(instance());

      instance()->handle_resize(glm::uvec2(w, h));
      instance()->reshape();
    }

    static void startup(glm::uvec2 const& s)
    {
      TRACE("oglplus::standalone_singleton::startup");
      
      assert(instance());

      instance()->startup(s);
    }
    
  private:

    static T*& instance()
    {
      TRACE("oglplus::standalone_singleton::instance");
      
      static T* result = nullptr;

      return result;
    }
    
  };

  class glew_init : private boost::noncopyable {

  protected:

    glew_init()
      : boost::noncopyable()
    {
      TRACE("oglplus::glew_init::glew_init");
      
      if(GLEW_OK != ::glewInit()) {
        throw std::runtime_error("GLEW initialization error");
      }
      
      ::glGetError();
    }

  };

  class glut_init : private boost::noncopyable {

  protected:

    glut_init(glm::uvec2 const& p, glm::uvec2 const& s,
              std::string const& t, signed& argc, char* argv[])
      : boost::noncopyable()
    {
      TRACE("oglplus::glut_init::glut_init");
      
      ::glutInit              (&argc, argv);
      ::glutInitDisplayMode   (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
      ::glutInitWindowPosition(p.x, p.y);
      ::glutInitWindowSize    (s.x, s.y);
      ::glutCreateWindow      (t.c_str());
    }
    
  };
  
  template <typename T>
  class glut_glew_app : public glut_init,
                        public glew_init {

  public:

    glut_glew_app(glm::uvec2 const& p, glm::uvec2 const& s,
                  std::string const& t, signed argc, char* argv[])
      : glut_init(p, s, t, argc, argv),
        glew_init(),
        instance_()
    {
      TRACE("oglplus::glut_glew_app::glut_glew_app");
      
      ::glutReshapeFunc      (&standalone_singleton_type::reshape);
      ::glutMotionFunc       (&standalone_singleton_type::motion);
      ::glutPassiveMotionFunc(&standalone_singleton_type::passive_motion);
      ::glutKeyboardFunc     (&standalone_singleton_type::keyboard);
      ::glutDisplayFunc      (&standalone_singleton_type::display);
      ::glutIdleFunc         (&standalone_singleton_type::display);

      standalone_singleton_type::startup(s);
    }
    
    void run()
    {
      TRACE("oglplus::glut_glew_app::run");
      
      ::glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
                      GLUT_ACTION_GLUTMAINLOOP_RETURNS);
      ::glutCloseFunc(&standalone_singleton_type::close);
      ::glutMainLoop();
    }
    
  private:

    typedef standalone_singleton<T> standalone_singleton_type;

    standalone_singleton_type instance_;
    
  };

  
  // variables, exported (extern)

  // functions, inlined (inline)

  template <typename T>
  int glut_glew_main(std::string const& title, int argc, char* argv[])
  {
    TRACE("oglplus::glut_glew_main");
    
    signed result(EXIT_FAILURE);
    
    try {
      std::cout << "=== Started: " << title << " ==\n";
      {
        glut_glew_app<T>(glm::uvec2(100, 100), glm::uvec2(800, 600), title, argc, argv).run();
      }
      std::cout << "== Finished: " << title << " ==\n";
      
      result = EXIT_SUCCESS;
    }
    
    catch(oglplus::ProgramBuildError& ex) {
      std::cerr << " Program build error (in " << ex.GLFunc() << ", " << ex.ObjectTypeName()
                << ": (" << ex.ObjectName() << ") '" << ex.ObjectDesc() << "'): " << ex.what()
                << ": " << ex.Log() << '\n';
    }
    
    catch(oglplus::LimitError& ex) {
      std::cerr << " Limit error: (" << ex.Value() << ") exceeds (" << ex.EnumParamName() << " == "
                << ex.Limit() << ") [" << ex.SourceFile() << ":" << ex.SourceLine() << "] " << '\n';
    }
    
    catch(oglplus::ObjectError& ex) {
      std::cerr << " Object error (in " << ex.GLFunc() << ", " << ex.ObjectTypeName() << ": ("
                << ex.ObjectName() << ") '" << ex.ObjectDesc() << "') [" << ex.SourceFile()
                << ":" << ex.SourceLine() << "]: " << ex.what() << '\n';
    }
    
    catch(oglplus::Error& ex) {
      std::cerr << " Error (in " << ex.GLFunc() << "') [" << ex.SourceFile() << ":"
                << ex.SourceLine() << "]: " << ex.what() << '\n';
    }
    
    catch(std::exception& ex) {
      std::cerr << " Error: " << ex.what() << '\n';
    }
    
    return result;
  }
  
  // functions, exported (extern)
  
} // namespace oglplus {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLUT_GLEW_APP_HPP)
