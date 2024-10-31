#pragma once
#include <concepts>
#include <iostream>
#include <memory>
#include <type_traits>

template <typename T>
concept Number = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <Number T>
class Point {
  public:
   T x, y;
   Point();
   Point(std::initializer_list<T>& t);
   Point(T, T);
   bool operator==(const Point&) const;
   bool operator!=(const Point&) const;
   Point operator+(const Point&) const;
   Point operator-(const Point&) const;
   double operator*(const Point&) const;
   double abs() const;
};

template <class T>
inline std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
   os << "Point[ " << point.x << ", " << point.y << " ]";
   return os;
}
