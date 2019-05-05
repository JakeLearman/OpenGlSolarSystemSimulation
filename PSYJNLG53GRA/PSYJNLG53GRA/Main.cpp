#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include "SolarSystem.h"
#include "glut.h"
#include <GL/gl.h>
#include <GL/GLU.h>
#include "camera.h"

const float movementSpeed = 0.005f;
const float acceleration = 10.0;
const int timerFrequency = 10;

const int windowWidth = 900;
const int windowHeight = 500;

SolarSystem *solarSystem;
Camera *camera;

void reshape(GLsizei w, GLsizei h);
void initOnReshape(double width, double height);
void display(void);
void keyboardPress(unsigned char pressedKey, int mouseXPosition, int mouseYPosition);
void timer(int);

int main(int argc, char **argv) {
	FreeConsole();

	camera = new Camera(); //Sets up new camera
	solarSystem = new SolarSystem(); //Sets up new solarsystem
	
	//Sets up OpenGL display settings
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutGameModeString("1366x768:64@80"); //Enables gaming mode for full screen
	glutEnterGameMode();
	glutSetCursor(GLUT_CURSOR_NONE);

	solarSystem->setUpObjectsTextures(); //Sets up all textures
	camera->positionCamera(0.0, 4.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //Sets camera to default position

	//Sets up OpenGl display and input functions
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardPress);
	glutTimerFunc(timerFrequency, timer, 0);
	glutMainLoop(); //Main loop of scene

	delete solarSystem; //Deletes solar system after main loop finishes
	delete camera; //Deletes camera after main loop finishes

	return 0;
}

void reshape(GLsizei w, GLsizei h){ //Reshaphes when appropriate
	glViewport(0, 0, w, h);
	initOnReshape(w, h);
}

void initOnReshape(double width, double height){ //Default reshape function
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	 
	double aspectRatio = width / height;

	gluPerspective(60.0, aspectRatio, 0.1, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display(void){ 
	camera -> setViewByMouse(); //Sets up camera to mouse position
	solarSystem -> display(camera); //Moves solar system to camera position
}

//Function for keyboard input
void keyboardPress(unsigned char pressedKey, int mouseXPosition, int mouseYPosition){
	switch(pressedKey){
		case 'w': //ALlows movement forwards
			camera -> moveCamera(movementSpeed);
			break;
		case 's': //Allows movement backwards
			camera -> moveCamera(-movementSpeed);
			break;
		case 'a': //Rotation around the camera leftward
			camera -> rotateAroundPoint(camera -> view, movementSpeed, 0, 1, 0);
			break;
		case 'd': //Rotation around the camera rightward
			camera -> rotateAroundPoint(camera -> view, -movementSpeed, 0, 1, 0);
			break;
		case '+': //Increases rotation speed
			solarSystem -> setRotationSpeed(solarSystem -> getRotationSpeed() * 2.0);
			break;
		case '-': //Decreases rotation speed
			solarSystem -> setRotationSpeed(solarSystem -> getRotationSpeed() * 0.5);
			break;
		case 27:{ //Exits the program
			if (glutGameModeGet(GLUT_GAME_MODE_ACTIVE) != 0) {
				glutLeaveGameMode();
				exit(0);
			}
			break;
		}
	}
}

//Sets up timer for synchronising movement
void timer(int){  
	solarSystem -> timeObjectsMovement();
	glutPostRedisplay();
	glutTimerFunc(timerFrequency, timer, 0);
}
