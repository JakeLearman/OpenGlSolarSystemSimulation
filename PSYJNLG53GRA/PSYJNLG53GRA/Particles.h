#pragma once

//Several constant values 

const int NUMBER_OF_PARTICLES = 800; //Number of particles on screen
const float MAX_ROTATION = 360; //Max rotaton
const float MIN_ROTATION = 0; //Min rotation
const float MIN_TRANS = .005; //min transparancy
const float MAX_TRANS = .03; //max transparancy
const float MIN_DELTA_ROTATION = 0.5; //Minimum rotation difference
const float MAX_DELTA_ROTATION = 3.0; //maximun rotation difference
const float MIN_DELTA_SURFACE = .005; //minimum surface delta
const float MAX_DELTA_SURFACE = .01; //maximum surface delta
const int MIN_LIFETIME = 10; // minimum lifetime
const int MAX_LIFETIME = 25; //maximun lifetime 
const int DELTA_LIFETIME = 1; //Delta lifetime

//A particle object with its parameters

struct Particle{
		float sideRotation, verticalRotation, surfaceTranslationFactor; 
		float sideDifference, verticalDifference, surfaceDifference;
		int lifetime;
};
		
class Particles{
	public: 
		Particle getNextParticle(); //Gets the next particle
		void updateAll(); //update all particles
		int getNumberOfParticles(); //get current number of particles
		Particles(); //constructor
	private:
		int currentParticle; //Current particle being drawn
		Particle particles[NUMBER_OF_PARTICLES]; //particle counter
		float generateRandomNumber(float lower, float upper); //RNG generator with upper and lower bounds
		Particle generateNewParticle(); //Create new particle
};
