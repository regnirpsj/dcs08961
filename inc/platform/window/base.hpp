// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform_window_base.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_BASE_HPP)

#define UKACHULLDCS_08961_PLATFORM_WINDOW_BASE_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <glm/glm.hpp>           // glm::ivec2
#include <string>                // std::string

// includes, project

#include <field/container.hpp>
#include <field/value/single.hpp>
#include <platform/export.h>
#include <platform/window/rect.hpp>
#include <support/printable.hpp>

namespace platform {

  namespace window {

    class DCS08961_PLATFORM_EXPORT base : private boost::noncopyable,
                                          public field::container {

    public:

      field::value::single<std::string> title;
      field::value::single<glm::ivec2>  position;
      field::value::single<glm::ivec2>  size;
      
    protected:
      
      explicit base(std::string const& /* title */, rect const& /* rect */ = rect::dflt_rect);
      
    };
      
    // types, exported (class, enum, struct, union, typedef)

    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace window {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_BASE_HPP)
