#pragma once

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <exception>
#include <vector>

#include "HalfEdgeDS.h"
#include "Geometry.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;
using glm::normalize;
using std::exception;
using std::ifstream;
using std::vector;

class HalfEdge : public Geometry {
// Constructors and destructor
public : 
	HalfEdge(vec3 scale, vec3 rotate, float rotAngle, vec3 translate);
	HalfEdge();
	~HalfEdge();

// Geometry Interface
public : 
	void initialize(unsigned int shaderProgram, unsigned int u_modelMatrix);
    void BuildBuffers();
	glm::vec4 centroid(HEFace* face);
	void draw(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate);
    void draw(mat4 Matrix, vec3 color);
	void setColor(vec3 color);
	bool collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity);
	virtual void subDivide(int iters = 1);

private:
	GLuint u_modelMatrix;
	GLuint shaderProgram;
	GLuint vertexBuffer;
	GLuint colorBuffer;
	GLuint normalBuffer;

	GLuint indexBuffer;
	GLuint vLocation;
	GLuint vColor;
	GLuint vNormal;

	vector<vec4> vertexBuf;
	vector<vec3> colorBuf;
	vector<vec4> normalBuf;
	vector<unsigned int> indexBuf;

protected:
	vector<HEVertex*> verts;
	vector<HEEdge*> edges;
	vector<HEFace*> faces;
	int addHEVert(HEVertex* v);
	int addHEFace(HEFace* f);
	int addHEEdge(HEEdge* e);
	int vID;
	int fID;
	int eID;

};