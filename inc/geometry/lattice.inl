// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

#include <sstream>   // std::ostringstream
#include <stdexcept> // std::range_error

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
  lattice<T,X,Y,Z>::lattice(value_type const& a)
    : support::printable(),
      data_             (X, std::vector<std::vector<T>>(Y, std::vector<T>(Z, a)))
  {
    TRACE("geometry::lattice<T," + std::to_string(X) + "," + std::to_string(Y) + "," +
          std::to_string(Z) + ">::lattice");
  }

  template <typename T, unsigned X, unsigned Y, unsigned Z>
  inline /* virtual */ void
  lattice<T,X,Y,Z>::print_on(std::ostream& os) const
  {
    TRACE_NEVER("geometry::lattice<T," + std::to_string(X) + "," + std::to_string(Y) + "," +
                std::to_string(Z) + ">::print_on");

    using support::ostream::operator<<;
    
    os << '['
       << data_.size() << 'x' << data_[0].size() << 'x' << data_[0][0].size() << ':'
       << data_
       << ']';
  }

  template <typename T, unsigned X, unsigned Y, unsigned Z>
  inline typename lattice<T,X,Y,Z>::value_type const&
  lattice<T,X,Y,Z>::at(unsigned x, unsigned y, unsigned z) const
  {
    TRACE("geometry::lattice<T," + std::to_string(X) + "," + std::to_string(Y) + "," +
          std::to_string(Z) + ">::at(const)");

    if ((X <= x) || (Y <= y) || (Z <= z)) {
      std::ostringstream ostr;

      ostr << "geometry::lattice<T," << X << ',' << Y << ',' << Z << ">::at(const): "
           << "index access at [" << x << ',' << y << ',' << z << "] out of range";
      
      throw std::range_error(ostr.str());
    }
    
    return data_[x][y][z];
  }
  
  template <typename T, unsigned X, unsigned Y, unsigned Z>
  inline typename lattice<T,X,Y,Z>::value_type&
  lattice<T,X,Y,Z>::at(unsigned x, unsigned y, unsigned z)
  {
    TRACE("geometry::lattice<T," + std::to_string(X) + "," + std::to_string(Y) + "," +
          std::to_string(Z) + ">::at");

    if ((X <= x) || (Y <= y) || (Z <= z)) {
      std::ostringstream ostr;

      ostr << "geometry::lattice<T," << X << ',' << Y << ',' << Z << ">::at: "
           << "index access at [" << x << ',' << y << ',' << z << "] out of range";
      
      throw std::range_error(ostr.str());
    }
    
    return data_[x][y][z];
  }
  
} // namespace geometry {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_GEOMETRY_LATTICE_INL)
