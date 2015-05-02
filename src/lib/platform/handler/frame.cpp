// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/frame.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/handler/frame.hpp"

// includes, system

#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <ostream>                // std::ostream

// includes, project

#include <support/chrono_io.hpp>
#include <support/io_utils.hpp>
#include <handler/common.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  support::clock::time_point const stamp_initial(support::clock::now());
    
  // functions, internal

} // namespace {

namespace platform {

  namespace handler {

    namespace frame {
  
      // variables, exported
  
      // functions, exported

      /* explicit */
      base::base(unsigned a)
        : handler::base  (),
          frameq_        (),
          frameq_max_len_(a)
      {
        TRACE("platform::handler::frame::base::base");
      }
      
      /* virtual */
      base::~base()
      {
        TRACE("platform::handler::frame::base::~base");
      }

      /* virtual */ bool
      base::update(time_point const& a)
      {
        TRACE("platform::handler::frame::base::update");

        record r = { 0, a - stamp_initial, std::chrono::nanoseconds(0), a };

        if (!frameq_.empty()) {
          r.counter  = frameq_.back().counter + 1;
          r.delta_t  = r.stamp - frameq_.back().stamp;
          r.cma      = (r.delta_t + ((r.counter - 1) * frameq_.back().cma)) / r.counter;
        }
        
        update_queue(frameq_, r, frameq_max_len_);

        return false;
      }

      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("platform::handler::frame::base::print_on");

        platform::handler::base::print_on(os);

        support::ostream::format_saver const sofs(os);
        
        using support::ostream::operator<<;
        
        os << "\b::frame,"
           << frameq_.size() << '(' << frameq_max_len_ << "):"
           << support::ostream::delimeter<char>('{', '}', ',')
           << support::ostream::indent<char>("\n ")
           << frameq_
           << ']';
      }

      std::ostream&
      operator<<(std::ostream& os, record const& a)
      {
        TRACE_NEVER("platform::handler::frame::operator<<(record)");

        std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          boost::io::ios_all_saver const ias (os);

          using namespace std::chrono;
          
          os << '['
             << std::setw(4)
             << a.counter                                                      << ','
             << std::setw(7)
             << duration_fmt(symbol) << duration_cast<microseconds>(a.delta_t) << ','
             << duration_fmt(symbol) << duration_cast<microseconds>(a.cma)     << ','
             << std::setw(12)
             << duration_cast<microseconds>(a.stamp.time_since_epoch()).count()
             << ']';
        }
    
        return os;
      }
      
    } // namespace frame {
    
  } // namespace handler {
  
} // namespace platform {
