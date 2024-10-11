#include "Figure.h"
#include <iostream>

void Figure::print() const {
   std::cout << "[ ";
   for (size_t i = 0; i < length; i++) {
      std::cout << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   std::cout << " ]" << std::endl;
}

Figure::Figure() : points(nullptr), length(0) {}

Figure::~Figure() {
   delete points;
   points = nullptr;
}

Figure::Figure(const std::initializer_list<Point>& t)
    : points(new Point[t.size()]), length(t.size()) {
   size_t i = 0;
   for (Point p : t) {
      points[i] = p;
      i++;
   }
}
