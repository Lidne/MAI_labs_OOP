#include "Figure.h"
#include <math.h>
#include <iostream>
#include "Point.h"

template <Number T>
void Figure<T>::print() const {
   std::cout << "[ ";
   for (size_t i = 0; i < length; i++) {
      std::cout << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   std::cout << "]" << std::endl;
}

template <Number T>
Figure<T>::Figure() : points(nullptr), length(0) {}

template <Number T>
Figure<T>::Figure(size_t n)
    : points(std::make_unique<Point<T>[]>(n)), length(n) {}

template <Number T>
Figure<T>::Figure(const Figure& other) {
   copy(other);
}

template <Number T>
Figure<T>::Figure(Figure&& other) noexcept
    : length(other.length), points(std::move(other.points)) {
   other.length = 0;
   other.points = nullptr;
}

template <Number T>
Figure<T>::~Figure() noexcept {
   clear();
}

template <Number T>
Figure<T>::Figure(const std::initializer_list<Point<T>>& t)
    : points(std::make_unique<Point<T>[]>(t.size())), length(t.size()) {
   size_t i = 0;
   for (Point<T> p : t) {
      points[i++] = p;
   }
}

template <Number T>
const std::unique_ptr<Point<T>[]>& Figure<T>::getPoints() const {
   return points;
}

template <Number T>
void Figure<T>::setPoints(std::unique_ptr<Point<T>[]> p) {
   points = std::move(p);
}

template <Number T>
void Figure<T>::setPoint(const Point<T>& point, size_t i) {
   if (i < length) {
      points[i] = point;
   }
}

template <Number T>
size_t Figure<T>::size() const {
   return length;
}

template <Number T>
void Figure<T>::clear() {
   points.reset();
   points = nullptr;
}

template <Number T>
void Figure<T>::copy(const Figure& other) {
   if (this != &other) {
      clear();

      length = other.length;
      points = std::make_unique<Point<T>[]>(length);

      for (size_t i = 0; i < length; i++) {
         points[i] = other.points[i];
      }
   }
}

template <Number T>
Figure<T>& Figure<T>::operator=(const Figure& other) {
   if (this != &other) {
      clear();
      copy(other);
   }
   return *this;
}

template <Number T>
Figure<T>& Figure<T>::operator=(Figure&& other) noexcept {
   if (this != &other) {
      for (int i = 0; i < length; i++) {
         points[i] = std::move(other.points[i]);
      }
   }
   return *this;
}

template <Number T>
bool Figure<T>::operator==(const Figure& other) const {
   if (length != other.size()) {
      return false;
   }
   Point<T>* otherPoints = other.getPoints();
   for (size_t i = 0; i < length; i++) {
      if (points[i].x != otherPoints[i].x || points[i].y != otherPoints[i].y) {
         return false;
      }
   }
   return true;
}

template <Number T>
double Figure<T>::area() const {
   /* функция будет правильно считать площадь, если точки указаны в порядке
    * обхода по/против часовой */
   double totalArea;
   for (size_t i = 0; i < length - 1; i++) {
      totalArea += points[i].x * points[i + 1].y;
   }
   totalArea += points[length - 1].x * points[0].y;
   for (size_t i = 0; i < length - 1; i++) {
      totalArea -= points[i + 1].x * points[i].y;
   }
   totalArea -= points[0].x * points[length - 1].y;
   return abs(totalArea) * 0.5;
}

template <Number T>
std::unique_ptr<Point<T>> Figure<T>::center() const {
   std::unique_ptr<Point<T>> center = std::make_unique<Point<T>>();
   for (size_t i = 0; i < length; i++) {
      center->x += points[i].x;
      center->y += points[i].y;
   }
   center->x /= length;
   center->y /= length;
   return center;
}

template <Number T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
   os << "[ ";
   auto& points = figure.getPoints();
   size_t size = figure.size();
   for (size_t i = 0; i < size; i++) {
      os << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   os << "]";
   return os;
}

template <Number T>
std::istream& operator>>(std::istream& in, Figure<T>& figure) {
   T x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point<T> point({x, y});
      figure.setPoint(point, i);
   }
   return in;
}