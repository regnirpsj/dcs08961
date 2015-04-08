// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/utilities.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_UTILITIES_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLUT_UTILITIES_HPP

// includes, system

#include <glm/glm.hpp> // glm::ivec2

// includes, project

#include <support/chrono.hpp>

namespace platform {

  namespace glut {
  
    // types, exported (class, enum, struct, union, typedef)

    struct frame_record_t {

      using duration   = support::clock::duration;
      using time_point = support::clock::time_point;
      
      unsigned   counter; // frame number
      duration   delta_t; // length
      time_point stamp;   // time stamp
      
    };
    
    struct mouse_record_t {

      using time_point = support::clock::time_point;
      
      signed     button;   // [LEFT] xor [MIDLLE] xor [RIGHT]
      signed     state;    // [DOWN] xor [UP]
      signed     modifier; // [ALT|CTRL|SHIFT] xor [NONE]
      glm::ivec2 pos;      // pointer position
      time_point stamp;    // time stamp
      
    };

    struct keyboard_record_t {

      using time_point = support::clock::time_point;
      
      signed     key;      // [char] xor [GLUT_KEY_*]
      signed     state;    // [DOWN] xor [UP]
      signed     modifier; // [ALT|CTRL|SHIFT] xor [NONE]
      bool       special;  // 'key' is 'GLUT_KEY_*' (true) xor 'char' (false)
      glm::ivec2 pos;      // pointer position
      time_point stamp;    // time stamp
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_UTILITIES_HPP)
