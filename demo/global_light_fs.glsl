#version 430

uniform sampler2DRect sampler_world_position;
uniform sampler2DRect sampler_world_normal;

uniform vec3 light_direction;
uniform float light_intensity = 0.15;

out vec3 reflected_light;

void main(void)
{
    ivec2 pixelCoord = ivec2(gl_FragCoord.xy);
    vec3 position = texelFetch(sampler_world_position, pixelCoord).xyz;
    vec3 normal = texelFetch(sampler_world_normal, pixelCoord).xyz;

    vec3 L = normalize(-light_direction);

    reflected_light = vec3(1) * max(dot(L, normal), 0) * light_intensity;
}