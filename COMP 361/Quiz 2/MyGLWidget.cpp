#include "MyGLWidget.h"
#include "glm/gtc/matrix_transform.hpp"
#include <fstream>

using namespace std;
using namespace glm;

void MyGLWidget::loadFile(QString filename) {
	points.clear();

	ifstream reader(filename.toStdString());
	unsigned int count;
	reader >> count;

	for(unsigned int i = 0; i < count; i++) {
		float x, y, z;
		reader >> x >> y >> z;
		points.push_back(vec4(x, y, z, 1.0f));
	}

	//check for planarity
	if (points.size() > 0) {
		glm::vec4 norm = glm::normalize(points[0]);
		glm::vec4 T;
		isPlanar = true;
		
		for(int i = 1; i < points.size(); ++i) {
			T = points[0] - points[i];

			if (!glm::dot(T, norm)) {
				isPlanar = false;
				break;
			}
		}
	}

	fillBuffers();

	emit sendPlanarity(isPlanar);

	update();
}

void MyGLWidget::fillBuffers() {
	//you may wish to use a dynamically allocated array based on the contents of the "points" vector.
	
	if(isPlanar) {
		//buffer the data without using an index buffer

	//Offload the colors, normals, and vertices into the buffer
		int total = points.size();
		glm::vec3 *colors = new glm::vec3[total];
		glm::vec4 *normals = new glm::vec4[total];
		glm::vec4 *vertices = new glm::vec4[total];

		glm::vec3 current = glm::vec3(points[0].x, points[0].y, points[0].z);
		glm::vec3 next = glm::vec3(points[1].x, points[1].y, points[1].z);
		glm::vec3 previous = glm::vec3(points[2].x, points[2].y, points[2].z);
		glm::vec4 normal = -glm::vec4(glm::normalize(glm::cross(next - current, previous - current)), 1.0f);

		for(int i = 0; i < total; ++i) {
			colors[i] = glm::vec3(1.0f, 1.0f, 1.0f);
			normals[i] = normal;
			vertices[i] = glm::vec4(points[i]);
		}
	
	//Bind the buffers to their respective data values
		size_t szColors = total * sizeof(glm::vec3);
		size_t szNormals = total * sizeof(glm::vec4);
		size_t szVertices = total * sizeof(glm::vec4);

		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, szColors + szNormals + szVertices, NULL, GL_STATIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, szVertices, vertices);
		glBufferSubData(GL_ARRAY_BUFFER, szVertices, szColors, colors);
		glBufferSubData(GL_ARRAY_BUFFER, szColors + szVertices, szNormals, normals);

	//Extract the position from the shader
		GLuint vPosition = glGetAttribLocation(shaderProgram, "vs_position");
		glEnableVertexAttribArray(vPosition);
		glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	//Extract the color from the shader
		GLuint vColor = glGetAttribLocation(shaderProgram, "vs_color");
		glEnableVertexAttribArray(vColor);
		glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(szVertices));

	//Extract the normals from the shader
		GLuint vNorm = glGetAttribLocation(shaderProgram, "vs_normal");
		glEnableVertexAttribArray(vNorm);
		glVertexAttribPointer(vNorm, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(szColors + szVertices));
	}
	else {
		//buffer the data and create an index buffer, you'll spit the polygon into triangles.  Remember to make face normals!
		glm::vec4 start = points[0];
		int total = points.size();
		vector<glm::vec4> emergency;

	//Triangulate
		for(int i = 1; i < total - 1; ++i) {
			emergency.push_back(start);
			emergency.push_back(points[i]);
			emergency.push_back(points[i + 1]);
		}

	//Build the vertex buffer
		/*int totalE = emergency.size();
		localPts = new glm::vec4[totalE];

		for(int i = 0; i < totalE; ++i) {
			localPts[i] = glm::vec4(emergency[i]);
		}

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, totalE * sizeof(glm::vec4), localPts, GL_STATIC_DRAW);*/
	}
}

void MyGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Start with identity matrix
	glm::mat4 modelMatrix(1.0f);

	glm::mat4 camera = glm::lookAt(glm::vec3(camPos.x, camPos.y, camPos.z), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(camUp.x, camUp.y, camUp.z));

	glm::vec4 light = camera * lightPos;
	glUniform4fv(u_lightLocation, 1, &light[0]);

	if(isPlanar) {
		//use glDrawArrays and GL_POLYGON to draw all the points in one shot
		glDrawArrays(GL_POLYGON, 0, points.size());
	}
	else {
		//use glDrawElements and GL_TRIANGLES
	}
		
	glFlush();
}

///// Should NOT have to change from here down!  //////

MyGLWidget::MyGLWidget(QWidget* parent = 0) : QGLWidget(parent) {
	isPlanar = true;

	camDist = 10.0f;
	camTheta = 0.0f;
	camPsi = -30.0f;

	lightPos = glm::vec4(2.5f, 4.0f, 2.5f, 1.0f);
	updateCamera();
}

void MyGLWidget::updateCamera() {
	glm::mat4 rotX = glm::rotate(glm::mat4(1.0f), camPsi, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotY = glm::rotate(glm::mat4(1.0f), camTheta, glm::vec3(0.0f, 1.0f, 0.0f));
	
	camPos = rotY * rotX * glm::vec4(0.0f, 0.0f, camDist, 1.0f);
	camUp = rotY * rotX * glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
}

MyGLWidget::~MyGLWidget() {
	glDetachShader(shaderProgram, fragmentShader);
	glDetachShader(shaderProgram, vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteProgram(shaderProgram);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &cbo);
}

void MyGLWidget::initializeGL() {
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	//Do something similar to this to set up a buffer for colors
	//glGenBuffers(1, &vbo);
	//glGenBuffers(1, &cbo);
	//glGenBuffers(1, &nbo);
	//glGenBuffers(1, &ibo);
	
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	shaderProgram = glCreateProgram();

	const char* vertexSource = textFileRead("diffuse.vert");
	const char* fragmentSource = textFileRead("diffuse.frag");
	glShaderSource(vertexShader, 1, &vertexSource, 0);
	glShaderSource(fragmentShader, 1, &fragmentSource, 0);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	vLocation = glGetAttribLocation(shaderProgram, "vs_position");
	u_modelLocation = glGetUniformLocation(shaderProgram, "u_modelMatrix");
	u_projLocation = glGetUniformLocation(shaderProgram, "u_projMatrix");
	u_lightLocation = glGetUniformLocation(shaderProgram, "u_lightPos");

	glUseProgram(shaderProgram);
	/*
	//also want to get the location of "vs_color"
	vLocation = glGetAttribLocation(shaderProgram, "vs_position");
	cLocation = glGetAttribLocation(shaderProgram, "vs_color");
	nLocation = glGetAttribLocation(shaderProgram, "vs_normal");

	//Do something similar to this to get the location of "u_modelMatrix"
	u_projLocation = glGetUniformLocation(shaderProgram, "u_projMatrix");
	u_modelLocation = glGetUniformLocation(shaderProgram, "u_modelMatrix");
	u_lightLocation = glGetUniformLocation(shaderProgram, "u_lightPos");

	//set up attribute arrays and pointers
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(vLocation);
	glVertexAttribPointer(vLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	glEnableVertexAttribArray(cLocation);
	glVertexAttribPointer(cLocation, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glEnableVertexAttribArray(nLocation);
	glVertexAttribPointer(nLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);*/
}

void MyGLWidget::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);

	//Here's how to make matrices for transformations, check the documentation of GLM for rotation, scaling, and translation
	glm::mat4 projection = glm::perspective(60.0f, static_cast<float>(width) / static_cast<float>(height), 0.1f, 30.0f);
	
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

void MyGLWidget::orbitUp() {
	camPsi -= 5.0f;

	updateCamera();

	update();
}

void MyGLWidget::orbitDown() {
	camPsi += 5.0f;

	updateCamera();

	update();
}

void MyGLWidget::orbitLeft() {
	camTheta += 5.0f;

	updateCamera();

	update();
}

void MyGLWidget::orbitRight() {
	camTheta -= 5.0f;

	updateCamera();

	update();
}

void MyGLWidget::zoomIn() {
	camDist -= 0.5f;

	updateCamera();

	update();
}

void MyGLWidget::zoomOut() {
	camDist += 0.5f;

	updateCamera();

	update();
}