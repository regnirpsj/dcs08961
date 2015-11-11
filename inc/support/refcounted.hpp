// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/refcounted.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SUPPORT_REFCOUNTED_HPP)

#define UKACHULLDCS_08961_SUPPORT_REFCOUNTED_HPP

// includes, system

#include <boost/smart_ptr/intrusive_ref_counter.hpp> // boost::intrusive_ref_counter<>

// includes, project

//#include <support/export.h>

namespace support {
  
  // types, exported (class, enum, struct, union, typedef)

  template <typename T> using refcounted = boost::intrusive_ref_counter<T,
                                                                        boost::thread_safe_counter>;
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace support {

#endif // #if !defined(UKACHULLDCS_08961_SUPPORT_REFCOUNTED_HPP)
