// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/application/base.inl                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_APPLICATION_BASE_INL)

#define UKACHULLDCS_08961_PLATFORM_APPLICATION_BASE_INL

// includes, system

#include <cstdlib> // EXIT_FAILURE

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace platform {

  namespace application {
  
    // functions, inlined (inline)

    template <typename T>
    inline /* explicit */
    executor<T>::executor(command_line const& a)
      : boost::noncopyable(),
        instance_         (new T(a))
    {
      TRACE("platform::application::executor<" + support::demangle(typeid(T)) + ">::executor");

      instance_->process_command_line();
    }

    template <typename T>
    inline /* explicit */
    executor<T>::~executor()
    {
      TRACE("platform::application::executor<" + support::demangle(typeid(T)) + ">::~executor");
    }
    
    template <typename T>
    inline signed
    executor<T>::run()
    {
      TRACE("platform::application::executor<" + support::demangle(typeid(T)) + ">::run");
      
      return instance_->run();
    }

    template <typename T>
    inline signed
    execute(command_line const& a)
    {
      TRACE("platform::application::execute<" + support::demangle(typeid(T)) + ">");
      
      return executor<T>(a).run();
    }

    template <typename T>
    inline signed
    execute(command_line const& a, std::nothrow_t const&) noexcept
    {
      TRACE("platform::application::execute<" + support::demangle(typeid(T)) + ">(std::nothrow_t)");
      
      signed result(EXIT_FAILURE);
      
      try {
        result = execute<T>(a);
      }
      
      catch (std::exception&) { /* ??? */ }
      
      return result;
    }
    
  } // namespace application {
  
} // namespace platform {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_APPLICATION_BASE_INL)
