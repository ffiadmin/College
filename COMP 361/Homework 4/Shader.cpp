/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The base class for managing view matrices located in the shader. 
*/

#include "Shader.h"

Shader::Shader(const char *fragmentFile, const char *vertexFile) {
//OpenGL initialization
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(shaderNS::BKG_RED, shaderNS::BKG_BLUE, shaderNS::BKG_GREEN, shaderNS::BKG_ALPHA);
	glClearDepth(1.0);

//Initialize the shaders
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	shaderProgram = glCreateProgram();

//Load the shaders
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
	location = glGetAttribLocation(shaderProgram, shaderNS::SHD_LOCATION);
	modelMatrix = glGetUniformLocation(shaderProgram, shaderNS::SHD_MDL_MTX);
	projectionMatrix = glGetUniformLocation(shaderProgram, shaderNS::SHD_PROJ_MTX);

//Apply the shader
	glUseProgram(shaderProgram);
}

Shader::~Shader() {
//Detach the shader from the program
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);

//Delete all program resources
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
}

// From swiftless.com
char* Shader::textFileRead(const char* fileName) {
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