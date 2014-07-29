// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/pass/conatiner.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_PASS_CONTAINER_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_PASS_CONTAINER_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <initializer_list>        // std::initializer_list<>
#include <unordered_set>           // std::unordered_set<>

// includes, project

#include <render/base/pass/base.hpp>
#include <support/hasher.hpp>
#include <support/thread.hpp>

namespace render {

  namespace base {

    namespace pass {
      
      // types, exported (class, enum, struct, union, typedef)

      class container : public base {

      public:

        explicit container();
        explicit container(std::initializer_list<base*> const&);
        virtual ~container();

        unsigned size() const;
        bool     add(base*);
        bool     sub(base*);
        
        virtual void execute();

        virtual void print_on(std::ostream&) const;
        
      protected:

        typedef std::unordered_set<boost::intrusive_ptr<stage::base>> pass_list_type;

                pass_list_type       pass_list_;
        mutable support::simple_lock pass_list_lock_;
        
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace pass {
    
  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_PASS_CONTAINER_HPP)
