// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/stats.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_COMMON_STATS_HPP)

#define UKACHULLDCS_08961_APP_COMMON_STATS_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable

// includes, project

#include <support/chrono.hpp>
#include <support/printable.hpp>

namespace stats {
  
  // types, exported (class, enum, struct, union, typedef)

  class base : public support::printable,
               private boost::noncopyable {

  public:

    virtual ~base();
    
    virtual void start() =0;
    virtual void stop () =0;
    virtual void fetch();

    virtual void print_on(std::ostream&) const;
    
  protected:

    explicit base(std::string const&);

    std::string name_;
    
  };

  class guard : private boost::noncopyable {

  public:

    explicit guard(base&);
            ~guard();
    
  private:

    base& stats_;
    
  };
  
  class cpu : public base {

  public:

    explicit cpu(std::string const&);
    virtual ~cpu();

    virtual void start();
    virtual void stop ();

    virtual void print_on(std::ostream&) const;

  private:
    
    support::timer::duration start_;
    support::timer::duration duration_;
    
  };

  class gpu : public base {

  public:

    explicit gpu(std::string const&);
    virtual ~gpu();

    virtual void start();
    virtual void stop ();
    virtual void fetch();

    virtual void print_on(std::ostream&) const;

  private:

    unsigned                 id_query_offset_;
    unsigned                 id_query_start_;
    unsigned                 id_query_stop_;
    support::timer::duration start_;
    support::timer::duration duration_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace stats {

#endif // #if !defined(UKACHULLDCS_08961_APP_COMMON_STATS_HPP)
