
#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Venus.h"

Venus::Venus(void) : Planet() { } //Default constructor

Venus::Venus(double depthValue) : Planet(depthValue) { } //Constructor with planet depth 

Venus::~Venus(void) { } //Default destructor

double Venus::getRadius(){ //Returns the radius of Venus
	return 0.18;
}

Coordinates Venus::getPathToOrbitCenter(){ //Gets the path to the center of the planet
	return Coordinates(2.0, 0.0, 0.0);
}

double Venus::getOrbitPeriod(){ //Gets the time to orbit
	return 225;
}

double Venus::getSpinPeriod(){ //Gets spin period
	return -243.018;
}

LPCSTR Venus::getImageName(){ //Gets the texture name
	return TEXT("Bitmaps/venus.bmp");
}

rotationCoordinates Venus::getSpinRotationCoordinates(){ //Gets spin rotation coordinates
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Venus::getOrbitCoordinates(){ //Gets orbit coordinates
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Venus::getInitialIncline(){ //Gets initial planet incline
	return 3.0;
}

double Venus::getTiltAngle(){ //Gets tilt angle
	return 177.3;
}
