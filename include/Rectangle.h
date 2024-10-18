#pragma once
#include <iostream>
#include "Figure.h"

class Rectangle : public Figure {
  public:
   Rectangle();
   Rectangle(const Rectangle&);
   Rectangle(Rectangle&&) noexcept;
   Rectangle(const std::initializer_list<Point>&);
   virtual ~Rectangle();
};

inline std::ostream& operator<<(std::ostream& os, const Rectangle& figure) {
   os << "Rectangle[ ";
   Point* points = figure.getPoints();
   size_t size = figure.size();
   for (size_t i = 0; i < figure.size(); i++) {
      os << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   os << "]";
   return os;
}

inline std::istream& operator>>(std::istream& in, Rectangle& figure) {
   double x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point point({x, y});
      figure.setPoint(point, i);
   }
   return in;
}