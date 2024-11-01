#include "Rhomb.h"

template <Number T>
Rhomb<T>::Rhomb() : Figure<T>(4) {}

template <Number T>
Rhomb<T>::Rhomb(const Rhomb& other) : Figure<T>(other) {}

template <Number T>
Rhomb<T>::Rhomb(Rhomb&& other) noexcept : Figure<T>(other) {}

template <Number T>
Rhomb<T>::Rhomb(const std::initializer_list<Point<T>>& t) {
   if (t.size() != 4) {
      throw std::invalid_argument("Rhomb has 4 vertices, idiot!");
   }

   auto it = t.begin();
   Point<T> p1 = *it++;
   Point<T> p2 = *it++;
   Point<T> p3 = *it++;
   Point<T> p4 = *it;

   T len1 = (p2 - p1).abs();
   T len2 = (p3 - p2).abs();
   T len3 = (p4 - p3).abs();
   T len4 = (p1 - p4).abs();

   if (len1 != len2 || len1 != len3 || len1 != len4 || len2 != len3 ||
       len2 != len4 || len3 != len4) {
      throw std::invalid_argument("Not a rhomb");
   }

   Figure<T>::length = t.size();
   Figure<T>::points = std::make_unique<Point<T>[]>(Figure<T>::length);

   size_t i = 0;
   for (Point<T> p : t) {
      Figure<T>::points[i] = p;
      i++;
   }
}

template <Number T>
Rhomb<T>::~Rhomb() {}

template <class T>
std::ostream& operator<<(std::ostream& os, const Rhomb<T>& figure) {
   os << "Rhomb[ ";
   auto& points = figure.getPoints();
   size_t size = figure.size();
   for (size_t i = 0; i < figure.size(); i++) {
      os << "(" << points[i].x << ", " << points[i].y << "), ";
   }
   os << "]";
   return os;
}

template <class T>
std::istream& operator>>(std::istream& in, Rhomb<T>& figure) {
   T x, y;
   for (size_t i = 0; i < figure.size(); i++) {
      in >> x >> y;
      Point<T> point(x, y);
      figure.setPoint(point, i);
   }
   return in;
}