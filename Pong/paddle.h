#pragma once
#include "sfwdraw.h"
#include <iostream>




namespace pad1
{
	void drawPlayer(float px, float py)//, float  pw, float ph)
	{
		//float px = 10;
		//float py = 10;
		float pw = px + 20;
		float ph = py + 80;

		sfw::drawLine(px, py, pw, py);
		sfw::drawLine(pw, py, pw, ph);
		sfw::drawLine(px, py, px, ph);
		sfw::drawLine(px, ph, pw, ph);


	}

}