#pragma once
#include "SpaceObjects.h"

class Asteroids :
	public SpaceObjects
{
	float x, y;
	int rad,check,cCheck;
	float angle;
	int npoints, dtheta,stheta;
	float theta, *theta2;
public:
	Asteroids();
	void Draw_Asteroid(const int & cx, const int &cy, int radius, const ColorNames & cname = DARK_SEA_GREEN);
	float getCenterX();
	float getCenterY();
	void setX(float);
	void setY(float);
	void setRadius(int);
	int getRadius();
	int getCheck();
	void setCheck(int);
	float get_Angle();
	void set_Angle(float);
	int getX();
	int getY();
	int getComplexCheck();
	void setComplexCheck(int);
	void Thurst();
	~Asteroids();
	void WrapCoordinates();
	const float get_maxX();
	const float get_maxY();
	const int get_maxLives();
};


