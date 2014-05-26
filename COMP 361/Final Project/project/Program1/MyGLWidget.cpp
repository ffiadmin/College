#include "MyGLWidget.h"
#include "../glm/gtc/matrix_transform.hpp"

MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent) {
}

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::initializeGL() {
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0);

	//Do something similar to this to set up a buffer for colors
	glGenBuffers(1, &vbo);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	shaderProgram = glCreateProgram();

	const char* vertexSource = textFileRead("color_xforms.vert");
	const char* fragmentSource = textFileRead("color_xforms.frag");
	glShaderSource(vertexShader, 1, &vertexSource, 0);
	glShaderSource(fragmentShader, 1, &fragmentSource, 0);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//also want to get the location of "vs_color"
	vLocation = glGetAttribLocation(shaderProgram, "vs_position");

	//Do something similar to this to get the location of "u_modelMatrix"
	u_projLocation = glGetUniformLocation(shaderProgram, "u_projMatrix");

	glUseProgram(shaderProgram);
}

void MyGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Start with identity matrix
	glm::mat4 modelMatrix = glm::mat4(1.0f);

	//Traverse your scene graph, remember the function to actually render something is as follows:
	//glDrawArrays(GL_POINTS, 0, 500000);
	//but you'll want to draw GL_QUADS for now
	glFlush();
}

//An example on how to use the buffer to get position
/*void MyGLWidget::generateGasket() {
	glm::vec2* points = new glm::vec2[500000];
	
	glm::vec2 vertices[3] = {glm::vec2(-1.0, -1.0), glm::vec2(0.0, 1.0), glm::vec2(1.0, -1.0)};
	points[0] = glm::vec2(0.25, 0.50);

	for(int i = 1; i < 500000; i++) {
		int k = rand() % 3;

		points[i] = glm::vec2((points[i-1].x + vertices[k].x) / 2.0, (points[i-1].y + vertices[k].y) / 2.0);
	}

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 500000 * sizeof(glm::vec2), points, GL_STATIC_DRAW);

	delete [] points;

	glEnableVertexAttribArray(vLocation);
	glVertexAttribPointer(vLocation, 2, GL_FLOAT, GL_FALSE, 0, 0);
}*/

void MyGLWidget::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);

	//Here's how to make matrices for transformations, check the documentation of GLM for rotation, scaling, and translation
	glm::mat4 projection = glm::perspective(90.0f, static_cast<float>(width) / static_cast<float>(height), 0.1f, 30.0f);
	glm::mat4 camera = glm::lookAt(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	//Can multiply matrices together, careful about ordering!
	projection = projection * camera;
	
	//Do something similar for u_modelMatrix before rendering things
	glUniformMatrix4fv(u_projLocation, 1, GL_FALSE, &projection[0][0]);
}

//from swiftless.com
char* MyGLWidget::textFileRead(const char* fileName) {
    char* text;
    
    if (fileName != NULL) {
        FILE *file = fopen(fileName, "rt");
        
        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            int count = ftell(file);
            rewind(file);
            
            if (count > 0) {
                text = (char*)malloc(sizeof(char) * (count + 1));
                count = fread(text, sizeof(char), count, file);
                text[count] = '\0';	//cap off the string with a terminal symbol, fixed by Cory
            }
            fclose(file);
        }
    }
    return text;
}