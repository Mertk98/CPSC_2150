#pragma once
#ifndef _CIRCLE_H_
#define _CIRCLE_H_

class Circle
{
private:
	int x_, y_;
	double radius_;
	static int classCount_;

	//Helper functions and variables
	double length(const int x1, const int y1, const int x2, const int y2);
	bool intersectY(const int x1, const int x2 = 0);
	void changeClassCount();
	bool Lintersect_;
	bool Rintersect_;

public:
	Circle();
	Circle(int x, int y, double radius);
	int getX();
	int getY();
	double getRadius();
	void translateXY(int X, int Y);
	void setRadius(double r);
	double computeArea();
	void displayCircle();
	bool intersect(Circle c2);
	int getNumberofCurrentCircles();
	~Circle();
};

#endif // !_CIRCLE_H_
