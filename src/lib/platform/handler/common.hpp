// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/common.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_COMMON_HPP)

#define UKACHULLDCS_08961_PLATFORM_HANDLER_COMMON_HPP

// includes, system

#include <deque> // std::deque<>

// includes, project

//#include <>

namespace platform {

  namespace handler {
  
    // types, exported (class, enum, struct, union, typedef)

    // variables, exported (extern)

    // functions, inlined (inline)

    template <typename T> void update_queue(std::deque<T>&, T const&, unsigned);
    
    // functions, exported (extern)
  
  } // namespace handler {
  
} // namespace platform {

#include <handler/common.inl>

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_COMMON_HPP)
