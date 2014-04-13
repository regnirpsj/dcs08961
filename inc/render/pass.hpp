// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render_pass.hpp                                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_PASS_HPP)

#define UKACHULLDCS_08961_RENDER_PASS_HPP

// includes, system

#include <glm/glm.hpp> // glm::ivec2

// includes, project

#include <render/stage.hpp>

namespace render {

  namespace pass {
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T>
    class base : public stage::base<T> {

    public:

      virtual ~base() =0;

      virtual void invalidate() =0;
      virtual void resize    (glm::ivec2 const& /* size */) =0;

    protected:

      typedef stage::base<T>::context_type context_type;
      
      explicit base(context_type&);

      virtual void do_execute() =0;

    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace pass {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_PASS_HPP)
