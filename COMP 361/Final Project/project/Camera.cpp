#include "Camera.h"
const double PI  =3.141592653589793238463;

Camera::Camera(void)
{
}


Camera::~Camera(void)
{
}

void Camera::initialize(unsigned int u_projectionLocation, unsigned int u_camMatrix, glm::vec3 myCenter, float radius)
{
	projection = glm::mat4(1.0f);
	this->radius = radius;
	FOV = 90.0f;
	height = 1;
	width = 1;
	center = myCenter;
	longitude = 0;
	latitude = PI/2;
	this->u_projLocation = u_projectionLocation;
	this->u_camMatrix = u_camMatrix;
	projection = glm::translate(projection, glm::vec3(0.0, 0.0, radius));
}
void Camera::rotateLeft()
{
	longitude -= PI/30;
	update();
}
void Camera::rotateRight()
{
	longitude += PI/30;
	update();
}
void Camera::rotateUp()
{
	latitude -= PI/30;
	if (latitude <= .01) {latitude =.01f;}
	update();
}
void Camera::rotateDown()
{
	latitude += PI/30;
	if (latitude >= .99f*PI) {latitude =.99f*PI;}
	update();
}
void Camera::zoomIn()
{
	FOV--;
	if (FOV <=0) {FOV = 1;}
	update();
}
void Camera::zoomOut()
{
	FOV++;
	if (FOV >=180) {FOV = 180;}
	update();
}
void Camera::update()
{
	//Here's how to make matrices for transformations, check the documentation of GLM for rotation, scaling, and translation

	float x=radius*sin(longitude)*sin(latitude);
	float y=radius*cos(latitude);
	float z=radius*cos(longitude)*sin(latitude);

	projection = glm::perspective(FOV, static_cast<float>(width) / static_cast<float>(height), 0.1f, 1000.0f);
	camera = glm::lookAt(glm::vec3(x, y, z) + center, center, glm::vec3(0.0f, 1.0f, 0.0f));
	
	//Do something similar for u_modelMatrix before rendering things
	glUniformMatrix4fv(u_projLocation, 1, GL_FALSE, &projection[0][0]);
	glUniformMatrix4fv(u_camMatrix, 1, GL_FALSE, &camera[0][0]);
}
void Camera::setViewport(int vpWidth, int vpHeight)
{
	height = vpHeight;
	width = vpWidth;
	update();
}