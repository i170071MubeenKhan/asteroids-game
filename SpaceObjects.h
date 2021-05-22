#pragma once

#include "util.h"
class SpaceObjects
{
public:
	SpaceObjects();

	virtual void WrapCoordinates() = 0;
	virtual float getCenterX() = 0;
	virtual float getCenterY() = 0;
	virtual void Thurst() = 0;
	virtual int getRadius() = 0;
	virtual void setRadius(int) = 0;
	virtual const float get_maxX() = 0;
	virtual const float get_maxY() = 0;
	virtual const int get_maxLives() = 0;
	virtual float get_Angle() = 0;
	virtual void set_Angle(float) = 0;

	//********** PlayerShip Functions **********

	virtual void Draw_Ship();
	virtual int get_Lives();
	virtual int get_Scores();
	virtual const int get_Left();
	virtual const int get_Right();
	virtual float get_Up();
	virtual const float get_X1();
	virtual const float get_Y1();
	virtual const float get_X2();
	virtual const float get_Y2();
	virtual const float get_X3();
	virtual const float get_Y3();
	virtual float getTimer();
	virtual void setTimer(float);
	virtual void set_Scores(int);
	virtual void set_Lives(int);
	virtual void set_Left(int);
	virtual void set_Right(int);
	virtual void set_Up(float);
	virtual void Reset_PlayerShip();
	virtual void Rotate_Left_PlayerShip();
	virtual void Rotate_Right_PlayerShip();

	//********** Bullets Functions **********
	virtual float get_X();
	virtual void set_X(float);
	virtual float get_Y();
	virtual void set_Y(float);
	virtual void  Draw_Bullets(float X, float Y);

	//********** EnemyShip Functions **********
	virtual void Draw_BigEnemyShip();
	virtual void Draw_SmallEnemyShip();
	virtual int getCheck();
	virtual void setCheck(int);

	//********** Asteroids Functions **********
	virtual void Draw_Asteroid(const int & cx, const int &cy, int radius, const ColorNames & cname = GREEN);
	virtual int getX();
	virtual int getY();
	virtual void setX(float);
	virtual void setY(float);
	virtual int getComplexCheck();
	virtual void setComplexCheck(int);

	virtual ~SpaceObjects();
};

