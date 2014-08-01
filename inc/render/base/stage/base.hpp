// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/base.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_STAGE_BASE_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_STAGE_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <support/printable.hpp>
#include <support/refcounted.hpp>

namespace render {

  namespace base {

    class context;

    namespace statistics {

      class base;
      
    } // namespace statistics {
    
    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class base : public support::printable,
                   public support::refcounted {

      public:

        virtual ~base() =0;

        bool active() const;
        bool active(bool);
        
        bool stats_enable() const;
        bool stats_enable(bool);
        
        void execute();
      
        virtual void print_on(std::ostream&) const;

      protected:

        context&          ctx_;
        bool              active_;
        statistics::base& stats_;
        bool              stats_enabled_;
        
        explicit base(context&, statistics::base&);

        virtual void do_execute() =0;
        
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {
    
  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_STAGE_BASE_HPP)
