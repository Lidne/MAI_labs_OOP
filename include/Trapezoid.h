#pragma once
#include <iostream>
#include "Figure.h"

template <Number T>
class Trapezoid : public Figure<T> {
  public:
   Trapezoid();
   Trapezoid(const Trapezoid& other);
   Trapezoid(Trapezoid&& other) noexcept;
   Trapezoid(const std::initializer_list<Point<T>>&);
   virtual ~Trapezoid() noexcept;

   template <Number V>
   friend std::ostream& operator<<(std::ostream& os,
                                   const Trapezoid<T>& figure);

   template <Number V>
   friend std::istream& operator>>(std::istream& in, Trapezoid<V>& figure);
};
