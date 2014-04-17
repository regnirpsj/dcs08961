// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  projection/main.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>                        // std::array<>
#include <boost/concept_check.hpp>      // boost::ignore_unused_variable_warning<>
#include <cstdlib>                      // EXIT_SUCCESS
#if defined(_WIN32)
#  include <directxmath.h>              // XMMatrixPerspectiveLH
#endif
#include <glm/gtc/matrix_transform.hpp> // glm::[frustum,perspective]
#include <glm/gtx/io.hpp>               // glm::operator<<
#include <glm/gtx/transform.hpp>        // glm::[rotate,scale,translate]
#include <iostream>                     // std::cout
#include <sstream>                      // std::ostringstream

// includes, project

#include <glm/gtx/utilities.hpp>
#include <scene/object/camera/frustum.hpp>
#include <scene/object/camera/viewport.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  typedef scene::object::camera::frustum  frustum_t;
  typedef scene::object::camera::viewport viewport_t;
  
  // variables, internal
  
  // functions, internal

  std::string
  pipeline_result(glm::vec3 const& obj, glm::vec4 const& clp, glm::vec3 const& ndc,
                  glm::vec3 const& wc)
  {
    std::ostringstream ostr;
   
    ostr << glm::io::precision(3) << glm::io::width(1 + 3 + 1 + 3)
         << "obj:" << obj << " -> "
         << "clp:" << clp << " -> "
         << "ndc:" << ndc << " -> "
         << "wc:"  << wc;

    return ostr.str();
  }
  
} // namespace {

namespace ogl {
    
  glm::vec4
  eye_to_clip(glm::vec3 const& p, glm::mat4 const& m)
  {
    return (m * glm::vec4(p, 1.0));
  }
  
  glm::vec3
  clip_to_ndc(glm::vec4 const& p)
  {
    return glm::vec3(p.x / p.w, p.y / p.w, p.z / p.w);
  } 
  
  glm::vec3
  ndc_to_wc(glm::vec3 const& p, viewport_t const& v)
  {
    glm::vec3 result;
    
#if 0
    // glspec43.core20120806:13.6.1
    result.x  = ((p.x + 1) * (v.w / 2.0f))      +                    v.x;
    result.y  = ((p.y + 1) * (v.h / 2.0f))      +                    v.y;
    result.z  =  (p.z * ((v.df - v.dn) / 2.0f)) + ((v.dn + v.df) / 2.0f);
#else
    // assuming v.df:1 and v.dn:0
    result    = p * 0.5f + 0.5f;
    result.x *= v.width  + v.x;
    result.y *= v.height + v.y;
#endif
    
    return result;
  } 
    
  std::string
  pipeline(glm::vec3 const& p, glm::mat4 const& mvp, viewport_t const& vp)
  {
    glm::vec3 const cs_obj(p);
    glm::vec4 const cs_clp(eye_to_clip(cs_obj, mvp));
    glm::vec3 const cs_ndc(clip_to_ndc(cs_clp));
    glm::vec3 const cs_wc (ndc_to_wc  (cs_ndc, vp));
  
    return pipeline_result(cs_obj, cs_clp, cs_ndc, cs_wc);
  }

} // namespace ogl {

namespace d3d {

  using ogl::eye_to_clip;
  using ogl::clip_to_ndc;

  glm::vec3
  ndc_to_wc(glm::vec3 const& p, viewport_t const& v)
  {
    glm::vec3 result;
  
    // http://msdn.microsoft.com/en-us/library/windows/desktop/bb205126%28v=vs.85%29.aspx
    result.x = ((p.x + 1) * (v.width  / 2.0f)) + v.x;
    result.y = ((1 - p.y) * (v.height / 2.0f)) + v.y;
    result.z = ( p.z * (v.far - v.near))       + v.near; 
   
    return result;
  }

  std::string
  pipeline(glm::vec3 const& p, glm::mat4 const& mvp, viewport_t const& vp)
  { 
    glm::vec3 const cs_obj(p);
    glm::vec4 const cs_clp(eye_to_clip(cs_obj, mvp));
    glm::vec3 const cs_ndc(clip_to_ndc(cs_clp));
    glm::vec3 const cs_wc (ndc_to_wc  (cs_ndc, vp));

    return pipeline_result(cs_obj, cs_clp, cs_ndc, cs_wc);
  }

} // namespace d3d {

namespace { 

  // types, internal (class, enum, struct, union, typedef)

  typedef std::pair<glm::mat4 const, glm::mat4 const> matrix_pair;
  
  // variables, internal

  float const      fov     (80.0);
  viewport_t const viewport( 0, 0, 500, 500, 0,     1   );
  frustum_t const  frustum (-1, 1,  -1,   1, 0.1f, 10.0f);
  
  std::array<glm::vec3, 3> const box = {
    {
      glm::vec3( 0.0,  0.0,  0.0),
      //glm::vec3(-0.5, -0.5,  0.5),
      //glm::vec3( 0.5, -0.5,  0.5),
      glm::vec3( 0.5,  0.5,  0.5), 
      //glm::vec3(-0.5,  0.5,  0.5),
      glm::vec3(-0.5, -0.5, -0.5),
      //glm::vec3( 0.5, -0.5, -0.5),
      //glm::vec3( 0.5,  0.5, -0.5),
      //glm::vec3(-0.5,  0.5, -0.5),
    }
  };

  glm::mat4 const camera_view(glm::lookAt(glm::vec3(0,1.8,3),
                                          glm::vec3(0,0,0),
                                          glm::vec3(0,1,0)));

  // functions, internal

  void
  test_ogl_native(glm::mat4 const& model, glm::mat4 const& view, bool terse)
  {
    glm::mat4 const proj1(glm::frustum(frustum.left, frustum.right, frustum.bottom, frustum.top,
                                       frustum.near, frustum.far));
    glm::mat4 const proj2(glm::perspective(fov,
                                           (viewport.width / viewport.height),
                                           frustum.near, frustum.far));
    glm::mat4 const mvp1 (proj1 * view * model);
    glm::mat4 const mvp2 (proj2 * view * model);

    matrix_pair const view_pair(std::make_pair(camera_view, view));
    matrix_pair const proj_pair(std::make_pair(proj1, proj2));
    matrix_pair const mvp_pair (std::make_pair(mvp1, mvp2));

    std::cout << '\n'
              << "OGL native"
              << '\n';
    
    if (!terse) {
      std::cout << "frustum :"                           << frustum   << ' '
                << "viewport:"                           << viewport  << '\n'
                << "model:"                              << model     << '\n'
                << "view: camera/view"                   << view_pair << '\n'
                << "proj: glm::frustum/glm::perspective" << proj_pair << '\n'
                << "mvp: glm::frustum/glm::perspective"  << mvp_pair  << '\n';
    }

    std::cout << std::string(159, '-') << '\n';
      
    for (auto const& c : box) {
      std::cout << "OGL:frust: " << ogl::pipeline(c, mvp1, viewport) << '\n'
                << "OGL:persp: " << ogl::pipeline(c, mvp2, viewport) << '\n';

      if (*(box.rbegin()) != c) {
        std::cout << '\n';
      }
    }
    
    std::cout << std::string(159, '-') << '\n';
  }

  void
  test_d3d_native(glm::mat4 const& model, glm::mat4 const& view, bool terse)
  {
#if defined(_WIN32)
    glm::mat4 const proj1;
    {
      using namespace DirectX;

      XMMATRIX const xmmat(XMMatrixPerspectiveFovLH(glm::radians(fov),
                                                    (viewport.width / viewport.height),
                                                    frustum.near, frustum.far));
      XMFLOAT4X4     xmflt;
    
      XMStoreFloat4x4(&xmflt, xmmat);
  
      proj1 = glm::mat4(xmflt._11, xmflt._12, xmflt._13, xmflt._14,
                        xmflt._21, xmflt._22, xmflt._23, xmflt._24,
                        xmflt._31, xmflt._32, xmflt._33, xmflt._34,
                        xmflt._41, xmflt._42, xmflt._43, xmflt._44);
      proj1 *= glm::scale(1.0f,1.0f,-1.0f);
    }
    glm::mat4 const proj2;
    {
      using namespace DirectX;

      XMMATRIX const xmmat(XMMatrixPerspectiveFovRH(glm::radians(fov),
                                                    (viewport.width / viewport.height),
                                                    frustum.near, frustum.far));
      XMFLOAT4X4     xmflt;
   
      XMStoreFloat4x4(&xmflt, xmmat);
  
      proj2 = glm::mat4(xmflt._11, xmflt._12, xmflt._13, xmflt._14,
                        xmflt._21, xmflt._22, xmflt._23, xmflt._24,
                        xmflt._31, xmflt._32, xmflt._33, xmflt._34,
                        xmflt._41, xmflt._42, xmflt._43, xmflt._44);
    }
    glm::mat4 const mvp1 (proj1 * view * model);
    glm::mat4 const mvp2 (proj2 * view * model);

    matrix_pair const view_pair(std::make_pair(camera_view, view));
    matrix_pair const proj_pair(std::make_pair(proj1, proj2));
    matrix_pair const mvp_pair (std::make_pair(mvp1, mvp2));

    std::cout << '\n'
              << "D3D native"
              << '\n';
    
    if (!terse) {
      std::cout << "frustum :"                           << frustum   << ' '
                << "viewport:"                           << viewport  << '\n'
                << "model:"                              << model     << '\n'
                << "view: camera/view"                   << view_pair << '\n'
                << "proj: glm::frustum/glm::perspective" << proj_pair << '\n'
                << "mvp: glm::frustum/glm::perspective"  << mvp_pair  << '\n';
    }

    std::cout << std::string(159, '-') << '\n';
      
    for (auto const& c : box) {
      std::cout << "D3D:frust: " << ogl::pipeline(c, mvp1, viewport) << '\n'
                << "D3D:persp: " << ogl::pipeline(c, mvp2, viewport) << '\n';

      if (*(box.rbegin()) != c) {
        std::cout << '\n';
      }
    }
    
    std::cout << std::string(159, '-') << '\n';
#else
    boost::ignore_unused_variable_warning(model);
    boost::ignore_unused_variable_warning(view);
    boost::ignore_unused_variable_warning(terse);
#endif
  }
  
  void
  test_ogl_over_d3d_proj(glm::mat4 const& model, glm::mat4 const& view, bool terse)
  {
    glm::mat4 const proj1(glm::convert::opengl_to_d3d *
                          glm::frustum(frustum.left, frustum.right, frustum.bottom, frustum.top,
                                       frustum.near, frustum.far));
    glm::mat4 const proj2(glm::convert::opengl_to_d3d *
                          glm::perspective(fov,
                                           (viewport.width / viewport.height),
                                           frustum.near, frustum.far));
    glm::mat4 const mvp1 (proj1 * view * model);
    glm::mat4 const mvp2 (proj2 * view * model);

    matrix_pair const view_pair(std::make_pair(camera_view, view));
    matrix_pair const proj_pair(std::make_pair(proj1, proj2));
    matrix_pair const mvp_pair (std::make_pair(mvp1, mvp2));

    std::cout << '\n'
              << "OGL over D3D (perspective)"
              << '\n';
    
    if (!terse) {
      std::cout << "frustum :"                           << frustum   << ' '
                << "viewport:"                           << viewport  << '\n'
                << "model:"                              << model     << '\n'
                << "view: camera/view"                   << view_pair << '\n'
                << "proj: glm::frustum/glm::perspective" << proj_pair << '\n'
                << "mvp: glm::frustum/glm::perspective"  << mvp_pair  << '\n';
    }

    std::cout << std::string(159, '-') << '\n';
      
    for (auto const& c : box) {
      std::cout << "D3D:frust: " << d3d::pipeline(c, mvp1, viewport) << '\n'
                << "D3D:persp: " << d3d::pipeline(c, mvp2, viewport) << '\n';

      if (*(box.rbegin()) != c) {
        std::cout << '\n';
      }
    }
    
    std::cout << std::string(159, '-') << '\n';
  }

  void
  test_ogl_over_d3d_ortho(glm::mat4 const& model, glm::mat4 const& view, bool terse)
  {
    glm::mat4 const proj1(glm::ortho(frustum.left, frustum.right, frustum.bottom, frustum.top,
                                     frustum.near, frustum.far));
    glm::mat4 const proj2(glm::convert::opengl_to_d3d * proj1);
    glm::mat4 const mvp1 (proj1 * view * model);
    glm::mat4 const mvp2 (proj2 * view * model);

    matrix_pair const view_pair(std::make_pair(camera_view, view));
    matrix_pair const proj_pair(std::make_pair(proj1, proj2));
    matrix_pair const mvp_pair (std::make_pair(mvp1, mvp2));

    std::cout << '\n'
              << "OGL over D3D (orthographic)"
              << '\n';
    
    if (!terse) {
      std::cout << "frustum :"                           << frustum   << ' '
                << "viewport:"                           << viewport  << '\n'
                << "model:"                              << model     << '\n'
                << "view: camera/view"                   << view_pair << '\n'
                << "proj: glm::frustum/glm::perspective" << proj_pair << '\n'
                << "mvp: glm::frustum/glm::perspective"  << mvp_pair  << '\n';
    }

    std::cout << std::string(159, '-') << '\n';
      
    for (auto const& c : box) {
      std::cout << "OGL:ortho: " << ogl::pipeline(c, mvp1, viewport) << '\n'
                << "D3D:ortho: " << d3d::pipeline(c, mvp2, viewport) << '\n';

      if (*(box.rbegin()) != c) {
        std::cout << '\n';
      }
    }
    
    std::cout << std::string(159, '-') << '\n';
  }
  
} // namespace {

int
main(int argc, char* /* argv */[])
{
  glm::mat4 const model(glm::scale(glm::vec3(0.9f, 0.9f, 0.9f)));
  glm::mat4 const view (camera_view);
  bool            terse(true);
  
  if (2 <= argc) {
    terse = false;
  }
  
  test_ogl_native        (model, view, terse);
  test_d3d_native        (model, view, terse);
  test_ogl_over_d3d_proj (model, view, terse);
  test_ogl_over_d3d_ortho(model, view, terse);
  
  return EXIT_SUCCESS;
}
