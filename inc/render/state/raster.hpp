// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/state/raster.hpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STATE_RASTER_HPP)

#define UKACHULLDCS_08961_RENDER_STATE_RASTER_HPP

// includes, system

//#include <>

// includes, project

#include <render/state/base.hpp>

namespace render {
  
  namespace state {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT raster : public base {

    public:
      
      virtual ~raster();

    protected:
      
      explicit raster(context::device&);

    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace state {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STATE_RASTER_HPP)
