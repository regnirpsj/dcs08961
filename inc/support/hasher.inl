// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/hasher.inl                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SUPPORT_HASHER_INL)

#define UKACHULLDCS_08961_SUPPORT_HASHER_INL

// includes, system

#include <boost/functional/hash.hpp> // boost::hash_value<>
#include <functional>                // std::hash<>

// includes, project

//#include <>

namespace std {
  
  // functions, inlined (inline)

  template <typename T1, typename T2>
  inline size_t
  hash<pair<T1, T2>>::operator()(pair<T1, T2> const& a) const
  {
    return boost::hash_value(a);
  }
  
} // namespace std {

#endif // #if !defined(UKACHULLDCS_08961_SUPPORT_HASHER_INL)
