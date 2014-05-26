#include "SurfRev.h"


SurfRev::SurfRev(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate)
{
	Mesh::Mesh(Scale, Rotate, RotAngle, Translate);
}


SurfRev::~SurfRev(void)
{
}

void SurfRev::import(ifstream& reader)
{
	faces.clear();
	slices = 0;
	
	reader >> slices;
	unsigned int count;
	reader >> count;


	Face face;
	for(unsigned int i = 0; i < count; i++) {
		float x, y;
		reader >> x >> y;

		if(i == 0 && x != 0.0f)
		{
			face.addVertex(vec4(0, y, 0, 1));
		}

		face.addVertex(vec4(x, y, 0, 1));

		if(i == count-1 && x != 0.0f)
		{
			face.addVertex(vec4(0, y, 0, 1));
		}
	}
	//vector<Face> newFaces = face.triangulate();
	//if(newFaces.size()>0)
	//{
	//	faces.insert(faces.end(), newFaces.begin(), newFaces.end());
	//}

	vector<Face> rotatedFaces = rotate(face);
	if(rotatedFaces.size()>0)
	{
		faces.insert(faces.end(), rotatedFaces.begin(), rotatedFaces.end());
	}	
}
vector<Face> SurfRev::rotate(Face polygon)
{
	vector<Face> faces;

	vector<vec4> points = polygon.getVertices();
	vector<vec4> pointSlice;
	mat4 rotMat = mat4(1.0f);
	for (int n = 0; n < slices; ++n)
	{
		rotMat = glm::rotate(rotMat, 360.0f/slices, vec3(0,1,0));
		vector<vec4> pointSlice = polygon.getVertices();
		for(int x=0; x<pointSlice.size(); ++x)
		{
			pointSlice[x] = (rotMat * pointSlice[x]);
		}

		for(int i = 0; i < points.size()-1; ++i)
		{
			Face face;
			face.addVertex(points[(i+1)%points.size()]);
			face.addVertex(points[i]);
			face.addVertex(pointSlice[i]);		
			face.addVertex(pointSlice[(i+1)%points.size()]);
			faces.push_back(face);
		}
		points = pointSlice;
	}

	vector<Face> retFaces;
	for(int w=0; w<faces.size(); ++w)
	{
		vector<Face> triFaces = faces[w].triangulate();
		retFaces.insert(retFaces.end(), triFaces.begin(), triFaces.end());
	}
	return retFaces;



}

bool SurfRev::collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity)
{
	return false;
}