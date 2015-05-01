// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/mouse.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_MOUSE_HPP)

#define UKACHULLDCS_08961_PLATFORM_HANDLER_MOUSE_HPP

// includes, system

//#include <>

// includes, project

#include <platform/handler/keyboard.hpp>

namespace platform {

  namespace handler {

    namespace mouse {
      
      // types, exported (class, enum, struct, union, typedef)

      enum class button : int8_t {
        last   = -2,
        none   = -1,
        left   =  0,
        middle =  1,
        right  =  2,
        wheel  =  3,
        aux5   =  4,
        aux6   =  5,
        aux7   =  6,
        aux8   =  7,
        aux9   =  8,
      };

      enum class direction : int8_t {
        none  =  0,
        down  = -1,
        left  = -2,
        right =  2,
        up    =  1,
      };

      enum class state : bool {
        down = false,
        up   = true,
      };

      struct DCS08961_PLATFORM_EXPORT record {

        using time_point = support::clock::time_point;
          
        button     btn;   // 
        state      updwn; // [DOWN] xor [UP]
        direction  dir;
        uint8_t    mod;   // [ALT|CTRL|SHIFT|SUPER] xor [NONE]
        glm::ivec2 pos;   // pointer position
        time_point stamp; // time stamp
          
      };

      class DCS08961_PLATFORM_EXPORT base : virtual public handler::base {

      public:

        using key        = keyboard::key;
        using time_point = support::clock::time_point;
        
        explicit base(unsigned /* mouseq max len */ = handler::base::dflt_queue_max_length);
        virtual ~base() =0;

        virtual bool motion (uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());
        
        virtual bool press  (button            /* button   */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());        
        
        virtual bool release(button            /* button   */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());

        virtual bool scroll (float             /* value    */,
                             direction         /* dir      */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());
        
        virtual void print_on(std::ostream&) const;
        
      protected:

        using mouse_queue_type = std::deque<record>;
          
        mouse_queue_type mouseq_;
        unsigned         mouseq_max_len_;
          
      };

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, button const&);
      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, direction const&);
      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, state const&);
      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, record const&);
      
    } // namespace mouse {
    
  } // namespace handler {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_MOUSE_HPP)
