#pragma once
#include "glm/glm.hpp"
#include <vector>
using std::vector;

struct HEFace;
struct HEVertex;
struct HEEdge;
struct VertLine;

struct HEEdge {
public : 
	HEFace *face;
	HEEdge *next;
	HEEdge *pair;
	HEVertex *vertex;
	int ID;
};

struct HEVertex {
public : 
	HEVertex(): ID(-1), position(glm::vec4(0,0,0,0)), normal(0,1,0,1), color(glm::vec3(1,0,0)){}
	HEEdge *edge;
	int ID;
	glm::vec4 position;
	glm::vec4 normal;
	glm::vec3 color;
};

struct HEFace {
	HEFace() : ID(0), subDivisions(0) { }

	HEEdge *edge;
	glm::vec4 normal;
	int ID;
	int subDivisions;
	glm::vec4 getNormal()
	{
		glm::vec4 p0, p1, p2;
		p0 = edge->vertex->position;
		p1 = edge->next->vertex->position;
		p2 = edge->next->next->vertex->position;
		

		glm::vec4 v = p0-p1;
		glm::vec4 u = p2-p1;

		glm::vec3 n = glm::cross(glm::vec3(u.x, u.y, u.z), glm::vec3(v.x, v.y, v.z));
		n = glm::normalize(n);
		edge->face->normal = glm::vec4(n, 1);
		return glm::vec4(n, 1);
	}
};



struct VertLine
{
	vector<HEVertex*> points;
	void addVertex(glm::vec4 p) 
	{
		HEVertex* v = new HEVertex();
		v->position = p;
		points.push_back(v);
	}
	bool isConvex()
	{
		glm::vec4 n1 = points[1]->position-points[0]->position;
		glm::vec4 n2 = points[2]->position - points[1]->position;

		glm::vec3 n = glm::cross(glm::vec3(n1.x, n1.y, n1.z), glm::vec3(n2.x, n2.y, n2.z));
		n = glm::normalize(n);

		for(int i=0; i< points.size(); ++i)
		{
			glm::vec4 t1 = points[(i+1)%points.size()]->position - points[i]->position;
			glm::vec4 t2 = points[(i-1)%points.size()]->position - points[i]->position;
			glm::vec3 t = glm::cross(glm::vec3(t1.x, t1.y, t1.z), glm::vec3(t2.x, t2.y, t2.z));
			t = glm::normalize(t);

			if (t==-n)
			{
				return false;
			}
		}
		return true;
	}
};