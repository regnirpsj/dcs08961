// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/application/base.hpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_APPLICATION_BASE_HPP)

#define UKACHULLDCS_08961_PLATFORM_WIN32_APPLICATION_BASE_HPP

// includes, system

#include <string>    // std::string
#include <windows.h> // win32 stuff

// includes, project

#include <platform/window/base.hpp>

namespace platform {

  namespace win32 {

    namespace window {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT base : public platform::window::base {
        
      public:
      
        virtual ~base();

        HWND const& handle() const;
      
        virtual void print_on(std::ostream&) const;
      
      protected:

        HWND  hwnd_;
        DWORD flags_;
        DWORD flags_ex_;

        explicit base(std::string const& /* title */,
                      rect const&        /* rect */ = rect::dflt_rect);

        virtual LRESULT CALLBACK cb_window_proc(HWND, UINT, WPARAM, LPARAM);

      private:
        
        class register_window_class : private boost::noncopyable {

        public:

          static std::string const class_name;
          
          explicit register_window_class();
                  ~register_window_class();

          static unsigned count();

        private:
        
          static unsigned count_;

        };

        register_window_class const register_window_class_;

        static LRESULT CALLBACK cb_window_proc_default(HWND, UINT, WPARAM, LPARAM);
      
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace window {
        
  } // namespace win32 {
    
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_APPLICATION_BASE_HPP)
