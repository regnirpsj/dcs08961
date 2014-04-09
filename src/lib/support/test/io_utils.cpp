// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/test/container_io.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>         // std::array<>
#include <cstdlib>       // EXIT_SUCCESS
#include <forward_list>  // std::forward_list<>
#include <iostream>      // std::cout, std::endl
#include <list>          // std::list<>
#include <map>           // std::map<>
#include <set>           // std::set<>
#include <typeinfo>      // typeid usage
#include <unordered_map> // std::unordered_map<>
#include <vector>        // std::vector<>

// includes, project

#include <support/io_utils.hpp>
#include <support/string.hpp>
#include <support/type_info.hpp>

#define DCSHULLACUK_USE_TRACE
#undef DCSHULLACUK_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  std::array<unsigned const, 10> const number_array = {
    {
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    }
  };

  std::array<std::pair<unsigned const, double const>, 10> const key_value_array = {
    {
#if defined(_MSC_VER) && (_MSC_VER <= 1700)
      std::make_pair(0, 0.0),
      std::make_pair(1, 0.1),
      std::make_pair(2, 0.2),
      std::make_pair(3, 0.3),
      std::make_pair(4, 0.4),
      std::make_pair(5, 0.5),
      std::make_pair(6, 0.6),
      std::make_pair(7, 0.7),
      std::make_pair(8, 0.8),
      std::make_pair(9, 0.9),
#else
      {0, 0.0}, {1, 0.1}, {2, 0.2}, {3, 0.3}, {4, 0.4},
      {5, 0.5}, {6, 0.6}, {7, 0.7}, {8, 0.8}, {9, 0.9},
#endif
    }
  };
  
  // functions, internal

  template <typename CTy>
  std::basic_string<CTy>
  demangle(std::type_info const& t)
  {
    return support::demangle(t);
  }
  
  template <>
  std::wstring
  demangle<wchar_t>(std::type_info const& t)
  {
    return support::string_to_wstring(demangle<char>(t));
  }
  
  template <typename Sequence, typename CTy, typename CTr>
  void
  test_sequence(std::basic_ostream<CTy, CTr>& os)
  {
    TRACE("<unnamed>::test_sequence");
    
    Sequence const s(number_array.begin(), number_array.end());

    support::ostream::basic_format_saver<CTy> fs(os);
    
    using support::ostream::operator<<;
    
    os << '\n'
       << demangle<CTy>(typeid(s)) << ": empty\n"
       << support::ostream::formatted << Sequence()
       << '\n'
       << demangle<CTy>(typeid(s)) << ": formatted\n"
       << support::ostream::formatted << s
       << '\n'
       << demangle<CTy>(typeid(s)) << ": unformatted\n"
       << support::ostream::unformatted << ' ' << s
       << std::endl;
  }

  template <typename Sequence, typename CTy, typename CTr>
  void
  test_associative(std::basic_ostream<CTy, CTr>& os)
  {
    TRACE("<unnamed>::test_associative");
    
    Sequence const s(key_value_array.begin(), key_value_array.end());

    support::ostream::basic_format_saver<CTy> fs(os);
    
    using support::ostream::operator<<;
    
    os << '\n'
       << demangle<CTy>(typeid(s)) << ": empty\n"
       << support::ostream::formatted << Sequence()
       << '\n'
       << demangle<CTy>(typeid(s)) << ": formatted\n"
       << support::ostream::formatted << s
       << '\n'
       << demangle<CTy>(typeid(s)) << ": unformatted\n"
       << support::ostream::unformatted << ' ' << s
       << std::endl;
  }

  template <typename CTy, typename CTr>
  void
  test_initializer_list(std::basic_ostream<CTy, CTr>& os)
  {
    TRACE("<unnamed>::test_initializer_list");

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
    {
      auto const s{ 0.1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9 };

      support::ostream::basic_format_saver<CTy> fs(os);
      
      using support::ostream::operator<<;

      os << '\n'
         << demangle<CTy>(typeid(s)) << ": formatted\n"
         << support::ostream::formatted
         << support::ostream::delimeter<CTy>('{', '}', ':') << s
         << '\n'
         << demangle<CTy>(typeid(s)) << ": unformatted\n"
         << support::ostream::unformatted << ' ' << s
         << std::endl;
    }

    {
      auto const s{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

      support::ostream::basic_format_saver<CTy> fs(os);
      
      using support::ostream::operator<<;

      os << '\n'
         << demangle<CTy>(typeid(s)) << ": formatted\n"
         << support::ostream::formatted << s
         << '\n'
         << demangle<CTy>(typeid(s)) << ": unformatted\n"
         << support::ostream::unformatted << ' ' << s
         << std::endl;
    }
#endif
  }
  
} // namespace {

// variables, exported
  
// functions, exported
  
int
main(int /* argc */, char* /* argv */[])
{
  TRACE("main");

  {
    std::cout << "\n======== std::cout ========\n";
    
    test_sequence   <std::forward_list<unsigned>>        (std::cout);
    test_sequence   <std::list<unsigned>>                (std::cout);
    test_sequence   <std::set<unsigned>>                 (std::cout);
    test_sequence   <std::vector<unsigned>>              (std::cout);
  
    test_associative<std::map<unsigned,double>>          (std::cout);
    test_associative<std::unordered_map<unsigned,double>>(std::cout);

    test_initializer_list                                (std::cout);
  }

  {
    std::cout << "\n======== std::wcout =======\n";
    
    test_sequence   <std::forward_list<unsigned>>        (std::wcout);
    test_sequence   <std::list<unsigned>>                (std::wcout);
    test_sequence   <std::set<unsigned>>                 (std::wcout);
    test_sequence   <std::vector<unsigned>>              (std::wcout);
  
    test_associative<std::map<unsigned,double>>          (std::wcout);
    test_associative<std::unordered_map<unsigned,double>>(std::wcout);

    test_initializer_list                                (std::wcout);
  }
  
  return EXIT_SUCCESS;
}
