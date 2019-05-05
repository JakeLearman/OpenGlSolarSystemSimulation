#pragma once
#pragma once

#include "satellite.h"

class Europa : public Satellite {
public:
	Europa(void);
	Europa(double depthValue, Planet *planet);
	~Europa(void);

	double getRadius();
	double getSpinPeriod();
	double getOrbitPeriod();

protected:
	LPCSTR	getImageName();
	Coordinates	 getPathToOrbitCenter();
	rotationCoordinates	getSpinRotationCoordinates();
	rotationCoordinates	getOrbitCoordinates();
	double getInitialIncline();
	double getTiltAngle();
};