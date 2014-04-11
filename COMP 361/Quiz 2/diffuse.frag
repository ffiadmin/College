#version 130 

in vec3 fs_color;
in vec3 fs_light;
in vec3 fs_normal;

out vec4 out_Color;

void main() {
    vec3 ambientContrib = fs_color * 0.1;
	vec4 diffuseColor = vec4(fs_color, 1.0);

	float diffuseTerm = clamp(dot(fs_normal, fs_light), 0.0, 1.0);

    out_Color = diffuseTerm * diffuseColor + ambientContrib;
}