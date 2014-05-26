#include "Face.h"


Face::Face(void)
{
}


Face::~Face(void)
{
}

void Face::addVertex(vec4 pos) //simplify this have a face color and face normal, not per vert.
{
	//Vertices must be added in counter-clockwise order
	points.push_back(pos);
	colors.push_back(vec3(1, 0, 0)); //default Red
	normals.push_back(vec4(0, 1, 0, 0)); //default up. will get calculated later.
}
bool Face::isConvex()
{
	vec4 n1 = points[1]-points[0];
	vec4 n2 = points[points.size()-1] - points[0];
	vec3 n = glm::cross(vec3(n1.x, n1.y, n1.z), vec3(n2.x, n2.y, n2.z));
	n = glm::normalize(n);

	for(int i=0; i< points.size(); ++i)
	{
		vec4 t1 = points[(i+1)%points.size()]-points[i];
		vec4 t2 = points[(i-1)%points.size()] - points[i];
		vec3 t = glm::cross(vec3(t1.x, t1.y, t1.z), vec3(t2.x, t2.y, t2.z));
		t = glm::normalize(t);

		if (t==-n)
		{
			return false;
		}
	}
	return true;
}
int Face::size()
{
	return points.size();
}
vector<vec4> Face::getVertices()
{
	return points;
}
vector<vec3> Face::getColors()
{
	return colors;
}
void Face::setColors(vec3 color)
{
	for (int i=0; i < colors.size(); ++i)
	{
		colors[i] = color;
	}
}
vector<vec4> Face::getNormals()
{
	return normals;
}
void Face::setNormals(vec4 normal)
{
	for (int i=0; i < normals.size(); ++i)
	{
		normals[i] = normal;
	}
}
vector<int> Face::getIndices(int startIndex)
{
	vector<int> indices;
	if(points.size() == 3)
	{
		indices.push_back(startIndex);
		indices.push_back(startIndex + 1);
		indices.push_back(startIndex + 2);
		return indices;
	}

	if(isConvex() && points.size() > 3)
	{
		for(int i=0; i<points.size()-2; ++i)
		{
			indices.push_back(startIndex);
			indices.push_back(startIndex + i + 1);
			indices.push_back(startIndex + i + 2);
		}
	}
	return indices;
}
vector<Face> Face::triangulate()
{
	vector<Face> faces;
	if(isConvex() && points.size() >= 3)
	{
		for(int i=0; i<points.size()-2; ++i)
		{
			Face face;
			face.addVertex(points[0]);
			face.addVertex(points[i + 1]);
			face.addVertex(points[i + 2]);

			//set Colors
			vec3 avgColor = colors[0] + colors[i + 1]+ colors[i + 2];
			avgColor /= 3;
			face.setColors(avgColor);
			
			//set Normals
			vec4 v0 = points[0];
			vec4 v0_v1 = points[i + 1] - points[0];
			vec4 v0_v2 = points[i + 2] - points[0];
			vec3 v0_normal = glm::cross(vec3(v0_v1.x, v0_v1.y, v0_v1.z), vec3(v0_v2.x, v0_v2.y, v0_v2.z));
			vec4 norm = vec4(glm::normalize(v0_normal), 0);
			face.setNormals(norm);

			faces.push_back(face);
		}
	}
	return faces;
}

// <oliver description="function to compute the winding order">
/*
void Face::wind() {
//Already wound
	if (points.size() <= 1) return;

	vector<vec4> 
}
*/
// </oliver>