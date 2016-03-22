// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/base.hpp                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_EVENT_BASE_HPP)

#define UKACHULLDCS_08961_EVENT_BASE_HPP

// includes, system

#include <functional> // std::function<>

// includes, project

#include <event/handler/base.hpp>
#include <support/chrono.hpp>

namespace event {
  
  // types, exported (class, enum, struct, union, typedef)

  template <typename T>
  class base {

  public:

    using time_point                = support::clock::time_point;
    using time_source_function_type = std::function<time_point ()>;

    static time_source_function_type time_source();
    static time_source_function_type time_source(time_source_function_type);
    
    virtual ~base() =0;

    time_point const& stamp() const;
    
  protected:

    explicit base(bool /* async */);
    explicit base(base const&);
    
    time_point const stamp_;
    bool const       async_;
    
  private:

    static time_source_function_type time_source_; // = &support::clock::now

    void operator=(base const&);                   // not implemented, not usable
    
  };
  
  template <typename T>
  class async : public base<T> {

  public:

    class handler : virtual public ::event::handler::base<T> {

    public:

      virtual ~handler();

      virtual void handle_event(T const&);

    protected:

      explicit handler();
      
    };
    
    virtual ~async();

  protected:

    explicit async();
    
  };

  template <typename T>
  class sync : public base<T> {

  public:

    class handler : virtual public ::event::handler::base<T> {

    public:

      virtual ~handler();

      virtual void handle_event(T const&);

    protected:

      explicit handler();
      
    };
    
    virtual ~sync();

  protected:

    explicit sync();
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace event {

#include <event/base.inl>

#endif // #if !defined(UKACHULLDCS_08961_EVENT_BASE_HPP)
