#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "SolarSystem.h"
#include "glut.h"
#include <GL/gl.h>
#include "Sun.h"
#include "Mercury.h"
#include "Venus.h"
#include "Earth.h"
#include "Moon.h"
#include "Mars.h"
#include "Jupiter.h"
#include "Saturn.h"
#include "Uranus.h"
#include "Neptune.h"
#include "Pluto.h"


//Definition for skybox positions

#define FRONT 0
#define BACK  1
#define LEFT  2
#define RIGHT 3
#define TOP 4
#define BOTTOM 5

//Solar system constructor
SolarSystem::SolarSystem(void){
	//Sets initial values 
	this -> currentEarthRotation = 0.0;
	this -> earthDaysPassed = 0.0;
	this -> addEarthDay = 0.8;
	//Adds all the celestial objects to vector
	SpaceSphere *earth = new Earth(99799);
	this -> maxEarthDays = earth -> getOrbitPeriod();
	SpaceSphere *sun = new Sun(100000);
	this -> sun = (Star*)sun;
	this -> celestials.push_back(sun);
	 this -> celestials.push_back(new Mercury(99999));
	this -> celestials.push_back(new Venus(99899));
	this -> celestials.push_back(earth);
	this -> celestials.push_back(new Moon(99789, (Planet*)earth));
	this -> celestials.push_back(new Mars(99699));
	SpaceSphere *jupiter = new Jupiter(99599);
	this -> celestials.push_back(jupiter);
	this -> celestials.push_back(new Saturn(99499));
	this -> celestials.push_back(new Uranus(99399));
	this -> celestials.push_back(new Neptune(99299));
	this -> celestials.push_back(new Pluto(99199));
}

SolarSystem::~SolarSystem(void) { //Destructor
	//Loop ensures that vector is cleared out and all values are deleted
	for (unsigned int index = 0; index < this -> celestials.size();){
		delete this->celestials[index];
	}
}

void SolarSystem::update(void){
	glEnable(GL_LIGHTING); //Set up lighting
	glEnable(GL_LIGHT0);
	
	Coordinates center = this -> sun -> getPathToOrbitCenter(); //Work out middle of scene

	float posLight0[4] = {center.x, center.y, center.z, 1.0}; //Position lighting
	float ambLight0[4] = {0.2, 0.2, 0.2, 1.0}; //Set up ambient lighting

	glLightfv(GL_LIGHT0, GL_POSITION, posLight0); 
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambLight0);

	GLfloat specular[] = {0.05, 0.05, 0.0, 1.0}; //Set up specular lighting
	GLfloat emission[] = {0.0, 0.0, 0.0, 1.0}; //Set up ligting emission

	//Apply lighting attributes to material
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular); 
	glMateriali(GL_FRONT, GL_SHININESS, 0.0);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
}

void SolarSystem::setUpObjectsTextures(void){ //Set up global textures
	this -> setUpSkyBoxTextures(); //Set up skybox texutres
	//Loop to set up all textures in celestrial vector
	for (unsigned int index = 0; index < this -> celestials.size(); index++){
		this -> celestials[index] -> setUpTextures();
	}
}

void SolarSystem::setUpSkyBoxTextures(){
	//Load skybox top file
	this -> skyBoxImages[TOP].loadFile(TEXT("Bitmaps/Skybox/top.bmp"));
	GLuint texture1 = skyboxTextures[TOP];
	glGenTextures(1, &texture1);
	
	//Load skybox bottom file
	this -> skyBoxImages[BOTTOM].loadFile(TEXT("Bitmaps/Skybox/bottom.bmp"));
	GLuint texture2 = skyboxTextures[BOTTOM];
	glGenTextures(1, &texture2);

	//Load skybox left file
	this -> skyBoxImages[LEFT].loadFile(TEXT("Bitmaps/Skybox/left.bmp"));
	GLuint texture3 = skyboxTextures[LEFT];
	glGenTextures(1, &texture3);

	//Load skybox right file
	this -> skyBoxImages[RIGHT].loadFile(TEXT("Bitmaps/Skybox/right.bmp"));
	GLuint texture4 = skyboxTextures[RIGHT];
	glGenTextures(1, &texture4);

	//Load skybox from file
	this -> skyBoxImages[FRONT].loadFile(TEXT("Bitmaps/Skybox/front.bmp"));
	GLuint texture5 = skyboxTextures[FRONT];
	glGenTextures(1, &texture5);

	//Load skybox back file
	this -> skyBoxImages[BACK].loadFile(TEXT("Bitmaps/Skybox/back.bmp"));
	GLuint texture6 = skyboxTextures[BACK];
	glGenTextures(1, &texture6);
}

void SolarSystem::display(Camera *camera){	//Set display to camera position
	//Enable all relevant OpenGL values
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glColor3d(1, 1, 1);

	glLoadIdentity();
	//Set view to camera
	gluLookAt(camera -> position.x, camera -> position.y, camera -> position.z,  camera -> view.x, camera -> view.y, camera -> view.z,  camera -> vector.x,	camera -> vector.y,	camera -> vector.z);
	this -> drawSkybox(0, 0, 0, 100, 100, 100); //Draw skybox
	for (unsigned int index = 0; index < this->celestials.size(); index++){ 
		this -> update(); //Update value in vector
		this -> celestials[index] -> draw(); //Draw value in vector
	}
	glutSwapBuffers();
	glFlush();
	glDisable(GL_TEXTURE_2D);
}

//Set up timer for orbiting and rotatio sync
void SolarSystem::timeObjectsMovement(void){
	this -> currentEarthRotation += this -> addEarthDay;
	this ->earthDaysPassed += this -> addEarthDay;

	//Loop to ensure all objects are set up correctly
	for (unsigned int index = 0; index < this -> celestials.size(); index++){
		double orbitPeriod = this -> celestials[index] -> getOrbitPeriod();
		double spinPeriod = this -> celestials[index] -> getSpinPeriod();
		this -> celestials[index] -> setSpinRotationAngle((this->currentEarthRotation / spinPeriod) * 360.0);
		this -> celestials[index] -> setOrbitRotationAngle((this->earthDaysPassed / orbitPeriod) * 360.0);
	}
}

double SolarSystem::getRotationSpeed(void){ //Gets current rotation speed
	return this -> addEarthDay;
}

void SolarSystem::setRotationSpeed(double speed){ //Sets rotation speed
	if (speed > 100.0)  {
		this -> addEarthDay = 100.0; //Allows for speeding up
		return;
	} else if(speed < 0.1){
		this -> addEarthDay = 0.1; //Allows for slowing down
		return;
	}
	this -> addEarthDay = speed; 
}

//Draw skybox
void SolarSystem::drawSkybox(float x, float y, float z, float width, float height, float length){
	glEnable(GL_TEXTURE_2D); //Enable texturing

	//Set up lighting values
	GLfloat specular[] = {0.4, 0.4, 0.4, 1.0};
	GLfloat emission[] = {0.2, 0.2, 0.2, 1.0};

	//Set up lighting attributes
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMateriali(GL_FRONT, GL_SHININESS, 1.0);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);

	x = x - width  / 2;
	y = y - height / 2;
	z = z - length / 2;

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//Assign 2D image to front
	glTexImage2D(GL_TEXTURE_2D, 0, 3, this -> skyBoxImages[FRONT].getWidth(), this -> skyBoxImages[FRONT].getHeight(), 0,  GL_BGR_EXT, GL_UNSIGNED_BYTE, this -> skyBoxImages[FRONT].getBits());
	//Bind texture
	glBindTexture(GL_TEXTURE_2D, skyboxTextures[FRONT]);
	glBegin(GL_QUADS);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,  z + length);
	glEnd();
	//Assign 2D image to back
	glTexImage2D(GL_TEXTURE_2D, 0, 3, this -> skyBoxImages[BACK].getWidth(), this -> skyBoxImages[BACK].getHeight(), 0,  GL_BGR_EXT, GL_UNSIGNED_BYTE, this->skyBoxImages[BACK].getBits());
	//Bing texture
	glBindTexture(GL_TEXTURE_2D, skyboxTextures[BACK]);
	glBegin(GL_QUADS);		
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();
	//Assign 2D image to left
	glTexImage2D(GL_TEXTURE_2D, 0, 3, this -> skyBoxImages[LEFT].getWidth(), this->skyBoxImages[LEFT].getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, this -> skyBoxImages[LEFT].getBits());
	//Bind texture
	glBindTexture(GL_TEXTURE_2D, skyboxTextures[LEFT]);
	glBegin(GL_QUADS);		
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height,	z);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,	y + height,	z + length); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,	y, z + length);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);		
	glEnd();
	//Assign 2D image to the right
	glTexImage2D(GL_TEXTURE_2D, 0, 3, this -> skyBoxImages[RIGHT].getWidth(), this->skyBoxImages[RIGHT].getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, this -> skyBoxImages[RIGHT].getBits());
	//Bind texture
	glBindTexture(GL_TEXTURE_2D, skyboxTextures[RIGHT]);
	glBegin(GL_QUADS);		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height,	z + length); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height,	z);
	glEnd();
	//Assign 2D image to top
	glTexImage2D(GL_TEXTURE_2D, 0, 3, this->skyBoxImages[TOP].getWidth(), this -> skyBoxImages[TOP].getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, this -> skyBoxImages[TOP].getBits());
	//Bind texture
	glBindTexture(GL_TEXTURE_2D, skyboxTextures[TOP]);
	glBegin(GL_QUADS);		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length); 
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();
	//Assign 2D image to top
	glTexImage2D(GL_TEXTURE_2D, 0, 3, this -> skyBoxImages[TOP].getWidth(), this->skyBoxImages[TOP].getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, this -> skyBoxImages[TOP].getBits());
	//Bind texture
	glBindTexture(GL_TEXTURE_2D, skyboxTextures[TOP]);
	glBegin(GL_QUADS);		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y,z + length); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
	glEnd();
}
