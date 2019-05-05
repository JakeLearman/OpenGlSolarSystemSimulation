#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Europa.h"

Europa::Europa(void) : Satellite() { }

Europa::Europa(double depthValue, Planet *planet) : Satellite(depthValue, planet) { }

Europa::~Europa(void) { }

double Europa::getRadius() {
	return 0.05;
}

Coordinates Europa::getPathToOrbitCenter() {
	return Coordinates(0.5, 0.0, 1.0);
}

double Europa::getOrbitPeriod() {
	return 1.769;
}

double Europa::getSpinPeriod() {
	return 85;
}

LPCSTR Europa::getImageName() {
	return TEXT("Bitmaps/Europa.bmp");
}

rotationCoordinates Europa::getSpinRotationCoordinates() {
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Europa::getOrbitCoordinates() {
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Europa::getInitialIncline() {
	return 25;
}

double Europa::getTiltAngle() {
	return 0.05;
}
