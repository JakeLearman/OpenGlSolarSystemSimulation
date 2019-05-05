#pragma once

#include "bitmap.h"
#include <GL/gl.h>
#include "Coordinates.h"

class SpaceSphere{
	public:
		SpaceSphere(void); //Default constructor
		SpaceSphere(double depthValue); //Secondary constructor with depth value relative to center 
		virtual ~SpaceSphere(void) = 0; //Purely virtual destructor


		/*
			The following virtual functions set default return values functions which are overridden by sub classes
		*/

		virtual double getInitialIncline() = 0; //Gets initial incline
		virtual Coordinates  getPathToOrbitCenter() = 0; //Gets distance to center of orbit
		virtual double getRadius() = 0; //Gets radius of space sphere
		virtual double getSpinPeriod() = 0;  //gets spin period
		virtual double getOrbitPeriod() = 0; //gets orbit period
		virtual rotationCoordinates getSpinRotationCoordinates() = 0; //gets coordinates for spin rotation
		virtual rotationCoordinates getOrbitCoordinates() = 0; //gets coordinates for orbit

		GLuint getTexture(void); //Gets texture used for sphere
		double getDepthValue(void); //Gets depth from center of model
		void setDepthValue(double depth); //Sets depth from center of model
		double getSpinRotationAngle(void); //Gets spin rotation angle
		void setSpinRotationAngle(double angle); //Sets spin rotation angle
		double getOrbitRotationAngle(void); //Gets orbit rotation angle
		void setOrbitRotationAngle(double angle); //Sets orbit rotation angle
		virtual void setUpTextures(void); //Sets up texture for sphere object
		virtual void draw(void); //Draws sphere object

	private:
		//The following are variables used to hold named value
		double spinRotationAngle; 
		double orbitRotationAngle;
		double depthValue;
		Bitmap image;
		GLuint texture;
		void orbitalRotation(void);
		void spinRotation(void);
		void initialRotation(void);

	protected:
		static const double sphereDrawnAngle;
		virtual LPCSTR getImageName() = 0; //Pointer to file name path
		virtual double getTiltAngle(); //Gets titls angle
		virtual rotationCoordinates	getInitialRotationCoordinates(); //Gets initial rotation coordinates
		virtual double getSphereSlices(); //Gets sphere slices
		virtual double getSphereStacks(); //Gets sphere stacks
};
