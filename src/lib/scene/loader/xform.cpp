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
#include <cctype>                  // std::isdigit
#include <glm/gtx/io.hpp>

// includes, project

#include <scene/file.hpp>
#include <scene/node/transform.hpp>
#include <support/io_utils.hpp>

#define UKACHULLDCS_USE_TRACE
//#undef UKACHULLDCS_USE_TRACE
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

    using size_type       = std::string::size_type;
    using pos_list_type   = std::vector<size_type>;
    using float_list_type = std::vector<float>;
    
    pos_list_type dots;
    pos_list_type commas;

    for (size_type i(0); i < a.size(); ++i) {
      if      ('.' == a[i]) { dots  .push_back(i); }
      else if (',' == a[i]) { commas.push_back(i); }
    }

    for (size_type i(commas.size()-1); i > 0; --i) {
      unsigned count(0);

      for (auto const& d : dots) {
        if ((d < commas[i]) && (d > commas[i-1])) {
          ++count;
        }
      }
  
      std::cout << support::trace::prefix()
                << commas[i] << ':' << commas[i-1] << ':' << count
                << '\n';

      if (2 <= count) {
        count = 0;
        
        pos_list_type tmp;

        for (auto const& d : dots) {
          if (d > commas[i-1]) {
            ++count;

            if (2 <= count) {
              tmp.push_back(d);
            }
          }
        }

        using std::swap;
        
        swap(tmp, dots);
      }
    }
    
    pos_list_type ranges(commas);

    ranges.insert   (ranges.begin(), *dots.begin());
    ranges.push_back(*dots.rbegin());

    for (size_type i(*commas.begin()); i > *dots.begin(); --i) {
      if (('.' == a[i]) &&
          (std::isdigit(a[i+1]) || ('-' == a[i+1]) || ('+' == a[i+1])) &&
          (!std::isdigit(a[i-1]) && ('-' != a[i-1]) && ('+' != a[i-1]))) {
        ranges[0] = i;
      }
    }

    float_list_type values;
    
    for (size_type i(0); i < ranges.size() - 1; ++i) {
      std::string const tmp(a, ranges[i]+1, ranges[i+1]-ranges[i]-1);
      float             f(0.0f);
      
      if (1 == std::sscanf(tmp.c_str(), "%f", &f)) {
        values.push_back(f);
      }

#if 1
      std::cout << support::trace::prefix()
                << ranges[i] << ":'" << tmp << "' -> " << f
                << '\n';
#endif
    }
    
    using scene::node::transform;
    
    transform*        result(new transform);
    std::string const suffix(a.substr(*dots.rbegin()));
    
    if        (".rot"   == suffix) {
      using support::ostream::operator<<;
      
      std::cout << support::trace::prefix() << "ROT: " << values << "\n";
    } else if (".scale" == suffix) {
      using support::ostream::operator<<;
      
      std::cout << support::trace::prefix() << "SCALE: " << values << "\n";
    } else if (".trans" == suffix) {
      using support::ostream::operator<<;
      
      std::cout << support::trace::prefix() << "TRANS: " << values << "\n";
    } else {
      result->xform = glm::mat4(1);
    }

    std::string tmp = a.substr(0, *ranges.begin());

    {
      using support::ostream::operator<<;
      
      std::cout << support::trace::prefix() << "'" << a << "' -> '" << tmp << "'"
                << "\n"
                << support::trace::prefix() << "d:" << dots << ", c:" << commas << ", r:" << ranges
        //      << '\n'
        //      << support::trace::prefix() << values
                << '\n';
    }

    a = tmp;
    
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
