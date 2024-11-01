#pragma once
#include <iostream>
#include "Figure.h"
#include "Point.h"

template <Number T>
class Rectangle : public Figure<T> {
  public:
   Rectangle();
   Rectangle(const Rectangle& other);
   Rectangle(Rectangle&& other) noexcept;
   Rectangle(const std::initializer_list<Point<T>>& t);
   virtual ~Rectangle() noexcept;

   template <Number V>
   friend std::ostream& operator<<(std::ostream& os,
                                   const Rectangle<V>& figure);

   template <Number V>
   friend std::istream& operator>>(std::istream& in, Rectangle<V>& figure);
};
