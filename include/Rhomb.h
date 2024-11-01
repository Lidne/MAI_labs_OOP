#pragma once
#include <iostream>
#include "Figure.h"

template <Number T>
class Rhomb : public Figure<T> {
  public:
   Rhomb();
   Rhomb(const Rhomb& other);
   Rhomb(Rhomb&& other) noexcept;
   Rhomb(const std::initializer_list<Point<T>>&);
   virtual ~Rhomb();

   template <Number V>
   friend std::ostream& operator<<(std::ostream& os, const Rhomb<T>& figure);

   template <Number V>
   friend std::istream& operator>>(std::istream& in, Rhomb<T>& figure);
};
