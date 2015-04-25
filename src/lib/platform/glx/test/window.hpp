// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glx/test/window.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLX_TEST_WINDOW_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLX_TEST_WINDOW_HPP

// includes, system

//#include <>

// includes, project

#include <platform/glx/window/simple.hpp>

namespace platform {

  namespace glx {

    namespace window {

      namespace test {
        
        // types, exported (class, enum, struct, union, typedef)

        class window : public platform::glx::window::simple {

          using inherited = platform::glx::window::simple;
          using duration  = support::clock::duration;
          using timer     = support::timer;
    
        public:

          static support::clock::duration const dflt_duration; // 1sec
          static rect const                     dflt_rect;     // [100, 100, 100, 100]
          
          explicit window(std::string const&,
                          rect const&     = dflt_rect,
                          duration const& = dflt_duration);
    
          virtual void frame_render_one();

          void print_state();
          
        private:
    
          duration const    duration_;
          timer             timer_;
          std::string const title_orig_;
            
        };
        
        // variables, exported (extern)
        
        // functions, inlined (inline)
  
        // functions, exported (extern)
        
      } // namespace test {

    } // namespace window {

  } // namespace glx {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLX_TEST_WINDOW_HPP)
