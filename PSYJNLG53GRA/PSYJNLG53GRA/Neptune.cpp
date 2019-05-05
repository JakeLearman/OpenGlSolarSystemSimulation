#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Neptune.h"

Neptune::Neptune(void) : Planet() { } //Default constructor

Neptune::Neptune(double depthValue) : Planet(depthValue) { } //Constructor with planet depth

Neptune::~Neptune(void) { } //Destructor

double Neptune::getRadius(){ //Get planet radius
	return 0.3;
}

Coordinates Neptune::getPathToOrbitCenter(){ //Get path to center
	return Coordinates(11.2, 0.0, 0.0);
}

double Neptune::getOrbitPeriod(){ //Get orbit period
	return 60152.0;
}

double Neptune::getSpinPeriod(){ //Get spin period
	return 0.671;
}

LPCSTR Neptune::getImageName(){ //Get image name
	return TEXT("Bitmaps/neptune.bmp");
}

rotationCoordinates Neptune::getSpinRotationCoordinates(){ //Get spin rotation coordinates
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Neptune::getOrbitCoordinates(){ //Get orbit coords
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Neptune::getInitialIncline(){ //Get initial incline
	return 2.0;
}

double Neptune::getTiltAngle(){ //Get tilt angle
	return 28.32;
}
