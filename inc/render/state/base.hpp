// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/state/base.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STATE_BASE_HPP)

#define UKACHULLDCS_08961_RENDER_STATE_BASE_HPP

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

  } // namespace context
  
  namespace state {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT base : public field::container,
                                        public support::refcounted<base> {

    public:

      field::value::single<bool>        active; ///< (dflt: true)
      field::value::single<std::string> name;   ///< 
      
      virtual ~base() =0;

      virtual void apply() const;
      
      virtual void print_on(std::ostream&) const;

    protected:

      context::device& ctx_;
      
      explicit base(context::device&);

      virtual void do_apply() const =0;
      
    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace state {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STATE_BASE_HPP)
