#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Earth.h"

Earth::Earth(void) : Planet() { } //Constructor

Earth::Earth(double depthValue) : Planet(depthValue) { } //Constructor with depth

Earth::~Earth(void) { } //Destructor

double Earth::getRadius(){ //Get radius
	return 0.18;
}

Coordinates Earth::getPathToOrbitCenter(){ //Get path to orbit center
	return Coordinates(3.0, 0.0, 0.0);
}

double Earth::getOrbitPeriod(){ //Get orbit period
	return 365;
}

double Earth::getSpinPeriod(){ //Get spin period
	return 0.997;
}

LPCSTR Earth::getImageName(){ //Get image name
	return TEXT("Bitmaps/earth.bmp");
}

rotationCoordinates Earth::getSpinRotationCoordinates(){ //Get spin rotation coords
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Earth::getOrbitCoordinates(){ //Get orbit coords
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Earth::getInitialIncline(){ //Get initial incline
	return 7.0;
}

double Earth::getTiltAngle(){ //Get tilt angle
	return 23.0;
}
