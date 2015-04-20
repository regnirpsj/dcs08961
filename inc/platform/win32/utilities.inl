// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/utilities.inl                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_UTILITIES_INL)

#define UKACHULLDCS_08961_PLATFORM_WIN32_UTILITIES_INL

// includes, system

//#include <>

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
  
  namespace win32  {
  
    // functions, inlined (inline)

    template <class T>
    inline T
    window_long(HWND a, signed b)
    {
      TRACE("platform::win32::window_long<" + support::demangle(typeid(T)) + ">(get)");
      
      return reinterpret_cast<T>(::GetWindowLong(a, b));
    }

    template <class T>
    inline T
    window_long(HWND a, T b, signed c)
    {
      TRACE("platform::win32::window_long<" + support::demangle(typeid(T)) + ">(set)");
      
      return reinterpret_cast<T>(::SetWindowLong(a, c, reinterpret_cast<LONG>(b)));
    }

    template <class T>
    inline T*
    window_long_ptr(HWND a, signed b)
    {
      TRACE("platform::win32::window_long_ptr<" + support::demangle(typeid(T)) + ">(get)");
      
      return reinterpret_cast<T*>(::GetWindowLongPtr(a, b));
    }
  
    template <class T>
    inline T*
    window_long_ptr(HWND a, T* b, signed c)
    {
      TRACE("platform::win32::window_long_ptr<" + support::demangle(typeid(T)) + ">(set)");
      
      return reinterpret_cast<T*>(::SetWindowLongPtr(a, c, reinterpret_cast<LONG_PTR>(b)));
    }

    template <>
    inline DWORD
    window_long<DWORD>(HWND a, signed b)
    {
      TRACE("platform::win32::window_long<DWORD>(get)");
      
      return static_cast<DWORD>(::GetWindowLong(a, b));
    }

    template <>
    inline DWORD
    window_long<DWORD>(HWND a, DWORD b, signed c)
    {
      TRACE("platform::win32::window_long<DWORD>(set)");
      
      return static_cast<DWORD>(::SetWindowLong(a, c, static_cast<LONG>(b)));
    }

    template <class T>
    inline T
    class_long(HWND a, signed b)
    {
      TRACE("platform::win32::class_long<" + support::demangle(typeid(T)) + ">(get)");
      
      return reinterpret_cast<T>(::GetClassLong(a, b));
    }

    template <class T>
    inline T
    class_long(HWND a, T b, signed c)
    {
      TRACE("platform::win32::class_long<" + support::demangle(typeid(T)) + ">(set)");
      
      return reinterpret_cast<T>(::SetClassLong(a, c, reinterpret_cast<LONG>(b)));
    }

    template <class T>
    inline T*
    class_long_ptr(HWND a, signed b)
    {
      TRACE("platform::win32::class_long_ptr<" + support::demangle(typeid(T)) + ">(get)");
      
      return reinterpret_cast<T*>(::GetClassLongPtr(a, b));
    }
  
    template <class T>
    inline T*
    class_long_ptr(HWND a, T* b, signed c)
    {
      TRACE("platform::win32::class_long_ptr<" + support::demangle(typeid(T)) + ">(set)");
      
      return reinterpret_cast<T*>(::SetClassLongPtr(a, c, reinterpret_cast<LONG_PTR>(b)));
    }

    template <>
    inline DWORD
    class_long<DWORD>(HWND a, signed b)
    {
      TRACE("platform::win32::class_long<DWORD>(get)");
      
      return static_cast<DWORD>(::GetClassLong(a, b));
    }

    template <>
    inline DWORD
    class_long<DWORD>(HWND a, DWORD b, signed c)
    {
      TRACE("platform::win32::class_long<DWORD>(set)");
      
      return static_cast<DWORD>(::SetClassLong(a, c, static_cast<LONG>(b)));
    }

  } // namespace win32 {
  
} // namespace platform {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_UTILITIES_INL)
