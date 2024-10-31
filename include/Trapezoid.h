#pragma once
#include <iostream>
#include "Figure.h"

template <class T>
class Trapezoid : public Figure<T> {
  public:
   Trapezoid() : Figure<T>(4) {}
   Trapezoid(const Trapezoid<T>& other) : Figure<T>(other) {}
   Trapezoid(Trapezoid<T>&& other) noexcept : Figure<T>(other) {}
   Trapezoid(const std::initializer_list<T>&);
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