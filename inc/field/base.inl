// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/base.inl                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_BASE_INL)

#define UKACHULLDCS_08961_FIELD_BASE_INL

// includes, system

#include <boost/serialization/nvp.hpp> // boost::serialization::make_nvp

// includes, project

// #include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

namespace field {
  
  // functions, inlined (inline)

  template <typename Archive>
  inline void
  base::serialize(Archive& ar, unsigned int const)
  {
    TRACE("field::base::serialize");

    namespace bs = boost::serialization;

    ar & bs::make_nvp("container",   container_);
    ar & bs::make_nvp("name",        name_);
    ar & bs::make_nvp("last_change", last_change_);
  }

} // namespace field {

BOOST_CLASS_TRACKING(field::base, boost::serialization::track_always);

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_BASE_INL)
