// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/glut.hpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_COMMON_GLUT_HPP)

#define UKACHULLDCS_08961_APP_COMMON_GLUT_HPP

// includes, system

#include <glm/glm.hpp> // glm::ivec2
#include <deque>       // std::deque<>

// includes, project

#include <support/application.hpp>
#include <support/chrono.hpp>

namespace glut {
  
  // types, exported (class, enum, struct, union, typedef)

  class application : public support::application {

  public:

    static signed exception_handled(int /* argc */, char* /* argv */[]);
    
    struct frame_info_t {
      unsigned                   counter;
      support::clock::time_point stamp;
      support::clock::duration   duration;
    };

    struct keyboard_info_t {
      signed key;
      signed modifier;
    };

    struct mouse_info_t {
      signed     button;
      signed     state;
      glm::ivec2 pos;
    };

    struct window_info_t {
      signed      id;
      bool        fullscreen;
      glm::ivec2  pos;
      glm::ivec2  size;
      std::string title;
    };
    
    virtual void   config(int /* argc */, char* /* argv */[]);
    virtual void   init  ();
    virtual signed run   ();
    virtual void   fini  ();

    virtual void print_on(std::ostream&) const;

  protected:

    unsigned                    queue_max_;
    std::deque<frame_info_t>    frameq_;
    std::deque<keyboard_info_t> keyboardq_;
    std::deque<mouse_info_t>    mouseq_;    
    window_info_t               window_;

    explicit application();
    virtual ~application();
    
    virtual void frame_render_one () =0;
    virtual void frame_render_post();
    virtual void frame_render_pre ();
    
    virtual void idle    ();
    virtual void keyboard(unsigned char, glm::ivec2 const&);
    virtual void mouse   (signed, signed, glm::ivec2 const&);
    virtual void reshape (glm::ivec2 const&) =0;
    
  private:

    // calling order: frame_render_pre(), frame_render_one(), frame_render_post()
    virtual void display();
    
    static void close_cb   ();
    static void display_cb ();
    static void idle_cb    ();
    static void keyboard_cb(unsigned char, signed, signed);
    static void motion_cb  (signed, signed);
    static void mouse_cb   (signed, signed, signed, signed);
    static void passive_cb (signed, signed);
    static void reshape_cb (signed, signed);
    static void special_cb (signed, signed, signed);
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace glut {

#endif // #if !defined(UKACHULLDCS_08961_APP_COMMON_GLUT_HPP)
