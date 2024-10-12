#include "Rhomb.h"

Rhomb::Rhomb() : Figure(4) {}

Rhomb::Rhomb(Point* p, size_t l) : Figure(p, l) {}

Rhomb::Rhomb(const std::initializer_list<Point>& t) {
   if (t.size() != 4) {
      throw std::invalid_argument("Rhomb has 4 vertices, idiot!");
   }

   auto it = t.begin();
   Point p1 = *it++;
   Point p2 = *it++;
   Point p3 = *it++;
   Point p4 = *it;

   double len1 = (p2 - p1).abs();
   double len2 = (p3 - p2).abs();
   double len3 = (p4 - p3).abs();
   double len4 = (p1 - p4).abs();

   if (len1 != len2 || len1 != len3 || len1 != len4 || len2 != len3 ||
       len2 != len4 || len3 != len4) {
      throw std::invalid_argument("Not a rhomb");
   }

   length = t.size();
   points = new Point[length];

   size_t i = 0;
   for (Point p : t) {
      points[i] = p;
      i++;
   }
}
