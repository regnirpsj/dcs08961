// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/pass/container.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_PASS_CONTAINER_HPP)

#define UKACHULLDCS_08961_RENDER_PASS_CONTAINER_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <field/adapter/multi.hpp>
#include <render/pass/base.hpp>

namespace render {
    
  namespace pass {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT container : public pass::base {

    public:

      using stage_field_type = field::adapter::multi<boost::intrusive_ptr<stage::base>>;
      
      stage_field_type stages; ///< stage/pass list (dflt: empty)
      
      explicit container(context::device&);
      virtual ~container();      

    protected:

      using stage_list_type = stage_field_type::value_container_type;
      using stage_type      = stage_field_type::value_type;
      
      stage_list_type stage_list_;
      
      virtual void do_execute(context::swap&);
      virtual void do_resize (glm::ivec2 const&);

    private:
      
      stage_list_type const& cb_get_stages() const;
      stage_list_type        cb_set_stages(stage_list_type const&);
      bool                   cb_add_stage (stage_type const&);
      bool                   cb_sub_stage (stage_type const&);

    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace pass {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_PASS_CONTAINER_HPP)
