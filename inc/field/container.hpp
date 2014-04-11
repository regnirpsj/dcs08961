// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
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

#include <support/printable.hpp>

namespace field {

  class base;
  
  // types, exported (class, enum, struct, union, typedef)

  class container : public support::printable {

  public:

    class manager : public support::printable {

    public:

      virtual ~manager() =0;

      virtual void print_on(std::ostream&) const;

      virtual bool schedule(container*);
      virtual bool unschedule(container*);
      
    protected:
      
      std::vector<container*> container_list_;
      
    };
    
    virtual void touch();

    virtual void print_on(std::ostream&) const;
    
  protected:
    
    explicit container();
    virtual ~container() =0;

    virtual void evaluate();
    virtual void changed(base&);
    
  private:

    friend class base;
    
    typedef std::vector<base*> field_list_type;

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
