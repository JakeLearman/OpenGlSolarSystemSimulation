#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Satellite.h"

Satellite::~Satellite(void) { } //Destructor

Satellite::Satellite(double depthValue, Planet *planet) : SpaceSphere(depthValue){ //Constructor with depth and orbiting planet
	this -> setOrbitingPlanet(planet); //Sets orbiting planet to parameter
}

void Satellite::setOrbitingPlanet(Planet *planet){ //Sets orbiting planet of satellite
	this -> planet = planet; //Sets planet
}

Planet* Satellite::getOrbitingPlanet(void){ //Gets orbiting planet
	return this -> planet; //Returns the planet
}

void Satellite::draw(void){
	glPushMatrix();{ //Create matrix
		rotationCoordinates orbit = this -> getOrbitingPlanet() -> getOrbitCoordinates(); //Sets orbit 
		Coordinates distance = this -> getOrbitingPlanet() -> getPathToOrbitCenter(); //Sets distance
		glRotated(this -> getOrbitingPlanet() -> getInitialIncline(), 0.0, 0.0, 1.0);  //Sets rotation based upon orbit and incline
		glRotated(orbit.angle, orbit.x, orbit.y, orbit.z); //Rotates via vector
		glTranslated(distance.x, distance.y, distance.z); //Moves satellite to correct locaton
		SpaceSphere::draw(); //Draws satellite
	}
	glPopMatrix(); //Close matrix
}