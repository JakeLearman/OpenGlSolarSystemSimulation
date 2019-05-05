#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Uranus.h"

Uranus::Uranus(void) : Planet() { } //Default constructor

Uranus::Uranus(double depthValue) : Planet(depthValue) { } //Constructor with planet depth 

Uranus::~Uranus(void) { } //Default destructor

double Uranus::getRadius(){  //Returns the radius of Uranus
	return 0.3;
}

Coordinates Uranus::getPathToOrbitCenter(){ //Gets the path to the center of the planet
	return Coordinates(9.9, 0.0, 0.0);
}

double Uranus::getOrbitPeriod(){ //Gets orbit period
	return 30776.8;
}

double Uranus::getSpinPeriod(){ //Gets spin period
	return -0.718;
}

LPCSTR Uranus::getImageName(){ //Gets texture name
	return TEXT("Bitmaps/uranus.bmp");
}

rotationCoordinates Uranus::getSpinRotationCoordinates(){ //Gets spin rotation coordinates
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Uranus::getOrbitCoordinates(){ //Gets orbit coordinates
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Uranus::getInitialIncline(){ //Gets initail planetary incline
	return 1.0;
}
 
double Uranus::getTiltAngle(){ //Gets planetary tilt angle
	return 97.77;
}
