// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/trace.cpp                                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "support/trace.hpp"

// includes, system

#include <array>    // std::array<>
#include <iomanip>  // std::dec, std::hex, std::setfill
#include <memory>   // std::unique_ptr<>
#include <ostream>  // std::ostream
#include <sstream>  // std::ostringstream
#include <utility>  // std::pair<>

// includes, project

#include <support/chrono.hpp>    // support::clock, support::timer
#include <support/chrono_io.hpp> // std::chrono::operator<<
#include <support/thread.hpp>    // support::lock_guard<>, support::mutex, thread_local

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal

  // per thread indentation depth
  thread_local unsigned                 trace_depth(0);

  // intra-thread output lock
  std::unique_ptr<support::simple_lock> trace_lock (nullptr);

  // global time tagged to process start
  std::unique_ptr<support::timer>       trace_timer(nullptr);
  
  // functions, internal

  void
  init_local_statics()
  {
    static bool initialized(false);

    if (!initialized) {
      std::ios_base::Init const _;
      
      trace_lock. reset(new support::simple_lock);
      trace_timer.reset(new support::timer);
      
      initialized = true;
    }
  }
  
} // namespace {

namespace support {
  
  // variables, exported
  
  // functions, exported

  /* explicit */
  trace::trace(std::string const& msg, std::ostream& os)
    : boost::noncopyable(),
      msg_              (msg),
      os_               (os),
      start_            (),
      stop_             ()
  {
    enter(this, msg_, os_);
  }

  trace::~trace()
  {
    leave(this, msg_, os_);
  }

  /* static */ void
  trace::enter(std::string const& msg, std::ostream& os)
  {
    enter(nullptr, msg, os);
  }

  /* static */ void
  trace::leave(std::string const& msg, std::ostream& os)
  {
    leave(nullptr, msg, os);
  }

  /* static */ std::string
  trace::prefix()
  {
    return prefix(nullptr, false);
  }

  /* static */ void
  trace::enter(trace* ctx, std::string const& msg, std::ostream& os)
  {
    init_local_statics();

    if (ctx) {
      ctx->start_ = trace_timer->lapse();
    }

    {
      support::simple_lock_guard const lg(*trace_lock);
    
      os << prefix(ctx, false) << "-> " << msg << '\n';
    }
    
    ++trace_depth;
  }

  /* static */ void
  trace::leave(trace* ctx, std::string const& msg, std::ostream& os)
  {
    init_local_statics();

    if (ctx) {
      ctx->stop_ = trace_timer->lapse();
    }

    --trace_depth;
     
    {
      support::simple_lock_guard const lg(*trace_lock);

      os << prefix(ctx, true) << "<- " << msg << '\n';
    }
  }
  
  /* static */ std::string
  trace::prefix(trace* ctx, bool show_duration)
  {
    init_local_statics();
    
    auto const stamp((ctx) ? ((show_duration) ? ctx->stop_ : ctx->start_) : trace_timer->lapse());
    
    using std::chrono::duration_cast;
    using std::chrono::microseconds;
    
    std::ostringstream ostr;
    
    ostr << std::setfill('0')
         << '['
         << "0x"
         << std::hex << std::setw(8) << support::this_thread::get_id()
         << ':'
         << std::dec << std::setw(12) << duration_cast<microseconds>(stamp).count()
         << "us:";
    
    if (ctx && show_duration) {
      static std::array<std::pair<double const, std::string const>, 11> const suffixes = {
        {
          { 1000.00, "ns" },
          { 1000.00, "us" },
          { 1000.00, "ms" },
          {   60.00, "s " },
          {   60.00, "m " },
          {   24.00, "h " },
          {  365.25, "d " },
          { 1000.00, "aj" }, // see [http://www.wikipedia.org/wiki/Year] 
          { 1000.00, "ka" }, // .5ka max for 64bit float
          { 1000.00, "Ma" },
          {    1.00, "Ga" }, // requires 85bit float
        }
      };

      using std::chrono::nanoseconds;
      
      double     duration(double(duration_cast<nanoseconds>(ctx->stop_ - ctx->start_).count()));
      unsigned idx     (0);
      
      while ((idx < suffixes.size()) && (suffixes[idx].first < duration)) {
        duration /= suffixes[idx].first;

        ++idx;
      }
      
      ostr << std::setfill(' ') << std::setprecision(1)
           << std::fixed << std::right << std::setw(5) << duration
           << suffixes[idx].second;
    } else {
      ostr << std::string(5 /* width */ + 2 /* suffix */, ' ');
    }
    
    ostr << ']'
         << std::string((trace_depth * 3) + 1, ' ');

    return ostr.str();
  }
  
} // namespace support {
