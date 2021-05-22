#include "PlayerShip.h"



PlayerShip::PlayerShip() :
	maxX(800), maxY(600), maxLives(5), lives(3), scores(0),
	x1(390), x2(400), x3(410), y1(290), y2(320), y3(290),
	Cx(400), Cy(305),
	left(0), right(0), up(0),angle(90),
	rad(15),
	timer(0)
{

}

const float PlayerShip::get_maxX() { return maxX; }
const float PlayerShip::get_maxY() { return maxY; }
const int PlayerShip::get_maxLives() { return maxLives; }
int PlayerShip::get_Lives() { return lives; }
int PlayerShip::get_Scores() { return scores; }
float PlayerShip::getCenterX() { return ((x1 + x2 + x3) / 3); }
float PlayerShip::getCenterY() { return ((y1 + y2 + y3) / 3); }
const int PlayerShip::get_Left(){ return left;  }
const int PlayerShip::get_Right(){ return right;  }
float PlayerShip::get_Up(){ return up;  }
const float PlayerShip::get_X1() { return x1; }
const float PlayerShip::get_Y1() { return y1; }
const float PlayerShip::get_X2() { return x2; }
const float PlayerShip::get_Y2() { return y2; }
const float PlayerShip::get_X3() { return x3; }
const float PlayerShip::get_Y3() { return y3; }
float PlayerShip::get_Angle() { return angle; }
int PlayerShip::getRadius() { return rad; }
float PlayerShip::getTimer() { return timer; }
void PlayerShip::setTimer(float t) { timer = t; }
void PlayerShip::set_Scores(int score) { scores = score; }
void PlayerShip::set_Lives(int life) { lives = life; }
void PlayerShip::setRadius(int r) { rad = r; }
void PlayerShip::set_Left(int left){ this->left = left;  }
void PlayerShip::set_Right(int right){ this->right = right;  }
void PlayerShip::set_Up(float up){ this->up = up;  }
void PlayerShip::set_Angle(float a) { angle = a; }


void PlayerShip::Reset_PlayerShip()
{
	x1 = 390; x2 = 400; x3 = 410; y1 = 290; y2 = 320; y3 = 290;
	angle = 90;
	Draw_Ship();
}

void PlayerShip::Draw_Ship()
{
	//cout << "DRAW1:  " << x1 << "  " << x2 << "  " << x3
	//	<< "  " << y1 << "  " << y2 << "  " << y3 << endl;
	WrapCoordinates();
	DrawLine(x1, y1, x2, y2, 1, colors[99]);
	DrawLine(x2, y2, x3, y3, 1, colors[99]);
	DrawLine(x3, y3, x1, y1, 1, colors[99]);
	//DrawTriangle(x1, y1, x2, y2, x3, y3, colors[99]);
}

void PlayerShip::WrapCoordinates() 
{
	if (x2 < -20)
	{
		x1 = x1 + 800;
		x2 = x2 + 800;
		x3 = x3 + 800;
	}
	if (x2 > 820)
	{
		x1 = x1 - 800;
		x2 = x2 - 800;
		x3 = x3 - 800;
	}
	if (y2 < -20)
	{
		y1 = y1 + 600;
		y2 = y2 + 600;
		y3 = y3 + 600;
	}
	if (y2 > 620)
	{
		y1 = y1 - 600;
		y2 = y2 - 600;
		y3 = y3 - 600;
	}
}

void PlayerShip::Rotate_Left_PlayerShip()
{
	Cx = getCenterX();
	Cy = getCenterY();

	x1 -= Cx;
	x2 -= Cx;
	x3 -= Cx;
	y1 -= Cy;
	y2 -= Cy;
	y3 -= Cy;

	float x1_ = x1;
	float x2_ = x2;
	float x3_ = x3;
	float y1_ = y1;
	float y2_ = y2;
	float y3_ = y3;


	x1_ = x1*(float)cos(Deg2Rad(9)) - y1*(float)sin(Deg2Rad(9));
	x2_ = x2*(float)cos(Deg2Rad(9)) - y2*(float)sin(Deg2Rad(9));
	x3_ = x3*(float)cos(Deg2Rad(9)) - y3*(float)sin(Deg2Rad(9));
	y1_ = x1*(float)sin(Deg2Rad(9)) + y1*(float)cos(Deg2Rad(9));
	y2_ = x2*(float)sin(Deg2Rad(9)) + y2*(float)cos(Deg2Rad(9));
	y3_ = x3*(float)sin(Deg2Rad(9)) + y3*(float)cos(Deg2Rad(9));

	x1 = x1_;
	x2 = x2_;
	x3 = x3_;
	y1 = y1_;
	y2 = y2_;
	y3 = y3_;

	x1 += Cx;
	x2 += Cx;
	x3 += Cx;
	y1 += Cy;
	y2 += Cy;
	y3 += Cy;

	angle += 9;
	if (angle >= 360)
		angle -= 360;

	left = 0;
}

void PlayerShip::Rotate_Right_PlayerShip()
{
	Cx = getCenterX();
	Cy = getCenterY();

	x1 -= Cx;
	x2 -= Cx;
	x3 -= Cx;
	y1 -= Cy;
	y2 -= Cy;
	y3 -= Cy;

	float x1_ = x1;
	float x2_ = x2;
	float x3_ = x3;
	float y1_ = y1;
	float y2_ = y2;
	float y3_ = y3;

	x1_ = x1*(float)cos(Deg2Rad(9)) + y1*(float)sin(Deg2Rad(9));
	x2_ = x2*(float)cos(Deg2Rad(9)) + y2*(float)sin(Deg2Rad(9));
	x3_ = x3*(float)cos(Deg2Rad(9)) + y3*(float)sin(Deg2Rad(9));
	y1_ = -x1*(float)sin(Deg2Rad(9)) + y1*(float)cos(Deg2Rad(9));
	y2_ = -x2*(float)sin(Deg2Rad(9)) + y2*(float)cos(Deg2Rad(9));
	y3_ = -x3*(float)sin(Deg2Rad(9)) + y3*(float)cos(Deg2Rad(9));

	x1 = x1_;
	x2 = x2_;
	x3 = x3_;
	y1 = y1_;
	y2 = y2_;
	y3 = y3_;

	x1 += Cx;
	x2 += Cx;
	x3 += Cx;
	y1 += Cy;
	y2 += Cy;
	y3 += Cy;

	angle -= 9;
	if (angle <= -360)
		angle += 360;

	right = 0;
}

void PlayerShip::Thurst()
{
	float dx, dy;
	dx = (float)(cos(Deg2Rad(angle)) * up);
	dy = (float)(sin(Deg2Rad(angle)) * up);
	x1 += dx;
	y1 += dy;
	x2 += dx;
	y2 += dy;
	x3 += dx;
	y3 += dy;

	up -= (up*0.002);
}

PlayerShip::~PlayerShip()
{

}

void PlayerShip::Draw_EnemyShip() {}
void PlayerShip::Draw_Asteroid(const int & cx, const int &cy, int radius, const ColorNames & cname) {}
