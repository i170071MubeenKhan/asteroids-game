/*
 * Board.h
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */
#ifndef _BOARD_H_
#define _BOARD_H_

#include <GL/glut.h>
#include <iostream>
#include "util.h"
#include "SpaceObjects.h"
#include "PlayerShip.h"
#include "Bullet.h"
#include "EnemyShip.h"
#include "Asteroids.h"

//#define WITH_TEXTURES
using namespace std;

//x=xcos0-xsin0
//y=ysin0+ycos0


class Board {
private:

	int xcellsize, ycellsize;
	int width, height;
	ColorNames pcolor, bcolor, gcolor;
	SpaceObjects *l[100];

public:
	static const int BOARD_X = 17;
	static const int BOARD_Y = 14;
	/*
	 static const int BOARD_X=17;
	 static const int BOARD_Y=14;
	 */

	int board_array[BOARD_Y][BOARD_X];
	Board(int xsize = 8, int ysize = 8);

	~Board(void);
	void InitalizeBoard(int, int);
	//draw the board
	void Draw();

	static int GetBoardX() {
		return BOARD_X;
	}
	static int GetBoardY() {
		return BOARD_Y;
	}
	int GetMidX() {
		return BOARD_X * xcellsize / 2.0;
	}
	int GetMidY() {
		return BOARD_Y * ycellsize / 2.0;
	}
	int GetCellSize() {
		return xcellsize;
	}

	void GetInitRandomPosition(int &x, int &y) {
		// leave 10 units from all sides
		x = GetRandInRange(50, width - 50);
		y = GetRandInRange(50, height - 50);
	}
	int GetWidth() {
		return width;
	}
	int GetHeight() {
		return height;
	}
	void GetInitTextPosition(int &x, int &y);
	void Display();
	void Up();
	void Left();
	void Right();
	void Shoot();
	void Time();
	void CollisionDetector();
};

#endif
