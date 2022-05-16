#pragma once
#ifndef _CIRCLE_H_
#define _CIRCLE_H_

class Circle
{
private:
	int x, y;
	double radius;
	static int class_count;
	// Helper functions and variables
	double length(const int x1, const int y1, const int x2, const int y2);
	bool intersectY(const int x1, const int x2 = 0);
	bool Lintersect;
	bool Rintersect;
	
public:
	Circle();
	Circle(int x, int y, int radius);
	int getX();
	int getY();
	double getRadius();
	void translateXY(int X, int Y);
	void setRadius(double r);
	double computeArea();
	void displayCircle();
	bool intersect(Circle c2);
	int getNumberofCurrentCircles();
};

#endif // !_CIRCLE_H_
