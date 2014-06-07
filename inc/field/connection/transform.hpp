// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/connection/transform.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_TRANSFORM_HPP)

#define UKACHULLDCS_08961_FIELD_CONNECTION_TRANSFORM_HPP

// includes, system

//#include <>

// includes, project

#include <field/connection/simple.hpp>

namespace field {

  namespace connection {

    // types, exported (class, enum, struct, union, typedef)

    template <typename T1, typename T2, typename C>
    class transform : public simple<T1,T2> {

    public:

      typedef          T1                           source_type;
      typedef          T2                           destination_type;
      typedef          C                            transform_type;
      typedef typename simple<T1,T2>::update_policy update_policy;
      
      explicit transform(source_type const&, destination_type&, transform_type,
                         update_policy const& = update_policy::push);
      virtual ~transform();
      
      virtual void update();

    private:

      transform_type transform_;
      
    };

    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
  } // namespace connection {
  
} // namespace field {

#include <field/connection/transform.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_TRANSFORM_HPP)
