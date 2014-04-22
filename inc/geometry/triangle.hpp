// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  geometry/triangle.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GEOMETRY_TRIANGLE_HPP)

#define UKACHULLDCS_08961_GEOMETRY_TRIANGLE_HPP

// includes, system

#include <glm/glm.hpp> // glm::mat4, glm::vec3

// includes, project

#include <support/printable.hpp>

namespace geometry {
  
  // types, exported (class, enum, struct, union, typedef)

  class triangle : public support::printable {

  public:

    glm::vec3 p0;
    glm::vec3 p1;
    glm::vec3 p2;

    explicit triangle(glm::vec3 const& /* p0 */ = glm::vec3(0, 0, 0),
                      glm::vec3 const& /* p1 */ = glm::vec3(1, 0, 0),
                      glm::vec3 const& /* p2 */ = glm::vec3(0, 1, 0));

    virtual void print_on(std::ostream&) const;
    
    glm::vec3::value_type area  () const;
    glm::vec3             normal() const;
    
    triangle& operator*=(glm::mat4 const&);
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)

  triangle operator*(glm::mat4 const&, triangle const&);
  triangle operator*(triangle const&,  glm::mat4 const&);
  
} // namespace geometry {

#endif // #if !defined(UKACHULLDCS_08961_GEOMETRY_TRIANGLE_HPP)
