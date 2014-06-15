// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/connection/update.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_UPDATE_HPP)

#define UKACHULLDCS_08961_FIELD_CONNECTION_UPDATE_HPP

// includes, system

//#include <>

// includes, project

// #include <>

namespace field {
  
  namespace connection {

    namespace update {
      
      // types, exported (class, enum, struct, union, typedef)
      
      // variables, exported (extern)

      // functions, inlined (inline)

      template <typename T1, typename T2>
      void assign(T1* const /* src */, T2* const /* dst */);

      template <typename T1, typename T2>
      void average(T1* const /* src */, T2* const /* dst */);
      
      template <typename T1, typename T2>
      void append(T1* const /* src */, T2* const /* dst */);

      template <typename T1, typename T2>
      void prepend(T1* const /* src */, T2* const /* dst */);
      
      // functions, exported (extern)

    } // namespace update {
      
  } // namespace connection {
  
} // namespace field {

#include <field/connection/update.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_UPDATE_HPP)
