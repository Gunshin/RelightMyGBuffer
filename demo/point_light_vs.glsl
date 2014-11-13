#version 330

uniform mat4 model_xform;

in vec3 vertex_position;

void main(void)
{
    gl_Position = model_xform * vec4(vertex_position, 1.0);
}
