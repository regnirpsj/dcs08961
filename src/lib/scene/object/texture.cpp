// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/texture.hpp"

// includes, system

#include <array>                // std::array<>
#include <boost/filesystem.hpp> // boost::filesystem::path
#include <functional>           // std::function
#include <ostream>              // std::ostream
#include <unordered_map>        // std::unordered_map<>

// includes, project

#include <gli/gtx/io.hpp>
#include <support/hasher.hpp>
#include <support/string.hpp>
#include <support/type_info.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#endif
// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  template <typename T, typename C>
  void
  fill(T& t, C const& c)
  {
    TRACE("scene::object::texture::<unnamed>::fill<" + support::demangle(typeid(T)) + "," +
          support::demangle(typeid(C)) + ">");

    for (unsigned l(0); l < t.levels(); ++l){
      for (unsigned i(0); i < t.template size<C>(); ++i) {
        *(t[l].template data<C>() + i) = c;
      }
    }
  }
  
  gli::storage
  load(std::string const& fname)
  {
    TRACE("scene::object::texture::<unnamed>::load");

    typedef std::function<gli::storage (char*)>                       load_function_type;
    typedef std::unordered_map<std::string const, load_function_type> suffix_map_type;

    static std::array<std::pair<std::string const, load_function_type>, 1> const suffix_array = {
      {
        std::make_pair(".dds", std::bind(gli::load_dds, std::placeholders::_1)),
      }
    };
    static suffix_map_type const suffix_map(suffix_array.begin(), suffix_array.end());
    
    gli::storage result(1, 1, 1, gli::RGBA8_UNORM, gli::storage::dimensions_type(1, 1, 1));

    try {
      namespace bfs = boost::filesystem;
      
      std::string const ext(bfs::path(fname).extension().string());

#if 1
#  pragma message("buggy gli::storage::op=, not using load_dds")
#else
      result = suffix_map.at(ext)(const_cast<char*>(fname.c_str()));
#endif
    }
    
    catch (std::exception&) { /* */ }
                               
    return result;
  }
  
} // namespace {

namespace scene {

  namespace object {
    
    // variables, exported

    /* static */ glm::uvec3 const texture::default_size (1, 1, 1);
    /* static */ glm::uvec4 const texture::default_color(1, 1, 1, 1);
    
    // functions, exported

    /* virtual */
    texture::~texture()
    {
      TRACE("scene::object::texture::~texture");
    }
    
    /* explicit */
    texture::texture()
      : base()
    {
      TRACE("scene::object::texture::texture");
    }
    
    /* explicit */
    texture_1d::texture_1d(unsigned const& a, glm::uvec4 const& b)
      : texture(),
        tdata_ (1, gli::RGBA8_UNORM, gli::texture1D::dimensions_type(a))
    {
      TRACE("scene::object::texture_1d::texture_1d");

      fill(tdata_, glm::u8vec4(b));
    }

    /* virtual */
    texture_1d::~texture_1d()
    {
      TRACE("scene::object::texture_1d::~texture_1d");
    }

    /* virtual */ void
    texture_1d::print_on(std::ostream& os) const
    {
      TRACE_NEVER("scene::object::texture_1d::print_on");

      texture::print_on(os);

      os << "\b," << tdata_ << ']';
    }

    /* explicit */
    texture_2d::texture_2d(glm::uvec2 const& a, glm::uvec4 const& b)
      : texture(),
        tdata_ (1, gli::RGBA8_UNORM, gli::texture2D::dimensions_type(a.x, a.y))
    {
      TRACE("scene::object::texture_2d::texture_2d(fill)");

      fill(tdata_, glm::u8vec4(b));
    }

    /* explicit */
    texture_2d::texture_2d(std::string const& a)
      : texture(),
        tdata_ (load(a))
    {
      TRACE("scene::object::texture_2d::texture_2d(file)");
    }
    
    /* virtual */
    texture_2d::~texture_2d()
    {
      TRACE("scene::object::texture_2d::~texture_2d");
    }

    /* virtual */ void
    texture_2d::print_on(std::ostream& os) const
    {
      TRACE_NEVER("scene::object::texture_2d::print_on");

      texture::print_on(os);

      os << "\b," << tdata_ << ']';
    }

    /* explicit */
    texture_3d::texture_3d(glm::uvec3 const& a, glm::uvec4 const& b)
      : texture(),
        tdata_ (1, gli::RGBA8_UNORM, gli::texture3D::dimensions_type(a.x, a.y, a.z))
    {
      TRACE("scene::object::texture_3d::texture_3d");

      fill(tdata_, glm::u8vec4(b));
    }

    /* virtual */
    texture_3d::~texture_3d()
    {
      TRACE("scene::object::texture_3d::~texture_3d");
    }

    /* virtual */ void
    texture_3d::print_on(std::ostream& os) const
    {
      TRACE_NEVER("scene::object::texture_3d::print_on");

      texture::print_on(os);

      os << "\b," << tdata_ << ']';
    }
      
  } // namespace object {
  
} // namespace scene {
