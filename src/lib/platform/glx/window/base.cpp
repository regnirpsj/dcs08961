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

#include <platform/glx/io.hpp>
#include <platform/glx/window/manager.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  signed
  wait_for_map_notify(Display*, XEvent* evt, XPointer arg)
  {
    TRACE("platform::glx::window::base::<unnamed>::wait_for_map_notify");
    
    return ((MapNotify == evt->type) && (reinterpret_cast<Window>(arg) == evt->xmap.window));
  }
  
} // namespace {

namespace platform {

  namespace glx {

    namespace window {
  
      // variables, exported

      /* static */ base::attribute_list const base::dflt_attributes = { GLX_RGBA,
                                                                        GLX_DEPTH_SIZE, 24,
                                                                        GLX_DOUBLEBUFFER,
                                                                        None };
      /* static */ std::string const          base::dflt_display_name(":0.0");
      
      // functions, exported

      /* virtual */
      base::~base()
      {
        TRACE("platform::glx::window::base::~base");

        window::manager::sub(this);
        
        if (display_) {
          if (context_) {
            ::glXDestroyContext(display_, context_);
          }

          if (vinfo_) {
            ::XFree(vinfo_);
          }
          
          if (window_) {
            ::XDestroyWindow(display_, window_);
          }

          if (colormap_) {
            ::XFreeColormap(display_, colormap_);
          }
          
          ::XCloseDisplay(display_);
        }
      }

      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("platform::glx::window::base::print_on");

        platform::window::base::print_on(os);

        os << "\b,"
           << "dpy:";

        if (display_) {
          os << *display_ << ',';
        } else {
          os << "invalid,";
        }

        os << "win:" << window_ << ','
           << "vis:";

        if (vinfo_) {
          os << *vinfo_ << ',';
        } else {
          os << "invalid,";
        }
        
        os << "ctx:" << context_
           << ']';
      }
      
      /* explicit */
      base::base(std::string const& a, rect const& b, std::string const& c, attribute_list const& d)
        : platform::window::base(a, b),
          display_              (::XOpenDisplay((c.empty()) ? nullptr : c.c_str())),
          colormap_             (0),
          window_               (0),
          vinfo_                (nullptr),
          context_              (nullptr)
      {
        TRACE("platform::glx::window::base::base");

        if (!display_) {
          std::runtime_error("platform::glx::window::base: 'XOpenDisplay'");
        }

        signed dummy;

        if (!::glXQueryExtension(display_, &dummy, &dummy)) {
          std::runtime_error("platform::glx::window::base: 'glXQueryExtension'");
        }

        vinfo_ = ::glXChooseVisual(display_, DefaultScreen(display_),
                                   const_cast<signed*>(&(d[0])));

        if (!vinfo_) {
          std::runtime_error("platform::glx::window::base: 'glXChooseVisual'");
        }

        if (TrueColor != vinfo_->c_class) {
          std::runtime_error("platform::glx::window::base: 'TrueColor != vinfo_->c_class'");
        }

        context_ = ::glXCreateContext(display_, vinfo_, None, True);

        if (!context_) {
          std::runtime_error("platform::glx::window::base: 'glXCreateContext'");
        }
        
        colormap_ = ::XCreateColormap(display_,RootWindow(display_, vinfo_->screen),
                                      vinfo_->visual, AllocNone);

        if (!colormap_) {
          std::runtime_error("platform::glx::window::base: 'XCreateColormap'");
        }
        
        XSetWindowAttributes swa;

        swa.border_pixel = 0;
        swa.colormap     = colormap_;
        swa.event_mask   = (ExposureMask       | 
                            ButtonPressMask    | 
                            ButtonReleaseMask  | 
                            KeyPressMask       | 
                            Button1MotionMask  | 
                            Button2MotionMask  | 
                            Button3MotionMask  | 
                            StructureNotifyMask);

        window_ = ::XCreateWindow(display_,
                                  RootWindow(display_, vinfo_->screen), 
                                  position->x, position->y, size->x, size->y,
                                  0,
                                  vinfo_->depth,
                                  InputOutput,
                                  vinfo_->visual,
                                  (CWBorderPixel | CWColormap | CWEventMask), 
                                  &swa);

        if (!window_) {
          std::runtime_error("platform::glx::window::base: 'XCreateWindow'");
        }

        // display, w, window_name, icon_name, icon_pixmap, argv, argc, hints
        ::XSetStandardProperties(display_, window_, a.c_str(), a.c_str(), None, nullptr, 0,
                                 nullptr);
        
        {
          ::XEvent evt;

          ::XMapWindow(display_, window_);
          ::XIfEvent  (display_, &evt, wait_for_map_notify, reinterpret_cast<XPointer>(window_));
        }

        if (!::glXMakeCurrent(display_, window_, context_)) {
          std::runtime_error("platform::glx::window::base: 'glXMakeCurrent'");
        }
          
        window::manager::add(reinterpret_cast<window::manager::id_type>(context_), this);
      }

      /* virtual */ void
      base::close()
      {
        TRACE("platform::glx::window::base::close");
      }
      
      /* virtual */ void
      base::display()
      {
        TRACE("platform::glx::window::base::display");

        throw std::logic_error("pure virtual function "
                               "'platform::glx::window::base::display' called");
      }
      
    } // namespace window {
    
  } // namespace glx {
    
} // namespace platform {
