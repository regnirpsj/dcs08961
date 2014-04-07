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

#include <field/adapter_multi.hpp>
#include <field/adapter_single.hpp>
#include <field/value_multi.hpp>
#include <field/value_single.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

// variables, exported

#define DEFAULT_FIELD_TYPE_FOR(type)           \
  template class field::value::multi   <type>; \
  template class field::value::single  <type>; \
  template class field::adapter::multi <type>; \
  template class field::adapter::single<type>

DEFAULT_FIELD_TYPE_FOR(         bool);
DEFAULT_FIELD_TYPE_FOR(signed   char);
DEFAULT_FIELD_TYPE_FOR(unsigned char);
DEFAULT_FIELD_TYPE_FOR(         char16_t);
DEFAULT_FIELD_TYPE_FOR(         char32_t);
DEFAULT_FIELD_TYPE_FOR(signed   short);
DEFAULT_FIELD_TYPE_FOR(unsigned short);
DEFAULT_FIELD_TYPE_FOR(signed   int);
DEFAULT_FIELD_TYPE_FOR(unsigned int);
DEFAULT_FIELD_TYPE_FOR(signed   long int);
DEFAULT_FIELD_TYPE_FOR(unsigned long int);
DEFAULT_FIELD_TYPE_FOR(signed   long long int);
DEFAULT_FIELD_TYPE_FOR(unsigned long long int);
DEFAULT_FIELD_TYPE_FOR(         float);
DEFAULT_FIELD_TYPE_FOR(         double);
DEFAULT_FIELD_TYPE_FOR(         long double);
DEFAULT_FIELD_TYPE_FOR(         std::string);

#undef DEFAULT_FIELD_TYPE_FOR
