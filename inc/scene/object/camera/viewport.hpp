// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/camera/viewport.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_VIEWPORT_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_VIEWPORT_HPP

// includes, system

#include <iosfwd> // std::ostream (fwd)

// includes, project

#include <scene/export.h>

#ifdef far
#  pragma message("Note: undefining 'near'! (" __FILE__ ")")
#  undef far
#endif

#ifdef near
#  pragma message("Note: undefining 'far'! (" __FILE__ ")")
#  undef near
#endif

namespace scene {

  namespace object {

    namespace camera {
      
      // types, exported (class, enum, struct, union, typedef)

      struct DCS08961_SCENE_EXPORT viewport {

      public:

        float x;      ///< lower-left corner x-ccordinate
        float y;      ///< lower-left corner y-ccordinate
        float width;  ///< width
        float height; ///< height
        float near;   ///< window coordinates minimum depth (see glDepthRange(3G))
        float far;    ///< window coordinates maximum depth (see glDepthRange(3G))

        explicit viewport(float /* x */      =   0.00,
                          float /* y */      =   0.00,
                          float /* width */  = 100.00,
                          float /* height */ = 100.00,
                          float /* near */   =   0.00,
                          float /* far */    =   1.00);
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
      
      std::ostream& operator<<(std::ostream&, viewport const&);
      
    } // namespace camera {

  } // namespace object {
      
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_VIEWPORT_HPP)
