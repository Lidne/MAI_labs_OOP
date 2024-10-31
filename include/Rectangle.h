#pragma once
#include <iostream>
#include "Figure.h"
#include "Point.h"

template <Number T>
class Rectangle : public Figure<T> {
  public:
   Rectangle();
   Rectangle(const Rectangle& other);
   Rectangle(Rectangle&& other) noexcept;
   Rectangle(const std::initializer_list<Point<T>>& t);
   virtual ~Rectangle() noexcept;
};

template <Number T>
inline std::ostream& operator<<(std::ostream& os, const Rectangle<T>& figure) {
   os << "Rectangle[ ";
   Point<T>* points = figure.getPoints();
   size_t size = figure.size();
   for (size_t i = 0; i < figure.size(); i++) {
      os << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   os << "]";
   return os;
}

template <Number T>
inline std::istream& operator>>(std::istream& in, Rectangle<T>& figure) {
   T x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point<T> point(x, y);
      figure.setPoint(point, i);
   }
   return in;
}