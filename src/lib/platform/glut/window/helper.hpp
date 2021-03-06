// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/helper.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_HELPER_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_HELPER_HPP

// includes, system

#include <deque>  // std::deque<>
#include <string> // std::string

// includes, project

//#include <>

namespace platform {

  namespace glut {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)

      std::string exec_context(void const* /* ptr */);
      
      template <typename T>
      void update_queue(std::deque<T>& /* queue            */,
                        T const&       /* element          */,
                        unsigned       /* max queue length */);
      
      // functions, exported (extern)
  
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {

#include <window/helper.inl>

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_HELPER_HPP)
