#pragma once

#include "Planet.h"

class Uranus : public Planet {
	public:
		Uranus(void); //Default constructor
		Uranus(double depthValue); //Constructor with depth
		~Uranus(void); //Default destructor
		double getRadius(); //Gets planet radius
		double getSpinPeriod(); //Get planet spin period
		double getOrbitPeriod(); //Get orbit period

	protected:
		LPCSTR	getImageName(); //Get texture image name
		Coordinates	 getPathToOrbitCenter(); //Get path to center
		rotationCoordinates	getSpinRotationCoordinates(); //Get spin rotation coordinates
		rotationCoordinates	getOrbitCoordinates(); //Get orbit coordinates
		double getInitialIncline(); //Get initial include
		double getTiltAngle(); //Get tilt angle
};