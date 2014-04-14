// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  glm_gtx_utilities.inl                                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GLM_GTX_UTILITIES_INL)

#define UKACHULLDCS_08961_GLM_GTX_UTILITIES_INL

// includes, system

//#include <>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
//#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
//#  include <typeinfo>
//#  include <support/type_info.hpp>
//#endif

namespace glm {
  
  // functions, inlined (inline)

#if defined(_MSC_VER) && (_MSC_VER <= 1700)
  inline double
#else
  inline constexpr double
#endif
  deg2rad(double a)
  {
    return (3.14159265358979323846264338327950288 / 180.0) * a;
  }

#if defined(_MSC_VER) && (_MSC_VER <= 1700)
  inline double
#else
  inline constexpr double
#endif
  rad2deg(double a)
  {
    return (180.0 / 3.14159265358979323846264338327950288) * a;
  }

#if defined(_MSC_VER) && (_MSC_VER <= 1700)
  // not going to reapeat warning here
#else
  inline constexpr double
  operator "" _deg(unsigned long long a)
  {
#  if defined(GLM_FORCE_RADIANS)
    return a * (3.14159265358979323846264338327950288 / 180.0);
#  else
    return a;
#  endif
  }
  
  inline constexpr double
  operator "" _deg(long double a)
  {
#  if defined(GLM_FORCE_RADIANS)
    return a * (3.14159265358979323846264338327950288 / 180.0);
#  else
    return a;
#  endif
  }
  
  inline constexpr double
  operator "" _rad(unsigned long long a)
  {
#  if defined(GLM_FORCE_RADIANS)
    return a;
#  else
    return a * (180.0 / 3.14159265358979323846264338327950288);
#  endif
  }
  
  inline constexpr double
  operator "" _rad(long double a)
  {
#  if defined(GLM_FORCE_RADIANS)
    return a;
#  else
    return a * (180.0 / 3.14159265358979323846264338327950288);
#  endif
  }
#endif // #if defined(_MSC_VER) && (_MSC_VER <= 1700)

  // http://stackoverflow.com/questions/1903954
  template <typename T>
  inline signed
  sgn(T val)
  {
    return (val > T(0)) - (val < T(0));
  }

} // namespace glm {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_GLM_GTX_UTILITIES_INL)
