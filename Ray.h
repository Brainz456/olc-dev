#pragma once
#include "Boundary.h"
#include <tuple>
class Ray
{
private:
	int x;
	int y;
	float angle;
	float m;
	float c;

public:
	Ray();
	Ray(int x, int y, float angle);
	int getX();
	int getY();
	float getAngle();
	float getC();
	float getM();
	std::tuple<int, int> intersect(Boundary bound);
};

