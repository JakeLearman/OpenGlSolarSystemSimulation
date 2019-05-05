#pragma once

#include "SpaceSphere.h"
#include "Planet.h"

//The Satellite class is a subclass of spacesphere used to create objects that orbit other objects

class Satellite : public SpaceSphere{
	public:
		Satellite(void) : SpaceSphere() { } //Default constructor same as spaceSpheres
		Satellite(double depthValue, Planet *planet); //Secondary constructor with takes in depth and the planet the satellite is orbiting
		virtual ~Satellite(void) = 0; //Default virtual destructor
		Planet* getOrbitingPlanet(void); //Function which returns orbiting planet
		void draw(void); //Draws satellite
	private:
		Planet *planet; //Pointer to orbiting planet
	protected:
		void setOrbitingPlanet(Planet *planet); //Setter for orbiting planet

};

