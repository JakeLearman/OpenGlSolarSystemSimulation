#pragma once

#include "satellite.h"

class Io : public Satellite {
public:
	Io(void);
	Io(double depthValue, Planet *planet);
	~Io(void);

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

