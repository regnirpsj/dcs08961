// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2013-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/loader/mtl.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "loader/mtl.hpp"

// includes, system

// altough dealing w/ lowering the noise level for boost::spirit headers,
// the pragmas need to be here
#if defined(_MSC_VER) && (_MSC_VER < 1800)
// warning C4100: 'x' : unreferenced formal parameter
#  pragma warning(disable:4100)
// warning C4127: conditional expression is constant
#  pragma warning(disable:4127)
#endif

#include <boost/algorithm/string.hpp>                // boost::trim[_copy]
#include <boost/config/warning_disable.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/tokenizer.hpp>                       // boost::char_separator<>, boost::tokenizer<>
#include <cmath>                                     // std::pow
#include <fstream>                                   // std::[i|o]fstream
#include <istream>                                   // std::istream
#include <ostream>                                   // std::ostream

// includes, project

// #include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#include <support/type_info.hpp>

#if defined(UKACHULLDCS_USE_TRACE)
#  include <boost/fusion/include/io.hpp>
#  include <glm/gtx/io.hpp>
#endif

BOOST_FUSION_ADAPT_STRUCT(glm::vec3,
                          (glm::vec3::value_type, x)
                          (glm::vec3::value_type, y)
                          (glm::vec3::value_type, z)
                          );

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  namespace qi    = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;
  
  template <typename IT>
  struct rgb_parser : qi::grammar<IT, glm::vec3(), ascii::space_type> {
    
    rgb_parser()
      : rgb_parser::base_type(start)
    {
      TRACE_NEVER("scene::file::mtl::<unnamed>::rgb_parser::rgb_parser");
        
      using qi::debug;
      using qi::float_;
        
      start %=
        float_ >>  // x
        float_ >>  // y
        float_     // z
        ;        
        
      // debug(start);
    }
    
    qi::rule<IT, glm::vec3(), ascii::space_type> start;
    
  };

  template <typename IT>
  struct xyz_parser : qi::grammar<IT, glm::vec3(), ascii::space_type> {
    
    xyz_parser()
      : xyz_parser::base_type(start)
    {
      TRACE_NEVER("scene::file::mtl::<unnamed>::xyz_parser::xyz_parser");
        
      using qi::debug;
      using qi::float_;
      using qi::lit;
      
      start %=
        lit("xyz") >>  // "xyz"
        float_     >>  // x
        float_     >>  // y
        float_         // z
        ;        
        
      // debug(start);
    }
    
    qi::rule<IT, glm::vec3(), ascii::space_type> start;
    
  };
  
  template <typename IT>
  struct float_parser : qi::grammar<IT, float(), ascii::space_type> {
    
    float_parser()
      : float_parser::base_type(start)
    {
      TRACE_NEVER("scene::file::mtl::<unnamed>::float_parser::float_parser");
        
      using qi::debug;
      using qi::float_;
        
      start %=
        float_
        ;        
        
      // debug(start);
    }
    
    qi::rule<IT, float(), ascii::space_type> start;
    
  };
  
  // variables, internal
  
  // functions, internal

  template <typename P, typename O>
  bool
  parse(std::string const& exp, O& o)
  {
    TRACE_NEVER("scene::file::mtl::<unamed>::parse<" +
                support::demangle(typeid(P)) + "," + support::demangle(typeid(O)) + ">");
        
    auto       first (exp.begin());
    auto       last  (exp.end());
    bool const result(phrase_parse(first, last, P(), ascii::space, o));

#if 0 // defined(UKACHULLDCS_USE_TRACE)
    if (result && first == last) {
      std::cout << support::trace::prefix() << "scene::file::mtl::parse<"
                << support::demangle(typeid(P)) << ',' << support::demangle(typeid(O)) << ">: "
                << boost::fusion::tuple_open('[')
                << boost::fusion::tuple_close(']')
                << boost::fusion::tuple_delimiter(", ")
                << "in:'" << exp << "', out:" << o
                << std::endl;
    } else {
      std::cout << support::trace::prefix() << "scene::file::mtl::parse<"
                << support::demangle(typeid(P)) << ',' << support::demangle(typeid(O)) << ">: "
                << "failed to parse '" << exp << "'" << std::endl;
    }
#endif
        
    return (result && first == last);
  }

  /*
   * see [http://www.wikipedia.org/wiki/SRGB]
   */
  glm::vec3
  xyz_to_rgb(glm::vec3 const& xyz)
  {
    static float const     a( 0.055);
    static float const     b(12.920);
    static glm::mat3 const c(+3.2406, -1.5372, -0.4986,
                             -0.9689, +1.8758, +0.0415,
                             +0.0557, -0.2040, +1.0570);
    
    glm::vec3 result(c * (xyz / glm::vec3(100.0)));
    
    result.r = (result.r > 0.0031308) ? ((1.0 + a) * std::pow(result.r, 1/2.4)) : (b * result.r);
    result.g = (result.g > 0.0031308) ? ((1.0 + a) * std::pow(result.g, 1/2.4)) : (b * result.g);
    result.b = (result.b > 0.0031308) ? ((1.0 + a) * std::pow(result.b, 1/2.4)) : (b * result.b);
    
    return result;
  }
  
} // namespace {

namespace scene {

  namespace file {

    namespace mtl {
      
      // variables, exported
  
      // functions, exported

      list_type
      load(std::istream& is)
      {
        TRACE("scene::file::mtl::load(std::istream)");

        list_type result;

        {
          result.push_back(new scene::object::material);

          (*result.rbegin())->name = "default material";
        }
        
        std::string line;

        while (std::getline(is, line)) {
          if (line.empty() ||
              ('#' == line[0]) ||
              ('!' == line[0]) ||
              ('$' == line[0]) ||
              ('\r' == line[0])) {
            continue;
          }

          static boost::char_separator<char> const token_separator_space(" ");
          
          using tokenizer = boost::tokenizer<boost::char_separator<char>>;
        
          tokenizer tokens(line, token_separator_space);
          
          // bump -options args filename
          
          if      ("d" == *tokens.begin()) { // d [-halo] f
            std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
            float             d;
              
            if (parse<float_parser<std::string::const_iterator>>(exp, d)) {
              (*result.rbegin())->alpha = d;
            }
          }

          else if ("illum" == *tokens.begin()) { // illum #
            // nothing to do (yet)
          }
          
          else if ("Ka" == *tokens.begin()) { // Ka [r g b] | [spectral file.refl f] | [xyz x y z]
            std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
            glm::vec3         c;
              
            if        (parse<rgb_parser<std::string::const_iterator>>(exp, c)) {
              (*result.rbegin())->ambient = c;
            } else if (parse<xyz_parser<std::string::const_iterator>>(exp, c)) {
              (*result.rbegin())->ambient = xyz_to_rgb(c);
            }
          }

          else if ("Ke" == *tokens.begin()) { // Ke [r g b] | [spectral file.refl f] | [xyz x y z]
            std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
            glm::vec3         c;
              
            if (parse<rgb_parser<std::string::const_iterator>>(exp, c)) {
              (*result.rbegin())->emission = c;
            }  else if (parse<xyz_parser<std::string::const_iterator>>(exp, c)) {
              (*result.rbegin())->emission = xyz_to_rgb(c);
            }
          }
          
          else if ("Kd" == *tokens.begin()) { // Kd [r g b] | [spectral file.refl f] | [xyz x y z]
            std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
            glm::vec3         c;
              
            if (parse<rgb_parser<std::string::const_iterator>>(exp, c)) {
              (*result.rbegin())->diffuse = c;
            } else if (parse<xyz_parser<std::string::const_iterator>>(exp, c)) {
              (*result.rbegin())->diffuse = xyz_to_rgb(c);
            }
          }

          else if ("Ks" == *tokens.begin()) { // Ks [r g b] | [spectral file.refl f] | [xyz x y z]
            std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
            glm::vec3         c;
              
            if (parse<rgb_parser<std::string::const_iterator>>(exp, c)) {
              (*result.rbegin())->specular = c;
            } else if (parse<xyz_parser<std::string::const_iterator>>(exp, c)) {
              (*result.rbegin())->specular = xyz_to_rgb(c);
            }
          }
          
          // else if ("map_d" == *tokens.begin()) { // map_d -options args filename
          // }

          // else if ("map_Ka" == *tokens.begin()) { // map_Ka -options args filenam
          // }

          // else if ("map_Ke" == *tokens.begin()) { // map_Ka -options args filenam
          // }
          
          // else if ("map_Kd" == *tokens.begin()) { // map_Kd -options args filename
          // }
          
          // else if ("map_Ks" == *tokens.begin()) { // map_Ks -options args filename
          // }

          // else if ("map_Ns" == *tokens.begin()) { // map_Ns -options args filename
          // }
          
          else if ("Ni" == *tokens.begin()) { // Ni f
            std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
            float             r;
              
            if (parse<float_parser<std::string::const_iterator>>(exp, r)) {
              (*result.rbegin())->refraction = r;
            }
          }
          
          else if ("Ns" == *tokens.begin()) { // Ns exp
            std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
            float             s;
              
            if (parse<float_parser<std::string::const_iterator>>(exp, s)) {
              (*result.rbegin())->shininess = s;
            }
          }
          
          else if ("newmtl" == *tokens.begin()) { // newmtl <string>
            result.push_back(new scene::object::material);

            (*result.rbegin())->name = boost::trim_copy(std::string(line.begin() +
                                                                    (*tokens.begin()).length(),
                                                                    line.end()));
          }
          
          //else if ("refl" == *tokens.begin()) { //refl -type <type> -options -args filename
          //}
          
          else if ("Tf" == *tokens.begin()) { // Tf [r g b] | [spectral file.refl f] | [xyz x y z]
            std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
            glm::vec3         c;
              
            if (parse<rgb_parser<std::string::const_iterator>>(exp, c)) {
              (*result.rbegin())->transmission = c;
            } else if (parse<xyz_parser<std::string::const_iterator>>(exp, c)) {
              (*result.rbegin())->transmission = xyz_to_rgb(c);
            }
          }
          
          else if ("Tr" == *tokens.begin()) { // Tr x (== 1 - alpha)
            std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
            float             t;
              
            if (parse<float_parser<std::string::const_iterator>>(exp, t)) {
              (*result.rbegin())->alpha = (1.0f - t);
            }
          }

          else if ("TWOSIDE" == *tokens.begin()) { // TWOSIDE (non-standard)
            (*result.rbegin())->front = true;
            (*result.rbegin())->back  = true;
          }

#if 0 // defined(UKACHULLDCS_USE_TRACE)
          else {
            std::cout << support::trace::prefix() << "scene::file::mtl::load(std::istream): "
                      << "unhandled token '" << *tokens.begin() << "'; skipping "
                      << "whole line '" << line << "'" << std::endl;
          }
#endif
        }

        return result;
      }
      
      list_type
      load(std::string const& a)
      {
        TRACE("scene::file::mtl::load(std::string) [" + a + "]");

        list_type     result;
        std::ifstream ifs(a, std::ios::in|std::ios::binary);
        
        if (ifs.is_open()) {
          result = load(ifs);
        }
        
        return result;
      }
      
      bool
      save(std::ostream&, list_type const&)
      {
        TRACE("scene::file::mtl::save(std::ostream)");

        return false;
      }
      
      bool
      save(std::string const& a, list_type const& b)
      {
        TRACE("scene::file::mtl::save(std::string) [" + a + "]");

        bool          result(false);
        std::ofstream ofs(a, std::ios::out|std::ios::binary|std::ios::trunc);

        if (ofs.is_open()) {
          result = save(ofs, b);
        }
        
        return result;
      }
      
    } // namespace mtl {
    
  } // namespace file {
  
} // namespace scene {
