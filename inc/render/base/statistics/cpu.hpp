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

      class DCS08961_RENDER_EXPORT cpu : virtual public base {

      public:

        class data : virtual public base::data {

        public:

          float  rate_in_hz;
          double time_in_ns;
          
          virtual ~data();
        
          virtual data& operator+=(data const&);

          virtual void print_on(std::ostream&) const;
        
        };
        
        explicit cpu(context&);
        virtual ~cpu();

        virtual std::unique_ptr<base::data> fetch() const;
        
        virtual void print_on(std::ostream&) const;

      protected:

        support::timer           rate_timer_;
        support::timer::duration rate_;
        support::timer           stamp_timer_;
        support::timer::duration stamp_;
        
        virtual void start ();
        virtual void stop  ();
        virtual bool done  ();
        virtual void update(bool /* force update */ = false);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace statistics {
    
  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_STATISTICS_CPU_HPP)
