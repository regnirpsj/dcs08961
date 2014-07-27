// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/light.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "light.hpp"

// includes, system

//#include <>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace light {
  
  // variables, exported
  
  // functions, exported

  /* explicit */
  buffer::buffer(oglplus::Program& a)
    : prg_       (a),
      buf_       (),
      light_list_(1)
  {
    TRACE("light::buffer::buffer");
  }
  
  void
  buffer::update()
  {
    TRACE("light::buffer::update");

    using namespace oglplus;
    
    //buf_.Bind(Buffer::Target::Uniform);
#if 0
    {
      Buffer::Data(Buffer::Target::Uniform, light_list_.size(), nullptr, BufferUsage::DynamicDraw);

      BufferRawMap map(Buffer::Target::Uniform, 0, light_list_.size(),
                       BufferMapAccess::Write|BufferMapAccess::InvalidateBuffer);
      {
        light_t* lights(reinterpret_cast<light_t*>(buffMap.RawData()));
      
        assert(lights);

        std::copy(light_list_.begin(), light_list_.end(), lights);
      }
      map.Unmap();
    }
    //#else
    {
      Buffer::Data(Buffer::Target::Uniform, light_list_.begin());
            
      (prg_|"light_list").Setup<light_t>(light_list_.size()).Enable();
    }
#endif
    // buf_.Unbind(Buffer::Target::Uniform);
  }
  
} // namespace light {
