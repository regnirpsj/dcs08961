// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

      class DCS08961_RENDER_EXPORT container : public base {

      protected:
        
        typedef stage::base                              base_type;
        typedef boost::intrusive_ptr<base_type>          refcounted_base_type;
        typedef std::unordered_set<refcounted_base_type> stage_list_type;
        
      public:
        
        virtual ~container();

        bool     empty() const;
        unsigned size() const;
        
        bool     add(base_type*);
        bool     sub(base_type*);
        void     clear();

        virtual void print_on(std::ostream&) const;
        
      protected:

                stage_list_type      stage_list_;
        mutable support::simple_lock stage_list_lock_;

        explicit container(context&, statistics::base&);
        explicit container(context&, statistics::base&, std::initializer_list<base_type*> const&);
        
        virtual void do_execute();
        
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace pass {
    
  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_PASS_CONTAINER_HPP)
