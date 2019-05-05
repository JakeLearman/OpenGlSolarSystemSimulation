#pragma once

#include <vector>
#include "SpaceSphere.h"
#include "camera.h"
#include "Sun.h"

class SolarSystem{
	public:
		SolarSystem(void); //Default constructor
		~SolarSystem(void); //Default destructor
		void setUpObjectsTextures(void); //Sets up objects textures
		void display(Camera *camera); //Display sets up initial camera view
		void timeObjectsMovement(void); //Sets up time for model so everything moves
		double getRotationSpeed(void); //Gets rotation speed
		void setRotationSpeed(double speed); //Sets rotation speed

	private:
		Star *sun; //Pointer to the sun object
		Bitmap skyBoxImages[6]; //Array to hold skybox images
		GLuint skyboxTextures[6]; //Array to hold skybox textures

	protected:
		double currentEarthRotation; //Variable to keep track of Earth days
		double earthDaysPassed; //Variable to keep track of completed Earth days
		double addEarthDay; //Adds earth day
		double maxEarthDays; //Limit of earth days
		std::vector<SpaceSphere*> celestials; //Vector to hold all celestial objects added to solar system
		void update(void); //Update the solar system model
		void setUpSkyBoxTextures(void); //Set up skybox textures
		void drawSkybox(float x, float y, float z, float width, float height, float length); //Draws the skybox

};

