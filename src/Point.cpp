#include "Point.h"
#include <math.h>

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double newX, double newY) : x(newX), y(newY) {}

bool Point::operator==(const Point& other) const {
   return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point& other) const { return !(*this == other); }

Point Point::operator+(const Point& other) const {
   return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point& other) const {
   return Point(x - other.x, y - other.y);
}

double Point::operator*(const Point& other) const {
   return x * other.x + y * other.y;
}

double Point::abs() const { return sqrt(x * x + y * y); }
