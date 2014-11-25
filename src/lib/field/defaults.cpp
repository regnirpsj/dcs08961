// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/defaults.cpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <string> // std::string

// includes, project

#include <field/adapters.hpp>
#include <field/values.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

// variables, exported

#if 0 // what for?

#define DEFAULT_FIELD_TYPES_FOR(type)           \
  template class field::value::multi   <type>; \
  template class field::value::single  <type>; \
  template class field::adapter::multi <type>; \
  template class field::adapter::single<type>

DEFAULT_FIELD_TYPES_FOR(         bool);
DEFAULT_FIELD_TYPES_FOR(signed   char);
DEFAULT_FIELD_TYPES_FOR(unsigned char);
DEFAULT_FIELD_TYPES_FOR(         char16_t);
DEFAULT_FIELD_TYPES_FOR(         char32_t);
DEFAULT_FIELD_TYPES_FOR(signed   short);
DEFAULT_FIELD_TYPES_FOR(unsigned short);
DEFAULT_FIELD_TYPES_FOR(signed   int);
DEFAULT_FIELD_TYPES_FOR(unsigned int);
DEFAULT_FIELD_TYPES_FOR(signed   long int);
DEFAULT_FIELD_TYPES_FOR(unsigned long int);
DEFAULT_FIELD_TYPES_FOR(signed   long long int);
DEFAULT_FIELD_TYPES_FOR(unsigned long long int);
DEFAULT_FIELD_TYPES_FOR(         float);
DEFAULT_FIELD_TYPES_FOR(         double);
DEFAULT_FIELD_TYPES_FOR(         long double);
DEFAULT_FIELD_TYPES_FOR(         std::string);

#undef DEFAULT_FIELD_TYPES_FOR

#endif // #if 0
