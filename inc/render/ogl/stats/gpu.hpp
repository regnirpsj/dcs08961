// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/stats/gpu.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_OGL_STATS_GPU_HPP)

#define UKACHULLDCS_08961_RENDER_OGL_STATS_GPU_HPP

// includes, system

//#include <>

// includes, project

#include <render/stats/base.hpp>
#include <support/chrono.hpp>

namespace render {

  namespace ogl {

    class context;
    
    namespace stats {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_EXPORT gpu : virtual public render::stats::base {

      public:

        class data : virtual public base::data {

        public:

          float  rate_in_hz;
          double time_in_ns;
          
          virtual ~data();
        
          virtual data& operator+=(data const&);

          virtual void print_on(std::ostream&) const;
        
        };
        
        explicit gpu(ogl::context&);
        virtual ~gpu();

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
  
    } // namespace stats {

  } // namespace ogl {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_OGL_STATS_GPU_HPP)
