// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/statistics/cpu.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_STATISTICS_CPU_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_STATISTICS_CPU_HPP

// includes, system

//#include <>

// includes, project

#include <render/base/statistics/base.hpp>

namespace render {

  namespace base {

    namespace statistics {
  
      // types, exported (class, enum, struct, union, typedef)

      class cpu : public base {

      public:

        virtual ~cpu();
        
        virtual void print_on(std::ostream&) const;

      protected:

        virtual void update() const;
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace statistics {
    
  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_STATISTICS_CPU_HPP)
