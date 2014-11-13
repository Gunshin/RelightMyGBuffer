#version 330

vec3 calculateColour(vec3 lightPos_, float lightRange_, vec3 fragPos_, vec3 fragNorm_, vec3 V_);

uniform sampler2DRect sampler_world_position;
uniform sampler2DRect sampler_world_normal;

uniform vec3 camPosition;
uniform vec3 light_position;
uniform float light_range;

out vec3 reflected_light;

void main(void)
{
    ivec2 pixelCoord = ivec2(gl_FragCoord.xy);
    vec3 position = texelFetch(sampler_world_position, pixelCoord).xyz;
    vec3 normal = texelFetch(sampler_world_normal, pixelCoord).xyz;

    vec3 V = normalize(camPosition - position);

    vec3 col = calculateColour(light_position, light_range, position, normal, V);

    reflected_light = col;
}

vec3 calculateColour(vec3 lightPos_, float lightRange_, vec3 fragPos_, vec3 fragNorm_, vec3 V_)
{
	
	vec3 L = normalize(lightPos_ - fragPos_);

	vec3 R = normalize(reflect(-L, fragNorm_));

	float distance = distance(fragPos_, lightPos_);

    vec3 attenuatedDistance = vec3(1.0, 1.0, 1.0) * smoothstep(lightRange_, 1, distance);

    vec3 attenuatedLight = attenuatedDistance;

	vec3 Id = max(dot(L, fragNorm_), 0) * attenuatedLight;

	/*vec3 Is = vec3(0, 0, 0);
	if(dot(L, vs_normal) > 0 && mat_.shininess > 0)
	{
		Is = vec3(1, 1, 1) * pow(max(0, dot(R, V_)), mat_.shininess) * attenuatedLight;
	}*/

	return Id;// + Is;
}