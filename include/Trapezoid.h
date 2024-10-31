#pragma once
#include <iostream>
#include "Figure.h"

template <Number T>
class Trapezoid : public Figure<T> {
  public:
   Trapezoid();
   Trapezoid(const Trapezoid& other);
   Trapezoid(Trapezoid&& other) noexcept;
   Trapezoid(const std::initializer_list<Point<T>>&);
   virtual ~Trapezoid() noexcept;
};

template <class T>
inline std::ostream& operator<<(std::ostream& os, const Trapezoid<T>& figure) {
   os << "Trapezoid[ ";
   Point<T>* points = figure.getPoints();
   size_t size = figure.size();
   for (size_t i = 0; i < figure.size(); i++) {
      os << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   os << "]";
   return os;
}

template <class T>
inline std::istream& operator>>(std::istream& in, Trapezoid<T>& figure) {
   T x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point<T> point(x, y);
      figure.setPoint(point, i);
   }
   return in;
}