#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "Particles.h"
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <time.h>

Particles::Particles(){ //Constructor
	currentParticle = 0;
	for(int i = 0; i < NUMBER_OF_PARTICLES; i++){ //Will keep constructing until limit 
		particles[i] = generateNewParticle();
	}
}

Particle Particles::generateNewParticle(){ //Make a new particle
	Particle newParticle;
	//Attributes are randomised using random numbers
	newParticle.sideRotation = generateRandomNumber(MIN_ROTATION, MAX_ROTATION);
	newParticle.verticalRotation = generateRandomNumber(MIN_ROTATION, MAX_ROTATION);
	newParticle.surfaceTranslationFactor = generateRandomNumber(MIN_TRANS, MAX_TRANS);
	newParticle.sideDifference = generateRandomNumber(MIN_DELTA_ROTATION, MAX_DELTA_ROTATION);
	newParticle.verticalDifference = generateRandomNumber(MIN_DELTA_ROTATION, MAX_DELTA_ROTATION);
	newParticle.surfaceDifference = generateRandomNumber(MIN_DELTA_SURFACE, MAX_DELTA_SURFACE);
	newParticle.lifetime = (int)generateRandomNumber(MIN_LIFETIME, MAX_LIFETIME);
	return newParticle; //Returns new particle
}

Particle Particles::getNextParticle(){ //Returns next particle
	currentParticle = (currentParticle == NUMBER_OF_PARTICLES) ? 0 : currentParticle; //If there are any particles, return the latest one
	return particles[currentParticle++]; //Returned incremented latest particle
}

int Particles::getNumberOfParticles(){ //Returns number of particles
	return NUMBER_OF_PARTICLES;
}


//RNG generator based on random time seed
float Particles::generateRandomNumber(float lower, float upper){
	static bool firstTime = true;
	time_t randomNumberSeed;

	if (firstTime){
		time(&randomNumberSeed);
		srand(randomNumberSeed);
		firstTime = false;
	}
	return (lower + ((upper - lower) * (float(rand()) / RAND_MAX)));
}

void Particles::updateAll(){ //Update all particles
	for(int i = 0; i < NUMBER_OF_PARTICLES; i++){
		if(particles[i].lifetime == 0){ // If a particle has died
			particles[i] = generateNewParticle(); //Make a new one
		} else{ //Otherwise make the appropriate additions to the particles attributes
			particles[i].sideRotation += particles[i].sideDifference;
			particles[i].verticalRotation += particles[i].verticalDifference;
			particles[i].surfaceTranslationFactor += particles[i].sideDifference;
			particles[i].lifetime -= DELTA_LIFETIME;
		}
	}
}
