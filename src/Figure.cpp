#include "Figure.h"
#include <math.h>
#include <iostream>

template <class T>
void Figure<T>::print() const {
   std::cout << "[ ";
   for (size_t i = 0; i < length; i++) {
      std::cout << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   std::cout << "]" << std::endl;
}

template <class T>
Figure<T>::Figure() : points(nullptr), length(0) {}

template <class T>
Figure<T>::Figure(size_t n) : points(new Point<T>[n]), length(n) {}

template <class T>
Figure<T>::Figure(const Figure& other) {
   copy(other);
}

template <class T>
Figure<T>::Figure(Figure&& other) noexcept
    : length(other.length), points(other.points) {
   other.length = 0;
   other.points = nullptr;
}

template <class T>
Figure<T>::~Figure() noexcept {
   clear();
}

template <class T>
Figure<T>::Figure(const std::initializer_list<Point<T>>& t)
    : points(new Point<T>[t.size()]), length(t.size()) {
   size_t i = 0;
   for (Point<T> p : t) {
      points[i] = p;
      i++;
   }
}

template <class T>
Point<T>* Figure<T>::getPoints() const {
   return points;
}

template <class T>
void Figure<T>::setPoints(Point<T>* p) {
   points = p;
}

template <class T>
void Figure<T>::setPoint(Point<T>& point, size_t i) {
   points[i] = point;
}

template <class T>
size_t Figure<T>::size() const {
   return length;
}

template <class T>
void Figure<T>::clear() {
   delete[] points;
   length = 0;
   points = nullptr;
}

template <class T>
void Figure<T>::copy(const Figure<T>& other) {
   length = other.size();
   points = new Point<T>[length];
   std::copy(other.getPoints(), other.getPoints() + length, points);
}

template <class T>
Figure<T>& Figure<T>::operator=(const Figure<T>& other) {
   if (this != &other) {
      clear();
      copy(other);
   }
   return *this;
}

template <class T>
Figure<T>& Figure<T>::operator=(Figure<T>&& other) noexcept {
   if (this != &other) {
      length = other.size();
      delete[] points;
      points = other.getPoints();
      other.length = 0;
      other.points = nullptr;
   }
   return *this;
}

template <class T>
bool Figure<T>::operator==(const Figure<T>& other) const {
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

template <class T>
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

template <class T>
Point<T>* Figure<T>::center() const {
   Point<T>* center = new Point<T>();
   for (size_t i = 0; i < length; i++) {
      center->x += points[i].x;
      center->y += points[i].y;
   }
   center->x /= length;
   center->y /= length;
   return center;
}
