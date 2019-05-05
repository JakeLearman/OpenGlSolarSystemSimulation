#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Moon.h"

Moon::Moon(void) : Satellite() { } //Moon constructor

Moon::Moon(double depthValue, Planet *planet) : Satellite(depthValue, planet) { } //Constructor with moon depth and orbiting planet

Moon::~Moon(void) { } //Destructor

double Moon::getRadius(){ //Moons radius
	return 0.04;
}

Coordinates Moon::getPathToOrbitCenter(){ //Get path to center
	return Coordinates(0.5, 0.0, 0.0);
}

double Moon::getOrbitPeriod(){ //Get orbit period
	return 27.32166;
}

double Moon::getSpinPeriod(){ //Get spin period
	return 27.32166;
}

LPCSTR Moon::getImageName(){ //Get texture name
	return TEXT("Bitmaps/moon.bmp");
}

rotationCoordinates Moon::getSpinRotationCoordinates(){ //Get spin rotation coordinates
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Moon::getOrbitCoordinates(){ //Get orbit coordinates
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Moon::getInitialIncline(){ //Get initial incline
	return 25;
}

double Moon::getTiltAngle(){ //Get tilt angle
	return 1.5424;
}
