/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The base class for all renderable objects. 
*/

#include "Geometry.h"

Geometry::Geometry(Shader *shader) : shader(shader) { }

Geometry::~Geometry() {
	glDeleteBuffers(1, &buffer);
}

void Geometry::begin() const {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Geometry::buildBuffer(int total, glm::vec3 colors[], glm::vec4 normals[], glm::vec4 verticies[]) {
//Create the buffers
	glGenBuffers(1, &buffer);

//Bind the buffers to their respective data values
	size_t szColors = total * sizeof(glm::vec3);
	size_t szIndices = total * sizeof(glm::vec4);
	size_t szNormals = total * sizeof(glm::vec4);
	size_t szVertices = total * sizeof(glm::vec4);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, szColors + szNormals + szVertices, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, szVertices, verticies);
	glBufferSubData(GL_ARRAY_BUFFER, szVertices, szColors, colors);
	glBufferSubData(GL_ARRAY_BUFFER, szColors + szVertices, szNormals, normals);

//Extract the position from the shader
	GLuint vPosition = glGetAttribLocation(shader->shaderProgram, shaderNS::SHD_LOCATION);
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

//Extract the color from the shader
	GLuint vColor = glGetAttribLocation(shader->shaderProgram, shaderNS::SHD_COLOR);
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(szVertices));

//Extract the normals from the shader
	GLuint vNorm = glGetAttribLocation(shader->shaderProgram, shaderNS::SHD_NORM);
	glEnableVertexAttribArray(vNorm);
	glVertexAttribPointer(vNorm, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(szColors + szVertices));
}

void Geometry::end() const {
	glFlush();
}

glm::vec3 Geometry::getRotation() const {
	return rotation;
}

float Geometry::getRotation(Axis axis) const {
	if (axis == X || axis == Y || axis == Z) {
		return rotation[axis];
	}

	return -1.0f;
}

glm::vec3 Geometry::getScale() const {
	return scale;
}

float Geometry::getScale(Axis axis) const {
	if (axis == X || axis == Y || axis == Z) {
		return scale[axis];
	}

	return -1.0f;
}

glm::vec3 Geometry::getTranslation() const {
	return translate;
}

float Geometry::getTranslation(Axis axis) const {
	if (axis == X || axis == Y || axis == Z) {
		return translate[axis];
	}

	return -1.0f;
}

void Geometry::masterDraw() {
//Generate an identity matrix
	glm::mat4 identityMatrix = glm::mat4(1.0f);

//Apply (if needed) any rotations
	identityMatrix = glm::rotate(identityMatrix, rotation[0], glm::vec3(1, 0, 0));
	identityMatrix = glm::rotate(identityMatrix, rotation[1], glm::vec3(0, 1, 0));
	identityMatrix = glm::rotate(identityMatrix, rotation[2], glm::vec3(0, 0, 1));

//Apply (if needed) any translation
	identityMatrix = glm::translate(identityMatrix, translate);

//Apply (if needed) any scaling
	identityMatrix = glm::scale(identityMatrix, scale);

//Render the object (whew, at last)!
	glUniformMatrix4fv(shader->modelMatrix, 1, GL_FALSE, &identityMatrix[0][0]);
}

void Geometry::masterReset(bool bufferReady) {
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
		buildGeometry();
	}
}

void Geometry::setRotation(const glm::vec3 rotation) {
	this->rotation = rotation;
}

void Geometry::setRotation(const Axis axis, const float rotation) {
	if ((axis == X || axis == Y || axis == Z) && rotation >= 0.0f) {
		this->rotation[axis] = rotation;
	}
}

void Geometry::setScale(const glm::vec3 factor) {
	scale = factor;
}

void Geometry::setScale(const Axis axis, const float factor) {
	if ((axis == X || axis == Y || axis == Z) && factor >= 0.0f) {
		scale[axis] = factor;
	}
}

void Geometry::setTranslation(const glm::vec3 translation) {
	translate = translation;
}

void Geometry::setTranslation(const Axis axis, const float translation) {
	if ((axis == X || axis == Y || axis == Z) && translation >= 0.0f) {
		translate[axis] = translation;
	}
}