// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/base.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STAGE_BASE_HPP)

#define UKACHULLDCS_08961_RENDER_STAGE_BASE_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <glm/glm.hpp>             // glm::ivec2
#include <string>                  // std::string

// includes, project

#include <field/container.hpp>
#include <field/value/single.hpp>
#include <render/export.h>
#include <render/stats/cpu.hpp>
#include <support/refcounted.hpp>

namespace render {

  class context;
  
  namespace stage {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT base : public field::container,
                                        public support::refcounted {

    public:

      field::value::single<bool>        active;
      field::value::single<std::string> name;
      
      virtual ~base();

      void execute();
      void resize (glm::ivec2 const&);
         
      virtual void print_on(std::ostream&) const;

    protected:

      context&     ctx_;
      stats::base& stats_execute_;
      stats::base& stats_resize_;
      
      explicit base(context&     /* ctx    */,
                    stats::base& /* exec   */ = stats::base::dflt_stats,
                    stats::base& /* resize */ = stats::base::dflt_stats);

      virtual void do_execute()                  =0;
      virtual void do_resize (glm::ivec2 const&) =0;

    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STAGE_BASE_HPP)
