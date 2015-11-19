// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  glm_gtx_utilities.inl                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GLM_GTX_UTILITIES_INL)

#define UKACHULLDCS_08961_GLM_GTX_UTILITIES_INL

// includes, system

#include <glm/gtc/constants.hpp> // glm::pi<>

// includes, project

//#include <>

namespace glm {
  
  // functions, inlined (inline)

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  inline constexpr double
  operator "" _deg(unsigned long long a)
  {
    return radians(double(a));
  }
  
  inline constexpr double
  operator "" _deg(long double a)
  {
    return radians(a);
  }
  
  inline constexpr double
  operator "" _rad(unsigned long long a)
  {
    return a;
  }
   
  inline constexpr double
  operator "" _rad(long double a)
  {
    return a;
  }
#endif // #if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))

  template <typename T>
  inline T
  rev(T a)
  {
    return a - glm::floor(a / glm::two_pi<T>()) * glm::two_pi<T>();
  }
  
  // http://stackoverflow.com/questions/1903954
  template <typename T>
  inline signed
  sgn(T val)
  {
    return (val > T(0)) - (val < T(0));
  }

} // namespace glm {

#endif // #if !defined(UKACHULLDCS_08961_GLM_GTX_UTILITIES_INL)
