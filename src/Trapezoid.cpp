#include "Trapezoid.h"
#include <iostream>

Trapezoid::Trapezoid() : Figure(4) {}

Trapezoid::Trapezoid(const Trapezoid& other) : Figure(other) {}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept : Figure(other) {}

Trapezoid::Trapezoid(const std::initializer_list<Point>& t) {
   if (t.size() != 4) {
      throw std::invalid_argument("Trapezoid has 4 vertices, idiot!");
   }

   auto it = t.begin();
   Point p1 = *it++;
   Point p2 = *it++;
   Point p3 = *it++;
   Point p4 = *it;

   Point v1 = p2 - p1;
   Point v2 = p3 - p2;
   Point v3 = p4 - p3;
   Point v4 = p1 - p4;

   if (!((((abs((v1 * v3) / (v1.abs() * v3.abs())) == 1.0) &&
           (abs((v2 * v4) / (v2.abs() * v4.abs())) != 1.0)) ||
          ((abs((v1 * v3) / (v1.abs() * v3.abs())) != 1.0) &&
           (abs((v2 * v4) / (v2.abs() * v4.abs())) == 1.0))) &&
         !((abs((v1 * v3) / (v1.abs() * v3.abs())) == 1.0) &&
           (abs((v2 * v4) / (v2.abs() * v4.abs())) == 1.0)))) {
      throw std::invalid_argument("Not a trapezoid");
   }

   length = t.size();
   points = new Point[length];

   size_t i = 0;
   for (Point p : t) {
      points[i] = p;
      i++;
   }
}

Trapezoid::~Trapezoid() {}