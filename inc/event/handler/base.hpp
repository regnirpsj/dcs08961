// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/handler/base.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_EVENT_HANDLER_BASE_HPP)

#define UKACHULLDCS_08961_EVENT_HANDLER_BASE_HPP

// includes, system

//#include <>

// includes, project

//#include <>

namespace event {

  namespace handler {
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T>
    class base {

    public:

      virtual ~base();

      virtual void handle_event(T const&) =0;

    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace handler {
  
} // namespace event {

#endif // #if !defined(UKACHULLDCS_08961_EVENT_HANDLER_BASE_HPP)
