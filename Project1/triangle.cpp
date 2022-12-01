#include <cmath>
#include "Triangle.h"

Triangle::Triangle() : a_(Point()), b_(Point()), c_(Point()) {}

Triangle::Triangle(Point a, Point b, Point c) : a_(a), b_(b), c_(c) {}

Triangle::Triangle(const Triangle& other) : a_(other.a_), b_(other.b_), c_(other.c_) {}

Triangle::~Triangle() = default;

void Triangle::setA(Point a) 
{
	a_.setX(a_.getX());
	a_.setY(a_.getY());
}

void Triangle::setB(Point b)
{
	b_.setX(b_.getX());
	b_.setY(b_.getY());
}

void Triangle::setC(Point c)
{
	c_.setX(c_.getX());
	c_.setY(c_.getY());
}

Point Triangle::getA()
{
	return a_;
}

Point Triangle::getB()
{
	return b_;
}

Point Triangle::getC()
{
	return c_;
}

bool Triangle::isTriangle()
{
	return ((a_.getDistance(b_) < (a_.getDistance(c_) + c_.getDistance(b_)))
		and (a_.getDistance(c_) < a_.getDistance(b_) + c_.getDistance(b_))
		and (c_.getDistance(b_) < a_.getDistance(b_) + a_.getDistance(c_)));
}

void Triangle::move(float k) 
{
	a_.move(k);
	b_.move(k);
	c_.move(k);
}

float Triangle::getPerimeter()
{
	return (a_.getDistance(b_) + a_.getDistance(c_) + b_.getDistance(c_));
}

bool Triangle::isEqual(Triangle& other)
{
	return ((a_.isEqual(other.getA()) or a_.isEqual(other.getB()) or a_.isEqual(other.getC()))
		and (b_.isEqual(other.getB()) or b_.isEqual(other.getC()) and (c_.isEqual(other.getC()))));
}

float Triangle::square() {
	return (abs((b_.getX() - a_.getX()) * (c_.getY() - a_.getY()) 
		- (c_.getX() - a_.getX()) * (b_.getY() - a_.getY())) / 2);
}
