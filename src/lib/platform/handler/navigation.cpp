// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/navigation.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/handler/navigation.hpp"

// includes, system

#include <glm/gtx/io.hpp>        // glm::operator<<
#include <glm/gtx/transform.hpp> // glm::rotate, glm::translate

// includes, project

#include <glm/gtx/utilities.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

#define UKACHULLDCS_HANDLER_NAVIGATION_DEBUG
#undef UKACHULLDCS_HANDLER_NAVIGATION_DEBUG

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace platform {

  namespace handler {

    namespace navigation {
  
      // variables, exported
  
      // functions, exported

      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("platform::handler::navigation::base::print_on");

        os << '[';
        keyboard::base::print_on(os);
        os << ',';
        mouse::base::print_on   (os);
        os << ']';
      }
      
      /* explicit */
      base::base(glm::uvec2 const& a)
        : keyboard::base(a.x),
          mouse::base   (a.y),
          xform         (*this, "xform",
                         std::bind(&base::cb_get_xform, this),
                         std::bind(&base::cb_set_xform, this, std::placeholders::_1)),
          xform_        ()
      {
        TRACE("platform::handler::navigation::base::base");
      }

      glm::mat4 const&
      base::cb_get_xform() const
      {
        TRACE_NEVER("platform::handler::navigation::base::cb_get_xform");

        return xform_;
      }
      
      glm::mat4
      base::cb_set_xform(glm::mat4 const&)
      {
        TRACE_NEVER("platform::handler::navigation::base::cb_set_xform");

        return xform_;
      }
      
      /* explicit */
      simple::simple()
        : base(glm::uvec2(1, 2))
      {
        TRACE("platform::handler::navigation::simple::simple");
      }
      
      /* virtual */ bool
      simple::press(key::ascii a, uint8_t b, glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::handler::navigation::simple::press(key::ascii)");
        
        bool const result(keyboard::base::press(a, b, c, d));
        
        return result;
      }
      
      /* virtual */ bool
      simple::press(key::code a, uint8_t b, glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::handler::navigation::simple::press(key::code)");
        
        bool result(keyboard::base::press(a, b, c, d));

        if (!result) {
          using key = keyboard::key;
          
          if (key::modifier::Alt & b) {
            
            switch (a) {
            case key::code::Left:     // -trans.x
            case key::code::Right:    // +trans.x
            case key::code::Down:     // -trans.y
            case key::code::Up:       // +trans.y
            case key::code::PageUp:   // -trans.z
            case key::code::PageDown: // +trans.z
              {
                float factor(0.05);

                if        ((key::modifier::Ctrl|key::modifier::Shift) & b) {
                  factor *= 16.0;
                } else if (key::modifier::Shift & b) {
                  factor *=  8.0;
                } else if (key::modifier::Ctrl & b) {
                  factor *=  4.0;
                }
            
                glm::vec3 incr;
                
                switch (a) {
                case key::code::Left:     incr.x -= factor; break;
                case key::code::Right:    incr.x += factor; break;
                case key::code::Down:     incr.y -= factor; break;
                case key::code::Up:       incr.y += factor; break;
                case key::code::PageUp:   incr.z -= factor; break;
                case key::code::PageDown: incr.z += factor; break;
                default:                                    break;
                }

                translate(incr);
                
                result |= true;
              }
              break;
              
            default:
              break;
            }
          } else {
            switch (a) {
            case key::code::Right:    // +rot.y
            case key::code::Left:     // -rot.y
            case key::code::Down:     // -rot.x
            case key::code::Up:       // +rot.x
              {
                float angle(1.0);

                if        ((key::modifier::Ctrl|key::modifier::Shift) & b) {
                  angle *= 15.0;
                } else if (key::modifier::Shift & b) {
                  angle *= 10.0;
                } else if (key::modifier::Ctrl & b) {
                  angle *=  5.0;
                }
            
                glm::vec3 axis;

                switch (a) {
                case key::code::Left:  axis.y += 1; break;
                case key::code::Right: axis.y -= 1; break;
                case key::code::Down:  axis.x -= 1; break;
                case key::code::Up:    axis.x += 1; break;
                default:                            break;
                }

                rotate(glm::vec4(axis, angle));
                
                result |= true;
              }
              break;

            default:
              break;
            }
          }
        }
        
        return result;
      }
      
      /* virtual */ bool
      simple::press(mouse::button a, uint8_t b, glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::handler::navigation::simple::press(mouse::button)");
        
        bool const result(mouse::base::press(a, b, c, d));

        return result;
      }

      /* virtual */ bool
      simple::release(mouse::button a, uint8_t b, glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::handler::navigation::simple::release(mouse::button)");
        
        bool const result(mouse::base::release(a, b, c, d));

        return result;
      }

      void
      simple::rotate(glm::vec4 const& a)
      {
        TRACE("platform::handler::navigation::simple::rotate");

        xform_ *= glm::rotate(glm::deg2rad(a.w), glm::vec3(a.x, a.y, a.z));

#if defined(UKACHULLDCS_HANDLER_NAVIGATION_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::handler::navigation::simple::rotate: "
                  << xform_ << '\n';
#endif
        
      }
      
      void
      simple::translate(glm::vec3 const& a)
      {
        TRACE("platform::handler::navigation::simple::translate");

        xform_ *= glm::translate(a);
        
#if defined(UKACHULLDCS_HANDLER_NAVIGATION_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::handler::navigation::simple::translate: "
                  << xform_ << '\n';
#endif
        
      }
      
    } // namespace navigation {

  } // namespace handler {
  
} // namespace platform {
