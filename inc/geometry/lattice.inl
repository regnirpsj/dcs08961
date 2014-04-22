// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  geometry/lattice.inl                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GEOMETRY_LATTICE_INL)

#define UKACHULLDCS_08961_GEOMETRY_LATTICE_INL

// includes, system

//#include <>

// includes, project

#include <support/io_utils.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
//#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
//#  include <typeinfo>
//#  include <support/type_info.hpp>
//#endif

namespace geometry {
  
  // functions, inlined (inline)

  template <typename T, unsigned X, unsigned Y, unsigned Z>
  inline /* explicit */
  lattice<T,X,Y,Z>::lattice()
    : support::printable(),
      data_             ()
  {
    TRACE("geometry::lattice<T,D>::lattice");
  }

  template <typename T, unsigned X, unsigned Y, unsigned Z>
  inline /* virtual */ void
  lattice<T,X,Y,Z>::print_on(std::ostream& os) const
  {
    TRACE_NEVER("geometry::lattice<T,D>::print_on");

    using support::ostream::operator<<;
    
    os << data_;
  }
  
} // namespace geometry {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_GEOMETRY_LATTICE_INL)
