#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Star.h"

/*
The purpose of the Star class is to act as a default superclass for any stars being created within the defined galaxy.

*/

Star::Star() : SpaceSphere() { } //Default constructor

Star::Star(double depthValue) : SpaceSphere(depthValue) { } //Constructor accounting for depth

Star::~Star(void) { } //Destructor

void Star::setUpTextures(void){ //Sets up textures for the star
	SpaceSphere::setUpTextures(); //Calls superclass function
	this -> particleImage.loadFile (TEXT("Bitmaps/particle.bmp")); //Adds particle texture
	GLuint texture = this -> particleTexture;
	glGenTextures(1, &texture); //Loads particle texture into memory
}

void Star::draw(){ 
	SpaceSphere::draw(); //Draws star using superclass fuction
}

void Star::drawShining(STAR_GLOW shineWith) { //Draws shining effect
	if (shineWith == STAR_GLOW_PARTICLES){ //If particles are being used
		glEnable(GL_BLEND);{ //Enable blending
			glDepthMask(GL_FALSE); 
			glBlendFunc(GL_SRC_COLOR, GL_ONE);
			this -> drawAllParticles(); //Draw all particles
			glDepthMask(GL_TRUE);
		}
		glDisable(GL_BLEND); //End blending
	}
}

void Star::drawAllParticles(){ //Draws all particles
	glEnable(GL_TEXTURE_2D); //Enables particle texturing
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//An image of relevant size is drawn
	glTexImage2D(GL_TEXTURE_2D, 0, 3, this -> particleImage.getWidth(), this -> particleImage.getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, this -> particleImage.getBits()); 
	glBindTexture(GL_TEXTURE_2D, particleTexture); //Particle texture is applied
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //Modulation is enabled

	particles.updateAll(); //All particles are updated
	for(int i = 0; i < particles.getNumberOfParticles(); i++){ //All particles are drawn in a loop
		drawParticle(particles.getNextParticle());
	}
}

void Star::drawParticle(Particle currentParticle){ //draws a particle 
	glPushMatrix();	{ //Enable a matrix
		//Set up correct rotation for drawing
		glRotatef(currentParticle.sideRotation, 0, 1, 0);
		glRotatef(currentParticle.verticalRotation, 0, 0, 1);
		glPushMatrix();{	//Push a matrix for the particles
			glTranslatef(1.2 + currentParticle.surfaceTranslationFactor, 0, 0);
			glScalef(0.5, 0.5, 1.0);
			//A triangle strip is used to build a 2D space for the particle to be in
			glBegin(GL_TRIANGLE_STRIP);{
				glTexCoord2d(1,1); 
				glVertex3f(0.5f, 0.5f, 0.0f); 
				glTexCoord2d(0,1);
				glVertex3f(-0.5f, 0.5f, 0.0f);
				glTexCoord2d(1,0); 
				glVertex3f(0.5f, -0.5f, 0.0f);
				glTexCoord2d(0,0); 
				glVertex3f(-0.5f, -0.5f, 0.0f);
			}
			glEnd();

			glBegin(GL_TRIANGLE_STRIP);{
				glTexCoord2d(1,1); 
				glVertex3f(-0.5f, 0.5f, 0.0f); 
				glTexCoord2d(0,1);
				glVertex3f(0.5f, 0.5f, 0.0f); 
				glTexCoord2d(1,0); 
				glVertex3f(-0.5f, -0.5f, 0.0f);
				glTexCoord2d(0,0); 
				glVertex3f(0.5f, -0.5f, 0.0f);
			}
			glEnd();
		}
		glPopMatrix();
		//First matrix is closed
		//Translation and rotation occurs to move particle drawing location
		glTranslatef(1.0 + currentParticle.surfaceTranslationFactor, 0, 0);
		glRotatef(90, 0, 1, 0);
		glScalef(0.5, 0.5, 1.0);
		//Another triangle strip is used to built 2D space
		glBegin(GL_TRIANGLE_STRIP);{
			glTexCoord2d(1,1); 
			glVertex3f(-0.5f, 0.5f, 0.0f);
			glTexCoord2d(0,1);
			glVertex3f(0.5f, 0.5f, 0.0f); 
			glTexCoord2d(1,0); 
			glVertex3f(-0.5f, -0.5f, 0.0f); 
			glTexCoord2d(0,0); 
			glVertex3f(0.5f, -0.5f, 0.0f); 
		}
		glEnd();
	}
	glPopMatrix(); //Close the matrix
}
