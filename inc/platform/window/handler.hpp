// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/window/handler.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_HANDLER_HPP)

#define UKACHULLDCS_08961_PLATFORM_WINDOW_HANDLER_HPP

// includes, system

#include <cstdint>     // uint*_t
#include <deque>       // std::deque<>
#include <glm/glm.hpp> // glm::ivec2
#include <vector>      // std::vector<>

// includes, project

#include <platform/export.h>
#include <support/chrono.hpp>

namespace platform {

  namespace window {

    namespace handler {
    
      // types, exported (class, enum, struct, union, typedef)
      
      class DCS08961_PLATFORM_EXPORT base {

      public:

        static unsigned const dflt_queue_max_length; // == 3
          
        virtual ~base() =0;

      protected:

        explicit base();
        
      };

      namespace keyboard {

        // types, exported (class, enum, struct, union, typedef)
        
        struct DCS08961_PLATFORM_EXPORT key {

          enum ascii : uint8_t {
            NUL,SOH,STX,ETX,EOT,ENQ,ACK,BEL,BS,HT,LF,VT,FF,CR,SO,SI,DLE,DC1,DC2,DC3,DC4,NAK,SYN,ETB,
            CAN,EM,SUB,ESC,FS,GS,RS,US,
            space,exclamation,quotation,hash,dollar,percent,ampersand,apostrophe,parentheses_l,
            parentheses_r,asterisk,plus,comma,minus,dot,slash,
            one,two,three,four,five,six,seven,eight,nine,zero,
            colon,semicolon,lessthan,equal,greaterthan,question,at,
            A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
            bracket_l,backslash,bracket_r,caret,underscore,grave,
            a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,
            brace_l,vbar,brace_r,tilde,
            DEL,
          };

          enum special : uint8_t {
            F1         = 0x01,
            F2         = 0x02,
            F3         = 0x03,
            F4         = 0x04,
            F5         = 0x05,
            F6         = 0x06,
            F7         = 0x07,
            F8         = 0x08,
            F9         = 0x09,
            F10        = 0x0A,
            F11        = 0x0B,
            F12        = 0x0C,
            Left       = 0x0D,
            Up         = 0x0E,
            Right      = 0x0F,
            Down       = 0x10,
            PageUp     = 0x11,
            PageDown   = 0x12,
            Home       = 0x13,
            End        = 0x14,
            Insert     = 0x15,
            NumLock    = 0x16,
            Begin      = 0x17,
            Delete     = 0x18,
            AltLeft    = 0x19,
            AltRight   = 0x20,
            CtrlLeft   = 0x21,
            CtrlRight  = 0x22,
            ShiftLeft  = 0x23,
            ShiftRight = 0x24,
            SuperLeft  = 0x25,
            SuperRight = 0x26,
          };

          enum modifier : uint8_t {
            ModNone = 0x00,
            Alt     = 0x01,
            Ctrl    = 0x02,
            Shift   = 0x04,
            Super   = 0x08,
          };

          enum state : bool {
            down = false,
            up   = true,
          };
          
        };

        struct DCS08961_PLATFORM_EXPORT  record {

          using time_point = support::clock::time_point;
      
          uint16_t      key;   // 0x00FF: ascii xor 0xFF00: special
          key::state    updwn; // [DOWN] xor [UP]
          key::modifier mod;   // [ALT|CTRL|SHIFT|SUPER] xor [NONE]
          glm::ivec2    pos;   // pointer position
          time_point    stamp; // time stamp
          
        };
        
        class DCS08961_PLATFORM_EXPORT base : virtual public handler::base {

        public:
          
          explicit base(unsigned /* kbdq max len */ = handler::base::dflt_queue_max_length);
          virtual ~base();

          virtual bool press  (record const&);
          virtual bool release(record const&);

        protected:

          using key_queue_type = std::deque<record>;
          
          key_queue_type keyboardq_;
          unsigned       keyboardq_max_len_;
          
        };
        
      } // namespace keyboard      

      namespace mouse {

        // types, exported (class, enum, struct, union, typedef)
        
        enum class button : int8_t {
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
          left  = -1,
          right =  1,
          up    =  1,
        };

        enum class state : bool {
          down = false,
          up   = true,
        };

        struct DCS08961_PLATFORM_EXPORT record {

          using time_point = support::clock::time_point;
          using modifier   = keyboard::key::modifier;
          
          button     btn;   // 
          state      updwn; // [DOWN] xor [UP]
          direction  dir;
          modifier   mod;   // [ALT|CTRL|SHIFT|SUPER] xor [NONE]
          glm::ivec2 pos;   // pointer position
          time_point stamp; // time stamp
          
        };
        
        class DCS08961_PLATFORM_EXPORT base : virtual public handler::base {

        public:
        
          explicit base(unsigned /* mouseq max len */ = handler::base::dflt_queue_max_length);
          virtual ~base();

          virtual bool motion (record const&);
          virtual bool press  (record const&);
          virtual bool release(record const&);
          virtual bool scroll (record const&, unsigned /* value*/);

        protected:

          using mouse_queue_type = std::deque<record>;
          
          mouse_queue_type mouseq_;
          unsigned         mouseq_max_len_;
          
        };
        
      } // namespace mouse {

      namespace touch {

        // types, exported (class, enum, struct, union, typedef)

        struct DCS08961_PLATFORM_EXPORT record {

          using position_list_type = std::vector<glm::ivec2>;
          using time_point         = support::clock::time_point;
          
          position_list_type pos;   // touch positions
          time_point         stamp; // time stamp
          
        };
        
        class DCS08961_PLATFORM_EXPORT base : virtual public handler::base {

        public:

          explicit base(unsigned /* touchq max len */ = handler::base::dflt_queue_max_length);
          virtual ~base();

          virtual bool motion (record const&);
          virtual bool press  (record const&);
          virtual bool release(record const&);

        protected:
          
          using touch_queue_type = std::deque<record>;
          
          touch_queue_type touchq_;
          unsigned         touchq_max_len_;
          
        };

      } // namespace touch {
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace handler {
    
  } // namespace window {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_HANDLER_HPP)
