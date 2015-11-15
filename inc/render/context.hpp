// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/context.hpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_CONTEXT_HPP)

#define UKACHULLDCS_08961_RENDER_CONTEXT_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable

// includes, project

#include <render/export.h>
#include <support/printable.hpp>
#include <support/refcounted.hpp>

namespace render {

  namespace context {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT base : public support::printable,
                                        public support::refcounted<base> {

    public:

      virtual ~base() =0;
      
      virtual void print_on(std::ostream&) const;

    protected:

      explicit base();
      
    };
      
    class DCS08961_RENDER_EXPORT device : virtual public base {

    public:

      virtual ~device() =0;
      
      virtual void print_on(std::ostream&) const;

    protected:

      explicit device();
    
    };

    class DCS08961_RENDER_EXPORT swap : virtual public base {

    public:

      virtual ~swap() =0;
      
      virtual void print_on(std::ostream&) const;

    protected:

      explicit swap();
    
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
  } // namespace context {

} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_CONTEXT_HPP)
