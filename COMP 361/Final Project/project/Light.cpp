#include "Light.h"
Geometry* Light::cube;

Light::Light(void)
{
}


Light::~Light(void)
{
}

void Light::initialize(unsigned int u_lightPos)
{
	this->u_lightPos = u_lightPos;
	setPosition(0, 0, 0);
}

void Light::setPosition(float x, float y, float z)
{
	position = glm::vec4(x, y, z, 1.0f);
	glUniform4fv(u_lightPos, 1, &position[0]);
}
void Light::addPosition(float x, float y, float z)
{
	position = position += glm::vec4(x, y, z, 0.0f);
	glUniform4fv(u_lightPos, 1, &position[0]);
}
void Light::draw()
{
	
	//cube->draw(glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, position.z)), glm::vec3(5,5,5));
}
void Light::setCube(Geometry* _cube)
{
	cube = _cube;
}