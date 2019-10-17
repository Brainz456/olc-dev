#include "Boundary.h"

Boundary::Boundary(){
	this->x1 = 0;
	this->y1 = 0;
	this->x2 = 10;
	this->y2 = 10;
	this->m = 0;
	this->c = 0;
}

Boundary::Boundary(int x1, int y1, int x2, int y2) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	if (x2 - x1 != 0) {
		this->m = (y2 - y1) / (x2 - x1);
	}
	else {
		this->m = 0;
	}
	this->c = y1 - m * x1;
}

int Boundary::getX1() {
	return this->x1;
}

int Boundary::getY1() {
	return this->y1;
}

int Boundary::getX2() {
	return this->x2;
}

int Boundary::getY2() {
	return this->y2;
}

float Boundary::getM() {
	return this->m;
}

float Boundary::getC() {
	return this->c;
}
