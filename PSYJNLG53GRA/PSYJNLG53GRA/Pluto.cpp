#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Pluto.h"

Pluto::Pluto(void) : Planet() { } //Default constructor

Pluto::Pluto(double depthValue) : Planet(depthValue) { } //Constructor allowing for planetary depth
 
Pluto::~Pluto(void) { } //Default destructor

double Pluto::getRadius(){ //Get planetary radius
	return 0.05;
}
 
Coordinates Pluto::getPathToOrbitCenter(){ //Get planetary orbit path
	return Coordinates(12.8, 0.0, 0.0);
}

double Pluto::getOrbitPeriod(){ //Get orbit period
	return 90556.5;
}

double Pluto::getSpinPeriod(){ //Get spin period
	return -6.387;
}

LPCSTR Pluto::getImageName(){ //Get texture name
	return TEXT("Bitmaps/pluto.bmp");
}

rotationCoordinates Pluto::getSpinRotationCoordinates(){ //Get spin rotation coords
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Pluto::getOrbitCoordinates(){ //Get orbit coords
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Pluto::getInitialIncline(){ //Get incline
	return 1.0;
}

double Pluto::getTiltAngle(){ //Get tilt angle
	return 119.591;
}
