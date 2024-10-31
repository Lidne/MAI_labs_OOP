#pragma once
#include <iostream>
#include "Figure.h"

template <class T>
class Rectangle : public Figure<T> {
  public:
   Rectangle() : Figure<T>(4) {}
   Rectangle(const Rectangle<T>& other) : Figure<T>(other) {}
   Rectangle(Rectangle<T>&& other) noexcept : Figure<T>(other) {}
   Rectangle(const std::initializer_list<T>& t);
   virtual ~Rectangle() noexcept;
};

template <class T>
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

template <class T>
inline std::istream& operator>>(std::istream& in, Rectangle<T>& figure) {
   T x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point<T> point(x, y);
      figure.setPoint(point, i);
   }
   return in;
}