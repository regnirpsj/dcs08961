// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/container.inl                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONTAINER_INL)

#define UKACHULLDCS_08961_FIELD_CONTAINER_INL

// includes, system

#include <boost/serialization/nvp.hpp> // boost::serialization::make_nvp

// includes, project

#include <field/base.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

namespace field {
  
  // functions, inlined (inline)

  template <typename Archive>
  inline void
  container::serialize(Archive& ar, unsigned int const)
  {
    TRACE("field::container::serialize");

    namespace bs = boost::serialization;

    ar & bs::make_nvp("last_change",   last_change_);
    ar & bs::make_nvp("last_evaluate", last_evaluate_);
    
    for (auto f : field_list_) {
      ar & bs::make_nvp(f->name().c_str(), f);
    }
  }

} // namespace field {

BOOST_CLASS_TRACKING(field::container, boost::serialization::track_always);

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONTAINER_INL)
