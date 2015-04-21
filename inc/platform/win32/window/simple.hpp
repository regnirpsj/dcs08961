// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/window/simple.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_WINDOW_SIMPLE_HPP)

#define UKACHULLDCS_08961_PLATFORM_WIN32_WINDOW_SIMPLE_HPP

// includes, system

//#include <>

// includes, project

#include <platform/win32/window/base.hpp>

namespace platform {

  namespace win32 {

    namespace window {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT simple : public platform::win32::window::base {
        
      public:
      
        using rect = platform::window::rect;
        
        field::value::single<bool> focused;
        field::value::single<bool> minimized;
        
        explicit simple(std::string const& /* title */,
                        rect const&        /* rect */ = rect::dflt_rect);

        virtual ~simple();
        
      protected:
      
        virtual LRESULT CALLBACK cb_window_proc(HWND, UINT, WPARAM, LPARAM);
      
        virtual bool focus (bool /* focused or not */);
        virtual bool redraw();
        virtual bool resize(glm::ivec2 const& /* size */, bool /* minimized */);
      
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace window {
        
  } // namespace win32 {
    
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_WINDOW_SIMPLE_HPP)
