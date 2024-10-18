#pragma once
#include <iostream>
#include "Figure.h"

class Rhomb : public Figure {
  public:
   Rhomb();
   Rhomb(const Rhomb&);
   Rhomb(Rhomb&&) noexcept;
   Rhomb(const std::initializer_list<Point>&);
   virtual ~Rhomb();
};

inline std::ostream& operator<<(std::ostream& os, const Rhomb& figure) {
   os << "Rhomb[ ";
   Point* points = figure.getPoints();
   size_t size = figure.size();
   for (size_t i = 0; i < figure.size(); i++) {
      os << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   os << "]";
   return os;
}

inline std::istream& operator>>(std::istream& in, Rhomb& figure) {
   double x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point point({x, y});
      figure.setPoint(point, i);
   }
   return in;
}