// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/light.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_COMMON_LIGHT_HPP)

#define UKACHULLDCS_08961_APP_COMMON_LIGHT_HPP

// includes, system

#include <GL/glew.h>                    // ::gl*
#include <oglplus/all.hpp>

#include <glm/glm.hpp>
#include <vector>

// includes, project

using namespace glm;

#include <../../../share/shader/glsl/common/light.glsl>

namespace light {
  
  // types, exported (class, enum, struct, union, typedef)

  class buffer {

  public:

    explicit buffer(oglplus::Program&);

    void update();
    
  private:

    typedef std::vector<light_t> light_list_type;
    
    oglplus::Program& prg_;
    oglplus::Buffer   buf_;
    light_list_type   light_list_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace light {

#endif // #if !defined(UKACHULLDCS_08961_APP_COMMON_LIGHT_HPP)
