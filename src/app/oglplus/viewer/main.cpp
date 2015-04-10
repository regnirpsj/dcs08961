// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/viewer/main.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <GL/glew.h>            // ::gl*

//#include <array>
//#include <boost/filesystem.hpp> // boost::filesystem::path
//#include <boost/tokenizer.hpp>  // boost::char_separator<>, boost::tokenizer<>
//#include <GL/freeglut.h>
//#include <oglplus/all.hpp>
//#include <oglplus/bound/texture.hpp>
//#include <oglplus/images/checker.hpp>
//#include <oglplus/images/random.hpp>
//#include <oglplus/images/sphere_bmap.hpp>
//#include <oglplus/images/squares.hpp>
// #include <oglplus/opt/smart_enums.hpp>

// #include <glm/glm.hpp>
// #include <oglplus/interop/glm.hpp>
// #include <glm/gtx/io.hpp>
// #include <glm/gtx/transform.hpp>

// #include <sstream>
// #include <vector>

// includes, project

// #include <platform/glut/application/base.hpp>
// #include <platform/glut/window/simple.hpp>
#include <platform/oglplus/application.hpp>
// #include <support/chrono_io.hpp>
#include <support/signal_handler.hpp>

#include <application.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {

  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

int
main(int argc, char const* argv[])
{
  TRACE("main");
  
  using support::signal_handler;
  
  signal_handler::instance->handler(SIGINT,  &viewer::application::terminate);
  signal_handler::instance->handler(SIGTERM, &viewer::application::terminate);
  
  namespace pa  = platform::application;
  namespace poa = platform::oglplus::application;
  
  return poa::execute<viewer::application>(pa::command_line(argc, argv), std::nothrow);
}
