// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/program.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_SHADER_PROGRAM_HPP)

#define UKACHULLDCS_08961_RENDER_SHADER_PROGRAM_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <render/shader/fragment.hpp>
#include <render/shader/geometry.hpp>
#include <render/shader/tessellation.hpp>
#include <render/shader/vertex.hpp>

namespace render {

  namespace device {
    
    class context;
    
  } // namespace device {
  
  namespace shader {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT program : public field::container,
                                           public support::refcounted<program> {

    public:

      using tess_ctrl = tessellation::control;
      using tess_eval = tessellation::evaluation;
      
      using vertex_shader_field_type    = field::value::single<boost::intrusive_ptr<vertex>>;
      using tess_ctrl_shader_field_type = field::value::single<boost::intrusive_ptr<tess_ctrl>>;
      using tess_eval_shader_field_type = field::value::single<boost::intrusive_ptr<tess_eval>>;
      using geometry_shader_field_type  = field::value::single<boost::intrusive_ptr<geometry>>;
      using fragment_shader_field_type  = field::value::single<boost::intrusive_ptr<fragment>>;
      
      field::value::single<bool>        active;           //<
      field::value::single<std::string> name;             //<
      vertex_shader_field_type          vertex_shader;    //<
      tess_ctrl_shader_field_type       tess_ctrl_shader; //<
      tess_eval_shader_field_type       tess_eval_shader; //<
      geometry_shader_field_type        geometry_shader;  //<
      fragment_shader_field_type        fragment_shader;  //<
      
      virtual ~program();

      void activate();
      void compile ();
      void link    ();
      
      virtual void print_on(std::ostream&) const;

    protected:

      device::context& ctx_;
      
      explicit program(device::context&);

      virtual void do_activate();
      virtual void do_compile () =0;
      virtual void do_link    () =0;

      virtual void do_changed(field::base&);
      
    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace shader {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_SHADER_PROGRAM_HPP)
