// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/pass/container.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_PASS_CONTAINER_HPP)

#define UKACHULLDCS_08961_RENDER_PASS_CONTAINER_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <field/value/multi.hpp>
#include <render/pass/base.hpp>

namespace render {
    
  namespace pass {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT container : public pass::base {

    public:

      using stage_field_type = field::value::multi<boost::intrusive_ptr<stage::base>>;
      
      stage_field_type stages;
      
      explicit container(context::device&);
      virtual ~container();      

    protected:

      virtual void do_execute(context::swap&);
      virtual void do_resize (glm::ivec2 const&);
        
    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace pass {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_PASS_CONTAINER_HPP)
