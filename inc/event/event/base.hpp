// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/event/base.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_EVENT_EVENT_BASE_HPP)

#define UKACHULLDCS_08961_EVENT_EVENT_BASE_HPP

// includes, system

#include <functional>

// includes, project

#include <support/chrono.hpp>
#include <support/printable.hpp>
#include <event/export.h>

namespace event {
  
  // types, exported (class, enum, struct, union, typedef)

  class DCS08961_EVENT_EXPORT base : public support::printable {

  public:

    typedef support::clock::time_point time_stamp_type;
    
    typedef std::function<time_stamp_type ()> time_source_function_type;

    static time_source_function_type time_source();
    static time_source_function_type time_source(time_source_function_type);

    virtual ~base();

    time_stamp_type const& time_stamp() const;

    virtual void notify() = 0;
    
    virtual void print_on(std::ostream&) const;
    
  protected:

    explicit base();
    explicit base(base const&);
    explicit base(base const&&);
    
    time_stamp_type const stamp_;

  private:

    static time_source_function_type time_source_; // = &support::clock::now

    void operator=(base const&);  // not implemented, not usable
    void operator=(base const&&); // not implemented, not usable
    
  };

  namespace handler {

    template <typename T>
    class base {

    public:

      virtual ~base();
      
      virtual void handle_event(T const&) =0;
      
  };
    
  } // namespace handler {
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace event {

#endif // #if !defined(UKACHULLDCS_08961_EVENT_EVENT_BASE_HPP)
