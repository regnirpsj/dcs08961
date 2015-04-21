// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/test/window.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "window.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <iomanip>        // std::fixed, std::right, std::setfill
#include <sstream>        // std::ostringstream

// includes, project

#include <platform/window/manager.hpp>
#include <support/chrono_io.hpp>

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

      namespace test {
        
        // variables, exported

        /* static */ support::clock::duration const window::dflt_duration(std::chrono::seconds(1));
        /* static */ platform::window::rect const   window::dflt_rect    (100, 100, 100, 100);
        
        // functions, exported
          
        /* explicit */
        window::window(std::string const& a, rect const& b, duration const& c)
          : inherited  (a, b),
            duration_  (c),
            timer_     (),
            title_orig_(*title)
        {
          TRACE("platform::glut::window::test::window::window");

          print_state();
        }
        
        /* virtual */ void
        window::frame_render_one()
        {
          TRACE("platform::glut::window::test::window::frame_render_one");

          duration const now(timer_.lapse());

          if (duration_ < now) {
            close();
          } else {
            namespace sc = std::chrono;
        
            std::ostringstream ostr;

            ostr << title_orig_
                 << " ["
                 << std::fixed << std::right << std::setfill(' ') << sc::duration_fmt(sc::symbol)
                 << sc::duration_cast<sc::duration<double>>(duration_ - now)
                 << ']';

            title = ostr.str();
      
            print_state();
          }
        }
        
        void
        window::print_state()
        {
#if 0
          TRACE("platform::glut::window::test::window::print_state");
          
          std::cout << "<unnamed>::win::print_state: "
                    << '\n'
                    << "window::manager: ";
          platform::window::manager::print_on(std::cout);
          std::cout << '\n'
                    << "window         : "
                    << *this
                    << '\n';
#endif
        }
        
      } // namespace test {

    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
