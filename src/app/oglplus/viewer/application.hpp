// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/viewer/application.hpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VIEWER_APPLICATION_HPP)

#define UKACHULLDCS_08961_APP_OGLPLUS_VIEWER_APPLICATION_HPP

// includes, system

#include <csignal>

// includes, project

#include <platform/glut/application/base.hpp>
#include <platform/window/rect.hpp>
#include <window.hpp>

namespace viewer {
  
  // types, exported (class, enum, struct, union, typedef)

  class application : public platform::glut::application::base {

    using command_line     = platform::application::command_line;
    using inherited        = platform::glut::application::base;
    using rect             = platform::window::rect;
    using string_list_type = std::vector<std::string>;
    
  public:

    static void terminate(signed);
    
    explicit application(command_line const&);
    virtual ~application();
    
    virtual void process_command_line();
    
  private:
    
    string_list_type        input_files_;
    std::string             layout_;
    std::unique_ptr<window> window_;
    
  };

  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace viewer {

#endif // #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VIEWER_APPLICATION_HPP)
