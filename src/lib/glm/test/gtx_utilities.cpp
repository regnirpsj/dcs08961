// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  glm/test/gtx_utilities.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>                 // std::array<>
#include <glm/gtc/constants.hpp> // glm::pi
#include <glm/gtc/random.hpp>    // glm::*Rand
#include <glm/gtx/io.hpp>        // glm::operator<<
#include <glm/gtx/transform.hpp> // glm::rotate, gm::scale, glm::translate>

// includes, project

#include <glm/gtx/utilities.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_utilities_deg2rad)
{
  BOOST_CHECK(glm::pi<double>() == glm::deg2rad(180.0));

  BOOST_MESSAGE(std::setprecision(12)
                << "glm::pi<double>():"   << glm::pi<double>()
                << " =?= deg2rad(180.0):" << glm::deg2rad(180.0));
}

BOOST_AUTO_TEST_CASE(test_utilities_rad2deg)
{
  BOOST_CHECK(180.0 == glm::rad2deg(glm::pi<double>()));

  BOOST_MESSAGE(std::setprecision(12)
                << 180.0 << " =?= rad2deg(glm::pi<double>():"
                << glm::rad2deg(glm::pi<double>()));
}

BOOST_AUTO_TEST_CASE(test_utilities_op_literal_deg)
{
#if defined(_MSC_VER) && (_MSC_VER <= 1700)
  BOOST_CHECK(glm::pi<double>() == 180.0 _deg);

  BOOST_MESSAGE(std::setprecision(12)
                << "glm::pi<double>():" << glm::pi<double>()
                << " =?= 180.0_deg:"    << 180.0 _deg);
#else
  BOOST_CHECK(glm::pi<double>() == 180.0_deg);

  BOOST_MESSAGE(std::setprecision(12)
                << "glm::pi<double>():" << glm::pi<double>()
                << " =?= 180.0_deg:"    << 180.0_deg);
#endif
}

BOOST_AUTO_TEST_CASE(test_utilities_op_literal_rad)
{
#if defined(_MSC_VER) && (_MSC_VER <= 1700)
  BOOST_CHECK(glm::pi<double>() == 180.0 _deg);

  BOOST_MESSAGE(std::setprecision(12)
                << "glm::pi<double>():" << glm::pi<double>()
                << " =?= 180.0_deg:"    << 180.0 _deg);
#else
  BOOST_CHECK(180.0_deg == glm::pi<double>());

  BOOST_MESSAGE(std::setprecision(12)
                << "180.0_deg:"              << 180.0_deg
                << " =?= glm::pi<double>():" << glm::pi<double>());
#endif
}

BOOST_AUTO_TEST_CASE(test_utilities_convert_transform)
{
  typedef std::pair<glm::mat4 const, glm::mat4 const> matrix_pair;
  
#if defined(_MSC_VER) && (_MSC_VER <= 1700)
  glm::vec3::value_type const angle(45 _deg);
#else
  glm::vec3::value_type const angle(45_deg);
#endif
  
  glm::mat4 const ir(glm::rotate   (angle, glm::vec3(glm::gaussRand(0.0, 20.0),
                                                     glm::gaussRand(0.0, 20.0),
                                                     glm::gaussRand(0.0, 20.0))));
  glm::mat4 const is(glm::scale    (       glm::vec3(glm::linearRand(0.1, 10.0),
                                                     glm::linearRand(0.1, 10.0),
                                                     glm::linearRand(0.1, 10.0))));
  glm::mat4 const it(glm::translate(       glm::vec3(glm::linearRand(-1.0, 1.0),
                                                     glm::linearRand(-1.0, 1.0),
                                                     glm::linearRand(-1.0, 1.0))));
  
  std::array<std::pair<glm::mat4, std::string>, 7> const input_xform_list = {
    {
      std::make_pair(glm::mat4(),  "Identity"),
      std::make_pair(ir * is * it, "RST"),
      std::make_pair(ir * it * is, "RTS"),
      std::make_pair(is * ir * it, "SRT"),
      std::make_pair(is * it * ir, "STR"),
      std::make_pair(it * ir * is, "TRS"),
      std::make_pair(it * is * ir, "TSR"),
    }
  };
  
  std::array<std::pair<glm::decompose::order, std::string>, 6> const decompose_order_list = {
    {
      std::make_pair(glm::decompose::rst, "RST"),
      std::make_pair(glm::decompose::rts, "RTS"),
      std::make_pair(glm::decompose::srt, "SRT"),
      std::make_pair(glm::decompose::str, "STR"),
      std::make_pair(glm::decompose::trs, "TRS"),
      std::make_pair(glm::decompose::tsr, "TSR"),
    }
  };

  for (auto i : input_xform_list) {
    for (auto e : decompose_order_list) {
      glm::mat4 r, s, t;
    
      glm::mat4 const   x(glm::convert::transform(i.first, e.first, r, s, t));
      matrix_pair const p(std::make_pair(i.first, x));

      BOOST_MESSAGE(i.second << ':' << std::string(43 - i.second.length(), ' ') << e.second << ':'
                    << p << '\n');

      for (unsigned i(0); i < 4; ++i) {
        for (unsigned j(0); j < 4; ++j) {
          BOOST_CHECK(std::abs(p.first[i][j] - p.second[i][j]) < 5E-6);
        }
      }
    }
  }
}
