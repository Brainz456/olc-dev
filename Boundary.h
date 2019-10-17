#pragma once
#include "olcPixelGameEngine.h"

class Boundary{
private:
	int x1;
	int y1;
	int x2;
	int y2;
	float m;
	float c;

public:
	Boundary(int x1, int y1, int x2, int y2);
	Boundary();
	int getX1();
	int getY1();
	int getX2();
	int getY2();
	float getM();
	float getC();
};

