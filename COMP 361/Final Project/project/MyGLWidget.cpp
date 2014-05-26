/*
	Author:	Clayton Sandham
	Course:	COMP 361, Computer Graphics
	Date:	February 10, 2014
	Description: This file contains the implementation of the driver for 
				 this program, MyGLWidget, as well as some helper functions.
*/
#include "MyGLWidget.h"

#define BUFFER_OFFSET(bytes) ((GLvoid*) (bytes))


MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent), cube() {

	
}




MyGLWidget::~MyGLWidget() {
	
}

void MyGLWidget::initializeGL() {
	//Setup GLEW and window.
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0);

	//Do something similar to this to set up a buffer for colors
	//glGenBuffers(1, &vbo);

	//Setup Shaders
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	shaderProgram = glCreateProgram();

	//color_xforms
	//lambert
	const char* vertexSource = textFileRead("lambert.vert");
	const char* fragmentSource = textFileRead("lambert.frag");

	glShaderSource(vertexShader, 1, &vertexSource, 0);
	glShaderSource(fragmentShader, 1, &fragmentSource, 0);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);


	//Do something similar to this to get the location of "u_modelMatrix"
	u_projLocation = glGetUniformLocation(shaderProgram, "u_projMatrix");
	u_camMatrix = glGetUniformLocation(shaderProgram, "u_camMatrix");
	u_modelMatrix = glGetUniformLocation(shaderProgram, "u_modelMatrix");
	u_lightPos = glGetUniformLocation(shaderProgram, "u_lightPos");

	glUseProgram(shaderProgram);

	
	cube = Cube(glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), 0, glm::vec3(0, 0, 0));
	cube.initialize(shaderProgram, u_modelMatrix);

	camera.initialize(u_projLocation, u_camMatrix, glm::vec3(0.0, 0.0, 0.0), 5);

	light = Light();
	light.initialize(u_lightPos);
	Light::setCube(&cube);
	light.setPosition(0, 5, 0);
	currentLocation = 0;

}

void MyGLWidget::importFile(string fileName)
{
	sceneGraph.clear();
	ifstream reader(fileName);
	string type;
	float xDim, zDim, xLoc, zLoc, rot, xScale, yScale, zScale;
	int numObjects;
	reader >> xDim;
	reader >> zDim;
	for (int i = 0; i < (xDim + 1) * (zDim + 1); i++)
	{
		sceneGraph.push_back(new Node());
	}
	reader >> numObjects;
	for(int i = 0; i < numObjects; i++) 
	{
		reader >> type;
		string meshName;
		int numSubdiv;
		if (type == "mesh") 
		{			
			reader >> meshName;
			reader >> numSubdiv;
			reader >> xLoc;
			reader >> zLoc;
			reader >> rot;
			reader >> xScale;
			reader >> yScale;
			reader >> zScale;
			string meshType;
			ifstream meshRead(meshName);
			Mesh* importedMesh;
			meshRead >> meshType;
			if (meshType == "extrusion")
			{
				Extrusion* extrusion = new Extrusion(glm::vec3(xScale, yScale, zScale), glm::vec3(0, 1, 0), rot, glm::vec3(xLoc, 0, zLoc));
				extrusion->import(meshRead);
				extrusion ->initialize(shaderProgram, u_modelMatrix);
				importedMesh = extrusion;
			}
			if (meshType == "surfrev")
			{
				SurfRev* surfRev = new SurfRev(glm::vec3(xScale, yScale, zScale), glm::vec3(0, 1, 0), rot, glm::vec3(xLoc, 0, zLoc));
				surfRev->import(meshRead);
				surfRev ->initialize(shaderProgram, u_modelMatrix);
				importedMesh = surfRev;
			}
			Node* newMesh = new Node(glm::mat4(1.0f), importedMesh);
			sceneGraph[zLoc * xDim + xLoc]->addObject(newMesh);
			meshRead.close();
		}
		else
		{
			reader >> xLoc;
			reader >> zLoc;
			reader >> rot;
			reader >> xScale;
			reader >> yScale;
			reader >> zScale;
			if (type == "box")
			{
				HECube* newCube;
				newCube = new HECube(glm::vec3(xScale, yScale, zScale), glm::vec3(0, 1, 0), rot, glm::vec3(xLoc, 0, zLoc));
				newCube->initialize(shaderProgram, u_modelMatrix);
				Node* newObject = new Node(glm::mat4(1.0f), newCube);
				sceneGraph[zLoc * xDim + xLoc]->addObject(newObject);

			}
			if (type == "sphere")
			{
				HECube* newSphere;
				newSphere = new HECube(glm::vec3(xScale, yScale, zScale), glm::vec3(0, 1, 0), rot, glm::vec3(xLoc, 0, zLoc));
				newSphere->initialize(shaderProgram, u_modelMatrix);
				Node* newObject = new Node(glm::mat4(1.0f), newSphere);
				sceneGraph[zLoc * xDim + xLoc]->addObject(newObject);
			}
			if (type == "chair")
			{
				Chair* newChair;
				newChair = new Chair(glm::vec3(xScale, yScale, zScale), glm::vec3(0, 1, 0), rot, glm::vec3(xLoc, 0, zLoc));
				newChair->initialize(shaderProgram, u_modelMatrix);
				Node* newObject = new Node(glm::mat4(1.0f), newChair);
				sceneGraph[zLoc * xDim + xLoc]->addObject(newObject);
			}
			if (type == "table")
			{
				Table* newTable;
				newTable = new Table(glm::vec3(xScale, yScale, zScale), glm::vec3(0, 1, 0), rot, glm::vec3(xLoc, 0, zLoc));
				newTable->initialize(shaderProgram, u_modelMatrix);
				Node* newObject = new Node(glm::mat4(1.0f), newTable);
				sceneGraph[zLoc * xDim + xLoc]->addObject(newObject);
			}
		}
	}	
	/*reader >> type;
	Mesh* importedMesh;
	if (type == "extrusion")
	{
		Extrusion* extrusion = new Extrusion(glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), 0, glm::vec3(0, 0, 0));
		extrusion->import(reader);
		extrusion ->initialize(shaderProgram, u_modelMatrix);
		importedMesh = extrusion;
	}
	if (type == "surfrev")
	{
		SurfRev* surfRev = new SurfRev(glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), 0, glm::vec3(0, 0, 0));
		surfRev->import(reader);
		surfRev ->initialize(shaderProgram, u_modelMatrix);
		importedMesh = surfRev;
	}
	sceneGraph.push_back(new Node(glm::mat4(1.0f), importedMesh));*/
	reader.close();
	Node* temp;
	for(int i = 0; i < sceneGraph.size(); i++)
	{
		temp = sceneGraph[i];
		if (temp->nextObject != NULL)
		{
			currentObject = temp->nextObject;
			currentObject->setColor(glm::vec3(0,1,0));
			currentLocation = i;
			break;
		}
	}
}

void MyGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	light.draw();
	for(int i=0; i<sceneGraph.size(); ++i)
	{
		sceneGraph.at(i)->visitChildren(glm::mat4(1.0f));
	}
	
}

void MyGLWidget::resizeGL(int width, int height) {
	glViewport(0, 0, width, height);
	camera.setViewport(width, height);
}

//from swiftless.com
char* MyGLWidget::textFileRead(const char* fileName) {
    char* text;
    
    if (fileName != NULL) {
        FILE *file = fopen(fileName, "rt");
        
        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            int count = ftell(file);
            rewind(file);
            
            if (count > 0) {
                text = (char*)malloc(sizeof(char) * (count + 1));
                count = fread(text, sizeof(char), count, file);
                text[count] = '\0';	//cap off the string with a terminal symbol, fixed by Cory
            }
            fclose(file);
        }
    }
    return text;
}

void MyGLWidget::up(void)
{
	camera.rotateUp();
	this->update();
}
void MyGLWidget::down(void)
{
	camera.rotateDown();
	this->update();
}
void MyGLWidget::left(void)
{
	camera.rotateLeft();
	this->update();
}
void MyGLWidget::right()
{
	camera.rotateRight();
	this->update();
}
void MyGLWidget::zoomIn(void)
{
	camera.zoomIn();
	this->update();
}
void MyGLWidget::zoomOut()
{
	camera.zoomOut();
	this->update();
}

void MyGLWidget::load(string filename)
{
	sceneGraph.clear();
	importFile(filename);
	camera.update();
	update();
}

void MyGLWidget::lightUp()
{
	light.addPosition(0,0.5f,0);
	this->update();
}
void MyGLWidget::lightDown()
{
	light.addPosition(0,-0.5f,0);
	this->update();
}
void MyGLWidget::lightXPlus()
{
	light.addPosition(0.5f,0,0);
	this->update();
}
void MyGLWidget::lightXMinus()
{
	light.addPosition(-0.5f,0,0);
	this->update();
}
void MyGLWidget::lightZPlus()
{
	light.addPosition(0,0,0.5f);
	this->update();
}
void MyGLWidget::lightZMinus()
{
	light.addPosition(0,0,-0.5f);
	this->update();
}

void MyGLWidget::cycleObjects()
{
	do
	{
		if (currentObject->nextObject != NULL)
		{
			currentObject->setColor(glm::vec3(0, 0, 1));
			currentObject = currentObject->nextObject;
			currentObject->setColor(glm::vec3(0, 1, 0));
		}
		else
		{
			currentObject->setColor(glm::vec3(0,0,1));
			currentLocation++;
			if(currentLocation == sceneGraph.size())
				currentLocation = 0;
			currentObject = sceneGraph[currentLocation];
		}
	} while(currentObject->geometry == NULL);
	update();
}

	void MyGLWidget::moveXPlus()
	{
		currentObject->mX++;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::moveXMinus()
	{
		currentObject->mX--;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::moveZPlus()
	{
		currentObject->mZ++;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::moveZMinus()
	{
		currentObject->mZ--;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::rotatePlus()
	{
		currentObject->reRot += 5.0;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::rotateMinus()
	{
		currentObject->reRot -= 5.0;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::scaleXPlus()
	{
		currentObject->sX += 0.1;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::scaleXMinus()
	{
		if (currentObject->sX > 0.1)
			currentObject->sX -= 0.1;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::scaleZPlus()
	{
		currentObject->sZ += 0.1;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::scaleZMinus()
	{
		if (currentObject->sZ > 0.1)
			currentObject->sZ -= 0.1;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::scaleYPlus()
	{
		currentObject->sY += 0.1;
		currentObject->updateTransform();
		update();
	}
	void MyGLWidget::scaleYMinus()
	{
		if (currentObject->sY > 0.1)
			currentObject->sY -= 0.1;
		currentObject->updateTransform();
		update();
	}

	void MyGLWidget::rayTrace()
	{
		unsigned int width = 800;
		unsigned int height = 600;
		float aspect = ((float)width)/height;
		float fovy = camera.FOV * 3.1415926535/180;
		float phi = fovy/2;
		vec4 up = vec4(0,1,0,0);
		vec4 u = vec4(-1,0,0,0);

		vec4 v = up * tan(phi);
		vec4 h = -u * tan(phi) * aspect;

		vec4 m = vec4(0,0,-1,1);
		vec4 e = vec4(0,0,0,1);

		BMP output;
		output.SetSize(width, height);
		output.SetBitDepth(24);


	
		for(unsigned int x = 0; x < width; x++) {
			for(unsigned int y = 0; y < height; y++) {
				Ray ray;
				vec4 p = m + (2 * (float)x/(width-1)-1)*h + (2 * (float)y/(height-1)-1) * v;
				ray.origin = e;
				ray.direction = (p-e)/length(p-e);
				//Ray trace stuff here! smooches!
				vec3 color = traceRay(ray);

				output(x, y)->Red = color.x * 255;
				output(x, y)->Green = color.y * 255;
				output(x, y)->Blue = color.z * 255;
			}
		}

		output.WriteToFile("output.bmp");
	}

	vec3 MyGLWidget::traceRay(Ray ray)
	{
		Ray* reflectedRay;
		vec3 color = vec3(1, 0, 0);
		float reflectivity = 1;

		for(int i=0; i < sceneGraph.size(); ++i)
		{
			Node* current = sceneGraph[i];
			while(current!=NULL)
			{
				if(current->geometry)
				{
					if (current->geometry->collideWithRay(ray, reflectedRay, color, reflectivity))
					{
						if(reflectedRay == NULL)
						{
							return vec3(0, 1, 1);
						}
						else
						{
							return vec3(1, 1, 0);
							//return (1-reflectivity)*color + reflectivity*traceRay(*reflectedRay);
						}

					}
				}
				current = current->nextObject;
			}
		}
		return vec3(0, 1, 0);
	}