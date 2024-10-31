#pragma once
#include <iostream>
#include "Figure.h"

template <class T>
class Rhomb : public Figure<T> {
  public:
   Rhomb() : Figure<T>(4) {}
   Rhomb(const Rhomb<T>& other) : Figure<T>(other) {}
   Rhomb(Rhomb<T>&& other) noexcept : Figure<T>(other) {}
   Rhomb(const std::initializer_list<T>&);
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