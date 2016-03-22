// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  geometry/kd_tree.inl                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GEOMETRY_KD_TREE_INL)

#define UKACHULLDCS_08961_GEOMETRY_KD_TREE_INL

// includes, system

//#include <>

// includes, project

#include <support/io_utils.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if 1 // defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace geometry {
  
  // functions, inlined (inline)

  template <typename T, unsigned D>
  /* virtual */ inline void
  kd_tree<T,D>::print_on(std::ostream& os) const
  {
#if 0
    {
      os << "[" << support::demangle(typeid(*this)) << "]";
    }
#else
    {
      using support::ostream::operator<<;
      
      os << values_ << ':';

      for (auto const& c : children_) {
        if (c.get()) { 
          os << *c << ' ';
        }
      }
    }
#endif
  }
  
} // namespace geometry {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_GEOMETRY_KD_TREE_INL)
