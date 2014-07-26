// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/02.cpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <GL/glew.h>            // ::gl*

#include <array>
#include <boost/filesystem.hpp> // boost::filesystem::path
#include <GL/freeglut.h>
#include <oglplus/all.hpp>
#include <oglplus/bound/texture.hpp>
#include <oglplus/images/checker.hpp>
#include <oglplus/opt/smart_enums.hpp>

#include <glm/glm.hpp>
#include <oglplus/interop/glm.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtx/transform.hpp>

#include <sstream>
#include <vector>

// includes, project

#include <../common/glut.hpp>
#include <../common/model.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {

  // types, internal (class, enum, struct, union, typedef)

  class application : public glut::application {
    
  public:    

    explicit application(int argc, char* argv[])
      : glut::application(argc, argv),
        ctx_             (),
        prg_             (),
        tex_             (),
        model_list_      ()
    {
      TRACE("<unnamed>::application::application");

      using namespace oglplus;    
      
      {
        namespace bfs = boost::filesystem;

        static bfs::path::string_type const sep(bfs::path("/").make_preferred().native());
        
        bfs::path const   p(argv[0]);
        std::string const d(bfs::canonical(p.parent_path()).string());
        // std::string const f(p.filename().string());
        std::string const b(d + sep + ".." + sep + "share" + sep + "shader" + sep + "glsl");
        
        std::array<std::string const, 9> const file_names = {
          {
            std::string(b + sep + "phong.vp.glsl"),
            std::string(b + sep + "phong.fp.glsl"),
            std::string(b + sep + "common/constants.glsl"),
            std::string(b + sep + "common/functions.glsl"),
            std::string(b + sep + "common/light.glsl"),
            std::string(b + sep + "common/material.glsl"),
            std::string(b + sep + "common/phong.glsl"),
            std::string(b + sep + "common/pipeline.glsl"),
            std::string(b + sep + "common/uniforms.glsl"),
          }
        };
        
        for (auto fn : file_names) {
          std::stringstream src;

          src << std::ifstream(fn).rdbuf();
          
          if (!src.str().empty()) {
            NamedString::Set(NamedStringType::ShaderInclude, fn, src.str());
          } else {
            throw std::runtime_error("unable to load content for shader file '" + fn + "'");
          }
        }
        
        prg_ << VertexShader()  .Source(NamedString::Get(file_names[0]))
             << FragmentShader().Source(NamedString::Get(file_names[1]));

        // GLSLStrings const paths({ (b + '\0').c_str(), (d + '\0').c_str(), });
        
        prg_.BuildInclude(b).Link().Use();
      }

      {
        ctx_.Bound(smart_enums::_2D(), tex_)
          .Image2D(images::CheckerRedBlack(64, 64, 16, 16))
          .GenerateMipmap()
          .MinFilter(smart_enums::LinearMipmapLinear())
          .MagFilter(smart_enums::Linear())
          .Anisotropy(2.0f)
          .WrapS(smart_enums::Repeat())
          .WrapT(smart_enums::Repeat());
        
        (prg_/"tex_diffuse") = 0;
      }
      
      if (!input_files_.empty()) {
        static glm::vec3 const incr(0.0, 0.0, -1.5);
        
        glm::vec3 xlat(0.0, 0.0, 0.0);

        if (0 == (input_files_.size() % 2)) {
          xlat.z  = 0.75;
          xlat.z *= input_files_.size() / 2;
        } else {
          xlat.z  = 1.5;
          xlat.z *= (input_files_.size() - 1) / 2;
        }
        
        for (auto f : input_files_) {
          model::mesh* mm(nullptr);
          
          //try {
#if 1
            std::cout << support::trace::prefix() << "<unnamed>::application::application: "
                      << "loading file: "  << f
                      << std::endl;
#endif

            mm = new model::mesh(f, prg_);
            
            mm->xform(glm::translate(xlat) *  mm->xform());
            
            model_list_.push_back(model_mesh_list_type::value_type(mm));
            
#if 0
            std::cout << support::trace::prefix() << "<unnamed>::application::application: "
                      << "xform: " << mm->xform << '\n'
                      << "xlat: "  << xlat
                      << std::endl;
#endif
            
            xlat += incr;
            //}

#if 0
          catch (std::runtime_error& ex) {
            std::cout << support::trace::prefix() << "<unnamed>::application::application: "
                      << "unable to load file: "  << f << ", error:'" << ex.what() << "'"
                      << std::endl;

            delete mm; mm = nullptr;
          }
#endif
        }
      }

      if (!input_files_.empty()) {
        camera_.xform = glm::inverse(glm::lookAt(glm::vec3( input_files_.size() / 10,
                                                            0.5f,
                                                            (input_files_.size() * 4) / 3),
                                                 glm::vec3( 0.0f, 0.0f, 0.0f),
                                                 glm::vec3( 0.0f, 1.0f, 0.0f)));
      }
      
      ctx_.ClearColor(0.95f, 0.95f, 0.95f, 0.0f);
      ctx_.ClearDepth(1.0f);
      ctx_.Enable(smart_enums::DepthTest());
      ctx_.Enable(smart_enums::CullFace());
    }
    
    virtual void frame_render_one()
    {
      TRACE("<unnamed>::application::frame_render_one");

      using namespace oglplus;
      
      ctx_.Clear().ColorBuffer().DepthBuffer();

      // view
      if (Uniform<glm::mat4>(prg_, "xform_view").IsActive()) {
        Uniform<glm::mat4>(prg_, "xform_view").Set(glm::inverse(camera_.xform));
      }
      
      // model(s)
      for (auto const& m : model_list_) {
        m->draw();
      }
    }
    
    virtual void reshape(glm::ivec2 const& size)
    {
      TRACE("<unnamed>::application::reshape");

      glut::application::reshape(size);
      
      using namespace oglplus;
      
      ctx_.Viewport(size.x, size.y);

      if (Uniform<glm::mat4>(prg_, "xform_projection").IsActive()) {
        Uniform<glm::mat4>(prg_, "xform_projection").Set(projection_.xform);
      }
      
      if (Lazy<Uniform<glm::ivec2>>(prg_, "screen_size").IsActive()) {
        Lazy<Uniform<glm::ivec2>>(prg_, "screen_size").Set(size);
      }
    }    
    
  private:

    typedef std::vector<std::unique_ptr<model::mesh>> model_mesh_list_type;
    
    oglplus::Context     ctx_;
    oglplus::Program     prg_;
    oglplus::Texture     tex_;
    model_mesh_list_type model_list_;
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

int
main(int argc, char* argv[])
{
  TRACE("main");
  
  return glut::execute<application>(argc, argv, std::nothrow);
}
