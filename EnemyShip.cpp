#include "EnemyShip.h"



EnemyShip::EnemyShip() :
	x((rand() % 850) + 0), y((rand() % 600) + 0),
	rad(15), angle((rand() % 360) + -360),
	Cx(0), Cy(0),
	check((rand() % 10) + 1),cCheck(0),
	speed(0)
{

}

void EnemyShip::Draw_SmallEnemyShip()
{
	WrapCoordinates();
	DrawLine(x, y, x+30, y, 2, colors[RED]); // ______D
	DrawLine(x, y+10, x+30, y + 10, 2, colors[RED]); // ______U
	DrawLine(x-5, y+5, x + 35, y+5, 2, colors[RED]); // ______M

	DrawLine(x, y, x-5, y+5, 2, colors[RED]); // \L
	DrawLine(x-5, y+5, x, y+10, 2, colors[RED]); // /L

	DrawLine(x + 35, y + 5, x + 30, y + 10, 2, colors[RED]);// \R
	DrawLine(x + 30, y, x + 35, y + 5, 2, colors[RED]); // /R
	

	DrawLine(x+9, y+10, x+16, y+25, 2, colors[RED]); // /H
	DrawLine(x+16, y+25, x+21, y+10, 2, colors[RED]); // \H
}

void EnemyShip::Draw_BigEnemyShip()
{
	WrapCoordinates();
	DrawLine(x, y, x + 40, y, 2, colors[RED]); // ______D
	DrawLine(x, y + 10, x + 40, y + 10, 2, colors[RED]); // ______U
	DrawLine(x - 5, y + 5, x + 45, y + 5, 2, colors[RED]); // ______M

	DrawLine(x, y, x - 5, y + 5, 2, colors[RED]); // \L
	DrawLine(x - 5, y + 5, x, y + 10, 2, colors[RED]); // /L

	DrawLine(x + 45, y + 5, x + 40, y + 10, 2, colors[RED]);// \R
	DrawLine(x + 40, y, x + 45, y + 5, 2, colors[RED]); // /R


	DrawLine(x + 12, y + 10, x + 21, y + 30, 2, colors[RED]); // /H
	DrawLine(x + 21, y + 30, x + 27, y + 10, 2, colors[RED]); // \H
}

float EnemyShip::getCenterX() 
{
	if (check % 2 != 0)
		return ((x + x + 70) / 2);
	return ((x + x + 30) / 2);
}
float EnemyShip::getCenterY()
{ 
	if (check % 2 != 0)
		return ((y + y + 45) / 2); 
	return ((y + y + 25) / 2);
}

void EnemyShip::Thurst() 
{
	if (check % 2 != 0) {
		Draw_BigEnemyShip();
		rad = 25;
		speed = 0.15;
	}
	else {
		Draw_SmallEnemyShip();
		rad = 15;
		speed = 0.2;
		if (cCheck == 2500)
		{
			angle *= -1.5;
			cCheck = 0;
		}

	}
	float dx, dy;
	
	dx = (float)(cos(Deg2Rad(angle)) *speed);
	dy = (float)(sin(Deg2Rad(angle)) * speed);
	x += dx;
	y += dy;
}

void EnemyShip::WrapCoordinates() {
	if (x < -rad)
		x = x + 800;

	if (x >(800 + rad))
		x = x - 800;

	if (y < -rad)
		y = y + 600;

	if (y >(600 + rad))
		y = y - 600;
}
int EnemyShip::getComplexCheck() { return cCheck; }
void EnemyShip::setComplexCheck(int cc) { cCheck = cc; }


EnemyShip::~EnemyShip()
{
}
int EnemyShip::getCheck() { return check; }
void EnemyShip::setCheck(int c) { check = c; }
void EnemyShip::setRadius(int r) { rad = r; }
int EnemyShip::getRadius() { return rad; }
float EnemyShip::get_Angle() { return angle; }
void EnemyShip::set_Angle(float a) { angle = a; }
const float EnemyShip::get_maxX()  {return 800;}
const float EnemyShip::get_maxY()  {return 600;}
const int EnemyShip::get_maxLives()  {return 5;}
