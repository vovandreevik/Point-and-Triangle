#include <iostream>
#include "Point.h"
#include "Triangle.h"


bool isPointInCircle(float r, const Point& p);

Point input(std::istream& s);

void outputPoint(std::ostream& s, const Point& p);

void outputTriangle(std::ostream& s, Triangle& t);

bool isEqualSquare(Triangle& t1, Triangle& t2);


int main()
{
    std::cout << "Test for class Point \n";
    float minnimalDistance = 2e30, k = 7;
    Point point(0.0, 0.0), test(9, 12), res(0.0, 0.0), origin(0.0, 0.0);

    while (true) {
        point = input(std::cin);
        try {
            if (!std::cin or std::cin.peek() != '\n') {
                throw std::runtime_error("bad input, the coordinates must be float");
            }
        }
        catch (std::exception const& e) {
            std::cerr << "Error: " << e.what() << "\n";
            return -1;
        }

        if (point.getX() == 0 and point.getY() == 0) {
            break;
        }
        if (minnimalDistance > point.getDistance(origin)) {
            minnimalDistance = point.getDistance(origin);
            res = point;
        }

        point.~Point();
    }
    std::cout << "Nearest to (0, 0): ";  outputPoint(std::cout, res); std::cout << '\n';
    std::cout << "Enter the coordinates of the point to check the functions:\n";
    point = input(std::cin);
    try {
        if (!std::cin or std::cin.peek() != '\n') {
            throw std::runtime_error("bad input, the coordinates must be float");
        }
    }
    catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return -1;
    }
    std::cout << "Is equal with (9; 12)? Result: " << point.isEqual(test) << '\n';
    std::cout << "Distance to (9; 12): " << point.getDistance(test) << '\n';
    point.move(k);
    std::cout << "Cordinates after moving ("<< k << "): "; outputPoint(std::cout, point); std::cout << "\n\n";
    res.~Point();
    point.~Point();
    test.~Point();

    std::cout << "Working with the Triangle \n";
    Triangle a(Point(3, 3), Point(2, 2), Point(4, 2));
    Triangle b(Point(3, 3), Point(-782, 2), Point(42, 32));
    Triangle c(Point(18, 24), Point(23, 18), Point(18213, 324324324));

    std::cout << "first triangle:"; outputTriangle(std::cout, a); std::cout << '\n';
    std::cout << "second triangle: "; outputTriangle(std::cout, b); std::cout << '\n';
    std::cout << "third triangle: "; outputTriangle(std::cout, c); std::cout << "\n\n";

    a.move(k);
    std::cout << "first triangle after moving ("<<k<<"): "; outputTriangle(std::cout, a); std::cout << "\n";
    
    std::cout << "Square of the first triangle: " << a.square() << '\n';
    std::cout << "Perimeter of the second triangle: " << b.getPerimeter() << "\n\n";

    std::cout << "Is the first triangle?  Result: " << a.isTriangle() << '\n';
    std::cout << "Is the third triangle? Result: " << c.isTriangle() << "\n\n";

    std::cout << "Is the first triangle equal the third triangle? Result: " << a.isEqual(b) << "\n\n";

    std::cout << "Is equal square of the first triangle and square of the second triangle? Result: " << isEqualSquare(a, b) << '\n';
    std::cout << "Is equal square of the first triangle and square of the third triangle? Result: " << isEqualSquare(a, c) << "\n\n";

    a.~Triangle();
    b.~Triangle();
    c.~Triangle();
    return 0;
}


bool isPointInCircle(float r, const Point& p) {
    return r >= sqrt(p.getX() * p.getX() + p.getY() * p.getY());
}


Point input(std::istream& s) {
    double x, y;
    s >> x;
    s >> y;
    Point p(x, y);
    return p;
}


void outputPoint(std::ostream& s, const Point& p) {
    s << "(" << p.getX() << "; " << p.getY() << ") ";
}


void outputTriangle(std::ostream& s, Triangle& t) {
    outputPoint(std::cout, t.getA());
    std::cout << ' ';
    outputPoint(std::cout, t.getB());
    std::cout << ' ';
    outputPoint(std::cout, t.getC());
}


bool isEqualSquare(Triangle& t1, Triangle& t2) {
    return (t1.square() == t2.square());
}