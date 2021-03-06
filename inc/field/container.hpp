// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/container.hpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONTAINER_HPP)

#define UKACHULLDCS_08961_FIELD_CONTAINER_HPP

// includes, system

#include <memory> // std::unique_ptr<>
#include <vector> // std::vector<>

// includes, project

#include <support/chrono.hpp>
#include <support/printable.hpp>
#include <field/export.h>

namespace field {

  class base;
  
  // types, exported (class, enum, struct, union, typedef)

  class DCS08961_FIELD_EXPORT container : public support::printable {

  public:

    class manager : public support::printable {

    public:

      virtual ~manager() =0;

      virtual void print_on(std::ostream&) const;

      virtual void evaluate();
      
    protected:

      friend class container;

      using container_list_type = std::vector<container*>;
      
      container_list_type container_list_;

      explicit manager();

      virtual bool schedule  (container*);
      virtual bool unschedule(container*);
      
    };

    using field_list_type = std::vector<base*>;
    
    static manager& eval_manager();

    field_list_type const& fields() const;
    
    void touch();
    void evaluate();
    void changed(base&);
    
    virtual void print_on(std::ostream&) const;
    
  protected:

    support::clock::time_point last_change_;
    support::clock::time_point last_evaluate_;
    
    explicit container();
    virtual ~container() =0;

    virtual void do_touch();
    virtual void do_evaluate();
    virtual void do_changed(base&);
    
  private:

    friend class ::field::base;

    static std::unique_ptr<manager> mgr;
    
    field_list_type field_list_;

    void add(base*);
    void sub(base*);
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace field {

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONTAINER_HPP)
