#pragma once

#include "satellite.h"

class SpaceStation : public Satellite {
public:
	SpaceStation(void);
	SpaceStation(double depthValue, Planet *planet);
	~SpaceStation(void);

	double getRadius();
	double getSpinPeriod();
	double getOrbitPeriod();
	void   setUpTextures(void);
	void   draw(void);

protected:
	Bitmap panelImage;
	LPCSTR	getImageName();
	Coordinates	 getPathToOrbitCenter();
	rotationCoordinates	getSpinRotationCoordinates();
	rotationCoordinates	getOrbitCoordinates();
	double getInitialIncline();
	double getTiltAngle();
	void drawPanel(void);
};