// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/test/glut.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <GL/freeglut.h> // ::glut*
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>

// includes, project

#include <support/chrono_io.hpp>
#include "../glut.hpp"

// internal unnamed namespace

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class application : public glut::application {

  public:

    void frame_render_one()
    {
      TRACE("<unnamed>::application::frame_render_one");

      {
        static std::random_device                 rd;
        static std::default_random_engine         e1(rd());
        static std::mt19937                       e2(rd());
        
        std::uniform_int_distribution<int> uniform_dist(9, 33);
        std::normal_distribution<>         normal_dist (uniform_dist(e1), 2);
 
        support::sleep(std::chrono::milliseconds(signed(std::round(normal_dist(e2)))));
      }
      
#if 0
      auto const& f(frameq_.back());
      
      if (0 == (f.counter % 50)) {
#if 0
        // std::cout << support::trace::prefix() << "<unnamed>::application::frame_render_one: ";
        print_on(std::cout);
#endif
        
        support::clock::duration avg;

        for (auto v : frameq_) {
          avg += v.duration;
        }

        avg /= frameq_.size() - 1;

        typedef std::chrono::duration<double> dsec;
        
        std::cout << ", [" << frameq_.size() << " frame avg:"
                  << std::fixed << std::right
                  << std::setprecision(3)
                  << std::chrono::duration_fmt(std::chrono::symbol)
                  << std::chrono::duration_cast<dsec>(avg) << ','
                  << std::setprecision(2)
                  << (1.0 / std::chrono::duration_cast<dsec>(avg).count()) << " Hz]"
                  << '\n';
      }
#endif
    }
    
    void reshape(glm::ivec2 const&)
    {
      TRACE("<unnamed>::application::reshape");
    }
    
  } instance;
  
  // variables, internal
  
  // functions, internal

} // namespace {

// functions, exported

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_app_common_glut_application_instance)
{
  BOOST_CHECK(application::instance());
}

BOOST_AUTO_TEST_CASE(test_app_common_glut_application_run)
{
  int   argc(1);
  char* argv[] = { "dummy" };
  
  BOOST_CHECK(EXIT_SUCCESS == application::exception_handled(argc, argv));
}
