#pragma once

#include "Planet.h"

class Venus : public Planet {
	public:
		Venus(void); //Default constructor
		Venus(double depthValue); //Constructor with depth
		~Venus(void); //Default destructor
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