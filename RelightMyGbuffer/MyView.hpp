#pragma once

#include <tygra/WindowViewDelegate.hpp>
#include <tgl/tgl.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class MyView : public tygra::WindowViewDelegate
{
public:
	
    MyView();
	
    ~MyView();

private:

    void
    windowViewWillStart(std::shared_ptr<tygra::Window> window);
	
    void
    windowViewDidReset(std::shared_ptr<tygra::Window> window,
                       int width,
                       int height);

    void
    windowViewDidStop(std::shared_ptr<tygra::Window> window);
    
    void
    windowViewRender(std::shared_ptr<tygra::Window> window);

    GLuint global_light_prog_;
	GLuint point_light_prog_;
    GLuint background_prog_;

    struct Mesh
    {
        GLuint vertex_vbo;
        GLuint element_vbo;
        GLuint vao;
        int element_count;

        Mesh() : vertex_vbo(0),
                 element_vbo(0),
                 vao(0),
                 element_count(0) {}
    };

    Mesh light_quad_mesh_; // vertex array of vec2 position
    Mesh light_sphere_mesh_; // element array into vec3 position

    GLuint gbuffer_position_tex_;
    GLuint gbuffer_normal_tex_;
    GLuint gbuffer_depth_tex_;

    GLuint lbuffer_fbo_;
    GLuint lbuffer_colour_rbo_;

    struct DirectionalLight
    {
        glm::vec3 light_direction;
        float light_intensity;
    };

    std::vector<DirectionalLight> directionalLights;
    GLuint bufferGlobalLights;

    float varying_time = 0; // not sure where to grab time from, so just incrementing a number in render

    void CreateBuffer(GLuint shaderProgram_, GLuint &bufferID_, unsigned int bufferChannel_, std::string shaderBufferName_, unsigned int bufferSize_);
    void SetBuffer(glm::vec3 ambient_, std::vector<DirectionalLight> lights_);

    /*
     * Tutorial: All of the resources you'll need are already defined.
     *           You should not need to add further member variables.
     */

};
