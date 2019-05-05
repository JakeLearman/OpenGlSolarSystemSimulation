#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Sun.h"

Sun::Sun(void) : Star() { } //Default constructor

Sun::Sun(double depthValue) : Star(depthValue) { } //Constructor with depth value

Sun::~Sun(void) { } //Destructor

double Sun::getRadius() { //Radius of planet
	return 1.0;
}

double Sun::getSpinPeriod(){ //Gets spin period of the sun
	return 25.0;
}

double Sun::getOrbitPeriod() { //Gets orbit period
	return 0.0;
}
 
LPCSTR	Sun::getImageName(){ // Gets texture name
	return TEXT("Bitmaps/sun.bmp");
}

Coordinates Sun::getPathToOrbitCenter(){ //Gets path to center
	return Coordinates(0.0, 0.0, 0.0); //Sun is in the center hence all 0 values
}

rotationCoordinates Sun::getSpinRotationCoordinates() { //Gets spin coordinates
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Sun::getOrbitCoordinates(){ //Gets orbit coordinates
	return rotationCoordinates(0.0, 0.0, 0.0, 0.0); //Has no orbit hence all 0 values
}

double Sun::getInitialIncline(){ //Gets initial incline
	return 0.0; //No incline hence 0 value
}

void Sun::draw(){ //Draws sun
	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0}; //Sets specular lighting
	GLfloat emission[] = {1.0, 1.0, 0.0, 1.0}; //Sets emission lighting
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular); //Adds specular value to front of object
	glMateriali(GL_FRONT, GL_SHININESS, 128.0); //Adds shininess to front of object
	glMaterialfv(GL_FRONT, GL_EMISSION, emission); //Adds emission to front of object
	Star::draw(); //Draws sun, swap with line below to draw sun as particles
	//Star::drawShining(STAR_GLOW_PARTICLES);
}
