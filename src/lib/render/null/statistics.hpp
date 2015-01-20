// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/statistics.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_NULL_STATISTICS_HPP)

#define UKACHULLDCS_08961_RENDER_NULL_STATISTICS_HPP

// includes, system

// #include <>

// includes, project

#include <render/base/statistics.hpp>

namespace render {

  namespace null {
  
    // types, exported (class, enum, struct, union, typedef)

    class stats : public render::base::statistics::cpu,
                  public render::base::statistics::gpu {

    public:

      static stats dflt;

      class data : public render::base::statistics::cpu::data,
                   public render::base::statistics::gpu::data {
        
      public:
          
        virtual ~data();
        
        virtual data& operator+=(data const&);
        
        virtual void print_on(std::ostream&) const;
        
      };
      
      explicit stats();
      virtual ~stats();
      
      virtual std::unique_ptr<render::base::statistics::base::data> fetch() const;
      
      virtual void print_on(std::ostream&) const;

    protected:

      virtual void start ();
      virtual void stop  ();
      virtual bool done  ();
      virtual void update(bool /* force update */ = false);
      
    };
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
  
  } // namespace null {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_NULL_STATISTICS_HPP)
