// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/geometry.inl                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_GEOMETRY_INL)

#define UKACHULLDCS_08961_SCENE_NODE_GEOMETRY_INL

// includes, system

//#include <>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

namespace scene {

  namespace node {
    
    // functions, inlined (inline)

    inline bool
    operator==(geometry::attribute const& lhs, geometry::attribute const& rhs)
    {
      TRACE("scene::node::operator==(geometry::attribute,geometry::attribute)");
      
      return ((&lhs == &rhs) ||
              ((lhs.position == rhs.position) &&
               (lhs.normal   == rhs.normal)   &&
               (lhs.tcoord   == rhs.tcoord)   &&
               (lhs.tangent  == rhs.tangent)  &&
               (lhs.color    == rhs.color)));
    }
    
  } // namespace node {
  
} // namespace scene {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_GEOMETRY_INL)
