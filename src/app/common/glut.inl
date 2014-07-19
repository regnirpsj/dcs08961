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

#include <GL/glew.h>                 // ::glew*
#include <oglplus/error/program.hpp> //
#include <oglplus/error/limit.hpp>   //

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
    TRACE("glut::execute<" + demangle(typeid(T)) + ">");
      
    return support::application::executor<T>(argc, argv).run();
  }

  template <typename T>
  inline signed
  execute(int argc, char* argv[], std::nothrow_t const&)
  {
    TRACE("glut::execute<" + demangle(typeid(T)) + ">(std::nothrow_t)");
      
    signed result(EXIT_FAILURE);
      
    try {
      result = support::application::execute<T>(argc, argv);
    }

    catch (oglplus::ProgramBuildError& ex) {
      std::cerr << " Program build error (in " << ex.GLFunc() << ", " << ex.ObjectTypeName()
                << ": (" << ex.ObjectName() << ") '" << ex.ObjectDesc() << "'): " << ex.what()
                << ": " << ex.Log() << '\n';
    }

    catch (oglplus::LimitError& ex) {
      std::cerr << " Limit error: (" << ex.Value() << ") exceeds (" << ex.EnumParamName() << " == "
                << ex.Limit() << ") [" << ex.SourceFile() << ":" << ex.SourceLine() << "] " << '\n';
    }

    catch (oglplus::ObjectError& ex) {
      std::cerr << " Object error (in " << ex.GLFunc() << ", " << ex.ObjectTypeName() << ": ("
                << ex.ObjectName() << ") '" << ex.ObjectDesc() << "') [" << ex.SourceFile()
                << ":" << ex.SourceLine() << "]: " << ex.what() << '\n';
    }

    catch (oglplus::Error& ex) {
      std::cerr << " Error (in " << ex.GLFunc() << "') [" << ex.SourceFile() << ":"
                << ex.SourceLine() << "]: " << ex.what() << '\n';
    }

    catch (std::exception& ex) {
      std::cerr << " Error: " << ex.what() << '\n';
    }
      
    return result;
  }
  
} // namespace glut {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_PROTO_INL)
