// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/null.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_STAGE_NULL_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_STAGE_NULL_HPP

// includes, system

//#include <>

// includes, project

#include <render/base/stage/base.hpp>

namespace render {

  namespace base {

    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_EXPORT null : public base {

      public:
        
        virtual ~null();
        
      protected:
        
        explicit null(context&);

        virtual void do_execute();
        virtual void do_resize (glm::ivec2 const&);

      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {

  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_STAGE_NULL_HPP)
