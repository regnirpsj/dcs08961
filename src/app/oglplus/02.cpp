// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/02.cpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

// #include <>

// includes, project

#include <../common/glut.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {

  // types, internal (class, enum, struct, union, typedef)

  class application : public glut::application {

  public:    

    explicit application(int argc, char* argv[])
      : glut::application(argc, argv)
    {
      TRACE("<unnamed>::application::application");
    }
    
    virtual void frame_render_one()
    {
      TRACE("<unnamed>::application::frame_render_one");
    }
    
    virtual void reshape(glm::ivec2 const& size)
    {
      TRACE("<unnamed>::application::reshape");
    }

  private:
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

int
main(int argc, char* argv[])
{
  TRACE("main");
  
  return glut::execute<application>(argc, argv, std::nothrow);
}
