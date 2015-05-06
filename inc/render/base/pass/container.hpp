// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/pass/container.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_PASS_CONTAINER_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_PASS_CONTAINER_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <field/value/multi.hpp>
#include <render/base/pass/base.hpp>

namespace render {
  
  namespace base {
    
    namespace pass {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_EXPORT container : public pass::base {

      public:

        using stage_field_type = field::value::multi<boost::intrusive_ptr<stage::base>>;
      
        stage_field_type stages;

        virtual ~container();      

      protected:
        
        explicit container(context&);

        virtual void do_apply ();
        virtual void do_resize(glm::ivec2 const&);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace pass {

  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_PASS_CONTAINER_HPP)
