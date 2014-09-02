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

#include <boost/noncopyable.hpp>   // boost::noncopyable

// includes, project

#include <support/chrono.hpp>
#include <support/printable.hpp>
#include <support/refcounted.hpp>

namespace stats {
  
  // types, exported (class, enum, struct, union, typedef)

  class base : private boost::noncopyable {

  public:
    
    virtual ~base();
    
    virtual void start() =0;
    virtual void stop () =0;
    
  protected:

    std::string name_;
    
    explicit base(std::string const&);
    
  };

  class guard : private boost::noncopyable {

  public:

    explicit guard(base&);
            ~guard();
    
  private:

    base& stats_;
    
  };

  class timer : public base {

  public:

    class result : public support::printable {

    public:

      std::string const              name;
      support::timer::duration const start;
      support::timer::duration const duration;

      explicit result(std::string const&              /* name */,
                      support::timer::duration const& /* start */,
                      support::timer::duration const& /* duration */);
      
      virtual void print_on(std::ostream&) const;
      
    };
    
    static support::timer::time_point reset_offset();

    virtual result fetch();    
    
  protected:

    static support::timer::time_point offset_;

    support::timer::duration start_;
    support::timer::duration duration_;
    
    explicit timer(std::string const&);
    
  };
  
  class cpu : public timer {

  public:

    explicit cpu(std::string const&);
    virtual ~cpu();

    virtual void start();
    virtual void stop ();
    
  };

  class gpu : public timer {

  public:

    explicit gpu(std::string const&);
    virtual ~gpu();

    virtual void   start();
    virtual void   stop ();
    virtual result fetch();

  private:

    unsigned id_query_start_;
    unsigned id_query_stop_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace stats {

#endif // #if !defined(UKACHULLDCS_08961_APP_COMMON_STATS_HPP)
