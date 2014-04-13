// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/window.hpp                                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_WINDOW_HPP)

#define UKACHULLDCS_08961_RENDER_WINDOW_HPP

// includes, system

//#include <>

// includes, project

//#include <>

namespace render {

  template <typename T> class context;

  namespace pass {
    
    template <typename T> class base;
    
  } // namespace pass {
  
  // types, exported (class, enum, struct, union, typedef)

  template <typename T>
  class window {

  public:

    typedef context<T> context_type;
    
    context_type& context();

    bool add(pass::base<T>*);
    bool sub(pass::base<T>*);

    void render(unsigned /* frames */ = 1);
    
  protected:
    
    typedef std::vector<boost::intrusive_ptr<pass::base<T>>> render_pass_list_type;
    
    context_type          context_;
    render_pass_list_type render_pass_list_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace render {

#include <render/window.inl>

#endif // #if !defined(UKACHULLDCS_08961_RENDER_WINDOW_HPP)
