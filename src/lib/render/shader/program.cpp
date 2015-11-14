// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/program.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/shader/program.hpp"

// includes, system

#include <stdexcept> // std::logic_error

// includes, project

#include <render/context.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  template <typename T>
  inline std::ostream&
  operator<<(std::ostream& os, boost::intrusive_ptr<T> const& a)
  {
    typename std::ostream::sentry const cerberus(os);
    
    if (cerberus) {
      if (a) {
        os << *(a.get());
      } else {
        os << a.get();
      }
    }
    
    return os;
  }
  
} // namespace {

namespace render {

  namespace shader {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    program::~program()
    {
      TRACE("render::shader::program::~program");
    }

    void
    program::activate()
    {
      TRACE("render::shader::program::activate");

      if (*active) {
        do_activate();
      }
    }
    
    void
    program::compile()
    {
      TRACE("render::shader::program::compile");

      if (*active) {
        do_compile();
      }
    }

    void
    program::link()
    {
      TRACE("render::shader::program::link");

      if (*active) {
        do_link();
      }
    }
    
    /* virtual */ void
    program::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::shader::program::print_on");

      field::container::print_on(os);

      os << "\b,"
         << ctx_
         << ']';
    }

    /* explicit */
    program::program(device::context& a)
      : field::container            (),
        support::refcounted<program>(),
        active                      (*this, "active",           true),
        name                        (*this, "name",             "[render::shader::program]"),
        vertex_shader               (*this, "vertex_shader",    nullptr),
        tess_ctrl_shader            (*this, "tess_ctrl_shader", nullptr),
        tess_eval_shader            (*this, "tess_eval_shader", nullptr),
        geometry_shader             (*this, "geometry_shader",  nullptr),
        fragment_shader             (*this, "fragment_shader",  nullptr),
        ctx_                        (a)
    {
      TRACE("render::shader::program::program");
    }

    /* virtual */ void
    program::do_activate()
    {
      TRACE("render::shader::program::do_activate");

      if (*vertex_shader || *fragment_shader) {
        if (*vertex_shader) {
          (*vertex_shader)->activate();
        }

        if (*tess_ctrl_shader && *tess_eval_shader) {
          (*tess_ctrl_shader)->activate();
          (*tess_eval_shader)->activate();
        }
        
        if (*geometry_shader) {
          (*geometry_shader)->activate();
        }

        if (*fragment_shader) {
          (*fragment_shader)->activate();
        }
      }
    }
    
    /* virtual */ void
    program::do_compile()
    {
      TRACE("render::shader::program::do_compile");

      throw std::logic_error("pure virtual function 'render::shader::program::do_compile' called");
    }

    /* virtual */ void
    program::do_link()
    {
      TRACE("render::shader::program::do_link");

      throw std::logic_error("pure virtual function 'render::shader::program::do_link' called");
    }

    /* virtual */ void
    program::do_changed(field::base& f)
    {
      TRACE("render::shader::program::do_changed");
      
      if (&active == &f) {
        if (*vertex_shader)    { (*vertex_shader)->active    = *active; }
        if (*tess_ctrl_shader) { (*tess_ctrl_shader)->active = *active; }
        if (*tess_eval_shader) { (*tess_eval_shader)->active = *active; }
        if (*geometry_shader)  { (*geometry_shader)->active  = *active; }
        if (*fragment_shader)  { (*fragment_shader)->active  = *active; }
      }

      else {
        field::container::do_changed(f);
      }
    }
    
  } // namespace shader {
  
} // namespace render {
