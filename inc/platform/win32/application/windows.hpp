// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/application/windows.hpp                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_APPLICATION_WINDOWS_HPP)

#define UKACHULLDCS_08961_PLATFORM_WIN32_APPLICATION_WINDOWS_HPP

// includes, system

//#include <>

// includes, project

#include <platform/win32/application/base.hpp>

namespace platform {

  namespace win32 {

    namespace application {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT windows : public base {

      public:

	virtual signed run();
	
      protected:

	bool const peekmessage_;
	
	explicit windows(platform::application::command_line const&, bool /* peekmessage */ = true);
	
	virtual void update();
	
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace application {
        
  } // namespace win32 {
    
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_APPLICATION_WINDOWS_HPP)
