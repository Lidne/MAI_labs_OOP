#pragma once
#include <iostream>

template <class T>
class Point {
  public:
   T x, y;
   Point();
   Point(std::initializer_list<T>& t);
   Point(T, T);
   bool operator==(const Point<T>&) const;
   bool operator!=(const Point<T>&) const;
   Point<T> operator+(const Point<T>&) const;
   Point<T> operator-(const Point<T>&) const;
   double operator*(const Point<T>&) const;
   double abs() const;
};

template <class T>
inline std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
   os << "Point[ " << point.x << ", " << point.y << " ]";
   return os;
}
