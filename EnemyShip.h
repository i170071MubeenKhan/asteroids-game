#pragma once
#include "SpaceObjects.h"
class EnemyShip :
	public SpaceObjects
{
	float x, y,rad,angle;
	float Cx, Cy;
	int check,cCheck;
	float speed;
public:
	EnemyShip();
	void Draw_BigEnemyShip();
	void Draw_SmallEnemyShip();
	void WrapCoordinates();
	void Thurst();
	void setRadius(int);
	int getRadius();
	float get_Angle();
	void set_Angle(float);
	int getCheck();
	void setCheck(int);
	int getComplexCheck();
	void setComplexCheck(int);
	~EnemyShip();

	 float getCenterX();
	 float getCenterY();
	 const float get_maxX();
	 const float get_maxY();
	 const int get_maxLives();

};

