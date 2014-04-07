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
  inline std::size_t
  hash<std::pair<T1, T2>>::operator()(std::pair<T1, T2> const& a) const
  {
    return boost::hash_value(a);
  } 

#if (defined(_MSC_VER) && (_MSC_VER <= 1700))
  template <>
  inline std::size_t
  hash<std::string const>::operator()(std::string const& a) const
  {
    return hash<std::string>()(a);
  }
#endif
  
} // namespace std {

#endif // #if !defined(UKACHULLDCS_08961_SUPPORT_HASHER_INL)
