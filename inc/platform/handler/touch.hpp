// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/touch.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_TOUCH_HPP)

#define UKACHULLDCS_08961_PLATFORM_HANDLER_TOUCH_HPP

// includes, system

#include <deque>       // std::deque<>
#include <glm/glm.hpp> // glm::ivec2
#include <vector>      // std::vector<>

// includes, project

#include <platform/handler/base.hpp>
#include <support/chrono.hpp>

namespace platform {

  namespace handler {

    namespace touch {
      
      // types, exported (class, enum, struct, union, typedef)

      enum class type : uint8_t {
        motion,
        press,
        release,
      };
      
      struct DCS08961_PLATFORM_EXPORT record {

        using position_list_type = std::vector<glm::ivec2>;
        using time_point         = support::clock::time_point;

        type               state; //
        position_list_type pos;   // touch positions
        time_point         stamp; // time stamp
          
      };

      class DCS08961_PLATFORM_EXPORT base : virtual public handler::base {

      public:

        using position_list_type = record::position_list_type;
        using time_point         = support::clock::time_point;
        
        explicit base(unsigned /* touchq max len */ = handler::base::dflt_queue_max_length);
        virtual ~base() =0;

        virtual bool motion (position_list_type const& /* pos */,
                             time_point const&         /* stamp    */ = support::clock::now());
        
        virtual bool press  (position_list_type const& /* pos */,
                             time_point const&         /* stamp    */ = support::clock::now());
        
        virtual bool release(position_list_type const& /* pos */,
                             time_point const&         /* stamp    */ = support::clock::now());
        
        virtual void print_on(std::ostream&) const;
        
      protected:

        using touch_queue_type = std::deque<record>;
          
        touch_queue_type touchq_;
        unsigned         touchq_max_len_;
          
      };

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, type const&);
      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, record const&);
      
    } // namespace touch {
    
  } // namespace handler {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_TOUCH_HPP)
