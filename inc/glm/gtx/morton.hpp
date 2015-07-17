// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  glm/gtx/morton.hpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GLM_GTX_MORTON_HPP)

#define UKACHULLDCS_08961_GLM_GTX_MORTON_HPP

// includes, system

#include <array>            // std::array<>
#include <glm/glm.hpp>      // glm::?vec[2-4]
#include <glm/gtc/vec1.hpp> // glm::?vec1

// includes, project

// #include <>

namespace glm {

  namespace morton {
    
    // types, exported (class, enum, struct, union, typedef)
  
    // variables, exported (extern)

    // functions, inlined (inline)

    template <unsigned N, typename T>
    std::array<T, N>       decode(T const&);
    
    template <unsigned N, typename T>
    T                      encode(std::array<T, N> const&);
    
    template <typename T>
    T                      decode(typename T::value_type const&);

    template <typename T>
    typename T::value_type encode(T const&);
    
    // functions, exported (extern)

  } // namespace morton {
  
} // namespace glm {

#include <glm/gtx/morton.inl>

#endif // #if !defined(UKACHULLDCS_08961_GLM_GTX_MORTON_HPP)
