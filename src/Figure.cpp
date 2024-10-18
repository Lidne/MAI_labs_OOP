#include "Figure.h"
#include <math.h>
#include <iostream>

void Figure::print() const {
   std::cout << "[ ";
   for (size_t i = 0; i < length; i++) {
      std::cout << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   std::cout << "]" << std::endl;
}

Figure::Figure() : points(nullptr), length(0) {}

Figure::Figure(size_t n) : points(new Point[n]), length(n) {}

Figure::Figure(const Figure& other) { copy(other); }

Figure::Figure(Figure&& other) noexcept
    : length(other.length), points(other.points) {
   other.length = 0;
   other.points = nullptr;
}

Figure::~Figure() { clear(); }

Figure::Figure(const std::initializer_list<Point>& t)
    : points(new Point[t.size()]), length(t.size()) {
   size_t i = 0;
   for (Point p : t) {
      points[i] = p;
      i++;
   }
}

Point* Figure::getPoints() const { return points; }

void Figure::setPoints(Point* p) { points = p; }

void Figure::setPoint(Point& point, size_t i) { points[i] = point; }

size_t Figure::size() const { return length; }

void Figure::clear() {
   delete[] points;
   length = 0;
   points = nullptr;
}

void Figure::copy(const Figure& other) {
   length = other.size();
   points = new Point[length];
   std::copy(other.getPoints(), other.getPoints() + length, points);
}

Figure& Figure::operator=(const Figure& other) {
   if (this != &other) {
      clear();
      copy(other);
   }
   return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
   if (this != &other) {
      length = other.size();
      delete[] points;
      points = other.getPoints();
      other.length = 0;
      other.points = nullptr;
   }
   return *this;
}

bool Figure::operator==(const Figure& other) const {
   if (length != other.size()) {
      return false;
   }
   Point* otherPoints = other.getPoints();
   for (size_t i = 0; i < length; i++) {
      if (points[i].x != otherPoints[i].x || points[i].y != otherPoints[i].y) {
         return false;
      }
   }
   return true;
}

double Figure::area() const {
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

Point* Figure::center() const {
   Point* center = new Point();
   for (size_t i = 0; i < length; i++) {
      center->x += points[i].x;
      center->y += points[i].y;
   }
   center->x /= length;
   center->y /= length;
   return center;
}
