// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  archive/template_@OUTPUT@.cpp */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <boost/archive/xml_iarchive.hpp>    // boost::archive::xml_iarchive
#include <boost/archive/xml_oarchive.hpp>    // boost::archive::xml_oarchive
#include <boost/archive/text_iarchive.hpp>   // boost::archive::text_iarchive
#include <boost/archive/text_oarchive.hpp>   // boost::archive::text_oarchive
#include <boost/archive/binary_iarchive.hpp> // boost::archive::binary_iarchive
#include <boost/archive/binary_oarchive.hpp> // boost::archive::binary_oarchive
#include <boost/serialization/export.hpp>    // BOOST_CLASS_*

// includes, project

#include <@INCLUDE@> // type to be archived

// internal unnamed namespace

namespace {
} // namespace {

// variables, exported

BOOST_CLASS_EXPORT_IMPLEMENT(@TYPE@);

// functions, exported
