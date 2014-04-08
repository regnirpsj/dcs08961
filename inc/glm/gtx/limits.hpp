// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  glm/gtx/limits.hpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GLM_GTX_LIMITS_HPP)

#define UKACHULLDCS_08961_GLM_GTX_LIMITS_HPP

// includes, system

#include <glm/glm.hpp>            // glm::vec[2,3,4], glm::mat[2,3,4]x[2,3,4]
#include <glm/gtc/quaternion.hpp> // glm::tquat
#include <limits>                 // std::numeric_limits<>

// includes, project

//#include <>

namespace std {
  
  // types, exported (class, enum, struct, union, typedef)

  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tmat2x2<T,P>>
    : public std::numeric_limits<typename glm::detail::tmat2x2<T,P>::value_type> { /* */ };
  
  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tmat2x3<T,P>>
    : public std::numeric_limits<typename glm::detail::tmat2x3<T,P>::value_type> { /* */ };
  
  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tmat2x4<T,P>>
    : public std::numeric_limits<typename glm::detail::tmat2x4<T,P>::value_type> { /* */ };
  
  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tmat3x2<T,P>>
    : public std::numeric_limits<typename glm::detail::tmat3x2<T,P>::value_type> { /* */ };
  
  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tmat3x3<T,P>>
    : public std::numeric_limits<typename glm::detail::tmat3x3<T,P>::value_type> { /* */ };
  
  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tmat3x4<T,P>>
    : public std::numeric_limits<typename glm::detail::tmat3x4<T,P>::value_type> { /* */ };

  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tmat4x2<T,P>>
    : public std::numeric_limits<typename glm::detail::tmat4x2<T,P>::value_type> { /* */ };
  
  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tmat4x3<T,P>>
    : public std::numeric_limits<typename glm::detail::tmat4x3<T,P>::value_type> { /* */ };
  
  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tmat4x4<T,P>>
    : public std::numeric_limits<typename glm::detail::tmat4x4<T,P>::value_type> { /* */ };
  
  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tquat<T,P>>
    : public std::numeric_limits<typename glm::detail::tquat<T,P>::value_type> { /* */ };
  
  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tvec2<T,P>>
    : public std::numeric_limits<typename glm::detail::tvec2<T,P>::value_type> { /* */ };

  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tvec3<T,P>>
    : public std::numeric_limits<typename glm::detail::tvec3<T,P>::value_type> { /* */ };

  template <typename T, glm::precision P>
  struct numeric_limits<glm::detail::tvec4<T,P>>
    : public std::numeric_limits<typename glm::detail::tvec4<T,P>::value_type> { /* */ };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace std {

#endif // #if !defined(UKACHULLDCS_08961_GLM_GTX_LIMITS_HPP)
