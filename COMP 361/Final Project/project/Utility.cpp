#include "Utility.h"

glm::mat4 toMat(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate)
{
	//Start with identity matrix
	glm::mat4 Matrix = glm::mat4(1.0f);
	
	Matrix = glm::translate(Matrix, Translate);
	Matrix = glm::rotate(Matrix, RotAngle, Rotate);
	Matrix = glm::scale(Matrix, Scale);
	return Matrix;
}