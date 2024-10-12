#pragma once
#include <iostream>
#include "Point.h"

class Figure {
  protected:
   Point* points;
   size_t length;

  public:
   Figure();
   Figure(size_t);
   Figure(Point*, size_t);
   Figure(const std::initializer_list<Point>& t);
   virtual ~Figure() noexcept;
   Point* getPoints() const;
   void setPoints(Point*);
   void setPoint(Point&, size_t);
   size_t size() const;
   void clear();
   void copy(const Figure&);
   void print() const;
   Figure& operator=(const Figure&);
   Figure& operator=(Figure&&) noexcept;
   bool operator==(const Figure&) const;
   double area() const;
   Point* center() const;
   operator double() const { return area(); }
};

inline std::ostream& operator<<(std::ostream& os, const Figure& figure) {
   os << "[ ";
   Point* points = figure.getPoints();
   size_t size = figure.size();
   for (size_t i = 0; i < figure.size(); i++) {
      os << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   os << "]";
   return os;
}

inline std::istream& operator>>(std::istream& in, Figure& figure) {
   double x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point point({x, y});
      figure.setPoint(point, i);
   }
   return in;
}