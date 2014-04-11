/* 
 Author: Oliver Spryn 
 Course: COMP 361, Computer Graphics 
 Date:   March 18, 2014 
 Description: The base geometry class. 
*/

#pragma once
#define BUFFER_OFFSET(bytes) ((GLvoid*)(bytes))

#include "Camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"

using std::size_t;

namespace geometryNS {
	const glm::vec3 COLORS[8] = {
		glm::vec3( 0.0, 0.0, 0.0 ), // BLACK
		glm::vec3( 1.0, 0.0, 0.0 ), // RED
		glm::vec3( 1.0, 1.0, 0.0 ), // YELLOW
		glm::vec3( 0.0, 1.0, 0.0 ), // GREEN
		glm::vec3( 0.0, 0.0, 1.0 ), // BLUE
		glm::vec3( 1.0, 0.0, 1.0 ), // MAGENTA
		glm::vec3( 1.0, 1.0, 1.0 ), // WHITE
		glm::vec3( 0.0, 1.0, 1.0 )  // CYAN
	};
}

enum Colors { BLACK, RED, YELLOW, GREEN, BLUE, MAGENTA, WHITE, CYAN };

class Geometry {
public : 
	Geometry(Shader *shader);
	~Geometry();

//Getter and setters
	glm::vec3 getRotation() const;
	float getRotation(const Axis axis) const;
	glm::vec3 getScale() const;
	float getScale(const Axis axis) const;
	glm::vec3 getTranslation() const;
	float getTranslation(const Axis axis) const;

	void setRotation(const glm::vec3 rotation);
	void setRotation(const Axis axis, const float rotation);
	void setScale(const glm::vec3 factor);
	void setScale(const Axis axis, const float factor);
	void setTranslation(const glm::vec3 translation);
	void setTranslation(const Axis axis, const float translation);

//Public interface for geometry display
	virtual void begin() const;
	virtual void draw() = 0;
	virtual void end() const;

protected : 
	unsigned int buffer;
	Shader *shader;

//Geometry manipulation
	glm::vec3 rotation;
	glm::vec3 scale;
	glm::vec3 translate;

	virtual void Geometry::buildBuffer(int total, glm::vec3 colors[], glm::vec4 normals[], glm::vec4 verticies[]);
	virtual void buildGeometry() = 0;
	void masterDraw();
	void masterReset(bool bufferLoaded);
	virtual void reset(bool bufferReady) = 0;
};