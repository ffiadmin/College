/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the function definitions for the Cube class.
*/
#include "Cube.h"

Cube::Cube() {}
Cube::~Cube() { }

Cube::Cube(glm::vec3 Scale, glm::vec3 Rotate, float RotAngle, glm::vec3 Translate)
{
    //Start with identity matrix
	modelMatrix = glm::mat4(1.0f);

	localMatrix = glm::mat4(1.0f);
	localMatrix = glm::scale(localMatrix, Scale);
	localMatrix = glm::rotate(localMatrix, RotAngle, Rotate);
	localMatrix = glm::translate(localMatrix, Translate);

	//
	//     1 +---------+ 2
	//      /   Top  / |
	//  3  /      4 /  |
	//    +--------+ R |
	//    |        |   + 6
	//    |  Back  |  /
	//    |        | /
	//    +--------+ 
	//    7        8
	//
	
	Face front;
	//Must flip winding order
	front.addVertex(vec4(-0.5, 0.5, 0.5, 1.0));	    //1
	front.addVertex(vec4(0.5, 0.5, 0.5, 1.0));		//2
	front.addVertex(vec4(0.5, -0.5, 0.5, 1.0));	    //6
	front.addVertex(vec4(-0.5, -0.5, 0.5, 1.0));	//5
	faces.push_back(front);

	Face back;
	back.addVertex(vec4(-0.5, 0.5, -0.5, 1.0));	    //3
	back.addVertex(vec4(-0.5, -0.5, -0.5, 1.0));	//7
	back.addVertex(vec4(0.5, -0.5, -0.5, 1.0));   	//8
	back.addVertex(vec4(0.5, 0.5, -0.5, 1.0));		//4
	faces.push_back(back);

	Face top;
	top.addVertex(vec4(-0.5, 0.5, 0.5, 1.0));	    //1
	top.addVertex(vec4(-0.5, 0.5, -0.5, 1.0));	    //3
	top.addVertex(vec4(0.5, 0.5, -0.5, 1.0));	    //4
	top.addVertex(vec4(0.5, 0.5, 0.5, 1.0));		//2
	faces.push_back(top);

	//Must flip winding order
	Face bottom;
	bottom.addVertex(vec4(0.5, -0.5, 0.5, 1.0));	//6
	bottom.addVertex(vec4(0.5, -0.5, -0.5, 1.0));	//8
	bottom.addVertex(vec4(-0.5, -0.5, -0.5, 1.0));	//7
	bottom.addVertex(vec4(-0.5, -0.5, 0.5, 1.0));	//5
	faces.push_back(bottom);

	//Must flip winding order
	Face left;
	left.addVertex(vec4(-0.5, 0.5, 0.5, 1.0));	    //1
	left.addVertex(vec4(-0.5, -0.5, 0.5, 1.0));	    //5
	left.addVertex(vec4(-0.5, -0.5, -0.5, 1.0));	//7
	left.addVertex(vec4(-0.5, 0.5, -0.5, 1.0));		//3
	faces.push_back(left);

	Face right;
	right.addVertex(vec4(0.5, 0.5, -0.5, 1.0));	    //4
	right.addVertex(vec4(0.5, -0.5, -0.5, 1.0));	//8
	right.addVertex(vec4(0.5, -0.5, 0.5, 1.0));  	//6
	right.addVertex(vec4(0.5, 0.5, 0.5, 1.0));	    //2
	faces.push_back(right);

	/*
	point4(-0.5, -0.5, 0.5, 1.0),	//0 //Front //Bottom Left
	point4(-0.5, 0.5, 0.5, 1.0),	//1 //Front //Top Left
	point4(0.5, 0.5, 0.5, 1.0),		//2 //Front //Top right
	point4(0.5, -0.5, 0.5, 1.0),	//3 //Front //Bottom right

	point4(-0.5, -0.5, -0.5, 1.0),	//4 //Back //Bottom Left
	point4(-0.5, 0.5, -0.5, 1.0),	//5 //Back //Top Left
	point4(0.5, 0.5, -0.5, 1.0),	//6 //Back //Top right
	point4(0.5, -0.5, -0.5, 1.0)	//7 //Back //Bottom right
	*/
}

bool Cube::collideWithRay(Ray ray, Ray* reflection, vec3& color, float& reflectivity)
{
	
	double t = Test_RayCubeIntersect(vec3(ray.origin.x, ray.origin.y, ray.origin.z), 
		vec3(ray.direction.x, ray.direction.y, ray.direction.z), modelMatrix);
	if(t>0)
	{
		color = vec3(0, 0, 1);
		return true;
	}
	return false; //change this
}