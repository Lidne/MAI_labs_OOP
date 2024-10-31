#pragma once
#include <iostream>
#include <memory>
#include "Point.h"

template <Number T>
class Figure {
  protected:
   std::unique_ptr<Point<T>[]> points;
   size_t length;

  public:
   Figure();
   Figure(size_t);
   Figure(const Figure&);
   Figure(Figure&&) noexcept;
   Figure(const std::initializer_list<Point<T>>&);
   virtual ~Figure() noexcept;
   Point<T>* getPoints() const;
   void setPoints(std::unique_ptr<Point<T>[]>);
   void setPoint(const Point<T>&, size_t);
   size_t size() const;
   void clear();
   void copy(const Figure&);
   void print() const;
   Figure& operator=(const Figure&);
   Figure& operator=(Figure&&) noexcept;
   bool operator==(const Figure&) const;
   double area() const;
   Point<T>* center() const;
   operator double() const { return area(); }
};

template <class T>
inline std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
   os << "[ ";
   Point<T>* points = figure.getPoints();
   size_t size = figure.size();
   for (size_t i = 0; i < figure.size(); i++) {
      os << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   os << "]";
   return os;
}

template <class T>
inline std::istream& operator>>(std::istream& in, Figure<T>& figure) {
   double x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point<T> point({x, y});
      figure.setPoint(point, i);
   }
   return in;
}