// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render_stage.hpp                                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STAGE_HPP)

#define UKACHULLDCS_08961_RENDER_STAGE_HPP

// includes, system

//#include <>

//// includes, project

#include <support/printable.hpp>
#include <support/refcounted.hpp>

namespace render {

  template <typename T> class context;
  
  namespace stage {
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T>
    class base : public support::refcounted,
                 public support::printable {

    public: 
      
      virtual ~base() =0;
      
      void execute();      
                   
      bool active() const;
      bool active(bool);

      virtual void print_on(std::ostream&) const;

    protected:

      typedef context<T> context_type;
      
      context_type& context_;
      bool          active_;

      explicit base(context_type&);

      virtual void do_execute() =0;
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STAGE_HPP)
