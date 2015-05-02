// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/context.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/ogl/context.hpp"

// includes, system

#include <GL/glew.h>  // glew*

#if defined(_WIN32)
#  include <GL/wglew.h>
#elif defined(__APPLE__) && !defined(GLEW_APPLE_GLX)
#  include <AGL/agl.h>
#else
#  include <GL/glxew.h>
#endif

#include <ostream>    // std::ostream
#include <sstream>    // std::ostringstream
#include <stdexcept>  // std::*_error

// includes, project

#include <support/refcounted.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

namespace render {

  namespace ogl {

    class context::implementation : public support::printable,
                                    public support::refcounted {

    public:

      virtual ~implementation() =0;

      signed visual() const;
      
    protected:

      explicit implementation();

      signed visual_;
      
    };

    // variables, exported

    // functions, exported

    /* virtual */
    context::implementation::~implementation()
    {
      TRACE("render::ogl::context::implementation::implementation");
    } 

    signed
    context::implementation::visual() const
    {
      TRACE("render::ogl::context::implementation::visual");
      
      return visual_;
    }
    
    /* explicit */
    context::implementation::implementation()
      : support::printable (),
        support::refcounted(),
        visual_            (-1)
    { 
      TRACE("render::ogl::context::implementation::implementation");
    } 
  
  } // namespace ogl {
  
} // namespace render {

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

#if 0 // defined(_WIN32)
  
  class context_win32 : public render::ogl::context::implementation {

  public:

    explicit context_win32(std::string const&, signed)
      : render::ogl::context::implementation()
    {
      TRACE("render::ogl::<unnamed>::context_win32::context_win32");

      WNDCLASS wc;
      
      /* register window class */
      ZeroMemory(&wc, sizeof(WNDCLASS));
      
      wc.hInstance     = GetModuleHandle(nullptr);
      wc.lpfnWndProc   = DefWindowProc;
      wc.lpszClassName = class_name;
      
      if (0 == RegisterClass(&wc)) {
        throw std::runtime_error("'RegisterClass' failed!");
      }
      
      /* create window */
      if (nullptr == (wnd_ = CreateWindow(class_name, class_name, 0,
                                          CW_USEDEFAULT, CW_USEDEFAULT,
                                          CW_USEDEFAULT, CW_USEDEFAULT,
                                          nullptr, nullptr,
                                          GetModuleHandle(nullptr), nullptr))) {
        throw std::runtime_error("'CreateWindow' failed!");
      }
      
      /* get the device context */
      if (nullptr == (dc_ = GetDC(wnd_))) {
        throw std::runtime_error("'GetDC' failed!");
      }

      PIXELFORMATDESCRIPTOR pfd;
      
      /* find pixel format */ 
      ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
      
      if (visual == -1) { /* find default */
        pfd.nSize    = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.nVersion = 1;
        pfd.dwFlags  = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
        
        if (0 == (visual = ChoosePixelFormat(dc_, &pfd))) {
          throw std::runtime_error("'ChoosePixelFormat' failed!");
        }
      }
      
      /* set the pixel format for the dc */
      if (FALSE == SetPixelFormat(dc_, visual, &pfd)) {
        throw std::runtime_error("'SetPixelFormat' failed!");
      }
      
      /* create rendering context */
      if (nullptr == (rc_ = wglCreateContext(dc_))) {
        throw std::runtime_error("'wglCreateContext' failed!");
      }
      
      if (FALSE == wglMakeCurrent(dc_, rc_)) {
        throw std::runtime_error("'wglMakeCurrent' failed!");
      }
    }
    
    virtual ~context_win32()
    {
      TRACE("render::ogl::<unnamed>::context_win32::~context_win32");

      if (nullptr != rc_) {
        wglMakeCurrent(nullptr, nullptr);
      }

      if (nullptr != rc_) {
        wglDeleteContext(wglGetCurrentContext());
      }
      
      if ((nullptr != wnd_) && (nullptr != dc_)) {
        ReleaseDC(wnd_, dc_);
      }

      if (nullptr != wnd_) {
        DestroyWindow(wnd_);
      }

      UnregisterClass(class_name, GetModuleHandle(nullptr));
    }

    virtual void print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::ogl::<unnamed>::context_win32::print_on");

      os << '['
         << "WIN32"
         << ']';
    }

  private:

    static char const class_name[] = "RNDROGLCTXHLPER";
    
    wnd_;
    dc_;
    rc_;
    
  };
  
#elif defined(__APPLE__) && !defined(GLEW_APPLE_GLX)

  class context_agl : public render::ogl::context::implementation {

  public:

    explicit context_agl(std::string const&, signed)
      : render::ogl::context::implementation()
    {
      TRACE("render::ogl::<unnamed>::context_agl::context_agl");
    }
    
    virtual ~context_agl()
    {
      TRACE("render::ogl::<unnamed>::context_agl::~context_agl");
    }

    virtual void print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::ogl::<unnamed>::context_agl::print_on");

      os << '['
         << "AGL"
         << ']';
    }
    
  };
  
#else
  
  class context_glx : public render::ogl::context::implementation {

  public:

    explicit context_glx(std::string const& display, signed visual)
      : render::ogl::context::implementation(),
        dpy_                           (nullptr),
        vi_                            (nullptr),
        vis_                           (nullptr),
        ctx_                           (nullptr),
        wnd_                           (0),
        cmap_                          (0)
    {
      TRACE("render::ogl::<unnamed>::context_glx::context_glx");
      
      /* open display */
      dpy_ = XOpenDisplay(display.c_str());
      
      if (!dpy_) {
        throw std::runtime_error("'XOpenDisplay' failed");
      }

      int attrib[] = { GLX_RGBA, GLX_DOUBLEBUFFER, None };
      int erb, evb;
      
      /* query for glx */
      if (!glXQueryExtension(dpy_, &erb, &evb)) {
        throw std::runtime_error("'glXQueryExtension' failed");
      }
      
      /* choose visual */
      if (-1 == visual) {
        vi_ = glXChooseVisual(dpy_, DefaultScreen(dpy_), attrib);
        
        if (!vi_) {
          throw std::runtime_error("'glXChooseVisual' failed");
        }
        
        visual_ = (int)XVisualIDFromVisual(vi_->visual);
      } else {
        int n_vis;
        
        vis_ = XGetVisualInfo(dpy_, 0, nullptr, &n_vis);
        
        for (signed i(0); i < n_vis; ++i) {
          if (static_cast<signed>(XVisualIDFromVisual(vis_[i].visual)) == visual) {
            vi_ = &vis_[i];
          }
        }
        
        if (!vi_) {
          throw std::runtime_error("'XVisualIDFromVisual' found no matching visual");
        } 
      }
      
      /* create context */
      ctx_ = glXCreateContext(dpy_, vi_, None, True);
      
      if (!ctx_) {
        throw std::runtime_error("'glXCreateContext' failed");
      }
      
      /* create window */
      cmap_ = XCreateColormap(dpy_, RootWindow(dpy_, vi_->screen), vi_->visual, AllocNone);

      XSetWindowAttributes swa;

      swa.border_pixel = 0;
      swa.colormap     = cmap_;

      wnd_ = XCreateWindow(dpy_, RootWindow(dpy_, vi_->screen), 0, 0, 1, 1, 0, vi_->depth,
                           InputOutput, vi_->visual,  CWBorderPixel | CWColormap, &swa);
      
      /* make context current */
      if (!glXMakeCurrent(dpy_, wnd_, ctx_)) {
        throw std::runtime_error("'glXMakeCurrent' failed");
      }
    }
    
    virtual ~context_glx()
    {
      TRACE("render::ogl::<unnamed>::context_glx::~context_glx");
      
      if (dpy_) {
        if (ctx_){
          glXDestroyContext(dpy_, ctx_); ctx_  = nullptr;
        }
        
        if (wnd_) {
          XDestroyWindow(dpy_, wnd_);    wnd_  = 0;
        }
        
        if (cmap_) {
          XFreeColormap(dpy_, cmap_);    cmap_ = 0;
        }
        
        if (vis_) {
          XFree(vis_);                   vis_  = nullptr;
        } else if (vi_) {
          XFree(vi_);                    vi_   = nullptr;
        }
        
        XCloseDisplay(dpy_);             dpy_  = nullptr;
      }
    }

    virtual void print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::ogl::<unnamed>::context_glx::print_on");

      os << '['
         << "GLX"
         << ']';
    }
    
  private:

    Display*     dpy_;
    XVisualInfo* vi_;
    XVisualInfo* vis_;
    GLXContext   ctx_;
    Window       wnd_;
    Colormap     cmap_;
    
  };

#endif

  // variables, internal
  
  // functions, internal

} // namespace {

namespace render {

  namespace ogl {
    
    // variables, exported

    /* static */ context::implementation* context::impl(nullptr);
    
    // functions, exported

#if defined(_WIN32)
    typedef context_win32 context_impl_type;
#elif defined(__APPLE__) && !defined(GLEW_APPLE_GLX)
    typedef context_agl   context_impl_type;
#else
    typedef context_glx   context_impl_type;
#endif
    
    /* explicit */
    context::context(std::string const& display, signed visual)
      : base::context(),
        display_     (display),
        visual_      (visual)
    {
      TRACE("render::ogl::context::context");

      if (nullptr == impl) {
        impl = new context_impl_type(display_, visual);
      }
      
      impl->add_ref();
      visual_ = impl->visual();
      
      glewExperimental = GL_TRUE;
      
      unsigned const result(glewInit());
      
      if (GLEW_OK != result) {
        std::ostringstream ostr;
          
        ostr << "'glewInit' failed" << "(error: '" << ::glewGetErrorString(result) << "')";
        
        throw std::runtime_error(ostr.str().c_str());
      }
    }
    
    /* virtual */
    context::~context()
    {
      TRACE("render::ogl::context::~context");

      if (nullptr != impl) {
        bool const set_to_nullptr(1 == impl->get_ref());
        
        impl->sub_ref();

        if (set_to_nullptr) {
          impl = nullptr;
        }
      }
    }
    
    /* virtual */void
    context::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::ogl::context::print_on");

      std::string const prefix(support::trace::prefix().length(), ' ');
      
      os << support::trace::prefix()
         << " OpenGL is '"
         << ::glGetString(GL_VERSION)  << "' by '"
         << ::glGetString(GL_VENDOR)   << "' on '"
         << ::glGetString(GL_RENDERER) << "'\n"
         << prefix
         << " GLSL is '" << ::glGetString(GL_SHADING_LANGUAGE_VERSION) << "'\n"
         << prefix
         << " GLEW is '" << ::glewGetString(GLEW_VERSION) << "'\n"
         << prefix << ' ';

      if (nullptr != impl) {
        os << "Display:'" << (display_.empty() ? "default" : display_) << "',"
           << " Visual:0x" << std::hex << std::uppercase << visual_ << ' '
           << *impl
           << " (" << impl->get_ref() << ')';
      } else {
        os << "oops, no platform-dependent implementation initialized!";
      }
    }
    
  } // namespace ogl {
  
} // namespace render {
