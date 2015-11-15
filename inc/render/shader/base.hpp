// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/base.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_SHADER_BASE_HPP)

#define UKACHULLDCS_08961_RENDER_SHADER_BASE_HPP

// includes, system

#include <string> // std::string

// includes, project

#include <field/container.hpp>
#include <field/value/single.hpp>
#include <render/export.h>
#include <support/refcounted.hpp>

namespace render {
  
  namespace context {
    
    class device;
    
  } // namespace context {
  
  namespace shader {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT base : public field::container,
                                        public support::refcounted<base> {

    public:

      field::value::single<bool>        active; ///<
      field::value::single<std::string> name;   ///<
      
      virtual ~base();

      void activate();
         
      virtual void print_on(std::ostream&) const;

    protected:

      context::device& ctx_;
      
      explicit base(context::device&);

      virtual void do_activate() =0;

    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace shader {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_SHADER_BASE_HPP)
