// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/camera.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_CAMERA_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_CAMERA_HPP

// includes, system

// #include <>

// includes, project

#include <scene/node/base.hpp>

// avoid "error C2208: 'float' : no members defined using this type" brought in by, you guessed it,
// 'windows.h', arrghh

#ifdef far
#  pragma message("Note: undefining 'near'! (" __FILE__ ")")
#  undef far
#endif

#ifdef near
#  pragma message("Note: undefining 'far'! (" __FILE__ ")")
#  undef near
#endif

namespace scene {

  namespace node {

    namespace camera {
      
      // types, exported (class, enum, struct, union, typedef)

      struct frustum {

      public:

        float left;   // left boundary
        float right;  // right boundary
        float bottom; // lower boundary
        float top;    // upper boundary
        float near;   // near clipping plane (see glFrustum(3G))
        float far;    // near clipping plane (see glFrustum(3G))
        
        explicit frustum(float /* left */   =  -1.00,
                         float /* right */  =   1.00,
                         float /* bottom */ =  -1.00,
                         float /* top */    =   1.00,
                         float /* near */   =   0.01,
                         float /* far */    = 100.00);
        
      };

      struct viewport {

      public:

        float x;      // lower-left corner x-ccordinate
        float y;      // lower-left corner y-ccordinate
        float width;  // width
        float height; // height
        float near;   // window coordinates minimum depth (see glDepthRange(3G))
        float far;    // window coordinates maximum depth (see glDepthRange(3G))

        explicit viewport(float /* x */      =   0.0,
                          float /* y */      =   0.0,
                          float /* width */  = 100.0,
                          float /* height */ = 100.0,
                          float /* near */   =   0.0,
                          float /* far */    =   1.0);
      };
    
      class base : public node::base {

      public:
      
        typedef node::base       inherited;
        typedef glm::mat4        matrix_type;
        typedef camera::viewport viewport_type;
        
        virtual ~base() =0;

        matrix_type const&   projection() const;             // <- projection_
        matrix_type          view() const;                   // <- inverse(absolute_xform())

        viewport_type const& viewport() const;               // <- viewport_
        viewport_type        viewport(viewport_type const&); // -> viewport_ + update()
        
        virtual void accept(visitor::base&);
      
        virtual void print_on(std::ostream&) const;

      protected:
      
        matrix_type   projection_;
        viewport_type viewport_;
        glm::vec2     near_far_;
        
        explicit base(std::string const&   /* name */,
                      matrix_type const&   /* projection */,
                      viewport_type const& /* viewport */,
                      glm::vec2 const&     /* near/far */);

        virtual void update() =0;
        
      };

      class orthographic : public base {

      public:

        typedef base inherited;
      
        explicit orthographic(viewport_type const& /* viewport */ = viewport_type(),
                              glm::vec2 const&     /* near/far */ = glm::vec2(frustum().near,
                                                                              frustum().far));

        virtual ~orthographic();
        
        virtual void accept(visitor::base&);
      
        virtual void print_on(std::ostream&) const;

      protected:

        virtual void update();
        
      };

      class perspective : public base {

      public:

        typedef base inherited;      

        explicit perspective(float                /* fovy */     = 60,
                             viewport_type const& /* viewport */ = viewport_type(),
                             glm::vec2 const&     /* near/far */ = glm::vec2(frustum().near,
                                                                             frustum().far));
      
        virtual ~perspective();

        float fovy() const;
        float fovy(float);
        
        virtual void accept(visitor::base&);
      
        virtual void print_on(std::ostream&) const;

      protected:

        virtual void update();
        
      private:

        float fovy_;
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      std::ostream& operator<<(std::ostream&, frustum const&);
      std::ostream& operator<<(std::ostream&, viewport const&);
      
    } // namespace camera {
    
  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_CAMERA_HPP)
