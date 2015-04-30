// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/keyboard.hpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_KEYBOARD_HPP)

#define UKACHULLDCS_08961_PLATFORM_HANDLER_KEYBOARD_HPP

// includes, system

#include <deque>       // std::deque<>
#include <glm/glm.hpp> // glm::ivec2

// includes, project

#include <platform/handler/base.hpp>
#include <support/chrono.hpp>

namespace platform {

  namespace handler {

    namespace keyboard {
      
      // types, exported (class, enum, struct, union, typedef)

      struct DCS08961_PLATFORM_EXPORT key {

        enum class ascii : uint8_t {
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

        enum class code : uint8_t {
          Invalid    = 0x00,
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
          AltRight   = 0x1A,
          CtrlLeft   = 0x1B,
          CtrlRight  = 0x1C,
          ShiftLeft  = 0x1D,
          ShiftRight = 0x1E,
          SuperLeft  = 0x1F,
          SuperRight = 0x20,
        };

        enum modifier : uint8_t {
          None  = 0x00,
          Alt   = 0x01,
          Ctrl  = 0x02,
          Shift = 0x04,
          Super = 0x08,
        };
        
        enum class state : bool {
          down = false,
          up   = true,
        };
          
      };

      struct DCS08961_PLATFORM_EXPORT record {

        using time_point = support::clock::time_point;
      
        uint16_t   key;   // 0x00FF: ascii xor 0xFF00: code
        key::state updwn; // [DOWN] xor [UP]
        uint8_t    mod;   // [ALT|CTRL|SHIFT|SUPER] xor [NONE]
        glm::ivec2 pos;   // pointer position
        time_point stamp; // time stamp
          
      };

      class DCS08961_PLATFORM_EXPORT base : virtual public handler::base {

      public:

        using time_point = support::clock::time_point;
        
        explicit base(unsigned /* kbdq max len */ = handler::base::dflt_queue_max_length);
        virtual ~base() =0;

        virtual bool press  (key::ascii        /* ascii    */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());
        
        virtual bool press  (key::code         /* key code */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());
        
        virtual bool release(key::ascii        /* ascii    */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());
        
        virtual bool release(key::code         /* key code */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());

        virtual void print_on(std::ostream&) const;
        
      protected:

        using key_queue_type = std::deque<record>;
          
        key_queue_type keyboardq_;
        unsigned       keyboardq_max_len_;
          
      };

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, key::ascii const&);
      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, key::code const&);
      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, key::modifier const&);
      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, key::state const&);
      DCS08961_PLATFORM_EXPORT std::ostream& operator<<(std::ostream&, record const&);
      
    } // namespace keyboard {
    
  } // namespace handler {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_KEYBOARD_HPP)
