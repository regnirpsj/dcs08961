// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/oglplus/application.inl                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_OGLPLUS_APPLICATION_INL)

#define UKACHULLDCS_08961_PLATFORM_OGLPLUS_APPLICATION_INL

// includes, system

// GLEW needs to go first and only because we need the oglplus exceptions
#include <GL/glew.h>                  // ::gl*

#include <oglplus/error/limit.hpp>    // oglplus::LimitError
#include <oglplus/error/program.hpp>  // oglplus::ProgramBuildError
#include <oglplus/error/prog_var.hpp> // oglplus::ProgVarError
#include <system_error>               // std::system_error

// includes, project

#include <platform/application/base.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace platform {

  namespace oglplus {

    namespace application {
  
      // functions, inlined (inline)

      template <typename T>
      inline signed
      execute(command_line const& a)
      {
        TRACE("platform::oglplus::application::execute<" + support::demangle(typeid(T)) + ">");
      
        return platform::application::executor<T>(a).run();
      }

      template <typename T>
      inline signed
      execute(command_line const& a, std::nothrow_t const&) noexcept
      {
        TRACE("platform::oglplus::application::execute<" + support::demangle(typeid(T)) +
              ">(std::nothrow_t)");
    
        signed result(EXIT_FAILURE);
      
        try {
          result = application::execute<T>(a);
        }
    
        catch (::oglplus::ProgVarError& ex) {
          print_oglplus_error_common(ex, std::cerr, "OGLPlus: Program variable error");
        }
    
        catch (::oglplus::ProgramBuildError& ex) {
          print_oglplus_error_common(ex, std::cerr, "OGLPlus: Program build error");
        }
    
        catch (::oglplus::LimitError& ex) {
          print_oglplus_error_common(ex, std::cerr, "OGLPlus: Limit error");
        }
    
        catch (::oglplus::ObjectError& ex) {
          print_oglplus_error_common(ex, std::cerr, "OGLPlus: Object error");
        }
    
        catch (::oglplus::Error& ex) {
          print_oglplus_error_common(ex, std::cerr, "OGLPlus: GL error");
        }
    
        catch (std::system_error& ex) {
          print_stdcpp_error_common(ex, std::cerr, "System: Error");
          std::cerr << "Error code: " << ex.code() << std::endl;
        }
    
        catch (std::runtime_error& ex) {
          print_stdcpp_error_common(ex, std::cerr, "System: Runtime error");
          std::cerr << std::endl;
        }
    
        catch (std::exception& ex) {
          print_stdcpp_error_common(ex, std::cerr, "System: Error");
          std::cerr << std::endl;
        }

        catch (...) {
          std::cerr << "Caught excpetion not derived from <std::exception>!" << std::endl;
        }
    
        return result;
      }

    } // namespace application {

  } // namespace oglplus {
  
} // namespace platform {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_OGLPLUS_APPLICATION_INL)
