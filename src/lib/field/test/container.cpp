// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/container.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <algorithm>      // std::find<>
#include <glm/glm.hpp>    // glm::vec3
#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <field/adapter_multi.hpp>
#include <field/adapter_single.hpp>
#include <field/container.hpp>
#include <field/value_multi.hpp>
#include <field/value_single.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class container : public field::container {

    typedef std::vector<unsigned> unsigned_list_type;
    
  public:

    field::value::single<bool>        svf_bool;
    field::value::single<std::string> svf_string;
    field::value::multi<glm::vec3>    mvf_vec3;
    field::adapter::single<unsigned>  saf_unsigned;
    field::adapter::multi<unsigned>   maf_unsigned;

    explicit container()
      : field::container(),
        svf_bool        (*this, "svf_bool", true),
        svf_string      (*this, "svf_string", "abcdefghijklmnopqrstuvwxyz"),
        mvf_vec3        (*this, "mvf_vec3", {glm::vec3(1), glm::vec3(2)}),
        saf_unsigned    (*this, "saf_unsigned",
                         std::bind(&container::cb_get_saf_unsigned, this),
                         std::bind(&container::cb_set_saf_unsigned, this, std::placeholders::_1)),
        maf_unsigned    (*this, "maf_unsigned",
                         std::bind(&container::cb_get_maf_unsigned, this),
                         std::bind(&container::cb_set_maf_unsigned, this, std::placeholders::_1),
                         std::bind(&container::cb_add_maf_unsigned, this, std::placeholders::_1),
                         std::bind(&container::cb_sub_maf_unsigned, this, std::placeholders::_1))
    {
      // 'field::adapter::[multi|single]<>::set' not working in initializer list
      saf_unsigned = 1;
      maf_unsigned = {1,2,3,4};
    }
    
  private:

    unsigned           value_;
    unsigned_list_type value_list_;

    unsigned const& cb_get_saf_unsigned() const
    {
      return value_;
    }
    
    unsigned cb_set_saf_unsigned(unsigned const& a)
    {
      unsigned const result(value_);

      value_ = a;
      
      return result;
    }

    unsigned_list_type const& cb_get_maf_unsigned() const
    {
      return value_list_;
    }
    
    unsigned_list_type cb_set_maf_unsigned(unsigned_list_type const& a)
    {
      unsigned_list_type const result(value_list_);

      value_list_ = a;
      
      return result;
    }
    
    bool cb_add_maf_unsigned(typename unsigned_list_type::value_type const& a)
    {
      bool result(false);
      auto found(std::find(value_list_.begin(), value_list_.end(), a));

      if (value_list_.end() == found) {
        value_list_.insert(value_list_.end(), a);
        result = true;
      }
      
      return result;
    }
    
    bool cb_sub_maf_unsigned(typename unsigned_list_type::value_type const& a)
    {
      bool result(false);
      auto found(std::find(value_list_.begin(), value_list_.end(), a));

      if (value_list_.end() != found) {
        value_list_.erase(found);
        result = true;
      }
      
      return result;
    }
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(container_ctor)
{
  container const c;
  
  BOOST_CHECK(true == c.svf_bool.get());
}

BOOST_AUTO_TEST_CASE(container_print_on)
{
  container const c;
  
  BOOST_CHECK(true == c.svf_bool.get());
  BOOST_MESSAGE(std::boolalpha << c);
}
