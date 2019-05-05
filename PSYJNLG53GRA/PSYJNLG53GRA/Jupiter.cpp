#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Jupiter.h"

Jupiter::Jupiter(void) : Planet() { } //Constructor

Jupiter::Jupiter(double depthValue) : Planet(depthValue) { } //Constructor with depth
 
Jupiter::~Jupiter(void) { } //Destructor

double Jupiter::getRadius(){ //Get radius
	return 0.6;
}

Coordinates Jupiter::getPathToOrbitCenter(){ //Get path to orbit
	return Coordinates(5.5, 0.0, 0.0);
}

double Jupiter::getOrbitPeriod(){ //Get orbit period
	return 4328.9;
}

double Jupiter::getSpinPeriod(){ //Get spin period
	return 0.410;
}

LPCSTR Jupiter::getImageName(){ //Get image name
	return TEXT("Bitmaps/jupiter.bmp");
}

rotationCoordinates Jupiter::getSpinRotationCoordinates(){ //Get spin rotation coords
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Jupiter::getOrbitCoordinates(){ //Get orbit coords
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Jupiter::getInitialIncline(){ //Get initial incline
	return 1.0;
}

double Jupiter::getTiltAngle(){ //Get tilt angle
	return 3.13;
}
