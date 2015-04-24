// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glx/window/base.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glx/window/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<< (field::container::print_on)
#include <stdexcept>      // std::runtime_error

// includes, project

#include <platform/glx/window/manager.hpp>

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

  namespace glx {

    namespace window {
  
      // variables, exported

      /* static */ base::attribute_list const base::dflt_attributes = { GLX_RGBA,
                                                                        GLX_DOUBLEBUFFER,
                                                                        None };
      /* static */ std::string const          base::dflt_display_name(":0.0");
      
      // functions, exported

      /* virtual */
      base::~base()
      {
        TRACE("platform::glx::window::base::~base");

        window::manager::sub(this);
        
        if (x11_display_) {
          if (glx_context_)  { glXDestroyContext(x11_display_, glx_context_);  }
          if (x11_window_)   { XDestroyWindow   (x11_display_, x11_window_);   }
          if (x11_colormap_) { XFreeColormap    (x11_display_, x11_colormap_); }
          if (x11_visual_)   { XFree            (x11_visual_);                 }
                               XCloseDisplay    (x11_display_);
        }
      }
      
      /* explicit */
      base::base(std::string const& a, rect const& b, std::string const& c, attribute_list const& d)
        : platform::window::base(a, b),
          x11_display_          (XOpenDisplay(c.c_str())),
          x11_window_           (0),
          x11_visual_           (nullptr),
          x11_colormap_         (0),
          glx_context_          (nullptr)
      {
        TRACE("platform::glx::window::base::base");

        if (!x11_display_) {
          throw std::runtime_error("XOpenDisplay");
        }

        int dummy;
        
        if (!glXQueryExtension(x11_display_, &dummy, &dummy)) {
          throw std::runtime_error("glXQueryExtension");
        }

        attribute_list attributes(d);
        
        if (nullptr == (x11_visual_ = glXChooseVisual(x11_display_,
                                                      DefaultScreen(x11_display_),
                                                      &(attributes[0])))) {
          throw std::runtime_error("glXChooseVisual");
        }
          
        if (nullptr == (glx_context_ = glXCreateContext(x11_display_, x11_visual_, None, True))) {
          throw std::runtime_error("glXCreateContext");
        }

        x11_colormap_ = XCreateColormap(x11_display_,
                                        RootWindow(x11_display_, x11_visual_->screen),
                                        x11_visual_->visual, AllocNone);

        XSetWindowAttributes swa;

        swa.border_pixel = 0;
        swa.colormap     = x11_colormap_;

        x11_window_ = XCreateWindow(x11_display_,
                                    RootWindow(x11_display_, x11_visual_->screen),
                                    b.x, b.y, b.w, b.h,
                                    0,
                                    x11_visual_->depth,
                                    InputOutput,
                                    x11_visual_->visual,
                                    (CWBorderPixel|CWColormap),
                                    &swa);

        if (!glXMakeCurrent(x11_display_, x11_window_, glx_context_)) {
          throw std::runtime_error("glXMakeCurrent");
        }
          
        window::manager::add(reinterpret_cast<window::manager::id_type>(glx_context_), this);
      }
  
    } // namespace window {
    
  } // namespace glx {
    
} // namespace platform {
