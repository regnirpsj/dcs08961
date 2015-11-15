// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stats/base.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STATS_BASE_HPP)

#define UKACHULLDCS_08961_RENDER_STATS_BASE_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <memory>                // std::unique_ptr<>

// includes, project

#include <render/export.h>
#include <support/printable.hpp>

namespace render {

  namespace context {

    class device;
    
  } // namespace context
  
  namespace stats {
    
    // types, exported (class, enum, struct, union, typedef)

    class guard;
    
    class DCS08961_RENDER_EXPORT base : private boost::noncopyable,
                                        public support::printable {

    public:

      class data : public support::printable {

      public:

        virtual ~data();
        
        virtual data& operator+=(data const&);

        virtual void print_on(std::ostream&) const;
        
      };
      
      virtual ~base() =0;

      virtual std::unique_ptr<data> fetch() const;
        
      virtual void print_on(std::ostream&) const;

    protected:

      friend class stats::guard;

      context::device& ctx_;
      bool             updated_;
      
      explicit base(context::device&);

      virtual void start ();
      virtual void stop  ();
      virtual bool done  ();
      virtual void update(bool /* force update */ = false);
        
    };

    class DCS08961_RENDER_EXPORT guard : private boost::noncopyable {

    public:

      explicit guard(base& /* stats object */, bool /* enabled */ = true);
              ~guard();

    private:

      base& stats_;
      bool  enabled_;

    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stats {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STATS_BASE_HPP)
