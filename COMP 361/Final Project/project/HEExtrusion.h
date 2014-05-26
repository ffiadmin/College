#pragma once
#include "halfedge.h"

using glm::vec4;
using glm::vec3;

class HEExtrusion :
	public HalfEdge
{
public:
	HEExtrusion(void);
	HEExtrusion(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate);
	~HEExtrusion(void);
	void extrude(VertLine polygon);
	int height;

// <oliver description="added triangulation">
private : 
	void triangulate();
// </oliver>
};