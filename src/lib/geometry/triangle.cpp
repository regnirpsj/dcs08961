// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  geometry/triangle.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "geometry/triangle.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <ostream>        // std::ostream

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace geometry {
  
  // variables, exported
  
  // functions, exported

  /* explicit */
  triangle::triangle(glm::vec3 const& a, glm::vec3 const& b, glm::vec3 const& c)
    : support::printable(),
      p0                (a),
      p1                (b),
      p2                (c)
  {
    TRACE("geometry::triangle::triangle");
  }
  
  /* virtual */ void
  triangle::print_on(std::ostream& os) const
  {
    TRACE_NEVER("geometry::triangle::print_on");

    os << '{' << p0 << ',' << p1 << ',' << p2 << '}';
  }

  glm::vec3::value_type
  triangle::area() const
  {
    TRACE("geometry::triangle::area");

    return 0.5f * glm::length(glm::cross(p1 - p2, p1 - p0));
  }

  glm::vec3
  triangle::normal() const
  {
    TRACE("geometry::triangle::normal");

    return glm::normalize(glm::cross(p1 - p2, p1 - p0));
  }

  triangle&
  triangle::operator*=(glm::mat4 const& rhs)
  {
    TRACE("geometry::triangle::operator*=(glm::mat4)");

    p0 = (rhs * glm::vec4(p0, 1)).xyz();
    p1 = (rhs * glm::vec4(p1, 1)).xyz();
    p2 = (rhs * glm::vec4(p2, 1)).xyz();
    
    return *this;
  }

  triangle
  operator*(glm::mat4 const& lhs, triangle const& rhs)
  {
    TRACE("geometry::operator*(glm::mat4,triangle)");

    triangle result(rhs);

    result *= lhs;

    return result;
  }

  triangle
  operator*(triangle const& lhs,  glm::mat4 const& rhs)
  {
    TRACE("geometry::operator*(triangle,glm::mat4)");

    triangle result(lhs);

    result *= rhs;

    return result;
  }

} // namespace geometry {
