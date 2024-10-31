#include "Point.h"
#include <math.h>

template <class T>
Point<T>::Point() : x(0.0), y(0.0) {}

template <class T>
Point<T>::Point(T newX, T newY) : x(newX), y(newY) {}

template <class T>
bool Point<T>::operator==(const Point<T>& other) const {
   return this->x == other.x && this->y == other.y;
}

template <class T>
bool Point<T>::operator!=(const Point<T>& other) const {
   return !(*this == other);
}

template <class T>
Point<T> Point<T>::operator+(const Point<T>& other) const {
   return Point(x + other.x, y + other.y);
}

template <class T>
Point<T> Point<T>::operator-(const Point<T>& other) const {
   return Point(x - other.x, y - other.y);
}

template <class T>
double Point<T>::operator*(const Point<T>& other) const {
   return x * other.x + y * other.y;
}

template <class T>
double Point<T>::abs() const {
   return sqrt(x * x + y * y);
}
