#include "Mesh.h"


Mesh::Mesh(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate)
{
	
}


Mesh::Mesh(void)
{
		 //Start with identity matrix
	modelMatrix = glm::mat4(1.0f);
	
	localMatrix = glm::mat4(1.0f);
	localMatrix = glm::scale(localMatrix, glm::vec3(1, 1, 1));
	localMatrix = glm::rotate(localMatrix, 0.0f, glm::vec3(1, 1, 1));
	localMatrix = glm::translate(localMatrix, glm::vec3(0, 0, 0));

	u_modelMatrix = 0;
	shaderProgram = 0;
	vertexBuffer = 0;
	colorBuffer = 0;
	normalBuffer = 0;
	indexBuffer = 0;
	vLocation = 0;
	vColor = 0;
	vNormal = 0;
}

Mesh::~Mesh(void)
{
}
void Mesh::initialize(unsigned int shaderProgram, unsigned int u_modelMatrix)
{
	vertices.clear();
	colors.clear();
	normals.clear();
	indices.clear();

	for (int i = 0; i < faces.size(); ++i)
	{
		vector<vec4> newPoints = faces[i].getVertices();
		if(newPoints.size()>0)
		{
			vertices.insert(vertices.end(), newPoints.begin(), newPoints.end());
		}
		vector<vec3> newColors = faces[i].getColors();
		if(newColors.size()>0)
		{
			colors.insert(colors.end(), newColors.begin(), newColors.end());
		}
		vector<vec4> newNormals = faces[i].getNormals();
		if(newNormals.size()>0)
		{
			normals.insert(normals.end(), newNormals.begin(), newNormals.end());
		}
		vector<int> newIndices = faces[i].getIndices(vertices.size()-newPoints.size());
		if(newIndices.size()>0)
		{
			indices.insert(indices.end(), newIndices.begin(), newIndices.end());
		}
	}


    this->u_modelMatrix = u_modelMatrix;
	this->shaderProgram = shaderProgram;

	//GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(vec4), &vertices[0], GL_STATIC_DRAW);
	//this->vertexBuffer = vertexBuffer;
	
	vLocation = glGetAttribLocation(shaderProgram, "vs_position");
	glEnableVertexAttribArray(vLocation);
	glVertexAttribPointer(vLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);
	//this->vLocation = vLocation;

	//GLuint colorBuffer;
	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, colors.size()*sizeof(vec3), &colors[0], GL_STATIC_DRAW);
	//this->colorBuffer = colorBuffer;

	vColor = glGetAttribLocation(shaderProgram, "vs_color");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//this->vColor = vColor;

	//GLuint normalBuffer;
	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size()*sizeof(vec4), &normals[0], GL_STATIC_DRAW);
	//this->normalBuffer = normalBuffer;

	vNormal = glGetAttribLocation(shaderProgram, "vs_normal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0, 0);
	//this->vNormal = vNormal;

	//GLuint indexBuffer;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
	//this->indexBuffer = indexBuffer;
}
void Mesh::draw(vec3 Scale, vec3 Rotate, float RotAngle, vec3 Translate)
{

}
void Mesh::draw(mat4 Matrix, vec3 color)
{
	setColor(color);

	modelMatrix = Matrix * localMatrix;
    glUniformMatrix4fv(u_modelMatrix, 1, GL_FALSE, &modelMatrix[0][0]);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vec4), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(vLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	//glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(vec4), &normals[0], GL_STATIC_DRAW);
	glVertexAttribPointer(vNormal, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLuint), &indices[0], GL_STATIC_DRAW);


	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, indices.size());
	glFlush();

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void Mesh::setColor(vec3 color)
{
	for (int i = 0; i < colors.size(); ++i)
	{
		colors[i] = vec3(color.x, color.y, color.z);
	}

	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	//glBufferData(GL_ARRAY_BUFFER, colors.size()* sizeof(vec3), &colors[0], GL_STATIC_DRAW);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, 0);
}
bool Mesh::collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity)
{
	return false;
}