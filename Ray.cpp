#include "Ray.h"
#include <math.h>

Ray::Ray() {
	this->x = 0;
	this->y = 0;
	this->angle = 0;
	this->m = std::tan(angle);
	this->c = y - m * x;
}

Ray::Ray(int x, int y, float angle) {
	this->x = x;
	this->y = y;
	this->angle = angle; // Angle is anti-clockwise from the x-axis drawn to the right of the initial point
	this->m = std::tan(angle);
	this->c = y - m * x;
}

int Ray::getX() {
	return this->x;
}

int Ray::getY() {
	return this->y;
}

float Ray::getAngle() {
	return this->angle;
}

float Ray::getM() {
	return this->m;
}

float Ray::getC() {
	return this->c;
}

std::tuple<int, int> Ray::intersect(Boundary bound) {
	int intersectX = -1;
	int intersectY = -1;
	// Do the intersect check here
	// Let the Wall be B and D, Line be A and C
	// If A == B then parallel, no contact
	// Equation of a line is Y = M*X + C
	// For two lines: Ax + C = Bx + D   therefore: x = (D-C)/(A-B)
	if (this->getM() != bound.getM()) {
		int intersectX = (int)(bound.getC() - this->getC()) / (this->getM() - bound.getM());
		int intersectY = (int)(this->getM() * x) + this->getC();
	}
	std::cout << "Intersection at x,y:" << x << "," << y << std::endl;
	std::tuple<int, int> intersect = std::make_tuple(intersectX, intersectY);
	return intersect;
}