#ifndef Utility_H
#define Utility_H

#define GLEW_STATIC
#include "glew.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"


glm::mat4 toMat(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate);

#endif //Utility_H