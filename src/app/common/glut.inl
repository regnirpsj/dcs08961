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

#include <GL/glew.h>                  // ::glew*
#include <oglplus/error/limit.hpp>    //
#include <oglplus/error/program.hpp>  //
#include <oglplus/error/prog_var.hpp> //
#include <system_error>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
//#undef UKACHULLDCS_USE_TRACE
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
    
    catch (oglplus::ProgVarError& pve) {
      std::cerr << "Program variable error" << std::endl;
      print_error_common(pve, std::cerr);
    }
    
    catch (oglplus::ProgramBuildError& pbe) {
      std::cerr << "Program build error" << std::endl;
      print_error_common(pbe, std::cerr);
    }
    
    catch (oglplus::LimitError& le) {
      std::cerr << "Limit error" << std::endl;
      print_error_common(le, std::cerr);
    }
    
    catch (oglplus::ObjectError& oe) {
      std::cerr << "Object error" << std::endl;
      print_error_common(oe, std::cerr);
    }
    
    catch (oglplus::Error& err) {
      std::cerr << "GL error" << std::endl;
      print_error_common(err, std::cerr);
    }
    
    catch (std::system_error& sye) {
      std::cerr << "System error" << std::endl;
      print_std_error_common(sye, std::cerr);
      std::cerr << "Error code: " << sye.code() << std::endl;
      std::cerr << std::endl;
    }
    
    catch (std::runtime_error& rte) {
      std::cerr << "Runtime error" << std::endl;
      print_std_error_common(rte, std::cerr);
      std::cerr << std::endl;
    }
    
    catch (std::exception& se) {
      std::cerr << "Error" << std::endl;
      print_std_error_common(se, std::cerr);
      std::cerr << std::endl;
    }
      
    return result;
  }
  
} // namespace glut {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_PROTO_INL)
