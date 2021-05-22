#include "SpaceObjects.h"


SpaceObjects::SpaceObjects()
{
}

const float SpaceObjects::get_maxX() { return 800; }
const float SpaceObjects::get_maxY() { return 600; }
const int SpaceObjects::get_maxLives() { return 5; }
int SpaceObjects::get_Lives() { return 0; }
int SpaceObjects::get_Scores() { return 0; }
const int SpaceObjects::get_Left() { return 0; }
const int SpaceObjects::get_Right() { return 0; }
float SpaceObjects::get_Up() { return 0; }
const float SpaceObjects::get_X1() { return 0; }
const float SpaceObjects::get_Y1() { return 0; }
const float SpaceObjects::get_X2() { return 0; }
const float SpaceObjects::get_Y2() { return 0; }
const float SpaceObjects::get_X3() { return 0; }
const float SpaceObjects::get_Y3() { return 0; }
float SpaceObjects::getTimer() { return 0; }
void SpaceObjects::setTimer(float t) {}
void SpaceObjects::set_Scores(int score) {}
void SpaceObjects::set_Lives(int live) {}
void SpaceObjects::set_Left(int left) { }
void SpaceObjects::set_Right(int right) {  }
void SpaceObjects::set_Up(float up) { }
void SpaceObjects::Reset_PlayerShip() {}
void SpaceObjects::Draw_Ship() {}
void SpaceObjects::Rotate_Left_PlayerShip() {}
void SpaceObjects::Rotate_Right_PlayerShip() {}
void SpaceObjects::Thurst() {}

float SpaceObjects::get_X() { return 0; }
void SpaceObjects::set_X(float x) {}
float SpaceObjects::get_Y() { return 0; }
void SpaceObjects::set_Y(float y) {}
void SpaceObjects::set_Angle(float a) {}
void  SpaceObjects::Draw_Bullets(float X, float Y) {}

void SpaceObjects::Draw_BigEnemyShip() {}
void SpaceObjects::Draw_SmallEnemyShip() {}
int SpaceObjects::getCheck() { return 0; }
void SpaceObjects::setCheck(int) {}

void SpaceObjects::Draw_Asteroid(const int & cx, const int &cy, int radius, const ColorNames & cname) {}
int SpaceObjects::getX() { return 0; }
int SpaceObjects::getY() { return 0; }
int SpaceObjects::getRadius() { return 0; }
void SpaceObjects::setX(float x) {}
void SpaceObjects::setY(float y) {}
void SpaceObjects::setRadius(int r) {}
int SpaceObjects::getComplexCheck() { return 0; }
void SpaceObjects::setComplexCheck(int cc) { }

SpaceObjects::~SpaceObjects()
{
}
