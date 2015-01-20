// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/pass/conatiner.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_NULL_PASS_CONTAINER_HPP)

#define UKACHULLDCS_08961_RENDER_NULL_PASS_CONTAINER_HPP

// includes, system

// #include <>

// includes, project

#include <render/base/pass/container.hpp>

namespace render {

  namespace null {
    
    namespace pass {
      
      // types, exported (class, enum, struct, union, typedef)

      class container : public base::pass::container {

      protected:

        typedef render::base::pass::container::base_type base_type;
        
      public:

        explicit container();
        explicit container(std::initializer_list<base_type*> const&);
        virtual ~container();

      protected:
        
        virtual void do_execute();
        
      };      
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace pass {
    
  } // namespace null {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_NULL_PASS_CONTAINER_HPP)
