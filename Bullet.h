#pragma once
#include "SpaceObjects.h"
class Bullet :
	public SpaceObjects
{
	float x, y, angle;
	int rad;
public:
	Bullet(float X = 400 ,float Y = 320 ,float theta = 90);

	float get_X();
	void set_X(float);
	float get_Y();
	void set_Y(float);
	float get_Angle();
	void set_Angle(float);
	void  Draw_Bullets(float X, float Y);
	 void WrapCoordinates();
	 float getCenterX();
	 float getCenterY();
	 void setRadius(int);
	 int getRadius();
	 void Thurst();
	 const float get_maxX();
	 const float get_maxY();
	 const int get_maxLives();
	 int getCheck();
	 void setCheck(int);

	~Bullet();
};

