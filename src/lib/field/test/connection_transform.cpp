// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/connection_transform.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <field/connection/transform.hpp>
#include <field/value/multi.hpp>
#include <field/value/single.hpp>
#include <shared.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  template <typename T1, typename T2 = T1>
  class assign {

  public:

    T1 operator()(T2 const& a)
    {
      return a;
    }
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_connection_transform_single, T, field::test::single_types)
{
  using namespace field;

  typedef test::container_single<T>                               container_type;
  typedef value::single<T>                                        field_type;
  typedef assign<T>                                               xform_type;
  typedef connection::transform<field_type,field_type,xform_type> connection_type;

  {
    container_type   c;
    field_type const f1(c, "f1");
    field_type       f2(c, "f2");
    connection_type  r (f1, f2, xform_type());

    r.update();
  
    BOOST_CHECK(f2.get() == f1.get());
    BOOST_MESSAGE(&r << ':' << r);
  }

  {
    container_type   c;
    field_type       f1(c, "f1");
    field_type       f2(c, "f2");
    connection_type* r (new connection_type(f1, f2, xform_type()));
    
    BOOST_CHECK(f1.connection_add(r));
    BOOST_CHECK(!f1.connection_add(r));
    
    f1.touch();
    
    BOOST_CHECK(f2.get() == f1.get());

    BOOST_MESSAGE(r << ':' << *r);

    BOOST_CHECK(f1.connection_sub(r));

    delete r;
  }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_field_connection_transform_multi, T, field::test::multi_types)
{
  using namespace field;

  typedef test::container_multi<T>                                container_type;
  typedef value::multi<T>                                         field_type;
  typedef assign<typename field_type::value_container_type>       xform_type;
  typedef connection::transform<field_type,field_type,xform_type> connection_type;
  
  {
    container_type   c;
    field_type const f1(c, "f1");
    field_type       f2(c, "f2");
    connection_type  r (f1, f2, xform_type());

    r.update();
  
    BOOST_CHECK(f2.get() == f1.get());
    BOOST_MESSAGE(&r << ':' << r);
  }

  {
    container_type   c;
    field_type       f1(c, "f1");
    field_type       f2(c, "f2");
    connection_type* r (new connection_type(f1, f2, xform_type()));
    
    BOOST_CHECK(f1.connection_add(r));
    BOOST_CHECK(!f1.connection_add(r));
    
    f1.touch();
    
    BOOST_CHECK(f2.get() == f1.get());

    BOOST_MESSAGE(r << ':' << *r);

    BOOST_CHECK(f1.connection_sub(r));

    delete r;
  }
}
