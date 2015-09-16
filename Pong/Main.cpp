#include "sfwdraw.h"
#include "paddle.h"
#include <iostream>
#include <cstdlib>

//I got a lot of my thought process and structure from Esme's example and cppgameprogramming.com
//Terry helped me understand certain concepts on generating windows
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;


void main()
{
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
	
	float xpos = SCREEN_WIDTH/2, ypos = SCREEN_HEIGHT/2;
	float xacc = 0, yacc = 0;
	float xvel = 300, yvel = 300;
	float speed = 100;
	float rad = 30;

	//Player 1 starting stats
	float p1_tempx = 10;
	float p1_tempy = ((SCREEN_HEIGHT / 2) - 40);

	//player 1
		float p1_x = p1_tempx;
		float p1_y = p1_tempy;
		float p1_w = p1_x + 20;
		float p1_h = p1_y + 80;

	//player 2 starting stats
	float p2_tempx = SCREEN_WIDTH - 30;
	float p2_tempy = ((SCREEN_HEIGHT / 2) - 40);

	//player 2
	float p2_x = p2_tempx;
	float p2_y = p2_tempy;
	float p2_w = p2_x + 20;
	float p2_h = p2_y + 80;

	int scoreP1 = 0;
	int scoreP2 = 0;

	while (sfw::stepContext())
	{
		sfw::drawLine(SCREEN_WIDTH, SCREEN_HEIGHT - 5, 0, SCREEN_HEIGHT - 5);
		sfw::drawLine(0, 5, SCREEN_WIDTH, 5);
	//this creates and allows player one movement
		//float p1_w = p1_x + 20;
		float p1_h = p1_y + 80;
		pad1::drawPlayer(p1_x, p1_y);
		if (sfw::getKey('w') && p1_y > 10) {pad1::drawPlayer(p1_x, p1_y -= 5);}
		if (sfw::getKey('s') && p1_h < 590) {pad1::drawPlayer(p1_x, p1_y += 5);}

		//this creates and allows player two movement
		//float p2_w = p1_x - 20;
		float p2_h = p2_y + 80;
		pad1::drawPlayer(p2_x, p2_y);
		if (sfw::getKey('o') && p2_y > 10) {pad1::drawPlayer(p2_x, p2_y -= 5);}
		if (sfw::getKey('l') && p2_h < 590) {pad1::drawPlayer(p2_x, p2_y += 5);}
		
		//draws the ball
		sfw::drawCircle(xpos, ypos, rad);
		xpos += xvel * sfw::getDeltaTime();
		ypos += yvel * sfw::getDeltaTime();

		//Reflection on walls and paddles. Terry pointed me the the right direction
		//for this one and let me figure it out from there
		if (ypos - rad < 10)
		{ 
			ypos = ((ypos + rad)-5);
			yvel *= -1;
			xvel *= 1; 
		}
		if (ypos + rad > 590) 
		{ 
			ypos = (ypos - rad);
			yvel *= -1;
			xvel *= 1;
		}
		if (xpos - rad <= p1_w && xpos -rad >= p1_x)
			{
				if (ypos >= p1_y && ypos <= p1_h)
				{ 
					xpos = (p1_w + rad);
					xvel *= -1;
					yvel *= 1;
				}
			}
		if (xpos + rad >= p2_x && xpos + rad <= p2_w)
		{
			if (ypos >= p2_y && ypos <= p2_h)
			{
				xpos = (p2_x - rad);
				xvel *= -1;
				yvel *= 1;
			}
		}
		if (xpos - rad >= SCREEN_WIDTH)
		{
			scoreP1 += 1;
			xpos = SCREEN_WIDTH / 2, ypos = SCREEN_HEIGHT / 2;
		}
		if (xpos + rad <= 0)
		{
			scoreP2 += 1;
			xpos = SCREEN_WIDTH / 2, ypos = SCREEN_HEIGHT / 2;
		}
		if (scoreP1 == 5 || scoreP2 == 5){ sfw::termContext(); }



	}
	sfw::stepContext();

	sfw::termContext();
}