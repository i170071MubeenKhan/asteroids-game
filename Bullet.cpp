#include "Bullet.h"



Bullet::Bullet(float X, float Y, float theta) :
	x(X),y(Y),angle(theta), // tip of ship has these values...
	rad(3) 
{
}

float Bullet::get_X() { return x; }
void Bullet::set_X(float X) { x = X; }
float Bullet::get_Y() { return y; }
void Bullet::set_Y(float Y) { y = Y; }
void Bullet::setRadius(int r) { rad = r; }
int Bullet::getRadius() { return rad; }
float Bullet::get_Angle() { return angle; }
void Bullet::set_Angle(float a) { angle = a; }
int Bullet::getCheck() { return 0; }
void Bullet::setCheck(int) { }

void  Bullet::Draw_Bullets(float X, float Y)
{
	DrawCircle(x, y, rad, colors[99]);
}

void Bullet::Thurst() 
{
	Draw_Bullets(x, y);
	float dx, dy;
	dx = (float)(cos(Deg2Rad(angle)) * 0.5);
	dy = (float)(sin(Deg2Rad(angle)) * 0.5);
	x += dx;
	y += dy;
}

void Bullet::WrapCoordinates() //THIS FUCTION IS FOR CHECKING IF BULLET IS SHOOTING RIGHTLY OR NOT...
{
	if (x < - 3)
		x = x + 800;

	if (x >(800 + 3))
		x = x - 800;

	if (y < -3)
		y = y + 600;

	if (y >(600 + 3))
		y = y - 600;
}
float Bullet::getCenterX() { return x; }
float Bullet::getCenterY() { return y; }
const float Bullet::get_maxX() { return 800; }
const float Bullet::get_maxY() { return 600; }
const int Bullet::get_maxLives() { return 5; }

Bullet::~Bullet()
{
}
