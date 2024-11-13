#pragma once

#include <iostream>
#include <iterator>
#include <memory_resource>
#include <vector>

template <typename T>
class DynamicArray {
  public:
   using allocator_type = std::pmr::polymorphic_allocator<T>;

   explicit DynamicArray(
       std::pmr::memory_resource* resource = std::pmr::get_default_resource());
   ~DynamicArray();

   void push_back(const T& value);
   void reserve(std::size_t new_capacity);
   void clear();
   std::size_t get_size() const;

   class Iterator {
     public:
      using iterator_category = std::forward_iterator_tag;
      using value_type = T;
      using difference_type = std::ptrdiff_t;
      using pointer = T*;
      using reference = T&;

      explicit Iterator(pointer ptr);
      reference operator*() const;
      pointer operator->();
      Iterator& operator++();
      Iterator operator++(int);
      friend bool operator==(const Iterator& a, const Iterator& b) {
         return a.ptr == b.ptr;
      }
      friend bool operator!=(const Iterator& a, const Iterator& b) {
         return a.ptr != b.ptr;
      }

     private:
      pointer ptr;
   };

   Iterator begin();
   Iterator end();

  private:
   allocator_type allocator;
   T* data;
   std::size_t size;
   std::size_t capacity;
};

// #include "../src/DynamicArray.cpp"