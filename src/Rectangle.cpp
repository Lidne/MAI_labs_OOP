#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() : Figure(4) {}

Rectangle::Rectangle(const Rectangle& other) : Figure(other) {}

Rectangle::Rectangle(Rectangle&& other) noexcept : Figure(other) {}

Rectangle::Rectangle(const std::initializer_list<Point>& t) {
   if (t.size() != 4) {
      throw std::invalid_argument("Rectangle has 4 vertices, idiot!");
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

   if ((v1 * v2 != 0) || (v2 * v3 != 0) || (v3 * v4 != 0) || (v4 * v1 != 0)) {
      throw std::invalid_argument("Not a rectangle");
   }

   length = t.size();
   points = new Point[length];

   size_t i = 0;
   for (Point p : t) {
      points[i] = p;
      i++;
   }
}

Rectangle::~Rectangle() {}