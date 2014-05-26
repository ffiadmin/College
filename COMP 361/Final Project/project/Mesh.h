#pragma once
#include "Geometry.h"
#include "Face.h"
class Mesh : public Geometry
{
public: 
	Mesh(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate);
    Mesh();
	~Mesh(void);
    void initialize(unsigned int shaderProgram, unsigned int u_modelMatrix);
    void draw(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate);
    void draw(mat4 Matrix, vec3 color);
	void setColor(vec3 color);
	virtual bool collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity);
protected:
	GLuint u_modelMatrix;
	GLuint shaderProgram;
	GLuint vertexBuffer;
	GLuint colorBuffer;
	GLuint normalBuffer;

	GLuint indexBuffer;
	GLuint vLocation;
	GLuint vColor;
	GLuint vNormal;

	vector<Face> faces;

	vector<vec4> vertices;
	vector<vec3> colors;
	vector<vec4> normals;
	vector<int> indices;
};

