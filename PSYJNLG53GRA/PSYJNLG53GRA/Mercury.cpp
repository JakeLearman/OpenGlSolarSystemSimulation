#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Mercury.h"

Mercury::Mercury(void) : Planet() { } //Constructor

Mercury::Mercury(double depthValue) : Planet(depthValue) { } //Constructor with depth

Mercury::~Mercury(void) { } //Destructor

double Mercury::getRadius(){ //Get radius
	return 0.1;
}

Coordinates Mercury::getPathToOrbitCenter(){ //Get path to center
	return Coordinates(1.5, 0.0, 0.0);
}

double Mercury::getOrbitPeriod(){ //Get orbit period
	return 87.9691;
}

double Mercury::getSpinPeriod(){ //Get spin period
	return 58.646;
}

LPCSTR Mercury::getImageName(){ //Get texture
	return TEXT("Bitmaps/mercury.bmp");
}

rotationCoordinates Mercury::getSpinRotationCoordinates(){ //Get spin rotation coordinates
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Mercury::getOrbitCoordinates(){ //Get orbit coordianates
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Mercury::getInitialIncline(){ //Get initial incline
	return 7.0;
}

double Mercury::getTiltAngle(){ //Get tilt angle
	return 0.03587;
}
