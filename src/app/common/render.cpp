// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  proto.cpp                                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  template <typename T>
  render::pass*
  make_render_pass_shadow(render::context<T>& ctx, scene::node::group* root)
  {
    using namespace render;
    
    pass::shadow* sdw(new pass::shadow<T>(ctx->name() + "::shadow"));
    
    sdw->add(stage::state_setup<T>    (sdw->name() + "::state_setup"));
    sdw->add(stage::clear<T>          (sdw->name() + "::clear"));
    sdw->add(stage::shadow::mapping<T>(sdw->name() + "::mapping", root));
    
    return sdw;
  }

  template <typename T>
  render::pass*
  make_render_pass_draw(render::context<T>& ctx,
                        scene::node::group* root, scene::node::camera* camera)
  {
    using namespace render;
    
    pass::draw* drw(new pass::draw<T>(ctx->name() + "::draw"));

    // drw->add(stage::resize_targets(drw->name() + "::resize_targets");
    drw->add(stage::state_setup<T>   (drw->name() + "::state_setup"));
    drw->add(stage::clear<T>         (drw->name() + "::clear"));
    drw->add(stage::draw::retained<T>(drw->name() + "::retained", root, camera));
    
    return drw;
  }

  template <typename T>
  render::pass*
  make_render_pass_postprocess(render::context<T>& ctx)
  {
    using namespace render;
    
    pass::postprocess* pp(new pass::postprocess<T>(ctx->name() + "::postprocess"));

    pp->add(stage::state_setup<T>         (pp->name() + "::state_setup"));
    pp->add(stage::clear<T>               (pp->name() + "::clear"));
    pp->add(stage::postprocess::tonemap<T>(pp->name() + "::tonemap"));
    
    return pp;
  }

  template <typename T>
  render::pass*
  make_render_pass_gui(render::context<T>& ctx)
  {
    using namespace render;
    
    return new pass::gui<T>(ctx->name() + "::gui");
  }

  template <typename T>
  render::pass*
  make_render_stage_swap(render::context<T>& ctx)
  {
    using namespace render;
    
    return new stage::swap<T>(ctx->name() + "::swap", stage::swap::synced_to_vblank);
  }

  template <typename T>
  render::pass::base*
  make_render_pipeline(render::context<T>& ctx,
                       scene::node::group* root, scene::node::camera* camera)
  {
    using namespace render;
    
    pass::base* pc(new pass::container<T>(ctx, ctx->name() + "::pipeline"));

    pc->add(make_render_pass_shadow<T>     (ctx, root));
    pc->add(make_render_pass_draw<T>       (ctx, root, camera));
    pc->add(make_render_pass_postprocess<T>(ctx));
    pc->add(make_render_pass_gui<T>        (ctx));
    pc->add(make_render_stage_swap<T>      (ctx));
    
    return pc;
  }
  
} // namespace {

int
main()
{
  std::vector<boost::intrusive_ptr<scene::node::camera>> camera_list;
  std::unique_ptr<scene::node::group*>                   root(make_scene(camera_list));
  
  {
    render::window<d3d11> win("d3d11");

    win.add(make_render_pipeline(win.context(), root, camera_list[0].get()));
  }

  {
    render::window<ogl4> win("ogl4");

    win.add(make_render_pipeline(win.context(), root, camera_list[0].get()));
  }
}
