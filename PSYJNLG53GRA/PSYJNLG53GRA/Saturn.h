#pragma once

#include "Planet.h"

class Saturn : public Planet{
	public:
		Saturn(void); //Default constructor
		Saturn(double depthValue); //Constructor with depth
		~Saturn(void); //Default destructor
		double getRadius(); //Gets planet radius
		double getSpinPeriod(); //Get planet spin period
		double getOrbitPeriod(); //Get orbit period
		void setUpTextures(void); //Sets up textures
		void draw(); //Draws Saturn

	protected:
		LPCSTR	getImageName(); //Get texture image name
		Coordinates	 getPathToOrbitCenter(); //Get path to center
		rotationCoordinates	getSpinRotationCoordinates(); //Get spin rotation coordinates
		rotationCoordinates	getOrbitCoordinates(); //Get orbit coordinates
		double getInitialIncline(); //Get initial include
		double getTiltAngle(); //Get tilt angle
		Bitmap ringImage; //Variable to hold ring image
		void drawRing(void); //draw the ring
};
