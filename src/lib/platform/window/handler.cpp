// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/window/handler.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/window/handler.hpp"

// includes, system

#include <typeinfo>

// includes, project

#include <support/type_info.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  template <typename T>
  void
  update_queue(std::deque<T>& q, T const& e, unsigned l)
  {
    TRACE("platform::window::handler::<unnamed>::update_queue<" + support::demangle(typeid(T)) +
          ">");

    if (0 < l) {
      q.push_back(e);

      if (q.size() > (l + 1)) {
        q.pop_front();
      }
    }
  }

  
  // variables, internal
  
  // functions, internal

} // namespace {

namespace platform {

  namespace window {

    namespace handler {

      // variables, exported

      /* static */ unsigned const handler::base::dflt_queue_max_length(3);
      
      // functions, exported
      
      /* virtual */
      base::~base()
      {
        TRACE("platform::window::handler::base::~base");
      }

      /* explicit */
      base::base()
      {
        TRACE("platform::window::handler::base::base");
      }
      
      namespace keyboard {
        
        // variables, exported
  
        // functions, exported

        /* explicit */
        base::base(unsigned a)
          : handler::base     (),
            keyboardq_        (),
            keyboardq_max_len_(a)
        {
          TRACE("platform::window::handler::keyboard::base::base");
        }
        
        /* virtual */
        base::~base()
        {
          TRACE("platform::window::handler::keyboard::base::~base");
        }

        /* virtual */ bool
        base::press(record const& a)
        {
          TRACE("platform::window::handler::keyboard::base::press");

          update_queue(keyboardq_, a, keyboardq_max_len_);
          
          return false;
        }
        
        /* virtual */ bool
        base::release(record const& a)
        {
          TRACE("platform::window::handler::keyboard::base::release");

          update_queue(keyboardq_, a, keyboardq_max_len_);
          
          return false;
        }

      } // namespace keyboard {

      namespace mouse {

        // variables, exported
  
        // functions, exported

        /* explicit */
        base::base(unsigned a)
          : handler::base  (),
            mouseq_        (),
            mouseq_max_len_(a)
        {
          TRACE("platform::window::handler::mouse::base::base");
        }
        
        /* virtual */
        base::~base()
        {
          TRACE("platform::window::handler::mouse::base::~base");
        }

        /* virtual */ bool
        base::motion(record const& a)
        {
          TRACE("platform::window::handler::mouse::base::motion");

          update_queue(mouseq_, a, mouseq_max_len_);
          
          return false;
        }
        
        /* virtual */ bool
        base::press(record const& a)
        {
          TRACE("platform::window::handler::mouse::base::press");

          update_queue(mouseq_, a, mouseq_max_len_);
          
          return false;
        }
        
        /* virtual */ bool
        base::release(record const& a)
        {
          TRACE("platform::window::handler::mouse::base::release");

          update_queue(mouseq_, a, mouseq_max_len_);
          
          return false;
        }

        /* virtual */ bool
        base::scroll(record const& a, unsigned)
        {
          TRACE("platform::window::handler::mouse::base::scroll");

          update_queue(mouseq_, a, mouseq_max_len_);
          
          return false;
        }
        
      } // namespace mouse {

      namespace touch {

        // variables, exported
  
        // functions, exported

        /* explicit */
        base::base(unsigned a)
          : handler::base  (),
            touchq_        (),
            touchq_max_len_(a)
        {
          TRACE("platform::window::handler::touch::base::base");
        }
        
        /* virtual */
        base::~base()
        {
          TRACE("platform::window::handler::touch::base::~base");
        }

        /* virtual */ bool
        base::motion(record const& a)
        {
          TRACE("platform::window::handler::touch::base::motion");

          update_queue(touchq_, a, touchq_max_len_);
          
          return false;
        }
        
        /* virtual */ bool
        base::press(record const& a)
        {
          TRACE("platform::window::handler::touch::base::press");

          update_queue(touchq_, a, touchq_max_len_);
          
          return false;
        }
        
        /* virtual */ bool
        base::release(record const& a)
        {
          TRACE("platform::window::handler::touch::base::release");

          update_queue(touchq_, a, touchq_max_len_);
          
          return false;
        }
        
      } // namespace touch {
      
    } // namespace handler {
    
  } // namespace window {
  
} // namespace platform {
