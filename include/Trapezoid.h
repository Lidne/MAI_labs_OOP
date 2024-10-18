#pragma once
#include <iostream>
#include "Figure.h"

class Trapezoid : public Figure {
  public:
   Trapezoid();
   Trapezoid(const Trapezoid&);
   Trapezoid(Trapezoid&&) noexcept;
   Trapezoid(const std::initializer_list<Point>&);
   virtual ~Trapezoid();
};

inline std::ostream& operator<<(std::ostream& os, const Trapezoid& figure) {
   os << "Trapezoid[ ";
   Point* points = figure.getPoints();
   size_t size = figure.size();
   for (size_t i = 0; i < figure.size(); i++) {
      os << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   os << "]";
   return os;
}

inline std::istream& operator>>(std::istream& in, Trapezoid& figure) {
   double x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point point({x, y});
      figure.setPoint(point, i);
   }
   return in;
}