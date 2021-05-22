#include "Asteroids.h"



Asteroids::Asteroids() :
	x((rand() % 800) + 0), y((rand() % 600) + 0), rad(30),angle((rand() % 360) + -360),
	check((rand() % 10) + 1), cCheck(0)
{
	npoints = GetRandInRange(5, 10);
	dtheta = 360 / npoints;
	theta = GetRandInRange(-30, dtheta);
	stheta = dtheta;
	theta2 = new float[npoints];
	for (int i = 0; i < npoints - 1; ++i) 
	{
		theta2[i] = GetRandInRange(stheta, stheta + dtheta);
		stheta += dtheta;
	}
}

float Asteroids::getCenterX() { return x; }
float Asteroids::getCenterY() { return y; }
int Asteroids::getX() { return x; }
int Asteroids::getY() { return y; }
int Asteroids::getRadius() { return rad; }
void Asteroids::setX(float X) { x = X; }
void Asteroids::setY(float Y) { y = Y; }
void Asteroids::setRadius(int R) { rad = R; }
float Asteroids::get_Angle() { return angle; }
void Asteroids::set_Angle(float a) { angle = a; }


void Asteroids::Draw_Asteroid(const int & cx, const int &cy, int radius, const ColorNames & cname)
{
	WrapCoordinates();
	
	int sx = cx + radius * cos(Deg2Rad(theta)), 
		sy = cy + radius * sin(Deg2Rad(theta));
	int x1 = sx;
	int y1 = sy;

	for (int i = 0; i < npoints - 1; ++i) {
		int x2 = cx + radius * cos(Deg2Rad(theta2[i])), y2 = cy
			+ radius * sin(Deg2Rad(theta2[i]));
	
		DrawLine(x1, y1, x2, y2, 2, colors[99]);
		x1 = x2;
		y1 = y2;
	}
	DrawLine(x1, y1, sx, sy, 2, colors[99]);
}

void Asteroids::Thurst() 
{
	float speed;
	if (check % 2 != 0)
		speed = 0.06;
	else
	{
		speed = 0.09;
		if (cCheck == 2500)
		{
			angle *= -1.5;
			cCheck = 0;
		}
	}
	float dx, dy;
	dx = (float)(cos(Deg2Rad(angle)) * speed);
	dy = (float)(sin(Deg2Rad(angle)) * speed);
	x += dx;
	y += dy;
}

int Asteroids::getComplexCheck() { return cCheck; }
void Asteroids::setComplexCheck(int cc) { cCheck = cc; }

void Asteroids::WrapCoordinates()
{
	if (x < -rad)
		x = x + 800;

	if (x > (800 + rad))
		x = x - 800;

	if (y < -rad)
		y = y + 600;

	if (y > (600 + rad))
		y = y - 600;
}

Asteroids::~Asteroids()
{
	delete[]theta2;
}
int Asteroids::getCheck() { return check; }
void Asteroids::setCheck(int c) { check = c; }
const float Asteroids::get_maxX() { return 800; }
const float Asteroids::get_maxY() { return 600; }
const int Asteroids::get_maxLives() { return 5; }