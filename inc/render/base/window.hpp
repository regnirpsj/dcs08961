// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/window.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_WINDOW_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_WINDOW_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <boost/noncopyable.hpp>   // boost::noncopyable
#include <glm/glm.hpp>             // glm::ivec2

// includes, project

#include <field/adapter/multi.hpp>
#include <field/container.hpp>
#include <render/export.h>

namespace render {

  namespace base {

    namespace pass {

      class container;
      
    };
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT window : private field::container {

    public:

      using pass_field_type = field::adapter::multi<boost::intrusive_ptr<pass::container>>;
      
      pass_field_type passes;
      
      virtual ~window() =0;

    protected:

      explicit window();

      virtual void render();
      virtual void resize(glm::ivec2 const&);
      
    };
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_WINDOW_HPP)
