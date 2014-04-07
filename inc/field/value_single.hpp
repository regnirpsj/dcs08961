// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/value_single.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_VALUE_SINGLE_HPP)

#define UKACHULLDCS_08961_FIELD_VALUE_SINGLE_HPP

// includes, system

// #include <>

// includes, project

#include <field/base.hpp>

namespace field {

  namespace value {

    class container;
    
    // types, exported (class, enum, struct, union, typedef)

    template <typename T>
    class single : public base {

    public:

      typedef base                      inherited;
      typedef inherited::container_type container_type;
      typedef T                         value_type;
    
      explicit single(container_type&    /* container */,
                      std::string const& /* name */,
                      value_type const&  /* init */ = value_type());
      virtual ~single();

      virtual void print_on(std::ostream&) const;
    
      value_type const& get() const;
      value_type        set(value_type const&);

      operator value_type const& () const;
      single& operator=(value_type const&);
      
    private:

      value_type value_;
    
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace value {

} // namespace field {

#include <field/value_single.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_VALUE_SINGLE_HPP)
