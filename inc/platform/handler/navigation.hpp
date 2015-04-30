// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/navigation.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_NAVIGATION_HPP)

#define UKACHULLDCS_08961_PLATFORM_HANDLER_NAVIGATION_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable

// includes, project

#include <field/adapter/single.hpp>
#include <field/container.hpp>
#include <platform/handler/keyboard.hpp>
#include <platform/handler/mouse.hpp>

namespace platform {

  namespace handler {

    namespace navigation {

      class DCS08961_PLATFORM_EXPORT base : private boost::noncopyable,
                                            public field::container,
                                            public keyboard::base,
                                            public mouse::base {
        
      public:

        field::adapter::single<glm::mat4> const xform;

        virtual void print_on(std::ostream&) const;
          
      protected:

        glm::mat4 xform_;
        
        explicit base(glm::uvec2 const& /* queue lens: kbd, mouse */);
        
      private:
        
        glm::mat4 const& cb_get_xform() const;
        glm::mat4        cb_set_xform(glm::mat4 const&);
        
      };

      class DCS08961_PLATFORM_EXPORT simple : public base {

      public:

        using time_point = support::clock::time_point;
        
        explicit simple();

        virtual bool press  (key::ascii        /* ascii    */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());
        
        virtual bool press  (key::code         /* key code */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());
        
        virtual bool press  (mouse::button     /* button   */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());

        virtual bool release(mouse::button     /* button   */,
                             uint8_t           /* modifier */ = key::modifier::None,
                             glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                             time_point const& /* stamp    */ = support::clock::now());

      private:

        void rotate   (glm::vec4 const& /* xyz, angle */);
        void translate(glm::vec3 const& /* xyz        */);
        
      };
      
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace navigation {

  } // namespace handler {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_HANDLER_NAVIGATION_HPP)
