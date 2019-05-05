#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Mars.h"


Mars::Mars(void) : Planet() { } //Constructor

Mars::Mars(double depthValue) : Planet(depthValue) { } //Constructor with depth

Mars::~Mars(void) { } //Destructor

double Mars::getRadius(){ //Get radius
	return 0.3;
}

Coordinates Mars::getPathToOrbitCenter(){ //Get path to center
	return Coordinates(4.0, 0.0, 0.0);
}

double Mars::getOrbitPeriod(){ //Get orbit period
	return 686.565;
}

double Mars::getSpinPeriod(){ //Get spin period
	return 1.026;
}

LPCSTR Mars::getImageName(){ //Get image name
	return TEXT("Bitmaps/mars.bmp");
}

rotationCoordinates Mars::getSpinRotationCoordinates(){ //Get spin rotation coords
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Mars::getOrbitCoordinates(){ //Get orbit coords
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Mars::getInitialIncline(){ //Get incline
	return 2.0;
}

double Mars::getTiltAngle(){ //Get tilt angle
	return 25.19;
}
