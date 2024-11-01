#pragma once
#include <iostream>
#include <memory>
#include "Point.h"

template <Number T>
class Figure {
  protected:
   std::unique_ptr<Point<T>[]> points;
   size_t length;

  public:
   Figure();
   Figure(size_t);
   Figure(const Figure&);
   Figure(Figure&&) noexcept;
   Figure(const std::initializer_list<Point<T>>&);
   virtual ~Figure() noexcept;

   const std::unique_ptr<Point<T>[]>& getPoints() const;
   void setPoints(std::unique_ptr<Point<T>[]>);
   void setPoint(const Point<T>&, size_t);
   size_t size() const;
   void clear();
   void copy(const Figure&);
   void print() const;
   double area() const;
   std::unique_ptr<Point<T>> center() const;

   Figure& operator=(const Figure&);
   Figure& operator=(Figure&&) noexcept;
   bool operator==(const Figure&) const;
   operator double() const { return area(); }

   template <Number V>
   friend std::ostream& operator<<(std::ostream& os, const Figure<V>& figure);

   template <Number V>
   friend std::istream& operator>>(std::istream& in, Figure<V>& figure);
};
