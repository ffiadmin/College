#version 130

//there are no rules about the prefixes but they do help
//keep track of things
uniform mat4 u_modelMatrix;
uniform mat4 u_camMatrix;
uniform mat4 u_projMatrix;
uniform vec4 u_lightPos;

in vec4 vs_position;
in vec3 vs_color;
in vec4 vs_normal;

out vec3 fs_color;
out vec3 fs_light;
out vec3 fs_normal;

void main() { 
	// Set the color and normal as just the input from the VBOs,
	// they only get interesting after they've been interpolated by the rasterizer
    fs_color = vs_color;
	fs_normal = normalize((u_camMatrix * u_modelMatrix * vs_normal).xyz);

	fs_light = normalize((u_lightPos - vs_position).xyz);
    
    //built-in things to pass down the pipeline
    gl_Position = u_projMatrix * u_camMatrix * u_modelMatrix * vs_position;
}