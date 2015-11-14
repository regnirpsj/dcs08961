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

#include <glm/glm.hpp> // glm::ivec2
#include <string>      // std::string

// includes, project

#include <field/container.hpp>
#include <field/value/single.hpp>
#include <render/export.h>
#include <support/refcounted.hpp>

namespace render {

  namespace device {
    
    class context;
    
  } // namespace device {
  
  namespace stats {

    class base;
    
  } // namespace stats {

  namespace swap {
    
    class context;
    
  } // namespace swap {
  
  namespace stage {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT base : public field::container,
                                        public support::refcounted<base> {

    public:

      field::value::single<bool>         active;
      field::value::single<std::string>  name;
      field::value::single<stats::base*> stats_execute;
      field::value::single<stats::base*> stats_resize;
      
      virtual ~base();

      void execute(swap::context&    /* swp ctx */);
      void resize (glm::ivec2 const& /* w/h */);
         
      virtual void print_on(std::ostream&) const;

    protected:

      device::context& ctx_;
      
      explicit base(device::context& /* dev ctx*/);

      virtual void do_execute(swap::context&)    =0;
      virtual void do_resize (glm::ivec2 const&) =0;

    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STAGE_BASE_HPP)
