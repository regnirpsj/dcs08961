// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  geometry/kd_tree.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GEOMETRY_KD_TREE_HPP)

#define UKACHULLDCS_08961_GEOMETRY_KD_TREE_HPP

// includes, system

#include <array>  // std::array<>
#include <memory> // std::unique_ptr<>
#include <vector> // std::vector<>

// includes, project

#include <support/printable.hpp>

namespace geometry {
  
  // types, exported (class, enum, struct, union, typedef)
  
  template <typename T, unsigned D>
  struct kd_tree : public support::printable {

  private:

    // [https://stackoverflow.com/questions/16443682]
    inline static constexpr unsigned pow(unsigned base, unsigned exponent)
    {
      return (exponent == 0) ? 1 : (base * pow(base, exponent-1));
    }
    
  public:

    using value_type      = T;
    using value_list_type = std::vector<T>;
    using children_type   = std::array<std::unique_ptr<kd_tree<T,D>>, pow(2, D)>;

    value_list_type values_;
    children_type   children_;

    virtual void print_on(std::ostream&) const;
    
  };

  namespace d1 { template <typename T> using tree = kd_tree<T, 1>; }
  namespace d2 { template <typename T> using tree = kd_tree<T, 2>; }
  namespace d3 { template <typename T> using tree = kd_tree<T, 3>; }
  namespace d4 { template <typename T> using tree = kd_tree<T, 4>; }
  
  template <typename T> using bintree      = d1::tree<T>;
  template <typename T> using quadtree     = d2::tree<T>;
  template <typename T> using octree       = d3::tree<T>;
  template <typename T> using hexadecatree = d4::tree<T>;
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace geometry {

#include <geometry/kd_tree.inl>

#endif // #if !defined(UKACHULLDCS_08961_GEOMETRY_KD_TREE_HPP)
