#pragma once
#include "SpaceObjects.h"
class PlayerShip :
	public SpaceObjects
{
	const float maxX, maxY, maxLives;
	int lives, scores;
	float x1, x2, x3, y1, y2, y3;
	float Cx, Cy;
	int left, right;
	float up,angle;
	int rad;
	float timer;
public:
	PlayerShip();
	float getCenterX();
	float getCenterY();
	const float get_maxX();
	const float get_maxY();
	const int get_maxLives();
	int get_Lives();
	int get_Scores();
	const int get_Left();
	const int get_Right();
	float get_Up();
	const float get_X1();
	const float get_Y1();
	const float get_X2();
	const float get_Y2();
	const float get_X3();
	const float get_Y3();
	float get_Angle();
	int getRadius();
	float getTimer();
	void setTimer(float);
	void set_Scores(int);
	void set_Lives(int);
	void setRadius(int);
	void set_Left(int);
	void set_Right(int);
	void set_Up(float);
	void set_Angle(float);
	void Reset_PlayerShip();
	void Draw_Ship();
	void WrapCoordinates();
	void Rotate_Left_PlayerShip();
	void Rotate_Right_PlayerShip();
	void Thurst();
	~PlayerShip();


	void Draw_EnemyShip();

	void Draw_Asteroid(const int & cx, const int &cy, int radius, const ColorNames & cname = RED);
};

