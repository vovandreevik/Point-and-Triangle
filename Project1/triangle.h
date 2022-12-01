#pragma once
#include "Point.h"

class Triangle
{
private:
	Point a_, b_, c_;

public:
	Triangle();
	Triangle(Point a, Point b, Point c);
	Triangle(const Triangle& other);
	~Triangle();

	void setA(Point a);
	void setB(Point b);
	void setC(Point c);
	Point getA();
	Point getB();
	Point getC();

	bool isTriangle();
	void move(float k);
	float getPerimeter();
	bool isEqual(Triangle& other);
	float square();
};

