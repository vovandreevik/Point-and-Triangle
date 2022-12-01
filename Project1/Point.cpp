#include "Point.h"
#include <cmath>

Point::Point() : x_(0), y_(0) {}

Point::Point(float x, float y) : x_(x), y_(y) {}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

Point::~Point() = default;

void Point::setX(float x)
{
	x_ = x;
}

void Point::setY(float y)
{
	y_ = y;
}

float Point::getX() const
{
	return x_;
}

float Point::getY() const
{
	return y_;
}

bool Point::isEqual(const Point& other)
{
	return ((x_ == other.x_) and (y_ == other.y_));
}

float Point::getDistance(const Point& other)
{
	return sqrt((x_ - other.x_) * (x_ - other.x_) + (y_ - other.y_) * (y_ - other.y_));
}

void Point::move(float k) 
{
	x_ += k;
	y_ += k;
}