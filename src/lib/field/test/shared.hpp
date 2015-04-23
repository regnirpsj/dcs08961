// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/shared.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_TEST_SHARED_HPP)

#define UKACHULLDCS_08961_FIELD_TEST_SHARED_HPP

// includes, system

#include <algorithm>          // std::find<>
#include <boost/mpl/list.hpp> // boost::mpl::list<>
#include <glm/glm.hpp>        // glm::mat4, glm::vec3
#include <glm/gtx/io.hpp>     // glm::operator<<
#include <string>             // std::string
#include <vector>             // std::vector<>

// includes, project

#include <field/container.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace field {
  
  namespace test {
  
    // types, exported (class, enum, struct, union, typedef)

    template <typename T>
    class container_single : public field::container {

    public:

      explicit container_single()
        : field::container(),
          value_          ()
      {
        TRACE("field::test::container_single::container_single");
      }
      
      inline T const& cb_get() const
      {
        TRACE("field::test::container_single::get<" + support::demangle(typeid(T)) + ">");

        return value_;
      }

      inline T cb_set(T const& a) 
      {
        TRACE("field::test::container_single::set<" + support::demangle(typeid(T)) + ">");

        T const result(value_);
        
        value_ = a;
        
        return result;
      }

    protected:
      
      T value_;
      
    };
    
    template <typename T>
    class container_multi : public container_single<T> {

      typedef container_single<T> inherited;
      
    public:

      explicit container_multi()
        : container_single<T>()
      {
        TRACE("field::test::container_single::container_single");
      }
      
      inline bool cb_add(typename T::value_type const& a)
      {
        TRACE("field::test::container_multi::add<" + support::demangle(typeid(T)) + ">");

        bool       result(false);
        auto const found(std::find(inherited::value_.begin(), inherited::value_.end(), a));
        
        if (inherited::value_.end() == found) {
          inherited::value_.insert(inherited::value_.end(), a);
          
          result = true;
        }
        
        return result;
      }

      inline bool cb_sub(typename T::value_type const& a)
      {
        TRACE("field::test::container_multi::sub<" + support::demangle(typeid(T)) + ">");

        bool       result(false);
        auto const found(std::find(inherited::value_.begin(), inherited::value_.end(), a));
        
        if (inherited::value_.end() != found) {
          inherited::value_.erase(found);
          
          result = true;
        }
        
        return result;
      }
      
    };

    typedef boost::mpl::list<
       bool
#if 1
      ,signed   char
      ,unsigned char
      ,char16_t
      ,char32_t
      ,signed   short
      ,unsigned short
      ,signed   int
      ,unsigned int
      ,signed   long int
      ,unsigned long int
      ,signed   long long int
      ,unsigned long long int
      ,float
      ,double
      ,long double
      ,std::string
      ,glm::mat4
      ,glm::vec3
#endif
      > single_types;

    typedef boost::mpl::list<
       std::vector<bool>
#if 1
      ,std::vector<signed   char>
      ,std::vector<unsigned char>
      ,std::vector<char16_t>
      ,std::vector<char32_t>
      ,std::vector<signed   short>
      ,std::vector<unsigned short>
      ,std::vector<signed   int>
      ,std::vector<unsigned int>
      ,std::vector<signed   long int>
      ,std::vector<unsigned long int>
      ,std::vector<signed   long long int>
      ,std::vector<unsigned long long int>
      ,std::vector<float>
      ,std::vector<double>
      ,std::vector<long double>
      ,std::vector<std::string>
      ,std::vector<glm::mat4>
      ,std::vector<glm::vec3>
#endif
      > multi_types;
    
    // variables, exported (extern)
  
    // functions, inlined (inline)
    
    // functions, exported (extern)
  
  } // namespace test {

} // namespace field {

#if defined(UKACHULLDCS_USE_TRACE)
#  undef UKACHULLDCS_USE_TRACE
#endif

#endif // #if !defined(UKACHULLDCS_08961_FIELD_TEST_SHARED_HPP)
