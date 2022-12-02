#pragma once

class Point
{
private:
	float x_, y_;

public:
	Point();
	Point(float x, float y);
	Point(const Point& other);
	~Point();

	void setX(float x);
	void setY(float y);

	float getX() const;
	float getY() const;

	bool isEqual(const Point& other);
	float getDistance(const Point& other);
	void move(float k);
};