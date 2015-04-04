// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/posix/application/base.hpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_POSIX_APPLICATION_BASE_HPP)

#define UKACHULLDCS_08961_PLATFORM_POSIX_APPLICATION_BASE_HPP

// includes, system

#include <string> // std::string
#include <vector> // std::vector<>

// includes, project

#include <platform/application/single_instance.hpp>

namespace platform {

  namespace posix {

    namespace application {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT base : public platform::application::single_instance {

      public:

        virtual void print_on(std::ostream&) const;
      
      protected:

        using string_list_type = std::vector<std::string>;
      
        string_list_type input_files_;

        explicit base(platform::application::command_line const&);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace application {

  } // namespace posix {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_POSIX_APPLICATION_BASE_HPP)
