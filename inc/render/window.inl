// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/window.inl                                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_WINDOW_INL)

#define UKACHULLDCS_08961_RENDER_WINDOW_INL

// includes, system

#include <algorithm> // std::find<>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace render {
  
  // functions, inlined (inline)

  template <typename T>
  inline window<T>::context_type&
  window<T>::context()
  {
    TRACE("render::window<" + support::demangle(typeid(T)) + ">::context");
    
    return context_;
  }

  template <typename T>
  inline bool
  window<T>::add(pass::base<T>* a)
  {
    TRACE("render::window<" + support::demangle(typeid(T)) + ">::add");
    
    bool       result(false);
    auto const found(std::find(render_pass_list_.begin(), render_pass_list_.end(), a));
    
    if (render_pass_list_.end() == found) {
      render_pass_list_.push_back(a);
      
      result = true;
    }
    
    return result;
  }
    
  template <typename T>
  inline bool
  window<T>::sub(pass::base<T>* a)
  {
    TRACE("render::window<" + support::demangle(typeid(T)) + ">::sub");
    
    bool       result(false);
    auto const found(std::find(render_pass_list_.begin(), render_pass_list_.end(), a));
    
    if (render_pass_list_.end() != found) {
      render_pass_list_.erase(found);
      
      result = true;
    }
    
    return result;
  }
  
  template <typename T>
  inline void
  window<T>::render(unsigned frames)
  {
    TRACE("render::window<" + support::demangle(typeid(T)) + ">::render");
    
    while (frames--) {
      for (auto& p : render_pass_list_) {
        p.execute();
      }
    }
  }
  
} // namespace render {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_RENDER_WINDOW_INL)
