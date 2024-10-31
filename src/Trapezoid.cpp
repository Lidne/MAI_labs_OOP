#include "Trapezoid.h"
#include <iostream>

// template <class T>
// Trapezoid<T>::Trapezoid() : Figure<T>(4) {}

// template <class T>
// Trapezoid<T>::Trapezoid(const Trapezoid<T>& other) : Figure<T>(other) {}

// template <class T>
// Trapezoid<T>::Trapezoid(Trapezoid<T>&& other) noexcept : Figure<T>(other) {}

template <class T>
Trapezoid<T>::Trapezoid(const std::initializer_list<T>& t) {
   if (t.size() != 4) {
      throw std::invalid_argument("Trapezoid has 4 vertices, idiot!");
   }

   auto it = t.begin();
   Point<T> p1 = *it++;
   Point<T> p2 = *it++;
   Point<T> p3 = *it++;
   Point<T> p4 = *it;

   Point<T> v1 = p2 - p1;
   Point<T> v2 = p3 - p2;
   Point<T> v3 = p4 - p3;
   Point<T> v4 = p1 - p4;

   if (!((((abs((v1 * v3) / (v1.abs() * v3.abs())) == 1.0) &&
           (abs((v2 * v4) / (v2.abs() * v4.abs())) != 1.0)) ||
          ((abs((v1 * v3) / (v1.abs() * v3.abs())) != 1.0) &&
           (abs((v2 * v4) / (v2.abs() * v4.abs())) == 1.0))) &&
         !((abs((v1 * v3) / (v1.abs() * v3.abs())) == 1.0) &&
           (abs((v2 * v4) / (v2.abs() * v4.abs())) == 1.0)))) {
      throw std::invalid_argument("Not a trapezoid");
   }

   Figure<T>::length = t.size();
   Figure<T>::points = new Point<T>[Figure<T>::length];

   size_t i = 0;
   for (Point<T> p : t) {
      Figure<T>::points[i] = p;
      i++;
   }
}

template <class T>
Trapezoid<T>::~Trapezoid() noexcept {}