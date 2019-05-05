#pragma once

#include "SpaceSphere.h"
#include "Particles.h"

// The STAR_GLOW type is used to declare the type of lighting used when applied to a star

typedef enum STAR_GLOW{
	STAR_GLOW_PARTICLES //Particles will add a particle effect
} STAR_GLOW;

class Star : public SpaceSphere{ //Star is a subclass of Spacesphere
	public:
		Star(void); //Default constructor
		Star(double depthValue); //Constructor with depth relative to the center of the galaxy
		virtual ~Star(void) = 0; //Purely virtual destructor to enable destruction via pointer
		void drawShining(STAR_GLOW shineWith); //add lighting to the star
		void draw(void); //draw the star
		void setUpTextures(void); //add texture to star object
	private:
		Bitmap particleImage; //Bitmap file to hold image used for particle effect
		Particles particles; //Instance of particle class struct
 		GLuint particleTexture; //The GLU instanance of the particle texture

	protected:
		void drawAllParticles(void); //Draws all particles
		void drawParticle(Particle currentParticle); //Draws next particle
};

