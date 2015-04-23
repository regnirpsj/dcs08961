// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  gli/gtx/io.hpp                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_GLI_GTX_IO_HPP)

#define UKACHULLDCS_08961_GLI_GTX_IO_HPP

// includes, system

#include <gli/gli.hpp> // gli::format, gli::texture?D
#include <iosfwd>      // std::basic_ostream<> (fwd)


// includes, project

// #include <>

namespace gli {
    
  // types, exported (class, enum, struct, union, typedef)

  // variables, exported (extern)

  // functions, inlined (inline)

  template <typename CTy, typename CTr>
  std::basic_ostream<CTy,CTr>& operator<<(std::basic_ostream<CTy,CTr>&, format const&);
  template <typename CTy, typename CTr>
  std::basic_ostream<CTy,CTr>& operator<<(std::basic_ostream<CTy,CTr>&, texture1D const&);
  template <typename CTy, typename CTr, typename T>
  std::basic_ostream<CTy,CTr>& operator<<(std::basic_ostream<CTy,CTr>&, texture2D const&);
  template <typename CTy, typename CTr>
  std::basic_ostream<CTy,CTr>& operator<<(std::basic_ostream<CTy,CTr>&, texture3D const&);
  
  // functions, exported (extern)
  
} // namespace gli {

#include <gli/gtx/io.inl>

#endif // #if !defined(UKACHULLDCS_08961_GLI_GTX_IO_HPP)
