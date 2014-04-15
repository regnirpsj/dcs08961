// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture/fill.inl                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_FILL_INL)

#define UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_FILL_INL

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

  namespace object {

    namespace texture {

      // functions, inlined (inline)
      
      template <typename T, typename C>
      inline void
      fill(T& t, C const& c)
      {
        TRACE("scene::object::texture::fill<" + support::demangle(typeid(T)) + "," +
              support::demangle(typeid(C)) + ">");
          
        for (unsigned l(0); l < t.levels(); ++l){
          for (unsigned i(0); i < t.template size<C>(); ++i) {
            *(t[l].template data<C>() + i) = c;
          } 
        } 
      }
  
    } // namespace texture {
    
  } // namespace object {
  
} // namespace scene {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_FILL_INL)
