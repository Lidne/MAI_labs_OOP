#pragma once
#include <memory>
#include <stdexcept>
#include "Point.h"

template <class T>
class Array {
  public:
   Array();
   Array(const Array &);
   Array(Array &&) noexcept;

   size_t size() const;
   Array &operator=(const Array &);
   Array &operator=(Array &&) noexcept;
   std::shared_ptr<T> &operator[](size_t);

   void append(std::shared_ptr<T>);
   void remove(size_t);
   void clear();

  private:
   size_t s;
   size_t capacity;

   std::unique_ptr<std::shared_ptr<T>[]> arr;
   void resize(size_t);
   void copy(const Array &);
};