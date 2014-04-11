#version 130

uniform mat4 u_camMatrix;
uniform vec4 u_lightPos;
uniform mat4 u_modelMatrix;
uniform mat4 u_projMatrix;

in vec4 vs_position;
in vec3 vs_color;
in vec4 vs_normal;

out vec3 fs_color;
out vec3 fs_light;
out vec3 fs_normal;

void main() { 
    fs_color = vs_color;
	fs_normal = normalize((u_camMatrix * u_modelMatrix * vs_normal).xyz);
	fs_light = normalize(((u_camMatrix * u_lightPos) - (u_camMatrix * u_modelMatrix * vs_position)).xyz);
	//fs_light = max(dot(fs_normal, L), 0.0);
	//fs_color = normalize((u_camMatrix * u_modelMatrix * vs_normal).xyz);
	//fs_color = (u_projMatrix * u_modelMatrix * vs_position).xyz;
	//fs_color = (u_modelMatrix * vs_position).xyz;
    
    gl_Position = u_projMatrix * u_camMatrix * u_modelMatrix * vs_position;
}