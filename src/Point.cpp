#include "Point.h"
#include <math.h>

template <Number T>
Point<T>::Point() : x(0.0), y(0.0) {}

template <Number T>
Point<T>::Point(T newX, T newY) : x(newX), y(newY) {}

template <Number T>
bool Point<T>::operator==(const Point& other) const {
   return this->x == other.x && this->y == other.y;
}

template <Number T>
bool Point<T>::operator!=(const Point<T>& other) const {
   return !(*this == other);
}

template <Number T>
Point<T> Point<T>::operator+(const Point& other) const {
   return Point(x + other.x, y + other.y);
}

template <Number T>
Point<T> Point<T>::operator-(const Point& other) const {
   return Point(x - other.x, y - other.y);
}

template <Number T>
double Point<T>::operator*(const Point& other) const {
   return x * other.x + y * other.y;
}

template <Number T>
double Point<T>::abs() const {
   return sqrt(x * x + y * y);
}
