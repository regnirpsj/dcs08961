// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/window/rect.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_RECT_HPP)

#define UKACHULLDCS_08961_PLATFORM_WINDOW_RECT_HPP

// includes, system

#include <glm/glm.hpp> // glm::ivec2
#include <iosfwd>      // std::ostream (fwd)

// includes, project

#include <platform/export.h>

namespace platform {

  namespace window {
  
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_PLATFORM_EXPORT rect {

    public:

      static signed const dflt_value_system; // -1
      static rect const   dflt_rect;

      signed x;
      signed y;
      signed w;
      signed h;

               rect(signed /* x */ = dflt_value_system,
                    signed /* y */ = dflt_value_system,
                    signed /* w */ = dflt_value_system,
                    signed /* h */ = dflt_value_system);

      explicit rect(glm::ivec2 const& /* (x,y) */, glm::ivec2 const& /* (w,h) */);

      void swap(rect&);

      bool contains(glm::ivec2 const&) const;
      
    };
        
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

    bool operator==(rect const&, rect const&);
    bool operator< (rect const&, rect const&);

    std::ostream& operator<<(std::ostream&, rect const&);

  } // namespace window {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_RECT_HPP)
