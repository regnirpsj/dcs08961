// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/tessellation.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_SHADER_TESSELLATION_HPP)

#define UKACHULLDCS_08961_RENDER_SHADER_TESSELLATION_HPP

// includes, system

//#include <>

// includes, project

#include <render/shader/base.hpp>

namespace render {
  
  namespace shader {

    namespace tessellation {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_EXPORT control : public base {

      public:      
      
        virtual ~control();
      
      protected:

        explicit control(context&);

      };

      class DCS08961_RENDER_EXPORT evaluation : public base {

      public:      
      
        virtual ~evaluation();
      
      protected:

        explicit evaluation(context&);

      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace tessellation {

    using hull   = tessellation::control;
    using domain = tessellation::evaluation;
    
  } // namespace shader {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_SHADER_TESSELLATION_HPP)
