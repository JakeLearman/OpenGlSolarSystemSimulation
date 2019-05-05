#pragma once

#include "Coordinates.h"

//Camera class makes use of coordinates to find and position on screen

class Camera {
	public:
		Coordinates position; //Position on screen
		Coordinates view; //Current View
		Coordinates vector; //Vector of location
		Camera(); //Constructor
		void positionCamera(float positionX, float positionY, float positionZ, float viewX,	 float viewY, float viewZ, float upVectorX, float upVectorY, float upVectorZ); //Position camera in a 3D space
		void moveCamera(float speed); //Move camera
		void rotateView(float angle, float x, float y, float z); //Rotate the current view
		void setViewByMouse(); //Change the view based on mouse movement
		void rotateAroundPoint(Coordinates vCenter, float angle, float x, float y, float z); //Rotate the view around a point
};