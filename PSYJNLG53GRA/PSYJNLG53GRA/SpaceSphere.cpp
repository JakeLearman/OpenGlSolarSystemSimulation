#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "SpaceSphere.h"
#include "glut.h"

const double SpaceSphere::sphereDrawnAngle = -90.0;

SpaceSphere::SpaceSphere(void){ //Default Consturctor
	this->setOrbitRotationAngle(0.0);
	this->setSpinRotationAngle(0.0);
	this->setDepthValue(0.0);
}

SpaceSphere::SpaceSphere(double depthValue){ //Constructor accounting for depth
	this->setDepthValue(depthValue);
}

GLuint SpaceSphere::getTexture(void){ //Returns the texture
	return this->texture;
}

double SpaceSphere::getDepthValue(void){ //Returns the depth
	return this->depthValue;
}

void SpaceSphere::setDepthValue(double depth){ //Sets the depth
	this->depthValue = depth;
}

double SpaceSphere::getSpinRotationAngle(void){ //Gets spin rotation angle
	return this->spinRotationAngle;
}

void SpaceSphere::setSpinRotationAngle(double angle){ //Sets spin rotation angle
	this->spinRotationAngle = angle;
}

double SpaceSphere::getOrbitRotationAngle(void){ //Gets orbit rotation angle
	return this->orbitRotationAngle; 
}

void SpaceSphere::setOrbitRotationAngle(double angle){ //Sets orbit rotation angle
	this->orbitRotationAngle = angle;
}


void SpaceSphere::setUpTextures(void){ //Loads image file into GLunit texture
	this->image.loadFile(this->getImageName());
	GLuint imgTexture = this->getTexture();
	glGenTextures(1, &imgTexture);
}

void SpaceSphere::draw(void){ //Draws the sphere
	GLUquadricObj* quadro = gluNewQuadric(); //Creates new quadratic object
	gluQuadricNormals(quadro, GLU_SMOOTH); //Gets its normals as smooth
	gluQuadricDrawStyle(quadro, GLU_FILL); //Sets it draw style as fill
	gluQuadricTexture(quadro, GL_TRUE);

	glEnable(GL_TEXTURE_2D);
	glPushMatrix();	{
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glPushMatrix();{
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			//Applies the texture as a 2D image using correct bit values
			glTexImage2D(GL_TEXTURE_2D, 0, 3, this->image.getWidth(), this->image.getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, this->image.getBits());
			//Applies appropriate rotation parameters
			this->orbitalRotation();
			this->spinRotation();
			this->initialRotation();

			glDepthFunc(this->getDepthValue());
			glBindTexture(GL_TEXTURE_2D, this->getTexture()); //Binds the texture
			gluSphere(quadro, this->getRadius(), this->getSphereSlices(), this->getSphereStacks()); //Draws the sphere
		}
		glPopMatrix();
	}
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(quadro);
}

void SpaceSphere::orbitalRotation(void){ //Creates rotation around the center 
	if (this->getOrbitPeriod() != 0.0){
		rotationCoordinates orbit = this->getOrbitCoordinates();
		Coordinates distance = this->getPathToOrbitCenter(); //Gets distance from center

		glRotated(this->getInitialIncline(), 0.0, 0.0, 1.0);
		glRotated(orbit.angle, orbit.x, orbit.y, orbit.z);
		glTranslated(distance.x, distance.y, distance.z);
	}
}

void SpaceSphere::spinRotation(void){ //Sets spining up
	if (this->getSpinPeriod() != 0.0){
		rotationCoordinates spin = this->getSpinRotationCoordinates();
		glRotated(spin.angle, spin.x, spin.y, spin.z); //Rotates sphere using relevant spin values
	}
}

void SpaceSphere::initialRotation(void){//Sets initial rotation
	rotationCoordinates init = this->getInitialRotationCoordinates(); 
	if (init.angle != 0.0){
		glRotated(init.angle, init.x, init.y, init.z);
	}
}

SpaceSphere::~SpaceSphere(void) { /* pure virtual destructor */ }

rotationCoordinates SpaceSphere::getInitialRotationCoordinates(){ //Gets initial rotation coords
	return rotationCoordinates(this->sphereDrawnAngle, 1.0, 0.0, 0.0);
}

double SpaceSphere::getTiltAngle(void){ //Gets tilt angle
	return 0.0;
}

double SpaceSphere::getSphereSlices(void){ //Gets sphere slices
	return 40.0;
}

double SpaceSphere::getSphereStacks(void){ //Gets sphere stacks
	return 32.0;
}