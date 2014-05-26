#version 130 

in vec3 fs_color;
in vec3 fs_light;
in vec3 fs_normal;
in vec3 fs_cam;

out vec4 out_Color;

void main() {
    vec3 ambientContrib = fs_color * 0.1;
	vec4 diffuseColor = vec4(fs_color, 1.0);
	vec4 specColor = vec4(1.0, 1.0, 1.0, 1.0); //White

	//TODO: complete this using the diffuse equation from class!
	float diffuseTerm = max(0.0, dot(fs_normal, fs_light));
	vec3 H = normalize(fs_light + fs_cam);
	float specTerm = pow(max(0.0, dot(fs_normal, H)), 5);
	//out_Color = diffuseColor;
	
	//TODO: replace above out_Color with below once the diffuse term works.
    out_Color = diffuseTerm * diffuseColor + ambientContrib + specTerm * specColor;
}