// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  glm/gtx/utilities.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GLM_GTX_UTILITIES_HPP)

#define UKACHULLDCS_08961_GLM_GTX_UTILITIES_HPP

// includes, system

#include <glm/glm.hpp> // glm::mat4, glm::vec3

// includes, project

#include <glm/export.h>

namespace glm {
  
  // types, exported (class, enum, struct, union, typedef)

  struct DCS08961_GLM_EXPORT decompose {
        
  public:

    enum order { rst, rts, srt, str, trs, tsr, };
    
    mat4 rotation;
    mat4 scale;
    mat4 translation;
    
    explicit decompose(mat4 const&);
    
  };
  
  // variables, exported (extern)

  namespace convert {

    /**
     * \brief transformtion to be left multiplied to an opengl projection matrix for in a
     *        d3d11 pipeline
     */
    extern DCS08961_GLM_EXPORT mat4 const opengl_to_d3d;

    /**
     * \brief glm::inverse(opengl_to_d3d); \see opengl_to_d3d
     */
    extern DCS08961_GLM_EXPORT mat4 const d3d_to_opengl;
    
  } // namespace convert {
  
  // functions, inlined (inline)
  
  /**
   * \brief converts the input value from (assumed) degrees to radians
   *
   * \return argument in radians
   */
  template <typename T>
#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  constexpr
#endif
  T deg2rad(T);
  
  /**
   * \brief converts the input value from (assumed) radians to degrees
   *
   * \return argument in degrees
   */
  template <typename T>
#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  constexpr
#endif
  T rad2deg(T);
  
#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  /**
   * \brief user-defined literals for distinguishing degrees and radians
   *
   * float a1(90_deg);                  // 90 degree in radians
   * float a2(glm::pi<float>() / 4.0);  // 90 degree in radians
   *
   * these operators respect the GLM_FORCE_RADIANS define, i.e
   *
   * #if defined(GLM_FORCE_RADIANS)
   *   180_deg -> pi
   *   pi_rad  -> pi
   * #else
   *   180_deg -> 180
   *   pi_rad  -> 180
   * #endif
   */
  //@{
  constexpr double operator "" _deg(unsigned long long);  
  constexpr double operator "" _deg(long double);
  constexpr double operator "" _rad(unsigned long long);
  constexpr double operator "" _rad(long double);
  //@}
#else
#  pragma message("Note: user-defined string literal operators not supported ")
#  pragma message("      using (unreliable) macro workaround for _deg/_rad")
#endif // !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  
  /**
   * \brief compute the signum of T
   *
   * \param  T
   *
   * \return signum(T)
   */
  template <typename T> signed sgn(T);
  
  // functions, exported (extern)

  namespace convert {
    
    /**
     * \brief converts the input matrix into its equivalent as
     *        determined by \c decompose::order
     *        input matrix may contain rotation, scale, or
     *        translation; however, shear etc. are not allowed
     *
     * \return converted matrix
     */
    DCS08961_GLM_EXPORT mat4 transform(mat4 const&, decompose::order);
  
    /**
     * \brief converts the input matrix into its equivalent as
     *        determined by \c decompose::order
     *        input matrix may contain rotation, scale, or
     *        translation; however, shear etc. are not allowed
     *
     * \return converted matrix as well as rotation, scale, and translation parts
     */
    DCS08961_GLM_EXPORT mat4 transform(mat4 const&, decompose::order,
                                       mat4& /* rotation */,
                                       mat4& /* scale */,
                                       mat4& /* translation */);
    
  } // namespace convert {

} // namespace glm {

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
// for convenience, to avoid cumbersome lines like 'using glm::operator "" _deg;'
using glm::operator "" _deg;
using glm::operator "" _rad;
#else
// poor solution to still keep _deg/_rad around, so '180.0_deg' should still work, well actually it
// must then be '180.0 _deg'; will possible break at the most inconvenient of times
#  if defined(GLM_FORCE_RADIANS)
#    define _deg *(3.14159265358979323846264338327950288/180.0)
#    define _rad
#  else
#    define _deg
#    define _rad *(180.0/3.14159265358979323846264338327950288)
#  endif // if defined(GLM_FORCE_RADIANS)
#endif // !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))

#include <glm/gtx/utilities.inl>

#endif // #if !defined(UKACHULLDCS_08961_GLM_GTX_UTILITIES_HPP)
