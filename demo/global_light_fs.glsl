#version 330

uniform sampler2DRect sampler_world_position;
uniform sampler2DRect sampler_world_normal;

uniform vec3 light_direction;
uniform float light_intensity = 0.15;

out vec3 reflected_light;

void main(void)
{
    ivec2 pixelCoord = ivec2(int(gl_FragCoord.x), int(gl_FragCoord.y));
    vec3 position = texelFetch(sampler_world_position, pixelCoord).xyz;
    vec3 normal = texelFetch(sampler_world_normal, pixelCoord).xyz;

    //reflected_light = vec3(1.0, 0.33, 0.0);
    reflected_light = normal;
}
