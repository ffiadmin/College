#pragma once
#define GLEW_STATIC
#include "glew.h"
#include "../glm/glm.hpp"
#include <stdlib.h>
#include "../glm/gtc/matrix_transform.hpp"
class Camera
{
public:
	Camera(void);
	~Camera(void);

	glm::mat4 projection;
	glm::mat4 camera;
	float radius;
	float latitude;
	float longitude;
	unsigned int u_projLocation;
	unsigned int u_camMatrix;
	int height, width;
	float FOV;
	glm::vec3 center;

	void initialize(unsigned int u_projectionLocation, unsigned int u_camMatrix, glm::vec3 myCenter, float radius);
	void rotateLeft();
	void rotateRight();
	void rotateUp();
	void rotateDown();
	void zoomIn();
	void zoomOut();
	void update();
	void setViewport(int width, int height);

};

