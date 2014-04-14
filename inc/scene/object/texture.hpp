// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_HPP

// includes, system

#include <gli/gli.hpp> // gli::texture?D
#include <string>      // std::string

// includes, project

#include <scene/object/base.hpp>

namespace scene {

  namespace object {
    
  // types, exported (class, enum, struct, union, typedef)

    class texture : public base {

    public:

      static glm::uvec3 const default_size;  // (1,1,1)
      static glm::uvec4 const default_color; // (1,1,1,1)
      
      virtual ~texture() =0;
      
    protected:
      
      explicit texture();
      
    };

    class texture_1d : public texture {

    public:
      
      explicit texture_1d(unsigned const&    /* size */  = default_size.x,
                          glm::uvec4 const&  /* color */ = default_color);
      virtual ~texture_1d();

      virtual void print_on(std::ostream&) const;
      
    private:

      gli::texture1D tdata_;
      
    };

    class texture_2d : public texture {

    public:
      
      explicit texture_2d(glm::uvec2 const&  /* size */  = default_size.xy(),
                          glm::uvec4 const&  /* color */ = default_color);
      explicit texture_2d(std::string const& /* file */);
      virtual ~texture_2d();

      virtual void print_on(std::ostream&) const;
      
    private:

      gli::texture2D tdata_;
      
    };

    class texture_3d : public texture {

    public:
      
      explicit texture_3d(glm::uvec3 const&  /* size */  = default_size.xyz(),
                          glm::uvec4 const&  /* color */ = default_color);
      virtual ~texture_3d();

      virtual void print_on(std::ostream&) const;

    private:

      gli::texture3D tdata_;
      
    };
    
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)

  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_HPP)
