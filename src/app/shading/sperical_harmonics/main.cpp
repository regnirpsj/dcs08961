// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  src/app/shading/sperical_harmonics.cpp                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <boost/io/ios_state.hpp>                      // boost::io::ios_all_saver
#include <boost/math/special_functions/factorials.hpp> // boost::math::factorial<>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtx/polar_coordinates.hpp>
#include <map>
#include <ostream>
#include <random>

// includes, project

#include <support/io_utils.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace sh {
  
  // types, internal (class, enum, struct, union, typedef)

  using scalar_t = glm::vec3::value_type;
  
  struct sample {

  public:

    glm::vec2             spherical;
    glm::vec3             euclidean;
    std::vector<scalar_t> coefficients;
    
  };
  
  // variables, internal
  
  // functions, internal

  scalar_t
  K(unsigned l, signed m)
  {
    TRACE("sh::K");
    
    return std::sqrt(((2.0 * l + 1.0) *             boost::math::factorial<scalar_t>(l - m)) /
                     ((4.0 * glm::pi<scalar_t>()) * boost::math::factorial<scalar_t>(l + m)));
  }

  scalar_t
  P(unsigned l, signed m, scalar_t x)
  {
    TRACE("sh::P");
    
    scalar_t pmm(1.0);

    if (0 < m) {
      scalar_t const somx2(std::sqrt((1.0 - x) * (1.0 + x)));
      double         fact(1.0);
      
      for (signed i(1); i <= m; ++i) {
        pmm  *= (-fact) * somx2;
        fact += 2.0;
      }
    }

    if (signed(l) == m) {
      return pmm;
    }

    scalar_t pmmp1(x * (2.0 * m + 1.0) * pmm);

    if (signed(l) == m+1) {
      return pmmp1;
    }

    scalar_t pll(0.0);

    for (unsigned i(m+2); i <= l; ++i) {
      pll   = ((2.0 * i - 1.0) * x * pmmp1 - (i + m - 1.0) * pmm) / (i-m);
      pmm   = pmmp1;
      pmmp1 = pll;
    }
    
    return pll;
  }
  
  scalar_t
  compute(unsigned l, signed m, scalar_t theta, scalar_t phi)
  {
    TRACE("sh::compute");

    scalar_t result(glm::root_two<scalar_t>());
    
    if (0 == m) {
      result  = K(l,  0) *                      P(l,  m, std::cos(theta));
    } else if (0 < m) {
      result *= K(l,  m) * std::cos( m * phi) * P(l,  m, std::cos(theta));
    } else {
      result *= K(l, -m) * std::sin(-m * phi) * P(l, -m, std::cos(theta));
    }

    return result;
  }
  
  std::vector<sample>
  create_samples(unsigned n_samples = 4, unsigned n_bands = 1)
  {
    TRACE("sh::create_samples");

    scalar_t const sqrt_n_samples(sqrt(n_samples));

    std::random_device               rd;
    std::mt19937                     gen (rd());
    std::uniform_real_distribution<> dist(0, 1);
    std::vector<sample>              result;
    
    for (unsigned a(0); a < sqrt_n_samples; ++a) {
      for (unsigned b(0); b < sqrt_n_samples; ++b) {
        scalar_t const x    ((a + dist(gen)) / sqrt_n_samples); // do not reuse results
        scalar_t const y    ((b + dist(gen)) / sqrt_n_samples); // each sample must be random
        scalar_t const theta(2.0 * std::acos(std::sqrt(1.0 - x)));
        scalar_t const phi  (2.0 * glm::pi<scalar_t>() * y);
        sample         s;

        s.spherical = glm::vec2     (theta, phi);
        s.euclidean = glm::euclidean(s.spherical);

        for (unsigned l(0); l <= n_bands; ++l) {
          for (signed m(-l); m <= signed(l); ++m) {
            s.coefficients.push_back(compute(l, m, theta, phi));
          }
        }
        
        result.push_back(s);
      }
    }

    return result;
  }
  
  std::ostream&
  operator<<(std::ostream& os, sample const& a)
  {
    std::ostream::sentry const cerberus(os);

    if (cerberus) {
      support::ostream::format_saver sofs(os);
      
      using support::ostream::operator<<;
      
      os << '['
         << glm::io::width(6)
         << a.spherical
         << ','
         << a.euclidean
         << ','
#if 1
         << a.coefficients.size()
#else
         << support::ostream::delimeter<char>('[', ']', ',')
         << a.coefficients
#endif
         << ']';
    }
    
    return os;
  }

} // namespace {

int
main()
{
  TRACE("main");

  std::vector<sh::sample> result;

  for (unsigned b(0); b < 10; ++b) {
    std::vector<sh::sample> const t(sh::create_samples(4, b));

    result.insert(result.end(), t.begin(), t.end());
  }
  
#if 1
  using support::ostream::operator<<;
  
  std::cout << support::ostream::delimeter<char>('[', ']', '\n')
            << result << std::endl;
#endif
}
