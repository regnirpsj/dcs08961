// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/test/visitor_print.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>                        // std::array<>
#include <glm/gtc/matrix_transform.hpp> // glm::lookAt
#include <glm/gtx/io.hpp>               // glm::io::*
#include <glm/gtx/transform.hpp>        // glm::rotate, glm::translate
#include <iostream>                     // std::cout

// includes, project

#include <scene/nodes.hpp>
#include <scene/primitives.hpp>
#include <scene/visitor/print.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class simple_bfs : public scene::visitor::bfs {

  public:
    
    virtual ~simple_bfs() { /* ... */ }

  private:

    virtual void visit(scene::visitor::subject&) { /* ... */ }
    
  };

  class simple_dfs : public scene::visitor::dfs {

  public:
    
    virtual ~simple_dfs() { /* ... */ }

  private:

    virtual void visit(scene::visitor::subject&) { /* ... */ }
    
  };
  
  // variables, internal
  
  // functions, internal

  scene::node::group*
  make_scene()
  {
    using namespace scene::node;
    using namespace scene::primitive;
    
    group* root(new group);

#if 0
    {
      group* g(new group);

      {
        std::array<camera::base*, 2> const cameras = {
          {
            new camera::perspective,
            new camera::orthographic,
          }
        };

        std::array<transform*, 2> const xforms = {
          {
            new transform(glm::lookAt(glm::vec3(0,0,1), glm::vec3(0,0,0), glm::vec3(0,1, 0))),
            new transform(glm::lookAt(glm::vec3(0,1,0), glm::vec3(0,0,0), glm::vec3(0,0,-1))),
          }
        };
        
        for (unsigned i(0); i < cameras.size(); ++i) {
          xforms[i]->add_child(cameras[i]);
          
          g->add_child(xforms[i]);
        }
      }

      root->add_child(g);
    }
#endif
    
    {
      group* g(new group);

      {
        std::array<global_light*, 5> const lights = {
          {
            new global_light,
            new global_light,
            new global_light,
            new global_light,
            new global_light,
          }
        };
        
        for (auto l : lights) {
          g->children += l;
        }
      }

      root->children += g;
    }

    {
      group* g(new group);

      {
        std::array<transform*, 3> const transforms = {
          {
            new transform(glm::translate(glm::vec3(-10.0f, 0.0f, 0.0f))),
            new rotor    (2.0f, glm::vec3(1.0f, 1.0f, 1.0f)),
            new transform(glm::translate(glm::vec3(+10.0f, 0.0f, 0.0f))),
          }
        };

        for (auto t : transforms) {
          {
            std::array<material_group*, 3> const materials = {
              {
                new material_group,
                new material_group,
                new material_group,
              }
            };
            
            for (auto m : materials) {
              {
                std::array<geometry*, 3> const primitives = {
                  {
                    new cube,
                    new sphere,
                    new tetrahedron,
                  }
                };
                
                for (auto p : primitives) {
                  m->children += p;
                }
              }
              
              t->children += m;
            }
          }
          
          g->children += t;
        }
      }

      root->children += g;
    }
    
    return root;
  }
  
} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(test_scene_visitor_print_simple_bfs)
{
  using namespace scene;
  
  node::group* g(make_scene());
  
  BOOST_CHECK(nullptr != g);

  simple_bfs v;
  
  g->accept(v);
    
  delete g;
}

BOOST_AUTO_TEST_CASE(test_scene_visitor_print_simple_dfs)
{
  using namespace scene;
  
  node::group* g(make_scene());
  
  BOOST_CHECK(nullptr != g);

  simple_dfs v;

  g->accept(v);
  
  delete g;
}

BOOST_AUTO_TEST_CASE(test_scene_visitor_print_graph_bfs)
{
  boost::test_tools::output_test_stream output;
  
  {
    // needs to be in a scope to ensure bfs' dtor is run to flush
    using namespace scene;
  
    node::group* g(make_scene());
  
    BOOST_CHECK(nullptr != g);
  
    visitor::print pv(output, visitor::print::order::bfs);
    
    g->accept(pv);

#if 0
    visitor::print pv1(std::cout, visitor::print::order::bfs);
    g->accept(pv1);
#endif
    
    delete g;
  }

  BOOST_CHECK(!output.is_empty(false));
  // BOOST_CHECK( output.check_length(6356, false));
}

BOOST_AUTO_TEST_CASE(test_scene_visitor_print_graph_dfs)
{
  boost::test_tools::output_test_stream output;
  
  using namespace scene;
  
  node::group* g(make_scene());
  
  BOOST_CHECK(nullptr != g);
  
  visitor::print pv(output, visitor::print::order::dfs);
  g->accept(pv);
  
#if 0
  visitor::print pv1(std::cout, visitor::print::order::dfs);
  g->accept(pv1);
#endif
    
  BOOST_CHECK(!output.is_empty(false));
  // BOOST_CHECK( output.check_length(6356, false));
  
  delete g;
}