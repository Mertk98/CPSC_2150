#include <iostream>
#include <cmath>
#include "Circle.h"

int Circle::class_count = 0;

Circle::Circle()
{
	x = y = 0;
	radius = 10;
	Lintersect = true;
	Rintersect = true;
	//class_count++;
}

Circle::Circle(int x, int y, int radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;

	//class_count++;

	if (this->x < 0 && !intersectY(this->x))
	{
		class_count++;
	}
}

int Circle::getX()
{
	return x;
}

int Circle::getY()
{
	return y;
}

double Circle::getRadius()
{
	return radius;
}

void Circle::translateXY(int X, int Y)
{
	x += X;
	y += Y;
	
	// decrements the class_count if the Circle falls to the left side
	// of the y-axis or intersects with y-axis
	if((x < 0 || intersectY(x)) && Lintersect)
	{
		Lintersect = false;
		Rintersect = true;
		class_count--;
	}
	
	// increments the class_count if the Circle does not intersect with 
	// y-axis and stays on the right side of y-axis
	if(x >= 0 && !intersectY(x) && Rintersect)
	{
		Lintersect = true;
		Rintersect = false; 
		class_count++;
	}
}

void Circle::setRadius(double r)
{
	radius = (r > 0) ? r : 10;
}

double Circle::computeArea()
{
	// acos returns Pi / 2
	double pi = std::acos(0) * 2;

	return pi * radius * radius;
}

void Circle::displayCircle()
{
	std::cout << "[ x= " << x << " , y= " << y << ", radius= " << radius << " ]" << std::endl;
}

bool Circle::intersect(Circle c2)
{
	double l = length(x, y, c2.getX(), c2.getY());

	return l <= (c2.getRadius() + radius);
}

int Circle::getNumberofCurrentCircles()
{
	return class_count;
}

// Helper functions
// Calculates the length between centre of two circles
double Circle::length(const int x1, const int y1, const int x2, int y2)
{
	return (double) std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
}

// returns true if the circle intersects with y-axis
bool Circle::intersectY(const int x1, const int x2)
{
	return std::pow(radius, 2) > std::pow(x2 - x1, 2);
}