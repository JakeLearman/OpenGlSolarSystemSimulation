#pragma once

//Coordinate type
typedef struct Coordinates{
	public:
		double x;
		double y; //X, Y and Z value for coordinates in a 3D space
		double z;

		Coordinates(){ 
			this -> x = 0.0; 
			this -> y = 0.0;  //Constructor setting x,y and z to 0
			this -> z = 0.0; 
		}
		Coordinates(double x, double y, double z){ 
			this -> x = x; 
			this -> y = y;  //Constructor passing in x, y and z values
			this -> z = z; 
		}
		Coordinates operator+ (Coordinates vector){
			return Coordinates(vector.x + this -> x, vector.y + this -> y, vector.z + this -> z); //Adding coordinates to a vector
		}
		Coordinates operator- (Coordinates vector){
			return Coordinates(this -> x - vector.x, this -> y - vector.y, this -> z - vector.z); //Minusing coordinates to a vector
		}

		Coordinates operator* (float number){
			return Coordinates(this -> x * number, this -> y * number, this -> z * number); //Multiplying some coordinates by a number
		}
		Coordinates operator/ (float number){
			return Coordinates(this -> x / number, this -> y / number, this -> z / number); //Diving some coordinates by a number
		}
		bool isZero (){
			return (this -> x == 0.0)  && (this -> y == 0.0) && (this -> z == 0.0);  //Check is coordinates are zero
		}
} Coordinates;

//A coordinate type accounting for rotation

typedef struct rotationCoordinates : public Coordinates{
	public:
		double angle; //Defaiult angle
		rotationCoordinates(double angle, double x, double y, double z) : Coordinates(x, y, z){ //constructor angle parameter to rotationCoordinate instance
			this -> angle = angle;
		}
} rotationCoordinates;
