#include <iostream>
#include <cmath>
#include "Circle.h"

int Circle::classCount_ = 0;

Circle::Circle()
{
	x_ = y_ = 0;
	radius_ = 10;
	Lintersect_ = true;
	Rintersect_ = true;
	//class_count++;
}

Circle::Circle(int x, int y, double radius)
{
	x_ = x;
	y_ = y;
	setRadius(radius);

	//class_count++;

	if (x_ < 0 && !intersectY(x_))
	{
		classCount_++;
	}
}

int Circle::getX()
{
	return x_;
}

int Circle::getY()
{
	return y_;
}

double Circle::getRadius()
{
	return radius_;
}

void Circle::translateXY(int X, int Y)
{
	x_ += X;
	y_ += Y;

	changeClassCount();
}

void Circle::setRadius(double r)
{
	radius_ = (r > 0) ? r : 10;
}

double Circle::computeArea()
{
	// acos returns Pi / 2
	double pi = std::acos(0) * 2;

	return pi * radius_ * radius_;
}

void Circle::displayCircle()
{
	std::cout << "[ x= " << x_ << " , y= " << y_ << ", radius= " << radius_ << " ]" << std::endl;
}

bool Circle::intersect(Circle c2)
{
	double l = length(x_, y_, c2.getX(), c2.getY());

	return l <= (c2.getRadius() + radius_);
}

int Circle::getNumberofCurrentCircles()
{
	return classCount_;
}

// Helper functions
// Calculates the length between centre of two circles
double Circle::length(const int x1, const int y1, const int x2, int y2)
{
	return (double)std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
}

// returns true if the circle intersects with y-axis
bool Circle::intersectY(const int x1, const int x2)
{
	return std::pow(radius_, 2) > std::pow(x2 - x1, 2);
}

void Circle::changeClassCount()
{
	// Decrements the class_count if the Circle intersects with 
	// y-axis and on the left side of y-axis
	if ((x_ < 0 || intersectY(x_)) && Lintersect_)
	{
		Lintersect_ = false;
		Rintersect_ = true;
		classCount_--;
	}

	// increments the class_count if the Circle does not intersect with 
	// y-axis and on the right side of y-axis
	if (x_ >= 0 && !intersectY(x_) && Rintersect_)
	{
		Lintersect_ = true;
		Rintersect_ = false;
		classCount_++;
	}
}


Circle::~Circle()
{
	classCount_--;
}