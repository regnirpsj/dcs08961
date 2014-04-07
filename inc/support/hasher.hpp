// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/hasher.hpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SUPPORT_HASHER_HPP)

#define UKACHULLDCS_08961_SUPPORT_HASHER_HPP

// includes, system

#include <string>  // std::string
#include <utility> // std::pair<>

// includes, project

// #include <>

namespace std {
  
  // types, exported (class, enum, struct, union, typedef)

  template <typename T1, typename T2>
  struct hash<std::pair<T1, T2>> {
      
    std::size_t operator()(std::pair<T1, T2> const& a) const;
      
  };

#if (defined(_MSC_VER) && (_MSC_VER <= 1700))
  /**
   *  MSVC 17.0 claims that the following doesn't exist
   *
   *  'error C2338: The C++ Standard doesn't provide a hash for this type.'
   */
  template <>
  struct hash<std::string const> {
      
    std::size_t operator()(std::string const& a) const;
    
  };
#endif
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)

} // namespace std {

#include <support/hasher.inl>

#endif // #if !defined(UKACHULLDCS_08961_SUPPORT_HASHER_HPP)
