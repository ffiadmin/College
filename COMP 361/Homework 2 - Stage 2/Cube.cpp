/* 
 Author: Oliver Spryn and Course Textbook
 Course: COMP 361, Computer Graphics 
 Date:   February 12, 2014 
 Description: This is a wrapper class for generating a Cube in OpenGL with basic functionality. 
*/

#include "Cube.h"

Cube::Cube() : 
	alpha(cubeNS::BKG_ALPHA), blue(cubeNS::BKG_BLUE), fragmentFile(""),
	green(cubeNS::BKG_GREEN), red(cubeNS::BKG_RED), vertexFile("") {
		eye = cubeNS::EYE;
		height = width = 0;
		reset(false);
}

Cube::~Cube() {
	destroy();
}

void Cube::applyColor(Side side, Colors color) {
	if (side != ALL) {
		cSides[side] = color;
	} else {
		cSides[0] = color;
		cSides[1] = color;
		cSides[2] = color;
		cSides[3] = color;
		cSides[4] = color;
		cSides[5] = color;
	}

//Update the buffer
	genCube();
	glBufferSubData(GL_ARRAY_BUFFER, cubeNS::TOTAL * sizeof(glm::vec4), cubeNS::TOTAL * sizeof(glm::vec3), colors);
}

void Cube::applyEye(Axis axis, float position) {
	eye[axis] = position;
	placeCamera();
}

void Cube::applyRotation(Axis axis, float degrees) {
	rotation[axis] = degrees;
}

void Cube::applyScale(Axis axis, float factor) {
	scale[axis] = factor;
}

void Cube::applyTranslation(float x, float y, float z) {
	translate[0] = x;
	translate[1] = y;
	translate[2] = z;
}

void Cube::begin() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Cube::buildBuffer() {
//Generate the cube coordinate points and colors
	genCube();

//Create the buffer
	glGenBuffers(1, &buffer);

//Bind the buffers to their respective data values
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, cubeNS::TOTAL * (sizeof(glm::vec4) + sizeof(glm::vec3)), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, cubeNS::TOTAL * sizeof(glm::vec4), points);
	glBufferSubData(GL_ARRAY_BUFFER, cubeNS::TOTAL * sizeof(glm::vec4), cubeNS::TOTAL * sizeof(glm::vec3), colors);

//Extract the position from the shader
	GLuint vPosition = glGetAttribLocation(shaderProgram, cubeNS::SHD_LOCATION);
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

//Extract the color from the shader
	GLuint vColor = glGetAttribLocation(shaderProgram, cubeNS::SHD_COLOR);
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points)));
}

void Cube::buildShader() throw(Missing_Shader) {
//OpenGL initialization
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(red, blue, green, alpha);
	glClearDepth(1.0);

//Initialize the shaders
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	shaderProgram = glCreateProgram();

//Load the shaders
	if (fragmentFile[0] == '\0' || vertexFile[0] == '\0') {
		throw Missing_Shader();
	}

	const char* fragmentSource = textFileRead(fragmentFile);
	const char* vertexSource = textFileRead(vertexFile);

//Generate and compile the loaded shader
	glShaderSource(vertexShader, 1, &vertexSource, 0);
	glShaderSource(fragmentShader, 1, &fragmentSource, 0);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

//Attach the compiled shader to this program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

//Extract variables from the shader program
	location = glGetAttribLocation(shaderProgram, cubeNS::SHD_LOCATION);
	modelMatrix = glGetUniformLocation(shaderProgram, cubeNS::SHD_MDL_MTX);
	projectionMatrix = glGetUniformLocation(shaderProgram, cubeNS::SHD_PROJ_MTX);

//Apply the shader
	glUseProgram(shaderProgram);
}

glm::mat4 Cube::calcCamera() {
	glm::vec3 center = glm::vec3(0, 0, 0);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

//Pulled from glm::lookAt
	glm::vec3 z = glm::normalize(center - eye);
	glm::vec3 x = glm::normalize(glm::cross(z, up));
	glm::vec3 y = glm::cross(x, z);

	glm::mat4 look = glm::mat4(1.0f);
	look[0][0] = x.x;
	look[1][0] = x.y;
	look[2][0] = x.z;
	look[0][1] = y.x;
	look[1][1] = y.y;
	look[2][1] = y.z;
	look[0][2] = -z.x;
	look[1][2] = -z.y;
	look[2][2] = -z.z;
	look[3][0] = -glm::dot(x, eye);
	look[3][1] = -glm::dot(y, eye);
	look[3][2] = glm::dot(z, eye);

	return look;
}

void Cube::destroy() {
//Detach the shader from the program
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);

//Delete all program resources
	glDeleteBuffers(1, &buffer);
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
}

void Cube::end() {
	glFlush();
}

void Cube::genCube() {
	int index = 0;

	quad(index, cSides[0], 1, 0, 3, 2); //SOUTH
	quad(index, cSides[1], 2, 3, 7, 6); //EAST
	quad(index, cSides[2], 3, 0, 4, 7); //DOWN
	quad(index, cSides[3], 6, 5, 1, 2); //UP
	quad(index, cSides[4], 4, 5, 6, 7); //NORTH
	quad(index, cSides[5], 5, 4, 0, 1); //WEST
}

float Cube::getEye(Axis axis) {
	return eye[axis];
}

void Cube::loadFragmentShader(const char* file) {
	fragmentFile = const_cast<char*>(file);
}

void Cube::loadVertexShader(const char* file) {
	vertexFile = const_cast<char*>(file);
}

void Cube::placeCamera() {
	if (height > 0 && width > 0) {
		placeCamera(width, height);
	}
}

void Cube::placeCamera(int width, int height) {
	this->height = height;
	this->width = width;

	glViewport(0, 0, width, height);

//Define the camera projection matrix
	glm::mat4 projection = glm::perspective(90.0f, static_cast<float>(width) / static_cast<float>(height), 0.1f, 100.0f);
	glm::mat4 camera = glm::lookAt(eye, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 stuff = calcCamera();
	projection = projection * camera;
	
//Do magic???
	glUniformMatrix4fv(projectionMatrix, 1, GL_FALSE, &projection[0][0]);
}

void Cube::present() {
//Generate an identity matrix
	glm::mat4 identityMatrix = glm::mat4(1.0f);

//Apply (if needed) any rotations
	identityMatrix = glm::rotate(identityMatrix, rotation[0], glm::vec3(1, 0, 0));
	identityMatrix = glm::rotate(identityMatrix, rotation[1], glm::vec3(0, 1, 0));
	identityMatrix = glm::rotate(identityMatrix, rotation[2], glm::vec3(0, 0, 1));

//Apply (if needed) any translation
	identityMatrix = glm::translate(identityMatrix, glm::vec3(translate[0], translate[1], translate[2]));

//Apply (if needed) any scaling
	identityMatrix = glm::scale(identityMatrix, glm::vec3(scale[0], scale[1], scale[2]));

//Render the cube (whew, at last)!
	glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, &identityMatrix[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, cubeNS::TOTAL);

//Reset all the things!
	reset(true);

//Drink lemonade
	//http://www.foodnetwork.com/recipes/paula-deen/lemonade-recipe.html
}

void Cube::quad(int &index, int color, int a, int b, int c, int d) {
	colors[index] = cubeNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[a];
	index++;

	colors[index] = cubeNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[b];
	index++;

	colors[index] = cubeNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[c];
	index++;

	colors[index] = cubeNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[a];
	index++;

	colors[index] = cubeNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[c];
	index++;

	colors[index] = cubeNS::COLORS[color];
	points[index] = cubeNS::VERTICIES[d];
	index++;
}

void Cube::reset(bool bufferReady) {
	cSides[0] = cubeNS::DEF_COLORS[0];
	cSides[1] = cubeNS::DEF_COLORS[1];
	cSides[2] = cubeNS::DEF_COLORS[2];
	cSides[3] = cubeNS::DEF_COLORS[3];
	cSides[4] = cubeNS::DEF_COLORS[4];
	cSides[5] = cubeNS::DEF_COLORS[5];

	rotation[0] = 0.0f;
	rotation[1] = 0.0f;
	rotation[2] = 0.0f;

	scale[0] = 1.0f;
	scale[1] = 1.0f;
	scale[2] = 1.0f;

	translate[0] = 0.0f;
	translate[1] = 0.0f;
	translate[2] = 0.0f;

	if (bufferReady) {
		genCube();
		glBufferSubData(GL_ARRAY_BUFFER, cubeNS::TOTAL * sizeof(glm::vec4), cubeNS::TOTAL * sizeof(glm::vec3), colors);
	}
}

//from swiftless.com
char* Cube::textFileRead(const char* fileName) {
    char* text;
    
    if (fileName != NULL) {
        FILE *file = fopen(fileName, "rt");
        
        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            int count = ftell(file);
            rewind(file);
            
            if (count > 0) {
                text = (char*)malloc(sizeof(char) * (count + 1));  // No free() !?!?!?!?!
                count = fread(text, sizeof(char), count, file);
                text[count] = '\0';	//cap off the string with a terminal symbol, fixed by Cory
            }
            fclose(file);
        }
    }
    return text;
}