// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/base.inl                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_BASE_INL)

#define UKACHULLDCS_08961_SCENE_NODE_BASE_INL

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
    operator==(base::bounds const& lhs, base::bounds const& rhs)
    {
      TRACE("scene::node::operator==(base::bounds,base::bounds)");
      
      return ((&lhs == &rhs) ||
              ((lhs.min   == rhs.min) &&
               (lhs.max   == rhs.max) &&
               (lhs.valid == rhs.valid)));
    }

    inline bool
    operator!=(base::bounds const& lhs, base::bounds const& rhs)
    {
      TRACE("scene::node::operator!=(base::bounds,base::bounds)");
      
      return !(lhs == rhs);
    }

  } // namespace node {
  
} // namespace scene {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_BASE_INL)
