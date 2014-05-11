// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/api.inl                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_API_INL)

#define UKACHULLDCS_08961_RENDER_API_INL

// includes, system

#include <ostream> // std::basic_ostream<>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
//#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
//#  include <typeinfo>
//#  include <support/type_info.hpp>
//#endif

namespace render {

  namespace api {
  
    // functions, inlined (inline)

    template <typename CTy, typename CTr>
    std::basic_ostream<CTy,CTr>&
    operator<<(std::basic_ostream<CTy,CTr>& os, type const& a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);
    
      if (cerberus) {
        switch (a) {
        case type::d3d:  os << "render::api::type::d3d";  break;
        case type::null: os << "render::api::type::null"; break;
        case type::ogl:  os << "render::api::type::ogl";  break;
        }
      }
    
      return os;
    }
    
  } // namespace api {
  
} // namespace render {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_RENDER_API_INL)
