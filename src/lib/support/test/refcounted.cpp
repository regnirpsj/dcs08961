// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/test/refcounted.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>                   // std::array<>
#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <condition_variable>      // std::condition_variable
#include <mutex>                   // std::mutex
#include <thread>                  // std::thread

// includes, project

#include <support/refcounted.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class refcounted_test : public support::refcounted { /* ... */ };

  class refcount_user {

  public:

    explicit refcount_user(refcounted_test* a)
      : rt_(a)
    {
      rt_->add_ref();
    }

    ~refcount_user()
    {
      rt_->sub_ref();
    }
    
  private:

    refcounted_test* rt_;
    
  };
  
  // variables, internal
  
  // functions, internal
  
} // namespace {

// functions, exported

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_support_refcounted_add_ref)
{
  refcounted_test a;

  a.add_ref();
  
  BOOST_CHECK(1 == a.get_ref());
}

BOOST_AUTO_TEST_CASE(test_support_refcounted_sub_ref)
{
  refcounted_test a;

  a.add_ref();
  a.add_ref();
  a.sub_ref();
  
  BOOST_CHECK(1 == a.get_ref());
}

BOOST_AUTO_TEST_CASE(test_support_refcounted_async)
{
  std::array<std::thread*, 10> const tpool = {
    { }
  };

  refcounted_test a;
  std::mutex      m;
  
  for (auto t : tpool) {
    t = new std::thread([&]{        
        a.add_ref();
        a.add_ref();
        a.sub_ref();

#if 0
        {
          std::lock_guard<std::mutex> lk(m);
          
          BOOST_MESSAGE(std::this_thread::get_id() << ':' << a.get_ref());
        }
#endif
      });
    
    t->detach();
  }
  
  std::this_thread::sleep_for(std::chrono::seconds(1));
  
  for (auto t : tpool) {    
    delete t;
  }
  
  BOOST_CHECK(tpool.size() == a.get_ref());

#if 0
  BOOST_MESSAGE(a.get_ref());
#endif
}

BOOST_AUTO_TEST_CASE(test_support_refcounted_user)
{
  refcounted_test* a(new refcounted_test);
  refcount_user    b(a);
  
  {
    refcount_user bb(a);

    BOOST_CHECK(2 == a->get_ref());
  }

  BOOST_CHECK(1 == a->get_ref());
}

BOOST_AUTO_TEST_CASE(test_support_refcounted_guard)
{
  refcounted_test* a(new refcounted_test);

  a->add_ref();
  
  {
    support::refcounted::guard const rcg(a);
  
    BOOST_CHECK(2 == a->get_ref());
  }

  BOOST_CHECK(1 == a->get_ref());
}

#if defined(_MSC_VER) && (_MSC_VER < 1900)
BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(test_support_refcounted_intrusive_ptr_0, 1);
#endif

BOOST_AUTO_TEST_CASE(test_support_refcounted_intrusive_ptr_0)
{
  refcounted_test* rct(new refcounted_test);
  
  BOOST_CHECK(0 == rct->get_ref());
  {
    boost::intrusive_ptr<refcounted_test> irct(rct);

    BOOST_CHECK(1 == irct->get_ref());
  }
  BOOST_CHECK(0 == rct->get_ref());
}

BOOST_AUTO_TEST_CASE(test_support_refcounted_intrusive_ptr_1)
{
  refcounted_test* rct(new refcounted_test);

  rct->add_ref();
  
  BOOST_CHECK(1 == rct->get_ref());
  {
    boost::intrusive_ptr<refcounted_test> irct(rct);

    BOOST_CHECK(2 == irct->get_ref());
  }
  BOOST_CHECK(1 == rct->get_ref());

  rct->sub_ref();
}

#if defined(_MSC_VER) && (_MSC_VER < 1900)
BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(test_support_refcounted_intrusive_ptr_2, 1);
#endif

BOOST_AUTO_TEST_CASE(test_support_refcounted_intrusive_ptr_2)
{  
  refcounted_test* rct(new refcounted_test);

  BOOST_CHECK(0 == rct->get_ref());
  {
    boost::intrusive_ptr<refcounted_test> irct(rct);

    BOOST_CHECK(rct == irct.get());
    BOOST_CHECK(  1 == irct->get_ref());

    irct = new refcounted_test;

    BOOST_CHECK(rct != irct.get());
    BOOST_CHECK(  1 == irct->get_ref());
  }
  BOOST_CHECK(0 == rct->get_ref());
}
