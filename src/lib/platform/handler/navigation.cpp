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

#if defined(UKACHULLDCS_HANDLER_NAVIGATION_DEBUG)
#  include <support/io_utils.hpp>
#endif

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
        : keyboard::base     (a.x),
          mouse::base        (a.y),
          rotation           (*this, "rotation",
                              std::bind(&base::cb_get_rotation,    this),
                              std::bind(&base::cb_set_rotation,    this, std::placeholders::_1)),
          rotation_factors   (*this, "rotation_factors",
                              glm::vec4(1.0, 5.0, 10.0, 15.0)),
          scale              (*this, "scale",
                              std::bind(&base::cb_get_scale,       this),
                              std::bind(&base::cb_set_scale,       this, std::placeholders::_1)),
          scale_factors      (*this, "scale_factors",
                              glm::vec4(1.0, 1.0, 1.0, 1.0)),
          translation        (*this, "translation",
                              std::bind(&base::cb_get_translation, this),
                              std::bind(&base::cb_set_translation, this, std::placeholders::_1)),
          translation_factors(*this, "translation_factors",
                              glm::vec4(0.05, 4.0, 8.0, 16.0)),
          xform              (*this, "xform",
                              std::bind(&base::cb_get_xform,       this),
                              std::bind(&base::cb_set_xform,       this, std::placeholders::_1)),
          rotation_          (),
          scale_             (),
          translation_       (),
          xform_             ()
      {
        TRACE("platform::handler::navigation::base::base");
      }

      void
      base::update()
      {
        TRACE("platform::handler::navigation::base::update");

        xform_ = translation_ * rotation_ * scale_;
      }
      
      glm::mat4 const&
      base::cb_get_rotation() const
      {
        TRACE_NEVER("platform::handler::navigation::base::cb_get_rotation");

        return rotation_;
      }
      
      glm::mat4
      base::cb_set_rotation(glm::mat4 const&)
      {
        TRACE_NEVER("platform::handler::navigation::base::cb_set_rotation");

        return rotation_;
      }

      glm::mat4 const&
      base::cb_get_scale() const
      {
        TRACE_NEVER("platform::handler::navigation::base::cb_get_scale");

        return scale_;
      }
      
      glm::mat4
      base::cb_set_scale(glm::mat4 const&)
      {
        TRACE_NEVER("platform::handler::navigation::base::cb_set_scale");

        return scale_;
      }

      glm::mat4 const&
      base::cb_get_translation() const
      {
        TRACE_NEVER("platform::handler::navigation::base::cb_get_translation");

        return translation_;
      }
      
      glm::mat4
      base::cb_set_translation(glm::mat4 const&)
      {
        TRACE_NEVER("platform::handler::navigation::base::cb_set_translation");

        return translation_;
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
                float factor(translation_factors->x);

                if        ((key::modifier::Ctrl|key::modifier::Shift) & b) {
                  factor *= translation_factors->w;
                } else if (key::modifier::Shift & b) {
                  factor *= translation_factors->z;
                } else if (key::modifier::Ctrl & b) {
                  factor *= translation_factors->y;
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

                apply_translation(incr);
                
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
                float angle(rotation_factors->x);

                if        ((key::modifier::Ctrl|key::modifier::Shift) & b) {
                  angle *= rotation_factors->w;
                } else if (key::modifier::Shift & b) {
                  angle *= rotation_factors->z;
                } else if (key::modifier::Ctrl & b) {
                  angle *= rotation_factors->y;
                }
            
                glm::vec3 axis;

                switch (a) {
                case key::code::Left:  axis.y += 1; break;
                case key::code::Right: axis.y -= 1; break;
                case key::code::Down:  axis.x -= 1; break;
                case key::code::Up:    axis.x += 1; break;
                default:                            break;
                }

                apply_rotation(glm::vec4(axis, angle));
                
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
      simple::apply_rotation(glm::vec4 const& a)
      {
        TRACE("platform::handler::navigation::simple::apply_rotation");

        rotation_ *= glm::rotate(glm::deg2rad(a.w), glm::vec3(a.x, a.y, a.z));

        update();
        
#if defined(UKACHULLDCS_HANDLER_NAVIGATION_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::handler::navigation::simple::apply_rotation: "
                  << std::make_pair(*xform, *rotation) << '\n';
#endif
      }

      void
      simple::apply_scale(glm::vec3 const& a)
      {
        TRACE("platform::handler::navigation::simple::apply_scale");

        scale_ *= glm::scale(a);

        update();
        
#if defined(UKACHULLDCS_HANDLER_NAVIGATION_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::handler::navigation::simple::apply_scale: "
                  << std::make_pair(*xform, *scale) << '\n';
#endif
      }
      
      void
      simple::apply_translation(glm::vec3 const& a)
      {
        TRACE("platform::handler::navigation::simple::apply_translation");

        translation_ *= glm::translate(a);

        update();
        
#if defined(UKACHULLDCS_HANDLER_NAVIGATION_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::handler::navigation::simple::apply_translation: "
                  << std::make_pair(*xform, *translation) << '\n';
#endif
      }
      
    } // namespace navigation {

  } // namespace handler {
  
} // namespace platform {
