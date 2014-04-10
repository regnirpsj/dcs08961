// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/base.inl                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_VISITOR_BASE_INL)

#define UKACHULLDCS_08961_SCENE_VISITOR_BASE_INL

// includes, system

//#include <>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace scene {

  namespace visitor {
    
    // functions, inlined (inline)

    template <typename T>
    inline void
    base::visit_base(T& o)
    {
      TRACE("scene::visitor::base::visit_base<" + support::demangle(typeid(T)) + ">");
      
      visit(static_cast<typename T::subject_inherited&>(o));
    }
    
  } // namespace visitor {
  
} // namespace scene {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_SCENE_VISITOR_BASE_INL)
