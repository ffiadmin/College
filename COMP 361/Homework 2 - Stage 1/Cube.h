/* 
 Author: Oliver Spryn and Course Textbook
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This is a wrapper class for generating a Cube in OpenGL with basic functionality. 
*/

#pragma once
#define _USE_MATH_DEFINES
#define GLEW_STATIC
#define BUFFER_OFFSET(bytes) ((GLvoid*)(bytes))

#include <cmath>
#include <cstdio>
#include <exception>
#include <malloc.h>

#include "glew.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

using std::exception;

enum Axis { X, Y, Z };
enum Colors { BLACK, RED, YELLOW, GREEN, BLUE, MAGENTA, WHITE, CYAN };
enum Side { SOUTH, EAST, DOWN, UP, NORTH, WEST, ALL };

namespace cubeNS {
//Background colors
	const float     BKG_ALPHA      = 1.0f;
	const float     BKG_BLUE       = 0.0f;
	const float     BKG_GREEN      = 0.0f;
	const float     BKG_RED        = 0.0f;

//Shader variables
	const char      SHD_COLOR[]    = "vs_color";
	const char      SHD_LOCATION[] = "vs_position";
	const char      SHD_MDL_MTX[]  = "u_modelMatrix";
	const char      SHD_PROJ_MTX[] = "u_projMatrix";

//Cube setup
	const glm::vec3 COLORS[8]      = {
		glm::vec3( 0.0, 0.0, 0.0 ), // BLACK
		glm::vec3( 1.0, 0.0, 0.0 ), // RED
		glm::vec3( 1.0, 1.0, 0.0 ), // YELLOW
		glm::vec3( 0.0, 1.0, 0.0 ), // GREEN
		glm::vec3( 0.0, 0.0, 1.0 ), // BLUE
		glm::vec3( 1.0, 0.0, 1.0 ), // MAGENTA
		glm::vec3( 1.0, 1.0, 1.0 ), // WHITE
		glm::vec3( 0.0, 1.0, 1.0 )  // CYAN
	};

	const int       DEF_COLORS[6]  = {
		RED, GREEN, BLUE, MAGENTA, YELLOW, CYAN
	};

	const int       TOTAL          = 36;

	const glm::vec4 VERTICIES[8]   = {
		glm::vec4( -1.0, -1.0,  1.0, 1.0 ),
		glm::vec4( -1.0,  1.0,  1.0, 1.0 ),
		glm::vec4(  1.0,  1.0,  1.0, 1.0 ),
		glm::vec4(  1.0, -1.0,  1.0, 1.0 ),
		glm::vec4( -1.0, -1.0, -1.0, 1.0 ),
		glm::vec4( -1.0,  1.0, -1.0, 1.0 ),
		glm::vec4(  1.0,  1.0, -1.0, 1.0 ),
		glm::vec4(  1.0, -1.0, -1.0, 1.0 )
	};
}

class Missing_Shader : public exception {
	
};

class Cube {
public : 
	Cube();
	~Cube();

//Public interface for cube manipulation
	void applyColor(Side side, Colors color);
	void applyRotation(Axis axis, float rotation = 0.0f);
	void applyScale(Axis axis, float factor = 1.0f);
	void applyTranslation(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	
//Public interface for cube memory management and display
	void begin();
	void buildBuffer();
	void buildShader() throw(Missing_Shader);
	void end();
	void loadFragmentShader(const char* file);
	void loadVertexShader(const char* file);
	void placeCamera(int width, int height);
	void present();
	void setBkgRGBA(float red = cubeNS::BKG_RED, float green = cubeNS::BKG_GREEN, float blue = cubeNS::BKG_BLUE, float alpha = cubeNS::BKG_ALPHA);

private : 
//Background colors
	float alpha;
	float blue;
	float green;
	float red;

//Buffer and shader references
	unsigned int buffer;
	unsigned int bufferN;
	char* fragmentFile;
	unsigned int fragmentShader;
	unsigned int shaderProgram;
	char* vertexFile;
	unsigned int vertexShader;

//Shader variables
	unsigned int location;
	unsigned int modelMatrix;
	unsigned int projectionMatrix;

//Cube data
	int cSides[6];
	glm::vec3 colors[cubeNS::TOTAL];
	glm::vec4 points[cubeNS::TOTAL];
	float rotation[3];
	float scale[3];
	float translate[3];

	void destroy();
	void genCube();
	void quad(int &index, int color, int a, int b, int c, int d);
	void reset(bool bufferReady);
	char* textFileRead(const char* fileName);
};