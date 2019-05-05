#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Io.h"

Io::Io(void) : Satellite() { }

Io::Io(double depthValue, Planet *planet) : Satellite(depthValue, planet) { }

Io::~Io(void) { }

double Io::getRadius() {
	return 0.0516;
}

Coordinates Io::getPathToOrbitCenter() {
	return Coordinates(1, 0.0, 0.0);
}

double Io::getOrbitPeriod() {
	return 1.769;
}

double Io::getSpinPeriod() {
	return 42;
}

LPCSTR Io::getImageName() {
	return TEXT("Bitmaps/Io.bmp");
}

rotationCoordinates Io::getSpinRotationCoordinates() {
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Io::getOrbitCoordinates() {
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Io::getInitialIncline() {
	return 25;
}

double Io::getTiltAngle() {
	return 0.05;
}
