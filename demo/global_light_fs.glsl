#version 430

struct DirectionalLight
{
    vec3 light_direction;
    float light_intensity;
};

uniform sampler2DRect sampler_world_position;
uniform sampler2DRect sampler_world_normal;

layout(std140, binding = 0) buffer Lights
{
    vec3 ambient_light;
    float pack0;
    DirectionalLight directional_lights[];
};

out vec3 reflected_light;

vec3 AddDirectionalLight(vec3 direction_, float intensity_, vec3 normal_);

void main(void)
{
    ivec2 pixelCoord = ivec2(gl_FragCoord.xy);
    vec3 position = texelFetch(sampler_world_position, pixelCoord).xyz;
    vec3 normal = texelFetch(sampler_world_normal, pixelCoord).xyz;

    vec3 directionalLightColour = vec3(0, 0, 0);
    for(int i = 0; i < directional_lights.length(); ++i)
    {
        directionalLightColour += AddDirectionalLight(directional_lights[i].light_direction, directional_lights[i].light_intensity, normal);
    }

    reflected_light = ambient_light + directionalLightColour;
}

vec3 AddDirectionalLight(vec3 direction_, float intensity_, vec3 normal_)
{
    vec3 L = normalize(direction_);

    return vec3(1) * max(dot(L, normal_), 0) * intensity_;
}