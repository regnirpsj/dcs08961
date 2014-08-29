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

  support::timer::time_point const offset(support::clock::now());
  
  // functions, internal

} // namespace {

namespace stats {
  
  // variables, exported
  
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

  /* virtual */ void
  base::fetch()
  {
    TRACE("stats::base::fetch");
  }

  /* virtual */ void
  base::print_on(std::ostream& os) const
  {
    TRACE_NEVER("stats::base::print_on");

    os << '[' << name_ << ']';
  }

  /* explicit */
  base::base(std::string const& a)
    : support::printable(),
      boost::noncopyable(),
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
  cpu::cpu(std::string const& a)
    : base     (a),
      start_   (support::clock::now() - offset),
      duration_()
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

    start_ = support::clock::now() - offset;
  }

  /* virtual */ void
  cpu::stop()
  {
    TRACE("stats::cpu::stop");

    duration_ = support::clock::now() - offset - start_;
  }

  /* virtual */ void
  cpu::print_on(std::ostream& os) const
  {
    TRACE_NEVER("stats::");

    base::print_on(os);

    using namespace std::chrono;
    
    os << "\b,cpu:@"
       << duration_fmt(symbol) << std::fixed << std::right
       << std::setw(9) << std::setfill(' ') << duration_cast<microseconds>(start_)
       << " + "
       << std::setw(6) << std::setfill(' ') << duration_cast<microseconds>(duration_) << ']';
  }

  /* explicit */
  gpu::gpu(std::string const& a)
    : base(a),
      id_elapsed_    (-1),
      id_query_start_(-1),
      id_query_stop_ (-1),
      cpu_start_     (),
      gpu_start_     (),
      gpu_duration_  ()
  {
    TRACE("stats::gpu::gpu");

    ::glGenQueries(1, &id_elapsed_);
    ::glGenQueries(1, &id_query_start_);
    ::glGenQueries(1, &id_query_stop_);
  }

  /* virtual */
  gpu::~gpu()
  {
    TRACE("stats::gpu::~gpu");

    ::glDeleteQueries(1, &id_query_stop_);
    ::glDeleteQueries(1, &id_query_start_);
    ::glDeleteQueries(1, &id_elapsed_);
  }

  /* virtual */ void
  gpu::start()
  {
    TRACE("stats::gpu::start");
      
    ::glBeginQuery(GL_TIME_ELAPSED, id_elapsed_);

    cpu_start_ = support::clock::now() - offset;
    
    ::glQueryCounter(id_query_start_, GL_TIMESTAMP);
  }

  /* virtual */ void
  gpu::stop()
  {
    TRACE("stats::gpu::stop");

    ::glEndQuery(GL_TIME_ELAPSED);
    ::glQueryCounter(id_query_stop_, GL_TIMESTAMP);
  }

  /* virtual */ void
  gpu::fetch()
  {
    TRACE("stats::gpu::fetch");

    std::uint_least64_t elapsed(-1), start(-1), stop(-1);

    ::glGetQueryObjectui64v(id_elapsed_,     GL_QUERY_RESULT, &elapsed);
    ::glGetQueryObjectui64v(id_query_start_, GL_QUERY_RESULT, &start);
    ::glGetQueryObjectui64v(id_query_stop_,  GL_QUERY_RESULT, &stop);

    using namespace std::chrono;
    
    gpu_duration_ = nanoseconds(stop - start);
    gpu_start_    = cpu_start_ + (nanoseconds(elapsed) - nanoseconds(stop - start));
  }

  /* virtual */ void
  gpu::print_on(std::ostream& os) const
  {
    TRACE_NEVER("stats::gpu::print_on");

    base::print_on(os);

    using namespace std::chrono;
    
    os << "\b,gpu:@"
       << duration_fmt(symbol) << std::fixed << std::right
       << std::setw(9) << std::setfill(' ') << duration_cast<microseconds>(gpu_start_)
       << " + "
       << std::setw(6) << std::setfill(' ') << duration_cast<microseconds>(gpu_duration_) << ']';
  }
    
} // namespace stats {
