#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Saturn.h"
#include "glut.h"

Saturn::Saturn(void) : Planet() { } //Default constructor

Saturn::Saturn(double depthValue) : Planet(depthValue) { } //Constructor accounting for planetary depth

Saturn::~Saturn(void) { } //Default destructor

double Saturn::getRadius(){ //Gets planetary radius
	return 0.5;
}

Coordinates Saturn::getPathToOrbitCenter(){ //Gets path to center
	return Coordinates(7.8, 0.0, 0.0);
}

double Saturn::getOrbitPeriod(){ //Get orbit path
	return 10752.9;
}

double Saturn::getSpinPeriod(){ //Get spin period
	return 0.426;
}

LPCSTR Saturn::getImageName(){ //Gets texture name
	return TEXT("Bitmaps/saturn.bmp");
}

rotationCoordinates Saturn::getSpinRotationCoordinates(){ //Gets spin rotation coords
	return rotationCoordinates(this->getSpinRotationAngle(), 0.0, 1.0, 0.0);
}

rotationCoordinates Saturn::getOrbitCoordinates(){ //Gets orbit coords
	return rotationCoordinates(this->getOrbitRotationAngle(), 0.0, 1.0, 0.0);
}

double Saturn::getInitialIncline(){ //Gets initial incline
	return 2.0;
}

double Saturn::getTiltAngle(){ //Gets tilt angle
	return 26.73;
}

void Saturn::setUpTextures(void){ //Sets up textures
	Planet::setUpTextures(); //Sets up main body of planet like every other planet
	this -> ringImage.loadFile(TEXT("Bitmaps/saturnRings.bmp")); //Loads ring file image
	GLuint image = this -> getTexture();
	glGenTextures(1, &image); //Generate a texture based upon ring image
}

void Saturn::draw(){ //Drawing saturn
	Planet::draw(); //Draw the main part of the planet
	this -> drawRing(); //Draw the ring
}

void Saturn::drawRing(){ //Draw the ring
	GLUquadricObj* quadro = gluNewQuadric(); //Create new quadratic object
	gluQuadricNormals(quadro, GLU_SMOOTH);	//Sets smooth normals throughout shape
	gluQuadricTexture(quadro, GL_TRUE);	 //Enable texturing
	gluQuadricDrawStyle(quadro, GLU_FILL); //Enable fillable object
	glEnable(GL_TEXTURE_2D); //Enable 2D texturing
	glPushMatrix();{ //Create matrix for ring
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //Set up texturing environment
		glPushMatrix();{ //Create matrix for texturing
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Enable linear texturing
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
			glTexImage2D(GL_TEXTURE_2D, 0, 3, this->ringImage.getWidth(), this->ringImage.getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, this->ringImage.getBits()); //Assign ring image 

			//Add planetary attributes to ring
			glRotated(this ->getInitialIncline(), 0.0, 0.0, 1.0); 
			glRotated(this ->getOrbitCoordinates().angle, 0.0, 1.0, 0.0);
			glTranslated(this -> getPathToOrbitCenter().x, 0.0, 0.0 );

			rotationCoordinates spin = this ->getSpinRotationCoordinates(); //Set spin of ring
			glRotated(spin.angle, spin.x, spin.y, spin.z); //Assign spin to gl object
			glRotated(this->sphereDrawnAngle, 1.0, 0.0, 0.0); 
			glScaled(1.0, 1.0, 0.001); //Scale texture
			glBindTexture(GL_TEXTURE_2D, this->getTexture()); //Bind texture to object
			glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP); //Set up texture mapping
			glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glutSolidTorus(this -> getRadius() * 0.7, this->getRadius() * 2, 3, 100); //Build torus shape to house texture
			glDisable(GL_TEXTURE_GEN_S);
			glDisable(GL_TEXTURE_GEN_T);
		}
		glPopMatrix(); //Close texture matrix
	}
	glPopMatrix(); //Close ring matrix
	glDisable(GL_TEXTURE_2D); //Disable 2D texture
	gluDeleteQuadric(quadro); //Delete quadratic object
}
