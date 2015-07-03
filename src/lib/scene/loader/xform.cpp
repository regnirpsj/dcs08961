// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/loader/xform.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "loader/xform.hpp"

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <boost/tokenizer.hpp>     // boost::char_separator<>, boost::tokenizer<>

// includes, project

#include <scene/file.hpp>
#include <scene/node/transform.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  scene::node::transform*
  process_xform(std::string& a)
  {
    TRACE("scene::file::xform::<unnamed>::process_xform");

    static boost::char_separator<char> const token_separator(".");
          
    using tokenizer = boost::tokenizer<boost::char_separator<char>>;
    
    tokenizer tokens(a, token_separator);

    using scene::node::transform;
    
    transform* result(new transform);
    
    // remove '.<float>,<float>,<float>,<float>.rot'
    // remove '.<float>,<float>,<float>.scale'
    // remove '.<float>,<float>,<float>,<float>.trans'
    // apply xform

    if        ("rot"   == *tokens.begin()) {
    } else if ("scale" == *tokens.begin()) {
    } else if ("trans" == *tokens.begin()) {
    } else {
      result->xform = glm::mat4(1);
    }
    
    return result;
  }
  
} // namespace {

namespace scene {

  namespace file {

    namespace xform {
      
      // variables, exported
  
      // functions, exported

      node::group*
      load(std::string const& a)
      {
        TRACE("scene::file::xform::load");

        using scene::node::transform;
        
        std::string fname (a);
        transform*  result(process_xform(fname));
        
        result->children += handler::load(fname);
        
        return result;
      }
      
      bool
      save(std::string const& a, node::group* b)
      {
        TRACE("scene::file::xform::save");

        using scene::node::transform;
        
        std::string                     fname (a);
        boost::intrusive_ptr<transform> result(process_xform(fname));

        result->children += b;

        return handler::save(fname, result.get());
      }
      
    } // namespace xform {
    
  } // namespace file {
    
} // namespace scene {
