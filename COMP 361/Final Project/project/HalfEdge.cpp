#include "HalfEdge.h"

HalfEdge::HalfEdge(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate)
	: Geometry()
{
	//Start with identity matrix
	modelMatrix = glm::mat4(1.0f);
	
	localMatrix = glm::mat4(1.0f);
	localMatrix = glm::scale(localMatrix, Scale);
	localMatrix = glm::rotate(localMatrix, RotAngle, Rotate);
	localMatrix = glm::translate(localMatrix, Translate);

	u_modelMatrix = 0;
	shaderProgram = 0;
	vertexBuffer = 0;
	colorBuffer = 0;
	normalBuffer = 0;
	indexBuffer = 0;
	vLocation = 0;
	vColor = 0;
	vNormal = 0;
	vID = 0;
	eID = 0;
	fID = 0;
}
HalfEdge::HalfEdge() : Geometry() {}

HalfEdge::~HalfEdge() { }

glm::vec4 HalfEdge::centroid(HEFace *face) {
	HEEdge *start = face->edge;
	HEEdge *cur = start;

	glm::vec4 out;
	out.x = 0.0f;
	out.y = 0.0f;
	out.z = 0.0f;
	out.w = 1.0f;

	double total = 0;
	vector<glm::vec4> vert;

	do {
		vert.push_back(cur->vertex->position);
		cur = cur->next;
	} while(start->ID != cur->ID);

	total = static_cast<double>(vert.size());

	for(int i = 0; i < vert.size(); ++i) {
		out.x += vert[i].x;
		out.y += vert[i].y;
		out.z += vert[i].z;
	}

	out.x /= total;
	out.y /= total;
	out.z /= total;

	return out;
}

void HalfEdge::subDivide(int iters) {
	HEFace *currentFace;

	for(int i = 0; i < faces.size(); ++i) {
		currentFace = faces[i];
		currentFace->subDivisions++;
		int edgeCount = 0;

		HEEdge *startHalfEdge = currentFace->edge;
		HEEdge *curHalfEdge = startHalfEdge;
		HEEdge *nextHalfEdge = curHalfEdge->next;
		bool ranOnce = false;

		while (curHalfEdge->ID != startHalfEdge->ID && ranOnce == true) {
			ranOnce = true;
			++edgeCount;

			if (nextHalfEdge->pair->face->subDivisions == currentFace->subDivisions) {
				// Already done Bobo!
			} else {
				vec4 average = avg(curHalfEdge->vertex->position, nextHalfEdge->vertex->position);
				HEVertex *newVertex = new HEVertex();
				newVertex->position = average;
				edgeCount++;
				addHEVert(newVertex);

				HEEdge *newHalfEdge = new HEEdge();
				newHalfEdge->face = currentFace;
				newHalfEdge->next = nextHalfEdge->next;
				newHalfEdge->vertex = nextHalfEdge->vertex;
				addHEEdge(newHalfEdge);

				nextHalfEdge->next = newHalfEdge;
				nextHalfEdge->vertex = newVertex;

				nextHalfEdge->pair->vertex = newVertex;

				newHalfEdge->pair = nextHalfEdge->pair;
				nextHalfEdge->pair = newHalfEdge;

				HEEdge *newOtherHalfEdge = new HEEdge();
				newOtherHalfEdge->face = nextHalfEdge->pair->face;
				newOtherHalfEdge->next = nextHalfEdge->pair->next;
				newOtherHalfEdge->pair = nextHalfEdge;
				newOtherHalfEdge->vertex = curHalfEdge->vertex;
				addHEEdge(newOtherHalfEdge);

				newHalfEdge->pair->next = newOtherHalfEdge;
				nextHalfEdge->pair = newOtherHalfEdge;
			}

			curHalfEdge = nextHalfEdge->next;
			nextHalfEdge = curHalfEdge->next;
		}

		glm::vec4 cent = centroid(currentFace);
		HEVertex *faceVertex = new HEVertex();
		faceVertex->position = cent;
		addHEVert(faceVertex);

		HEVertex *curVert = startHalfEdge->vertex;
		curHalfEdge = startHalfEdge->next;
		HEEdge *firstEdge = NULL;
		HEFace *newFace;
		HEEdge *prevHalfEdge = NULL;

		for(int i = 0; i < edgeCount; ++i) {
			if (i != edgeCount - 1) {
				newFace = new HEFace();
				addHEFace(newFace);
			} else {
				newFace = currentFace;
			}

			HEEdge *edgeOne = new HEEdge();
			HEEdge *edgeTwo = curHalfEdge;
			HEEdge *edgeThree = new HEEdge();

			addHEEdge(edgeOne);
			addHEEdge(edgeThree);

			if (i == 0)
				firstEdge = edgeOne;

			edgeOne->face = newFace;
			edgeOne->next = edgeTwo;

			if (prevHalfEdge != NULL) {
				edgeOne->pair = prevHalfEdge;
				prevHalfEdge->pair = edgeOne;
			}

			edgeOne->vertex = curVert;

			curVert = edgeTwo->vertex;
			curHalfEdge = edgeTwo->next;

			edgeThree->face = newFace;
			edgeThree->next = edgeOne;

			
			if (i == edgeCount - 1) {
				edgeThree->pair = firstEdge;
				firstEdge->pair = edgeThree;
			}

			edgeThree->vertex->position = cent;

			prevHalfEdge = edgeThree;
		}
	}
}

void HalfEdge::initialize(unsigned int shaderProgram, unsigned int u_modelMatrix)
{
	vertexBuf.clear();
	colorBuf.clear();
	normalBuf.clear();
	indexBuf.clear();

	//This is where the code to create the buffers goes.
	BuildBuffers();

	this->u_modelMatrix = u_modelMatrix;
	this->shaderProgram = shaderProgram;

	//GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexBuf.size()*sizeof(glm::vec4), &vertexBuf[0], GL_STATIC_DRAW);
	//this->vertexBuffer = vertexBuffer;
	
	vLocation = glGetAttribLocation(shaderProgram, "vs_position");
	glEnableVertexAttribArray(vLocation);
	glVertexAttribPointer(vLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);
	//this->vLocation = vLocation;

	//GLuint colorBuffer;
	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colorBuf.size()*sizeof(glm::vec3), &colorBuf[0], GL_STATIC_DRAW);
	//this->colorBuffer = colorBuffer;

	vColor = glGetAttribLocation(shaderProgram, "vs_color");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//this->vColor = vColor;

	//GLuint normalBuffer;
	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normalBuf.size()*sizeof(glm::vec4), &normalBuf[0], GL_STATIC_DRAW);
	//this->normalBuffer = normalBuffer;

	vNormal = glGetAttribLocation(shaderProgram, "vs_normal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0, 0);
	//this->vNormal = vNormal;

	//GLuint indexBuffer;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBuf.size()*sizeof(GLuint), &indexBuf[0], GL_STATIC_DRAW);
	//this->indexBuffer = indexBuffer;

}

void HalfEdge::BuildBuffers()
{
	//calculate all of the vertex normals. because I'm batman!
	for(int i=0; i < verts.size(); ++i)
	{
		HEEdge * next = verts[i]->edge->pair;

		vec4 normal = verts[i]->edge->face->getNormal();

		while(next->next != verts[i]->edge)
		{
			normal += next->face->getNormal();
			next = next->next->pair;
		}
		//Normalize this monkey.
		//verts[i]->normal = vec4(0, 1, 0, 1);
		vec3 n = normalize(vec3(normal.x, normal.y, normal.z));
		verts[i]->normal = vec4(n, 0);
	}

	//create the other buffers
	for(int i = 0; i < verts.size(); ++i)
	{
		vertexBuf.push_back(verts[i]->position);
		normalBuf.push_back(verts[i]->normal);
		colorBuf.push_back(verts[i]->color);
	}

	//Create index buffer, but do it carefully.  Faces may bite.
	for(int i=0; i < faces.size(); ++i)
	{
		HEEdge* start = faces[i]->edge;
		HEEdge* next = start->next;
		indexBuf.push_back(faces[i]->edge->vertex->ID);
		while(next != start)
		{
			indexBuf.push_back(next->vertex->ID);
			next = next->next;
		}
	}

}

void HalfEdge::draw(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate)
{
	
}
void HalfEdge::draw(mat4 Matrix, vec3 color)
{
	//glBegin(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	setColor(color);

	modelMatrix = Matrix * localMatrix;
    glUniformMatrix4fv(u_modelMatrix, 1, GL_FALSE, &modelMatrix[0][0]);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	//glBufferData(GL_ARRAY_BUFFER, vertexBuf.size() * sizeof(vec4), &vertexBuf[0], GL_STATIC_DRAW);
	glVertexAttribPointer(vLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(vLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	//glBufferData(GL_ARRAY_BUFFER, normalBuf.size() * sizeof(vec4), &normalBuf[0], GL_STATIC_DRAW);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBuf.size()*sizeof(GLuint), &indexBuf[0], GL_STATIC_DRAW);
	
	glDrawElements(GL_QUADS, indexBuf.size(), GL_UNSIGNED_INT, NULL);
	//glDrawArrays(GL_TRIANGLES, 0, indices.size());
	glFlush();


	glDrawElements(GL_TRIANGLES, indexBuf.size(), GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, indices.size());
	glFlush();
}
void HalfEdge::setColor(vec3 color)
{
	for (int i = 0; i < colorBuf.size(); ++i)
	{
		colorBuf[i] = vec3(color.x, color.y, color.z);
	}

	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colorBuf.size()* sizeof(vec3), &colorBuf[0], GL_STATIC_DRAW);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

int HalfEdge::addHEVert(HEVertex* v)
{
	v->ID = vID++;
	v->position.w = 1;
	verts.push_back(v);
	return v->ID;
}
int HalfEdge::addHEFace(HEFace* f)
{
	f->ID = fID++;
	faces.push_back(f);
	return f->ID;
}
int HalfEdge::addHEEdge(HEEdge* e)
{
	e->ID = eID++;
	edges.push_back(e);
	return e->ID;
}
bool HalfEdge::collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity)
{
	return false;
}