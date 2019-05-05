#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "SpaceStation.h"
#include "glut.h"

SpaceStation::SpaceStation(void) : Satellite() { }

SpaceStation::SpaceStation(double depthValue, Planet *planet) : Satellite(depthValue, planet) { }

SpaceStation::~SpaceStation(void) { }

double SpaceStation::getRadius() {
	return 0.04;
}

Coordinates SpaceStation::getPathToOrbitCenter() {
	return Coordinates(0.5, 0.0, 0.0);
}

double SpaceStation::getOrbitPeriod() {
	return 50;
}

void SpaceStation::setUpTextures(void){
	Satellite::setUpTextures();
	this->panelImage.loadFile(TEXT("Bitmaps/solarPanel.bmp"));
	GLuint image = this->getTexture();
	glGenTextures(1, &image);
}



double SpaceStation::getSpinPeriod() {
	return 27.32166;
}

LPCSTR SpaceStation::getImageName() {
	return TEXT("Bitmaps/mainSatellite.bmp");
}

rotationCoordinates SpaceStation::getSpinRotationCoordinates() {
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates SpaceStation::getOrbitCoordinates() {
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double SpaceStation::getInitialIncline() {
	return 25;
}

void SpaceStation::draw(void){
	Satellite::draw();
	//this->drawPanel();
}

double SpaceStation::getTiltAngle() {
	return 1.5424;
}

void SpaceStation::drawPanel(void){
	
}