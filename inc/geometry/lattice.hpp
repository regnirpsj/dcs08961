// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  geometry/lattice.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GEOMETRY_LATTICE_HPP)

#define UKACHULLDCS_08961_GEOMETRY_LATTICE_HPP

// includes, system

#include <array> // std::array<>

// includes, project

#include <support/printable.hpp>

namespace geometry {
  
  // types, exported (class, enum, struct, union, typedef)

  template <typename T, unsigned X = 2, unsigned Y = 2, unsigned Z = 2>
  class lattice : public support::printable {

  public:

    explicit lattice();
    
    virtual void print_on(std::ostream&) const;
    
  protected:

    std::array<std::array<std::array<T, Z>, Y>, X> data_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace geometry {

#include <geometry/lattice.inl>

#endif // #if !defined(UKACHULLDCS_08961_GEOMETRY_LATTICE_HPP)
