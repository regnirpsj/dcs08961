// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/frame.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_FRAME_HPP)

#define UKACHULLDCS_08961_PLATFORM_HANDLER_FRAME_HPP

// includes, system

#include <deque> // std::deque<>

// includes, project

#include <platform/handler/base.hpp>
#include <support/chrono.hpp>

namespace platform {

  namespace handler {

    namespace frame {
      
      // types, exported (class, enum, struct, union, typedef)
      
      struct DCS08961_PLATFORM_EXPORT record {

        using duration   = support::clock::duration;
        using time_point = support::clock::time_point;
      
        unsigned   counter; // frame number
        duration   delta_t; // length
        duration   cma;     // cumulative moving average
        time_point stamp;   // time stamp
        
      };

      class DCS08961_PLATFORM_EXPORT base : virtual public handler::base {

      public:

        using time_point = support::clock::time_point;
        
        explicit base(unsigned /* frameq max len */ = handler::base::dflt_queue_max_length);
        virtual ~base() =0;

        virtual bool update(time_point const& /* stamp */ = support::clock::now());
        
        virtual void print_on(std::ostream&) const;
        
      protected:

        using frame_queue_type = std::deque<record>;
          
        frame_queue_type frameq_;
        unsigned         frameq_max_len_;
        
      };

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, record const&);
      
    } // namespace frame {
    
  } // namespace handler {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_FRAME_HPP)
