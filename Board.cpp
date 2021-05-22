/*
 * Board.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */

#include "Board.h"
#include <cstdio>

// Asteroids board

// Note that all these enum constants from NILL onwards
// have been given numbers in increasing order
// e.g. NILL=0, and so on
// and these numbers are represented in the board array...
enum BoardParts {
	NILL, S_BRICK, G_BRICK, R_BRICK
};
// defining some utility functions...

/* board_array[Board::BOARD_Y][Board::BOARD_X] = { { 0 } };*/

// Destructor
Board::~Board(void) {
}
void Board::InitalizeBoard(int w, int h) {
	cout << "Initialize board" << endl;
	width = w;
	height = h;
	for (int i = 0; i < BOARD_Y - 1; ++i) {
		for (int j = 0; j < BOARD_X; ++j) {
			// can use G_BRICK, R_BRICK, or S_BRICK here
			board_array[i][j] = NILL;
		}
	}
}
//Constructor
Board::Board(int xsize, int ysize) {
	cout << "Constructor board" << endl;
	xcellsize = xsize;
	ycellsize = ysize;
	pcolor = CHOCOLATE;
	bcolor = ORANGE_RED;
	gcolor = PINK;

	for (int i = 0; i < BOARD_Y; ++i)
		for (int j = 0; j < BOARD_X; ++j)
			board_array[i][j] = 0;

	for (int i = 0; i < 100; i++)
		l[i] = NULL;

	for (int i = 0; i < 100; i++)
		if (i == 0)
			l[i] = new PlayerShip;
		else if (i == 1 || i == 2)
			l[i] = new EnemyShip;
		else if (i > 35 && i < 43)
			l[i] = new Asteroids;
//set up board
}

void Board::Draw() {
	glColor3f(0, 0, 1);
	glPushMatrix();

	for (int i = BOARD_Y - 2, y = 0; i >= 0; --i, y += xcellsize) {
		for (int j = 0, x = 0; j < BOARD_X; j++, x += (ycellsize)) {
			//			cout <<      " " << board_array[i][j] << " " << flush;
			switch (board_array[i][j]) {
			case NILL:
				// Empty space
				break;
			case S_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize,
						colors[SLATE_GRAY]);
				//DrawLine(x - 10, y, x - 10 + ycellsize, y, 4, colors[BLACK]);
				break;
			case G_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize,
						colors[LIGHT_GREEN]);
				break;
			case R_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize, colors[RED]);
				break;
			}
		}
	}
	glPopMatrix();
}

void Board::GetInitTextPosition(int &x, int &y) {
	x = xcellsize;
	y = (BOARD_Y - 1) * ycellsize + ycellsize / 2;
}

void Board::Display()
{
	if (l[0]->getTimer() < 6) {
		int t = l[0]->getTimer();
		if (t == 0)
		{
		//title of game
		//A
		DrawLine(225, 296, 240, 350, 4, colors[99]);
		DrawLine(232, 320, 247, 320, 4, colors[99]);
		DrawLine(255, 297, 240, 350, 4, colors[99]);
		//S
		DrawLine(267, 350, 297, 350, 4, colors[99]);
		DrawLine(267, 350, 267, 325, 4, colors[99]);
		DrawLine(267, 325, 297, 325, 4, colors[99]);
		DrawLine(297, 325, 297, 300, 4, colors[99]);
		DrawLine(297, 300, 267, 300, 4, colors[99]);
		//T
		DrawLine(309, 350, 339, 350, 4, colors[99]);
		DrawLine(324, 350, 324, 297, 4, colors[99]);
		//E
		DrawLine(351, 350, 351, 300, 4, colors[99]);
		DrawLine(351, 350, 381, 350, 4, colors[99]);
		DrawLine(351, 325, 371, 325, 4, colors[99]);
		DrawLine(351, 300, 381, 300, 4, colors[99]);
		//R
		DrawLine(393, 350, 393, 297, 4, colors[99]);
		DrawLine(393, 350, 423, 350, 4, colors[99]);
		DrawLine(423, 350, 423, 325, 4, colors[99]);
		DrawLine(423, 325, 393, 325, 4, colors[99]);
		DrawLine(393, 325, 423, 300, 4, colors[99]);
		//O
		DrawLine(435, 350, 465, 350, 4, colors[99]);
		DrawLine(465, 350, 465, 300, 4, colors[99]);
		DrawLine(465, 300, 435, 300, 4, colors[99]);
		DrawLine(435, 300, 435, 350, 4, colors[99]);
		//I
		DrawLine(477, 350, 507, 350, 4, colors[99]);
		DrawLine(492, 350, 492, 300, 4, colors[99]);
		DrawLine(477, 300, 507, 300, 4, colors[99]);
		//D
		DrawLine(519, 350, 519, 300, 4, colors[99]);
		DrawLine(519, 350, 549, 337, 4, colors[99]);
		DrawLine(549, 337, 549, 315, 4, colors[99]);
		DrawLine(549, 315, 519, 300, 4, colors[99]);
		//S
		DrawLine(561, 350, 591, 350, 4, colors[99]);
		DrawLine(561, 350, 561, 325, 4, colors[99]);
		DrawLine(561, 325, 591, 325, 4, colors[99]);
		DrawLine(591, 325, 591, 300, 4, colors[99]);
		DrawLine(591, 300, 561, 300, 4, colors[99]);

		DrawString(405, 270, "ARCADE GAMES", colors[99]);

		DrawString(360, 50, "Loading.", colors[99]);
		}
		else if (t == 1) 
		{
					//title of game
		//A
		DrawLine(225, 296, 240, 350, 4, colors[99]);
		DrawLine(232, 320, 247, 320, 4, colors[99]);
		DrawLine(255, 297, 240, 350, 4, colors[99]);
		//S
		DrawLine(267, 350, 297, 350, 4, colors[99]);
		DrawLine(267, 350, 267, 325, 4, colors[99]);
		DrawLine(267, 325, 297, 325, 4, colors[99]);
		DrawLine(297, 325, 297, 300, 4, colors[99]);
		DrawLine(297, 300, 267, 300, 4, colors[99]);
		//O
		DrawLine(309, 350, 339, 350, 4, colors[99]);
		DrawLine(324, 350, 324, 297, 4, colors[99]);
		//E
		DrawLine(351, 350, 351, 300, 4, colors[99]);
		DrawLine(351, 350, 381, 350, 4, colors[99]);
		DrawLine(351, 325, 371, 325, 4, colors[99]);
		DrawLine(351, 300, 381, 300, 4, colors[99]);
		//R
		DrawLine(393, 350, 393, 297, 4, colors[99]);
		DrawLine(393, 350, 423, 350, 4, colors[99]);
		DrawLine(423, 350, 423, 325, 4, colors[99]);
		DrawLine(423, 325, 393, 325, 4, colors[99]);
		DrawLine(393, 325, 423, 300, 4, colors[99]);
		//O
		DrawLine(435, 350, 465, 350, 4, colors[99]);
		DrawLine(465, 350, 465, 300, 4, colors[99]);
		DrawLine(465, 300, 435, 300, 4, colors[99]);
		DrawLine(435, 300, 435, 350, 4, colors[99]);
		//I
		DrawLine(477, 350, 507, 350, 4, colors[99]);
		DrawLine(492, 350, 492, 300, 4, colors[99]);
		DrawLine(477, 300, 507, 300, 4, colors[99]);
		//D
		DrawLine(519, 350, 519, 300, 4, colors[99]);
		DrawLine(519, 350, 549, 337, 4, colors[99]);
		DrawLine(549, 337, 549, 315, 4, colors[99]);
		DrawLine(549, 315, 519, 300, 4, colors[99]);
		//S
		DrawLine(561, 350, 591, 350, 4, colors[99]);
		DrawLine(561, 350, 561, 325, 4, colors[99]);
		DrawLine(561, 325, 591, 325, 4, colors[99]);
		DrawLine(591, 325, 591, 300, 4, colors[99]);
		DrawLine(591, 300, 561, 300, 4, colors[99]);

		DrawString(405, 270, "ARCADE GAMES", colors[99]);

		DrawString(360, 50, "Loading..", colors[99]);
		}
		else if (t == 2) 
		{
		//title of game
		//A
		DrawLine(225, 296, 240, 350, 4, colors[99]);
		DrawLine(232, 320, 247, 320, 4, colors[99]);
		DrawLine(255, 297, 240, 350, 4, colors[99]);
		//S
		DrawLine(267, 350, 297, 350, 4, colors[99]);
		DrawLine(267, 350, 267, 325, 4, colors[99]);
		DrawLine(267, 325, 297, 325, 4, colors[99]);
		DrawLine(297, 325, 297, 300, 4, colors[99]);
		DrawLine(297, 300, 267, 300, 4, colors[99]);
		//O
		DrawLine(309, 350, 339, 350, 4, colors[99]);
		DrawLine(324, 350, 324, 297, 4, colors[99]);
		//E
		DrawLine(351, 350, 351, 300, 4, colors[99]);
		DrawLine(351, 350, 381, 350, 4, colors[99]);
		DrawLine(351, 325, 371, 325, 4, colors[99]);
		DrawLine(351, 300, 381, 300, 4, colors[99]);
		//R
		DrawLine(393, 350, 393, 297, 4, colors[99]);
		DrawLine(393, 350, 423, 350, 4, colors[99]);
		DrawLine(423, 350, 423, 325, 4, colors[99]);
		DrawLine(423, 325, 393, 325, 4, colors[99]);
		DrawLine(393, 325, 423, 300, 4, colors[99]);
		//O
		DrawLine(435, 350, 465, 350, 4, colors[99]);
		DrawLine(465, 350, 465, 300, 4, colors[99]);
		DrawLine(465, 300, 435, 300, 4, colors[99]);
		DrawLine(435, 300, 435, 350, 4, colors[99]);
		//I
		DrawLine(477, 350, 507, 350, 4, colors[99]);
		DrawLine(492, 350, 492, 300, 4, colors[99]);
		DrawLine(477, 300, 507, 300, 4, colors[99]);
		//D
		DrawLine(519, 350, 519, 300, 4, colors[99]);
		DrawLine(519, 350, 549, 337, 4, colors[99]);
		DrawLine(549, 337, 549, 315, 4, colors[99]);
		DrawLine(549, 315, 519, 300, 4, colors[99]);
		//S
		DrawLine(561, 350, 591, 350, 4, colors[99]);
		DrawLine(561, 350, 561, 325, 4, colors[99]);
		DrawLine(561, 325, 591, 325, 4, colors[99]);
		DrawLine(591, 325, 591, 300, 4, colors[99]);
		DrawLine(591, 300, 561, 300, 4, colors[99]);	

		DrawString(405, 270, "ARCADE GAMES", colors[99]);

		DrawString(360, 50, "Loading...", colors[99]);
		}
			
		else if (t == 3)
		{
		//title of game
		//A
		DrawLine(225, 296, 240, 350, 4, colors[99]);
		DrawLine(232, 320, 247, 320, 4, colors[99]);
		DrawLine(255, 297, 240, 350, 4, colors[99]);
		//S
		DrawLine(267, 350, 297, 350, 4, colors[99]);
		DrawLine(267, 350, 267, 325, 4, colors[99]);
		DrawLine(267, 325, 297, 325, 4, colors[99]);
		DrawLine(297, 325, 297, 300, 4, colors[99]);
		DrawLine(297, 300, 267, 300, 4, colors[99]);
		//O
		DrawLine(309, 350, 339, 350, 4, colors[99]);
		DrawLine(324, 350, 324, 297, 4, colors[99]);
		//E
		DrawLine(351, 350, 351, 300, 4, colors[99]);
		DrawLine(351, 350, 381, 350, 4, colors[99]);
		DrawLine(351, 325, 371, 325, 4, colors[99]);
		DrawLine(351, 300, 381, 300, 4, colors[99]);
		//R
		DrawLine(393, 350, 393, 297, 4, colors[99]);
		DrawLine(393, 350, 423, 350, 4, colors[99]);
		DrawLine(423, 350, 423, 325, 4, colors[99]);
		DrawLine(423, 325, 393, 325, 4, colors[99]);
		DrawLine(393, 325, 423, 300, 4, colors[99]);
		//O
		DrawLine(435, 350, 465, 350, 4, colors[99]);
		DrawLine(465, 350, 465, 300, 4, colors[99]);
		DrawLine(465, 300, 435, 300, 4, colors[99]);
		DrawLine(435, 300, 435, 350, 4, colors[99]);
		//I
		DrawLine(477, 350, 507, 350, 4, colors[99]);
		DrawLine(492, 350, 492, 300, 4, colors[99]);
		DrawLine(477, 300, 507, 300, 4, colors[99]);
		//D
		DrawLine(519, 350, 519, 300, 4, colors[99]);
		DrawLine(519, 350, 549, 337, 4, colors[99]);
		DrawLine(549, 337, 549, 315, 4, colors[99]);
		DrawLine(549, 315, 519, 300, 4, colors[99]);
		//S
		DrawLine(561, 350, 591, 350, 4, colors[99]);
		DrawLine(561, 350, 561, 325, 4, colors[99]);
		DrawLine(561, 325, 591, 325, 4, colors[99]);
		DrawLine(591, 325, 591, 300, 4, colors[99]);
		DrawLine(591, 300, 561, 300, 4, colors[99]);	

		DrawString(405, 270, "ARCADE GAMES", colors[99]);
		
		DrawString(360, 50, "Loading.", colors[99]);
		}
		else if (t == 4)
		{
		//title of game
		//A
		DrawLine(225, 296, 240, 350, 4, colors[99]);
		DrawLine(232, 320, 247, 320, 4, colors[99]);
		DrawLine(255, 297, 240, 350, 4, colors[99]);
		//S
		DrawLine(267, 350, 297, 350, 4, colors[99]);
		DrawLine(267, 350, 267, 325, 4, colors[99]);
		DrawLine(267, 325, 297, 325, 4, colors[99]);
		DrawLine(297, 325, 297, 300, 4, colors[99]);
		DrawLine(297, 300, 267, 300, 4, colors[99]);
		//O
		DrawLine(309, 350, 339, 350, 4, colors[99]);
		DrawLine(324, 350, 324, 297, 4, colors[99]);
		//E
		DrawLine(351, 350, 351, 300, 4, colors[99]);
		DrawLine(351, 350, 381, 350, 4, colors[99]);
		DrawLine(351, 325, 371, 325, 4, colors[99]);
		DrawLine(351, 300, 381, 300, 4, colors[99]);
		//R
		DrawLine(393, 350, 393, 297, 4, colors[99]);
		DrawLine(393, 350, 423, 350, 4, colors[99]);
		DrawLine(423, 350, 423, 325, 4, colors[99]);
		DrawLine(423, 325, 393, 325, 4, colors[99]);
		DrawLine(393, 325, 423, 300, 4, colors[99]);
		//O
		DrawLine(435, 350, 465, 350, 4, colors[99]);
		DrawLine(465, 350, 465, 300, 4, colors[99]);
		DrawLine(465, 300, 435, 300, 4, colors[99]);
		DrawLine(435, 300, 435, 350, 4, colors[99]);
		//I
		DrawLine(477, 350, 507, 350, 4, colors[99]);
		DrawLine(492, 350, 492, 300, 4, colors[99]);
		DrawLine(477, 300, 507, 300, 4, colors[99]);
		//D
		DrawLine(519, 350, 519, 300, 4, colors[99]);
		DrawLine(519, 350, 549, 337, 4, colors[99]);
		DrawLine(549, 337, 549, 315, 4, colors[99]);
		DrawLine(549, 315, 519, 300, 4, colors[99]);
		//S
		DrawLine(561, 350, 591, 350, 4, colors[99]);
		DrawLine(561, 350, 561, 325, 4, colors[99]);
		DrawLine(561, 325, 591, 325, 4, colors[99]);
		DrawLine(591, 325, 591, 300, 4, colors[99]);
		DrawLine(591, 300, 561, 300, 4, colors[99]);

		DrawString(405, 270, "ARCADE GAMES", colors[99]);
		
		DrawString(360, 50, "Loading..", colors[99]);
		}
		else if (t == 5)
		{
		//title of game
		//A
		DrawLine(225, 296, 240, 350, 4, colors[99]);
		DrawLine(232, 320, 247, 320, 4, colors[99]);
		DrawLine(255, 297, 240, 350, 4, colors[99]);
		//S
		DrawLine(267, 350, 297, 350, 4, colors[99]);
		DrawLine(267, 350, 267, 325, 4, colors[99]);
		DrawLine(267, 325, 297, 325, 4, colors[99]);
		DrawLine(297, 325, 297, 300, 4, colors[99]);
		DrawLine(297, 300, 267, 300, 4, colors[99]);
		//O
		DrawLine(309, 350, 339, 350, 4, colors[99]);
		DrawLine(324, 350, 324, 297, 4, colors[99]);
		//E
		DrawLine(351, 350, 351, 300, 4, colors[99]);
		DrawLine(351, 350, 381, 350, 4, colors[99]);
		DrawLine(351, 325, 371, 325, 4, colors[99]);
		DrawLine(351, 300, 381, 300, 4, colors[99]);
		//R
		DrawLine(393, 350, 393, 297, 4, colors[99]);
		DrawLine(393, 350, 423, 350, 4, colors[99]);
		DrawLine(423, 350, 423, 325, 4, colors[99]);
		DrawLine(423, 325, 393, 325, 4, colors[99]);
		DrawLine(393, 325, 423, 300, 4, colors[99]);
		//O
		DrawLine(435, 350, 465, 350, 4, colors[99]);
		DrawLine(465, 350, 465, 300, 4, colors[99]);
		DrawLine(465, 300, 435, 300, 4, colors[99]);
		DrawLine(435, 300, 435, 350, 4, colors[99]);
		//I
		DrawLine(477, 350, 507, 350, 4, colors[99]);
		DrawLine(492, 350, 492, 300, 4, colors[99]);
		DrawLine(477, 300, 507, 300, 4, colors[99]);
		//D
		DrawLine(519, 350, 519, 300, 4, colors[99]);
		DrawLine(519, 350, 549, 337, 4, colors[99]);
		DrawLine(549, 337, 549, 315, 4, colors[99]);
		DrawLine(549, 315, 519, 300, 4, colors[99]);
		//S
		DrawLine(561, 350, 591, 350, 4, colors[99]);
		DrawLine(561, 350, 561, 325, 4, colors[99]);
		DrawLine(561, 325, 591, 325, 4, colors[99]);
		DrawLine(591, 325, 591, 300, 4, colors[99]);
		DrawLine(591, 300, 561, 300, 4, colors[99]);

		DrawString(405, 270, "ARCADE GAMES", colors[99]);
		
		DrawString(360, 50, "Loading...", colors[99]);
		}
	}
	else if (l[0]->getTimer() < 12)
	{
		DrawString(300, 560, "ABOUT GAMEPLAY", colors[99]);
		DrawString(10, 530 - 10, "1.  There are 7 asteroids and 2 enemy ships in the start.", colors[99]);
		DrawString(10, 500 - 10, "2.  Shooting Big Asteroid is awarded 10 points.", colors[99]);
		DrawString(10, 470 - 10, "3.  Shooting Medium Asteroid is awarded 20 points.", colors[99]);
		DrawString(10, 440 - 10, "4.  Shooting Small Asteroid is awarded 30 points.", colors[99]);
		DrawString(10, 410 - 10, "5.  Shooting Biggest Enemy Ship is awarded 100 points.", colors[99]);
		DrawString(10, 380 - 10, "6.  Shooting Small Enemy Ship is awarded 500 points.", colors[99]);
		DrawString(10, 350 - 10, "7.  Everything wraps around when goes out of screen, except bullets.", colors[99]);
		DrawString(10, 320 - 10, "8.  Enemy Ships move faster and try to collide with your ship, but don't shoot.", colors[99]);
		DrawString(10, 290 - 10, "9.  New asteroids will create at ramdom position after hitting by bullet.", colors[99]);
		DrawString(10, 260 - 10, "10. There are some asteroids and enemy ships who change their positions.", colors[99]);
		DrawString(10, 230 - 10, "11. You must be strong to win this game.", colors[99]);
		DrawString(570, 40 - 10, "By Mubeen Khan", colors[99]);
	}
	else if (l[0]->getTimer() < 14)
		DrawString(340, 290, "GET READY!", colors[99]);
	else if (l[0]->getTimer() < 15)
		DrawString(360, 290, "START!", colors[99]);


	// ***************************************************************************************
	if (l[0]->getTimer() >= 15)
	{
		if (l[0]->get_Lives() <= 0)
		{
			DrawString(320, 320, "GAME OVER!", colors[99]);
			DrawString(330, 280, "Scores: ", colors[99]);
			DrawString(410, 280, Num2Str(l[0]->get_Scores()), colors[99]);
		}
		if (l[0]->get_Lives() > 0)
		{
			//		   ******** Asteroids working... *********
			for (int i = 35; i < 43; i++)
				if (l[i] != NULL && l[i]->getRadius()>0)
				{
					l[i]->Draw_Asteroid(l[i]->getX(), l[i]->getY(), l[i]->getRadius());
					l[i]->Thurst();
					l[i]->setComplexCheck(l[i]->getComplexCheck() + 1);
				}
			//		   ******** Thursts... *********
			for (int i = 1; i < 23; i++)
				if (l[i] != NULL)
					l[i]->Thurst();

			//			******** EnemyShip working... *********
			l[1]->setComplexCheck(l[1]->getComplexCheck() + 1);
			l[2]->setComplexCheck(l[2]->getComplexCheck() + 1);


			//				******** String *********
			if (l[0]->getTimer() >= 0 && l[0]->get_Lives() > 0)
			{
				DrawString(5, 570, "Lives: ", colors[99]);

				DrawString(5, 545, "Scores: ", colors[99]);
				DrawString(85, 545, Num2Str(l[0]->get_Scores()), colors[99]);
			}

			//		    ******** PlayerShip working... *********
			for (int i = 0, x = 65; i < l[0]->get_Lives(); i++, x += 25)
			{
				DrawLine(x, 570, x + 10, 600, 2, colors[99]);
				DrawLine(x + 10, 600, x + 20, 570, 2, colors[99]);
				DrawLine(x + 20, 570, x, 570, 2, colors[99]);
			}

			l[0]->Draw_Ship();

			if (l[0]->get_Up() > 0)
				l[0]->Thurst();

			if (l[0]->get_Right() == 1)
				l[0]->Rotate_Right_PlayerShip();

			if (l[0]->get_Left() == 1)
				l[0]->Rotate_Left_PlayerShip();
		}

		CollisionDetector();

	}
}

void Board::Up()
{
	if (l[0]->get_Up() <= 0.6)
		l[0]->set_Up(l[0]->get_Up() + 0.2);
}
void Board::Left()
{
	l[0]->set_Left(1);
}
void Board::Right()
{
	l[0]->set_Right(1);
}
void Board::Shoot()
{
	for (int i = 3, x = 0; i < 23; i++)
	{
		if (l[i] != NULL && i > 21)
		{
			for (int i = 3; i < 23; i++)
			{
				delete l[i];
				l[i] = NULL;
			}
		}
		if (l[i] == NULL)
		{
			l[i] = new Bullet(l[0]->get_X2(), l[0]->get_Y2(), l[0]->get_Angle());
			x++;
		}
		if (x == 1)
			break;
	}
}
void Board::Time()
{
	l[0]->setTimer(l[0]->getTimer() + 1);
}

void Board::CollisionDetector()
{
	//for collision detection
	if (l[0]->getTimer() > 6)
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				if (l[i] != NULL && l[j] != NULL && i != j)
				{
					int xx = pow(l[i]->getCenterX() - l[j]->getCenterX(), 2);
					int yy = pow(l[i]->getCenterY() - l[j]->getCenterY(), 2);
					int distance = pow((xx + yy), 0.5);
					if (distance <= (l[i]->getRadius() + l[j]->getRadius()))
					{

						//SHIP COLLISION
						if (i == 0)
						{
							l[0]->Reset_PlayerShip();
							l[0]->set_Lives(l[0]->get_Lives() - 1);

							// WITH ENEMYSHIP
							if (j == 1 || j == 2)
							{
								if (l[j]->getCheck() % 2 != 0)
									l[0]->set_Scores(l[0]->get_Scores() + 100);
								else
									l[0]->set_Scores(l[0]->get_Scores() + 500);

								delete l[j];
								l[j] = new EnemyShip;
							}

							// WITH ASTEROID
							if (j >= 35)
							{
								if (l[j]->getRadius() == 30)
									l[0]->set_Scores(l[0]->get_Scores() + 10);
								else if (l[j]->getRadius() == 20)
									l[0]->set_Scores(l[0]->get_Scores() + 20);
								else if (l[j]->getRadius() == 10)
									l[0]->set_Scores(l[0]->get_Scores() + 30);

								float x = l[j]->getCenterX();
								float y = l[j]->getCenterY();
								int r = l[j]->getRadius();
								int c = l[j]->getCheck();

								delete l[j];
								l[j] = NULL;
								for (int k = 35, xx = 0; k < 100; k++)
								{
									if (l[k] == NULL)
									{
										l[k] = new Asteroids;
										l[k]->setX(x);
										l[k]->setY(y);
										l[k]->setCheck((c % 2) + 1);
										if (r > 0)
											l[k]->setRadius(r - 10);
										else
										{
											r = 30;
											l[k]->setRadius(r);
											xx = 5;
										}
										xx++;
									}
									if (xx >= 2)
										break;
								}
							}
						}

						//BULLET COLLISION

						else if (i > 2 && i < 23)
						{
							l[i]->set_X(-10000);
							l[i]->set_Y(-10000);
							// WITH ENEMYSHIP
							if (j == 1 || j == 2)
							{
								if (l[j]->getCheck() % 2 != 0)
									l[0]->set_Scores(l[0]->get_Scores() + 100);
								else
									l[0]->set_Scores(l[0]->get_Scores() + 500);
								delete l[j];
								l[j] = new EnemyShip;
							}

							// WITH ASTEROID
							if (j >= 35)
							{
								if (l[j]->getRadius() == 30)
									l[0]->set_Scores(l[0]->get_Scores() + 10);
								else if (l[j]->getRadius() == 20)
									l[0]->set_Scores(l[0]->get_Scores() + 20);
								else if (l[j]->getRadius() == 10)
									l[0]->set_Scores(l[0]->get_Scores() + 30);

								float x = l[j]->getCenterX();
								float y = l[j]->getCenterY();
								int r = l[j]->getRadius();
								int c = l[j]->getCheck();

								delete l[j];
								l[j] = NULL;
								for (int k = 35, xx = 0; k < 100; k++)
								{
									if (l[k] == NULL)
									{
										l[k] = new Asteroids;
										l[k]->setX(x);
										l[k]->setY(y);
										l[k]->setCheck((c % 2) + 1);
										if (r > 0)
											l[k]->setRadius(r - 10);
										else
										{
											r = 30;
											l[k]->setRadius(r);
											x = 5;
										}
										xx++;
									}
									if (xx >= 2)
										break;
								}
							}
						}

						//// ENEMYSHIP COLLISION
						//else if (i == 1 || i == 2)
						//{
						//	delete l[j];
						//	l[j] = new EnemyShip;

						//	// WITH ASTEROID
						//	if (j >= 35)
						//	{
						//		if (l[j]->getRadius() == 30)
						//			l[0]->set_Scores(l[0]->get_Scores() + 10);
						//		else if (l[j]->getRadius() == 20)
						//			l[0]->set_Scores(l[0]->get_Scores() + 20);
						//		else if (l[j]->getRadius() == 10)
						//			l[0]->set_Scores(l[0]->get_Scores() + 30);

						//		float x = l[j]->getCenterX();
						//		float y = l[j]->getCenterY();
						//		int r = l[j]->getRadius();
						//		int c = l[j]->getCheck();

						//		delete l[j];
						//		l[j] = NULL;
						//		for (int k = 35, xx = 0; k < 100; k++)
						//		{
						//			if (l[k] == NULL)
						//			{
						//				l[k] = new Asteroids;
						//				l[k]->setX(x);
						//				l[k]->setY(y);
						//				l[k]->setCheck((c % 2) + 1);
						//				if (r > 0)
						//					l[k]->setRadius(r - 10);
						//				else
						//				{
						//					r = 30;
						//					l[k]->setRadius(r);
						//					xx = 5;
						//				}
						//				xx++;
						//			}
						//			if (xx >= 2)
						//				break;
						//		}
						//	}
						//}
					}
				}
}

