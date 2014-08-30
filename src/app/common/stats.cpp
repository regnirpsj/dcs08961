// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/stats.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "stats.hpp"

// includes, system

#include <GL/glew.h> // ::gl[ew]*

#include <cstdint>   // std::uint_least64_t
#include <iomanip>   // std::setfill
#include <ostream>   // std::ostream
#include <stdexcept> // std::logic_error

// includes, project

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

namespace stats {
  
  // variables, exported

  /* static */ support::timer::time_point timer::offset_(support::clock::now());
  
  // functions, exported
  
  /* virtual */
  base::~base()
  {
    TRACE("stats::base::~base");
  }
  
  /* virtual */ void
  base::start()
  {
    TRACE("stats::base::start");
    
    throw std::logic_error("pure virtual function 'stats::base::start' called");
  }

  /* virtual */ void
  base::stop()
  {
    TRACE("stats::base::stop");

    throw std::logic_error("pure virtual function 'stats::base::stop' called");
  }

  /* explicit */
  base::base(std::string const& a)
    : boost::noncopyable(),
      name_             (a)
  {
    TRACE("stats::base::base");
  }

  /* explicit */
  guard::guard(base& a)
    : boost::noncopyable(),
      stats_            (a)
  {
    TRACE("stats::guard::guard");

    stats_.start();
  }

  guard::~guard()
  {
    TRACE("stats::guard::~guard");

    stats_.stop();
  }

  /* explicit */
  timer::result::result(std::string const& a, support::timer::duration const& b,
                        support::timer::duration const& c)
    : name    (a),
      start   (b),
      duration(c)
  {
    TRACE("stats::timer::result::result");
  }
  
  /* virtual */ void
  timer::result::print_on(std::ostream& os) const
  {
    TRACE_NEVER("stats::timer::result::print_on");

    using namespace std::chrono;
    
    os << '['
       << std::string(20 - name.length(), ' ') << name
       << ",@"
       << duration_fmt(symbol) << std::fixed << std::right
       << std::setw(9) << std::setfill(' ') << duration_cast<microseconds>(start)
       << " + "
       << std::setw(6) << std::setfill(' ') << duration_cast<microseconds>(duration)
       << ']';
  }
  
  /* static */ support::timer::time_point
  timer::reset_offset()
  {
    TRACE("stats::timer::reset_offset");

    support::timer::time_point const result(offset_);
    
    offset_ = support::clock::now();

    return result;
  }  

  /* virtual */ timer::result
  timer::fetch()
  {
    TRACE("stats::timer::fetch");

    return result(name_, start_, duration_);
  }
  
  /* explicit */
  timer::timer(std::string const& a)
    : base     (a),
      start_   (support::clock::now() - offset_),
      duration_(std::chrono::nanoseconds(0))
  {
    TRACE("stats::timer::timer");
  }
  
  /* explicit */
  cpu::cpu(std::string const& a)
    : timer(a)
  {
    TRACE("stats::cpu::cpu");
  }
  
  /* virtual */
  cpu::~cpu()
  {
    TRACE("stats::cpu::~cpu");
  }

  /* virtual */ void
  cpu::start()
  {
    TRACE("stats::cpu::start");

    start_ = support::clock::now() - offset_;
  }

  /* virtual */ void
  cpu::stop()
  {
    TRACE("stats::cpu::stop");

    duration_ = support::clock::now() - offset_ - start_;
  }

  /* explicit */
  gpu::gpu(std::string const& a)
    : timer           (a),
      id_query_offset_(-1),
      id_query_start_ (-1),
      id_query_stop_  (-1)
  {
    TRACE("stats::gpu::gpu");

    ::glGenQueries(1, &id_query_offset_);
    ::glGenQueries(1, &id_query_start_);
    ::glGenQueries(1, &id_query_stop_);
  }

  /* virtual */
  gpu::~gpu()
  {
    TRACE("stats::gpu::~gpu");

    ::glDeleteQueries(1, &id_query_stop_);
    ::glDeleteQueries(1, &id_query_start_);
    ::glDeleteQueries(1, &id_query_offset_);
  }

  /* virtual */ void
  gpu::start()
  {
    TRACE("stats::gpu::start");
      
    ::glBeginQuery(GL_TIME_ELAPSED, id_query_offset_);
    {
      start_ = support::clock::now() - offset_;
    
      ::glQueryCounter(id_query_start_, GL_TIMESTAMP);
    }
    ::glEndQuery(GL_TIME_ELAPSED);
  }

  /* virtual */ void
  gpu::stop()
  {
    TRACE("stats::gpu::stop");
    
    ::glQueryCounter(id_query_stop_, GL_TIMESTAMP);
  }

  /* virtual */ timer::result
  gpu::fetch()
  {
    TRACE("stats::gpu::fetch");

    std::uint_least64_t offset(-1), start(-1), stop(-1);

    ::glGetQueryObjectui64v(id_query_offset_, GL_QUERY_RESULT, &offset);
    ::glGetQueryObjectui64v(id_query_start_,  GL_QUERY_RESULT, &start);
    ::glGetQueryObjectui64v(id_query_stop_,   GL_QUERY_RESULT, &stop);

    start_    += std::chrono::nanoseconds(offset);
    duration_  = std::chrono::nanoseconds(stop - start);

    return timer::fetch();
  }
    
} // namespace stats {
