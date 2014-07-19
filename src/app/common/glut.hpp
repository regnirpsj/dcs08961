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
      glm::ivec2 position;
    };

    struct window_info_t {
      glm::ivec2  position;
      glm::ivec2  size;
      std::string title;
    };
    
    virtual void   config(int /* argc */, char* /* argv */[]);
    virtual void   init  ();
    virtual signed run   ();
    virtual void   fini  ();

    virtual void print_on(std::ostream&) const;

  protected:

    frame_info_t    frame_;
    keyboard_info_t keyboard_;
    mouse_info_t    mouse_;    
    window_info_t   window_;

    explicit application();
    virtual ~application();

    virtual void display () =0;
    virtual void idle    ();
    virtual void keyboard(unsigned char, glm::ivec2 const&);
    virtual void motion  (glm::ivec2 const&);
    virtual void mouse   (signed, signed, glm::ivec2 const&);
    virtual void passive (glm::ivec2 const&);
    virtual void reshape (glm::ivec2 const&) =0;
    virtual void special (signed, glm::ivec2 const&);
    
  private:

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
