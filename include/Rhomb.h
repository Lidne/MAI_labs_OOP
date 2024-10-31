#pragma once
#include <iostream>
#include "Figure.h"

template <Number T>
class Rhomb : public Figure<T> {
  public:
   Rhomb();
   Rhomb(const Rhomb& other);
   Rhomb(Rhomb&& other) noexcept;
   Rhomb(const std::initializer_list<Point<T>>&);
   virtual ~Rhomb();
};

template <class T>
inline std::ostream& operator<<(std::ostream& os, const Rhomb<T>& figure) {
   os << "Rhomb[ ";
   Point<T>* points = figure.getPoints();
   size_t size = figure.size();
   for (size_t i = 0; i < figure.size(); i++) {
      os << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   os << "]";
   return os;
}

template <class T>
inline std::istream& operator>>(std::istream& in, Rhomb<T>& figure) {
   T x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point<T> point(x, y);
      figure.setPoint(point, i);
   }
   return in;
}