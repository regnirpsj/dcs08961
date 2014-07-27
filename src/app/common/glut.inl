// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/glut.inl                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PROTO_INL)

#define UKACHULLDCS_08961_PROTO_INL

// includes, system

#include <GL/glew.h>                  // ::gl*
#include <oglplus/error/limit.hpp>    // oglplus::LimitError
#include <oglplus/error/program.hpp>  // oglplus::ProgramBuildError
#include <oglplus/error/prog_var.hpp> // oglplus::ProgVarError
#include <system_error>               // std::system_error

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace glut {
  
  // functions, inlined (inline)

  template <typename T>
  inline signed
  execute(int argc, char* argv[])
  {
    TRACE("glut::execute<" + support::demangle(typeid(T)) + ">");
      
    return support::application::executor<T>(argc, argv).run();
  }

  template <typename T>
  inline signed
  execute(int argc, char* argv[], std::nothrow_t const&)
  {
    TRACE("glut::execute<" + support::demangle(typeid(T)) + ">(std::nothrow_t)");
    
    signed result(EXIT_FAILURE);
      
    try {
      result = execute<T>(argc, argv);
    }
    
    catch (oglplus::ProgVarError& ex) {
      print_error_common(ex, std::cerr, "OGLPlus: Program variable error");
    }
    
    catch (oglplus::ProgramBuildError& ex) {
      print_error_common(ex, std::cerr, "OGLPlus: Program build error");
    }
    
    catch (oglplus::LimitError& ex) {
      print_error_common(ex, std::cerr, "OGLPlus: Limit error");
    }
    
    catch (oglplus::ObjectError& ex) {
      print_error_common(ex, std::cerr, "OGLPlus: Object error");
    }
    
    catch (oglplus::Error& ex) {
      print_error_common(ex, std::cerr, "OGLPlus: GL error");
    }
    
    catch (std::system_error& ex) {
      print_std_error_common(ex, std::cerr, "System: Error");
      std::cerr << "Error code: " << ex.code() << std::endl;
    }
    
    catch (std::runtime_error& ex) {
      print_std_error_common(ex, std::cerr, "System: Runtime error");
      std::cerr << std::endl;
    }
    
    catch (std::exception& ex) {
      print_std_error_common(ex, std::cerr, "System: Error");
      std::cerr << std::endl;
    }

    catch (...) {
      std::cerr << "Caught excpetion not derived from <std::exception>!" << std::endl;
    }
    
    return result;
  }
  
} // namespace glut {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_PROTO_INL)
