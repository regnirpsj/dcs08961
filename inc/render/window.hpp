// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/window.hpp                                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_WINDOW_HPP)

#define UKACHULLDCS_08961_RENDER_WINDOW_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <boost/noncopyable.hpp>   // boost::noncopyable
#include <glm/glm.hpp>             // glm::ivec2

// includes, project

#include <field/value/multi.hpp>
#include <field/container.hpp>
#include <render/context.hpp>
#include <render/export.h>
#include <render/pass/container.hpp>

namespace render {
  
  // types, exported (class, enum, struct, union, typedef)

  class DCS08961_RENDER_EXPORT window : public field::container {

  public:

    using pass_field_type = field::value::multi<boost::intrusive_ptr<pass::container>>;

    field::value::single<std::string> title; //< window base title
    pass_field_type                   passes; //< pass(es)/stage(s) list (dflt: empty)
      
    virtual ~window() =0;

  protected:

    boost::intrusive_ptr<context::device> dev_ctx_;
    boost::intrusive_ptr<context::swap>   swp_ctx_;
    
    explicit window(std::string const& /* win title */,
                    context::device*   /* dev ctx   */ = nullptr);

    virtual void render(unsigned /* frames */ = 1);
    virtual void resize(glm::ivec2 const&);
      
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_WINDOW_HPP)
