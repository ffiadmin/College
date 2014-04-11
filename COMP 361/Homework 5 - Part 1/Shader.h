/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The base class for managing view matrices located in the shader. 
*/

#pragma once
#define GLEW_STATIC

#include <cstdio>
#include <cstdlib>
#include "glew.h"

namespace shaderNS {
//Background colors
	const float     BKG_ALPHA      = 1.0f;
	const float     BKG_BLUE       = 0.0f;
	const float     BKG_GREEN      = 0.0f;
	const float     BKG_RED        = 0.0f;

//Shader variables
	const char      SHD_COLOR[]    = "vs_color";
	const char      SHD_LOCATION[] = "vs_position";
	const char      SHD_MDL_MTX[]  = "u_modelMatrix";
	const char      SHD_NORM[]     = "vs_normal";
	const char      SHD_PROJ_MTX[] = "u_projMatrix";
};

class Shader {
public : 
	Shader(const char *fragmentFile, const char *vertexFile);
	~Shader();

//Shader references
	unsigned int fragmentShader;
	unsigned int shaderProgram;
	unsigned int vertexShader;

//Location matricies
	unsigned int location;
	unsigned int modelMatrix;
	unsigned int projectionMatrix;

private : 
	char* textFileRead(const char* fileName);
};