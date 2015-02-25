// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  window/base.hpp                                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_WINDOW_BASE_HPP)

#define UKACHULLDCS_08961_WINDOW_BASE_HPP

// includes, system

#include <string>      // std::string
#include <glm/glm.hpp> // glm::i16vec2

// includes, project

#include <field/container.hpp>
#include <field/value/single.hpp>
#include <window/export.h>

namespace window {
  
  // types, exported (class, enum, struct, union, typedef)

  class DCS08961_WINDOW_EXPORT base : public field::container {

  public:

    field::value::single<std::string>   title;
    field::value::single<glm::i16vec2>  position;
    field::value::single<glm::i16vec2>  size;
    
    virtual ~base() =0;

  protected:
    
    explicit base(std::string const&  /* title */,
                  glm::i16vec2 const& /* pos */  = glm::i16vec2(-1, -1),
                  glm::i16vec2 const& /* size */ = glm::i16vec2(-1, -1));
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace window {

#endif // #if !defined(UKACHULLDCS_08961_WINDOW_BASE_HPP)
