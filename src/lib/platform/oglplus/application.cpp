// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/oglplus/application.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/oglplus/application.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

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

namespace platform {

  namespace oglplus {

    namespace application {
    
      // variables, exported
  
      // functions, exported
      
      void
      print_oglplus_error_common(::oglplus::Error& error, std::ostream& os,
                                 std::string const& prefix)
      {
        TRACE("platform::oglplus::application::print_oglplus_error_common");
        
        os << prefix << '\n';
    
        if (error.SourceFile()) {
          os << "Source file: '" << error.SourceFile() << "'\n";
        }

        if (error.SourceLine()) {
          os << "Source line: " << error.SourceLine() << '\n';
        }

        if (error.SourceFunc()) {
          os << "Source function: '" << error.SourceFunc() << "'\n";
        }
    
        print_stdcpp_error_common(error, os, prefix);
    
        if (error.GLFunc()) {
          os << "GL function: '";

          if (error.GLLib()) {
            os << error.GLLib();
          }

          os << error.GLFunc() << "'\n";
        }

        if (error.EnumParam() || error.EnumParamName()) {
          os << "GL constant: ";
          if (error.EnumParamName()) {
            os << "'" << error.EnumParamName() << "'";
          } else {
            os << "(0x" << std::hex << error.EnumParam() << ")";
          }
          os << '\n';
        }

        if (error.BindTarget() || error.TargetName()){
          os << "Binding point: ";
          if (error.TargetName()) {
            os << "'" << error.TargetName() << "'";
          } else {
            os << "(0x" << std::hex << error.BindTarget() << ")";
          }
          os << '\n';
        }

        if (error.ObjectTypeName() || error.ObjectType()) {
          os << "Object type: ";
          if (error.ObjectTypeName()) {
            os << "'" << error.ObjectTypeName() << "'";
          } else {
            os << "(0x" << std::hex << error.ObjectType() << ")";
          }
          os << '\n';
        }

        if ((!error.ObjectDesc().empty()) || (0 <= error.ObjectName())) {
          os << "Object: ";
          if (!error.ObjectDesc().empty()) {
            os << "'" << error.ObjectDesc() << "'";
          } else {
            os << "(" << error.ObjectName() << ")";
          }
          os << '\n';
        }

        if (error.SubjectTypeName() || error.SubjectType()) {
          os << "Subject type: ";
          if (error.SubjectTypeName()) {
            os << "'" << error.SubjectTypeName() << "'";
          } else {
            os << "(0x" << std::hex << error.SubjectType() << ")";
          }
          os << '\n';
        }

        if ((!error.SubjectDesc().empty()) || (0 <= error.SubjectName())) {
          os << "Subject: ";
          if (!error.SubjectDesc().empty()) {
            os << "'" << error.SubjectDesc() << "'";
          } else {
            os << "(" << error.SubjectName() << ")";
          }
          os << '\n';
        }

        if (error.Identifier()) {
          os << "Identifier: '" << error.Identifier() << "'\n";
        }

        if (0 <= error.Index()) {
          os << "Index: (" << error.Index() << ")\n";
        }

        if (0 != error.Value()) {
          os << "Value: (" << error.Value() << ")\n";
        }

        if (0 != error.Limit()) {
          os << "Limit: (" << error.Limit() << ")\n";
        }

        if (!error.Log().empty()) {
          os << "Log:\n" << error.Log() << '\n';
        }

        os << std::flush;
      }

      void
      print_stdcpp_error_common(std::exception& ex, std::ostream& os, std::string const& prefix)
      {
        TRACE("platform::oglplus::application::print_stdcpp_error_common");

        os << prefix << '\n'
           << "Message: '" << ex.what() << "'"
           << std::endl;
      }
      
    } // namespace application {

  } // namespace oglplus {
  
} // namespace platform {
