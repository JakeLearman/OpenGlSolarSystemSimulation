#pragma once

#include "Planet.h"

class Earth : public Planet{
	public:
		Earth(void); //Default constructor
		Earth(double depthValue); //Constructor with depth
		~Earth(void); //Default destructor
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
