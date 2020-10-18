#include "Vigur.h"
#include <cmath>
#include <iostream>

#define PI 3.14159265358979323846

Vigur::Vigur() 
{
	this->x = 0;
	this->y = 0;
}

Vigur::Vigur(float X, float Y) 
{
	this->x = X;
	this->y = Y;
}

void Vigur::prenta()
{
	std::cout << "[" << this->x << " " << this->y << "]" << std::endl;
}


float Vigur::lengd()
{
	return sqrt(this->x*this->x + this->y * this->y);
}


float Vigur::halli()
{
	return this->y/this->x;
}


Vigur Vigur::þvervigur()
{
	return Vigur(this->y, - this->x);
}


float Vigur::stefnuhorn()
{
	return this->horn(Vigur(1,0));
}


float Vigur::horn(Vigur v)
{
	return (180 / PI) * acosf(this->innfeldi(v) / (this->lengd() * v.lengd()))                                                                                                                             ;
}

float Vigur::innfeldi(Vigur v)
{
	return this->x * v.x + this->y * v.y;
}


Vigur Vigur::summa(Vigur v)
{
	return *this + v;
}

Vigur Vigur::operator+(Vigur other) 
{
	return Vigur(this->x + other.x, this->y + other.y);
}
