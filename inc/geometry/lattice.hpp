// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

#include <vector> // std::vector<>

// includes, project

#include <support/printable.hpp>

namespace geometry {
  
  // types, exported (class, enum, struct, union, typedef)

  template <typename T, unsigned X = 2, unsigned Y = 2, unsigned Z = 2>
  class lattice : public support::printable {

  public:

    using value_type = T;
    
    explicit lattice(value_type const& = value_type());
    
    virtual void print_on(std::ostream&) const;

    value_type const& at(unsigned, unsigned, unsigned) const;
    value_type&       at(unsigned, unsigned, unsigned);
    
  protected:

    using data_container_type = std::vector<std::vector<std::vector<value_type>>>;
    
    data_container_type data_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace geometry {

#include <geometry/lattice.inl>

#endif // #if !defined(UKACHULLDCS_08961_GEOMETRY_LATTICE_HPP)
