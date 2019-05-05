#pragma once

#include "SpaceSphere.h"

class Planet : public SpaceSphere {
	public:
		Planet(void) : SpaceSphere() { } //Default constructor
		Planet(double depthValue) : SpaceSphere(depthValue) { } //Secondary constructor with depth derived from superclass
		virtual ~Planet(void) = 0; //Default virutal destructor
};

