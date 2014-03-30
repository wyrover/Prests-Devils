#ifndef __CONSTANTVALUE__H__
#define __CONSTANTVALUE__H__

#include <iostream>
#include <string>
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;


class ConstantValue
{
private:
	float rightPrests1x;
	float rightPrests1y;
	float rightPrests2x;
	float rightPrests2y;
	float rightPrests3x;
	float rightPrests3y;
	float rightDevels1x;
	float rightDevels1y;
	float rightDevels2x;
	float rightDevels2y;
	float rightDevels3x;
	float rightDevels3y;
	float right7x;
	float right7y;
	float right8x;
	float right8y;

	float leftPrests1x;
	float leftPrests1y;
	float leftPrests2x;
	float leftPrests2y;
	float leftPrests3x;
	float leftPrests3y;
	float leftDevels1x;
	float leftDevels1y;
	float leftDevels2x;
	float leftDevels2y;
	float leftDevels3x;
	float leftDevels3y;
	float left7x;
	float left7y;
	float left8x;
	float left8y;

public:
	ConstantValue()
	{
		rightPrests1x = -130;
		rightPrests1y = 105;
		rightPrests2x = -105;
		rightPrests2y = 105;
		rightPrests3x = -80;
		rightPrests3y = 105;
		rightDevels1x = -60;
		rightDevels1y = 105;
		rightDevels2x = -35;
		rightDevels2y = 105;
		rightDevels3x = -10;
		rightDevels3y = 105;
		right7x = -175;
		right7y = 75;
		right8x = -235;
		right8y = 75;
		leftPrests1x = 130;
		leftPrests1y = 105;
		leftPrests2x = 105;
		leftPrests2y = 105;
		leftPrests3x = 80;
		leftPrests3y = 105;
		leftDevels1x = 60;
		leftDevels1y = 105;
		leftDevels2x = 35;
		leftDevels2y = 105;
		leftDevels3x = 15;
		leftDevels3y = 105;
		left7x = 175;
		left7y = 75;
		left8x = 235;
		left8y = 75;

	}

	void getCoordinate(string dir, int number, float *p)
	{
		if (dir == "right")
		{
			switch (number)
			{
			case 1: p[0] = rightPrests1x; p[1] = rightPrests1y; return ;
			case 2: p[0] = rightPrests2x; p[1] = rightPrests2y; return ;
			case 3: p[0] = rightPrests3x; p[1] = rightPrests3y; return ;
			case 4: p[0] = rightDevels1x; p[1] = rightDevels1y; return ;
			case 5: p[0] = rightDevels2x; p[1] = rightDevels2y; return ;
			case 6: p[0] = rightDevels3x; p[1] = rightDevels3y; return ;
			case 7: p[0] = right7x; p[1] = right7y; return ;
			case 8: p[0] = right8x; p[1] = right8y; return ;
			}
		}
		else
		{
			switch (number)
			{
			case 1: p[0] = leftPrests1x; p[1] = leftPrests1y; return ;
			case 2: p[0] = leftPrests2x; p[1] = leftPrests2y; return ;
			case 3: p[0] = leftPrests3x; p[1] = leftPrests3y; return ;
			case 4: p[0] = leftDevels1x; p[1] = leftDevels1y; return ;
			case 5: p[0] = leftDevels2x; p[1] = leftDevels2y; return ;
			case 6: p[0] = leftDevels3x; p[1] = leftDevels3y; return ;
			case 7: p[0] = left7x; p[1] = left7y; return ;
			case 8: p[0] = left8x; p[1] = left8y; return ;
			}
		}
	}
};

#endif