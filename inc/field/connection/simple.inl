// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/connection/simple.inl                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_SIMPLE_INL)

#define UKACHULLDCS_08961_FIELD_CONNECTION_SIMPLE_INL

// includes, system

//#include <>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace field {

  namespace connection {
    
    // functions, inlined (inline)

    template <typename T1, typename T2>
    inline /* explicit */
    simple<T1,T2>::simple(source_type const& a, destination_type& b, update_policy const& c)
      : base(c),
        src_(a),
        dst_(b)
    {
      TRACE("field::connection::simple<" +
            support::demangle(typeid(T1)) + "," + support::demangle(typeid(T2)) +
            ">::simple");
    }
    
    template <typename T1, typename T2>
    inline /* virtual */
    simple<T1,T2>::~simple()
    {
      TRACE("field::connection::simple<" +
            support::demangle(typeid(T1)) + "," + support::demangle(typeid(T2)) +
            ">::~simple");
    }

    template <typename T1, typename T2>
    inline /* virtual */ typename simple<T1,T2>::destination_type const&
    simple<T1,T2>::destination() const
    {
      TRACE("field::connection::simple<" +
            support::demangle(typeid(T1)) + "," + support::demangle(typeid(T2)) +
            ">::destination");

      return dst_;
    }

    template <typename T1, typename T2>
    inline /* virtual */ typename simple<T1,T2>::source_type const&
    simple<T1,T2>::source() const
    {
      TRACE("field::connection::simple<" +
            support::demangle(typeid(T1)) + "," + support::demangle(typeid(T2)) +
            ">::source");

      return src_;
    }
    
    template <typename T1, typename T2>
    inline /* virtual */ void
    simple<T1,T2>::update()
    {
      TRACE("field::connection::simple<" +
            support::demangle(typeid(T1)) + "," + support::demangle(typeid(T2)) +
            ">::update");

      dst_.set(src_.get());
    }
      
    template <typename T1, typename T2>
    inline /* virtual */ void
    simple<T1,T2>::print_on(std::ostream& os) const
    {
      TRACE_NEVER("field::connection::simple<" +
                  support::demangle(typeid(T1)) + "," + support::demangle(typeid(T2)) +
                  ">::print_on");

      base::print_on(os);

      os << "\b,"
         << "src:" << src_ << ','
         << "dst:" << dst_
         << ']';
    }
    
  } // namespace connection {
  
} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_SIMPLE_INL)
