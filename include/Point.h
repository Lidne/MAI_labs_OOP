#pragma once
#include <iostream>

class Point {
  public:
   double x, y;
   Point();
   Point(double, double);
   bool operator==(const Point&) const;
   bool operator!=(const Point&) const;
   Point operator+(const Point&) const;
   Point operator-(const Point&) const;
   double operator*(const Point&) const;
   double abs() const;
};

inline std::ostream& operator<<(std::ostream& os, const Point& point) {
   os << "Point[ " << point.x << ", " << point.y << " ]";
   return os;
}
