// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/statistics/base.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_STATISTICS_BASE_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_STATISTICS_BASE_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable

// includes, project

#include <support/chrono.hpp>
#include <support/printable.hpp>

namespace render {

  namespace base {

    namespace statistics {
  
      // types, exported (class, enum, struct, union, typedef)

      class base : private boost::noncopyable,
                   public support::printable {

      public:

        virtual ~base() =0;

        /* data fetch() const; */
        
        virtual void print_on(std::ostream&) const;

      protected:

        friend class guard;
        
        explicit base();

        virtual void update() const;
        
      };

      class guard : private boost::noncopyable {

      public:

        explicit guard(base& /* statistics object */, bool /* enabled */ = true);
                ~guard();

      private:

        base&          stats_;
        bool           enabled_;
        support::timer timer_;

      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace statistics {
    
  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_STATISTICS_BASE_HPP)
