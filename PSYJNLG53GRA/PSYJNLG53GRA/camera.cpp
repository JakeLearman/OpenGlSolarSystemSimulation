#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "camera.h"
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include "glut.h"

Camera::Camera(){ //Constructor
	//Set initial value as default view
	Coordinates newZero = Coordinates();
	Coordinates newView = Coordinates(0.0, 1.0, 0.5);	
	Coordinates newVector = Coordinates(0.0, 0.0, 1.0);
 
	//Assign values
	position = newZero;
	view = newView;
	vector = newVector;
}


 //Used to position camera to parameter values
void Camera::positionCamera(float positionX, float positionY, float positionZ, float viewX,	 float viewY, float viewZ, float vectorX, float vectorY, float vectorZ){
	//Create new attributes based off parameters
	Coordinates newPosition	= Coordinates(positionX, positionY, positionZ);
	Coordinates newView	= Coordinates(viewX, viewY, viewZ);
	Coordinates newVector = Coordinates(vectorX, vectorY, vectorZ);
	
	//Assign values
	position = newPosition;
	view = newView;
	vector = newVector;
}

//Used to rotate the view
void Camera::rotateView(float angle, float x, float y, float z){
	Coordinates newView;
	Coordinates currentView;
 
	//Calculate current view using current values
	currentView.x = view.x - position.x;
	currentView.y = view.y - position.y;
	currentView.z = view.z - position.z;
 
	//Work out relevant trig values
	float cosTheta = (float)cos(angle);
	float sinTheta = (float)sin(angle);
 
	//Work out new x value
	newView.x  = (cosTheta + (1 - cosTheta) * x * x)	* currentView.x;
	newView.x += ((1 - cosTheta) * x * y - z * sinTheta)	* currentView.y;
	newView.x += ((1 - cosTheta) * x * z + y * sinTheta)	* currentView.z;
 
	//Work out new y value
	newView.y  = ((1 - cosTheta) * x * y + z * sinTheta)	* currentView.x;
	newView.y += (cosTheta + (1 - cosTheta) * y * y)	* currentView.y;
	newView.y += ((1 - cosTheta) * y * z - x * sinTheta)	* currentView.z;
 
	//Work out new z value
	newView.z  = ((1 - cosTheta) * x * z - y * sinTheta)	* currentView.x;
	newView.z += ((1 - cosTheta) * y * z + x * sinTheta)	* currentView.y;
	newView.z += (cosTheta + (1 - cosTheta) * z * z)	* currentView.z;
 
	//Assign new values
	view.x = position.x + newView.x;
	view.y = position.y + newView.y;
	view.z = position.z + newView.z;
}

//Used to rotate camera around a center point
void Camera::rotateAroundPoint(Coordinates center, float angle, float x, float y, float z){
	Coordinates newPosition;
	Coordinates difference = position - center;

	//Work out relevant trig values
	float cosTheta = (float)cos(angle);
	float sinTheta = (float)sin(angle);
 
	//Work out new x position
	newPosition.x  = (cosTheta + (1 - cosTheta) * x * x) * difference.x;
	newPosition.x += ((1 - cosTheta) * x * y - z * sinTheta) * difference.y;
	newPosition.x += ((1 - cosTheta) * x * z + y * sinTheta) * difference.z;
 
	//Work out new y value
	newPosition.y  = ((1 - cosTheta) * x * y + z * sinTheta) * difference.x;
	newPosition.y += (cosTheta + (1 - cosTheta) * y * y) * difference.y;
	newPosition.y += ((1 - cosTheta) * y * z - x * sinTheta) * difference.z;

	//Work our new z value
	newPosition.z  = ((1 - cosTheta) * x * z - y * sinTheta) * difference.x;
	newPosition.z += ((1 - cosTheta) * y * z + x * sinTheta) * difference.y;
	newPosition.z += (cosTheta + (1 - cosTheta) * z * z) * difference.z;

	//Assign new position
	position = center + newPosition;
}

//Used to move camera
void Camera::moveCamera(float speed){
	Coordinates vector = view - position;

	//Work out new position by adjusting the vector
	position.x += vector.x * speed;
	position.y += vector.y * speed;
	position.z += vector.z * speed;
	//Work out new view using vector and speed
	view.x += vector.x * speed;
	view.y += vector.y * speed;
	view.z += vector.z * speed;
}
//Work out cross join between 2 vectors
Coordinates cross(Coordinates vector1, Coordinates vector2) {
	Coordinates normal = Coordinates(); //Assign the normal
	//Calculate the X, Y and Z value for the normal
	normal.x = ((vector1.y * vector2.z) - (vector1.z * vector2.y));
	normal.y = ((vector1.z * vector2.x) - (vector1.x * vector2.z));
	normal.z = ((vector1.x * vector2.y) - (vector1.y * vector2.x));
	return normal;
}

//Gets the value of the normal
float getMagnitude(Coordinates normal) {
	return (float)sqrt((normal.x * normal.x) + (normal.y * normal.y) + (normal.z * normal.z));
}

//Used to normalise the inputted coordinates
Coordinates normalize(Coordinates coordinates) {
	float magnitude = getMagnitude(coordinates);
	coordinates = coordinates / magnitude;
	return coordinates;
}

//Used to set the mouse as able to navigate the scene
void Camera::setViewByMouse() { 
	POINT mousePos; //Set mouse position
	int middleX = glutGet(GLUT_WINDOW_WIDTH) >> 1;
	int middleY = glutGet(GLUT_WINDOW_HEIGHT) >> 1;
	float angleY = 0.0f;
	float angleZ = 0.0f;
	static float currentRotation = 0.0f;
	GetCursorPos(&mousePos); //Assign pointer to cursor position

	if ((mousePos.x == middleX) && (mousePos.y == middleY)) { //Check that mouse is the center of the scene
		return;
	}

	SetCursorPos(middleX, middleY); //Otherwise set cursor as middle of scene
	angleY = (float)((middleX - mousePos.x)) / 1000.0f;
	angleZ = (float)((middleY - mousePos.y)) / 1000.0f;
	static float lastRotation = 0.0f;
	lastRotation = currentRotation;
	if (currentRotation > 1.0f) { //Check for rotation rightward
		currentRotation = 1.0f;
		if (lastRotation != 1.0f) {
			Coordinates vetricalAxis = cross(view - position, vector);
			vetricalAxis = normalize(vetricalAxis);
			//Rotate the view if changes are made
			this->rotateView(1.0f - lastRotation, vetricalAxis.x, vetricalAxis.y, vetricalAxis.z);
		}
	}
	else if (currentRotation < -1.0f) { //Check for rotation leftward
		currentRotation = -1.0f;
		if (lastRotation != -1.0f) {
			Coordinates vetricalAxis = cross(view - position, vector);
			vetricalAxis = normalize(vetricalAxis);
			//Rotate the view if changes are made
			this->rotateView(-1.0f - lastRotation, vetricalAxis.x, vetricalAxis.y, vetricalAxis.z);
		}
	}
	else { //Otherwise normalise and rotate
		Coordinates vetricalAxis = cross(view - position, vector);
		vetricalAxis = normalize(vetricalAxis);
		this->rotateView(angleZ, vetricalAxis.x, vetricalAxis.y, vetricalAxis.z);
	}
	this->rotateView(angleY, 0, 1, 0);
}