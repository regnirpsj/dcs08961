// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/touch.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/handler/touch.hpp"

// includes, system

#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <glm/gtx/io.hpp>         // glm::operator<<
#include <ostream>                // std::ostream

// includes, project

#include <support/io_utils.hpp>
#include <handler/common.hpp>

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

  namespace handler {

    namespace touch {
  
      // variables, exported
  
      // functions, exported

      /* explicit */
      base::base(unsigned a)
        : handler::base  (),
          touchq_        (),
          touchq_max_len_(a)
      {
        TRACE("platform::handler::touch::base::base");
      }
      
      /* virtual */
      base::~base()
      {
        TRACE("platform::handler::touch::base::~base");
      }

      /* virtual */ bool
      base::motion(position_list_type const& a, time_point const& b)
      {
        TRACE("platform::handler::touch::base::motion");

        update_queue(touchq_, record{ type::motion, a, b }, touchq_max_len_);

        return false;
      }

      /* virtual */ bool
      base::press(position_list_type const& a, time_point const& b)
      {
        TRACE("platform::handler::touch::base::press");

        update_queue(touchq_, record{ type::press, a, b }, touchq_max_len_);

        return false;
      }

      /* virtual */ bool
      base::release(position_list_type const& a, time_point const& b)
      {
        TRACE("platform::handler::touch::base::release");

        update_queue(touchq_, record{ type::release, a, b }, touchq_max_len_);

        return false;
      }

      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("platform::handler::touch::base::print_on");

        platform::handler::base::print_on(os);

        support::ostream::format_saver const sofs(os);
        
        using support::ostream::operator<<;
        
        os << "\b::touch,"
           << touchq_.size() << '(' << touchq_max_len_ << "):"
           << support::ostream::delimeter<char>('{', '}', ',')
           << support::ostream::indent<char>("\n ")
           << touchq_
           << ']';
      }

      std::ostream&
      operator<<(std::ostream& os, type const& a)
      {
        TRACE_NEVER("platform::handler::touch::operator<<(type)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          switch (a) {
          case type::motion:  os << " MOTION";  break;
          case type::press:   os << "  PRESS";   break;
          case type::release: os << "RELEASE"; break;
          }
        }

        return os;
      }
      
      std::ostream&
      operator<<(std::ostream& os, record const& a)
      {
        TRACE_NEVER("platform::handler::touch::operator<<(record)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          using namespace std::chrono;
          using support::ostream::operator<<;
          
          boost::io::ios_all_saver const       ias (os);
          glm::io::format_saver const          iofs(os);
          support::ostream::format_saver const sofs(os);
          
          os << '['
             << a.state << ','
             << glm::io::width(2)
             << support::ostream::delimeter<char>('{', '}', ',')
             << support::ostream::indent<char>("")
             << a.pos   << ','
             << std::dec
             << std::setw(12)
             << duration_cast<microseconds>(a.stamp.time_since_epoch()).count()
             << ']';
        }
    
        return os;
      }
      
    } // namespace touch {
    
  } // namespace handler {
  
} // namespace platform {
