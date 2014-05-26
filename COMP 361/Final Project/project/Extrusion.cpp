#include "Extrusion.h"


Extrusion::Extrusion(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate)
{
	Mesh::Mesh(Scale, Rotate, RotAngle, Translate);
}


Extrusion::~Extrusion(void)
{
}
void Extrusion::import(ifstream& reader)
{
	faces.clear();
	height = 0;
	
	reader >> height;
	unsigned int count;
	reader >> count;


	Face face;
	float x1, z1;
	for(unsigned int i = 0; i < count; i++) {
		float x, z;
		reader >> x >> z;
		face.addVertex(vec4(x, 0, z, 1));
	}
	if(face.isConvex())
	{
		vector<Face> newFaces = face.triangulate();
		if(newFaces.size()>0)
		{
			faces.insert(faces.end(), newFaces.begin(), newFaces.end());
		}
	}

	vector<Face> extrudedFaces = extrude(face);
	if(extrudedFaces.size()>0)
	{
		faces.insert(faces.end(), extrudedFaces.begin(), extrudedFaces.end());
	}	
}
vector<Face> Extrusion::extrude(Face polygon)
{
	vector<vec4> points = polygon.getVertices();
	vector<Face> faces;
	if(polygon.isConvex())
	{
		Face topFace;
		for(int i = points.size()-1; i > 0; --i)
		{
			topFace.addVertex(points[i] + vec4(0, height, 0, 0));	
		}
		faces.push_back(topFace);
	}

	for(int i = 0; i < points.size(); ++i)
	{
		Face face;
		face.addVertex(points[i] + vec4(0, height, 0, 0));
		face.addVertex(points[i]);
		face.addVertex(points[(i+1)%points.size()]);
		face.addVertex(points[(i+1)%points.size()] + vec4(0, height, 0, 0));
		faces.push_back(face);
	}
	vector<Face> retFaces;
	for(int w=0; w<faces.size(); ++w)
	{
		vector<Face> triFaces = faces[w].triangulate();
		retFaces.insert(retFaces.end(), triFaces.begin(), triFaces.end());
	}
	return retFaces;
}

bool Extrusion::collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity)
{
	return false;
}
