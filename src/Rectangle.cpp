#include "Rectangle.h"
#include <iostream>

// template <class T>
// Rectangle<T>::Rectangle() : Figure<T>(4) {}

// template <class T>
// Rectangle<T>::Rectangle(const Rectangle<T>& other) : Figure<T>(other) {}

// template <class T>
// Rectangle<T>::Rectangle(Rectangle<T>&& other) noexcept : Figure<T>(other) {}

template <class T>
Rectangle<T>::Rectangle(const std::initializer_list<T>& t) {
   if (t.size() != 4) {
      throw std::invalid_argument("Rectangle has 4 vertices, idiot!");
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

   if ((v1 * v2 != 0) || (v2 * v3 != 0) || (v3 * v4 != 0) || (v4 * v1 != 0)) {
      throw std::invalid_argument("Not a rectangle");
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
Rectangle<T>::~Rectangle() noexcept {}