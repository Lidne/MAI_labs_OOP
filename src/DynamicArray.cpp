#include "DynamicArray.h"
#include <iostream>
#include <iterator>
#include <memory_resource>
#include <utility>
#include <vector>

template <typename T>
DynamicArray<T>::DynamicArray(std::pmr::memory_resource* resource)
    : allocator(resource), data(nullptr), size(0), capacity(0) {}

template <typename T>
DynamicArray<T>::~DynamicArray() {
   clear();
   allocator.deallocate(data, capacity);
}

template <typename T>
void DynamicArray<T>::push_back(const T& value) {
   if (size == capacity) {
      reserve(capacity == 0 ? 1 : capacity * 2);
   }
   allocator.construct(&data[size++], value);
}

template <typename T>
void DynamicArray<T>::reserve(std::size_t new_capacity) {
   if (new_capacity > capacity) {
      T* new_data = allocator.allocate(new_capacity);
      for (std::size_t i = 0; i < size; ++i) {
         allocator.construct(&new_data[i], std::move(data[i]));
         allocator.destroy(&data[i]);
      }
      allocator.deallocate(data, capacity);
      data = new_data;
      capacity = new_capacity;
   }
}

template <typename T>
void DynamicArray<T>::clear() {
   for (std::size_t i = 0; i < size; ++i) {
      allocator.destroy(&data[i]);
   }
   size = 0;
}

template <typename T>
std::size_t DynamicArray<T>::get_size() const {
   return size;
}

// Iterator methods
template <typename T>
DynamicArray<T>::Iterator::Iterator(pointer ptr) : ptr(ptr) {}

template <typename T>
typename DynamicArray<T>::Iterator::reference
DynamicArray<T>::Iterator::operator*() const {
   return *ptr;
}

template <typename T>
typename DynamicArray<T>::Iterator::pointer
DynamicArray<T>::Iterator::operator->() {
   return ptr;
}

template <typename T>
typename DynamicArray<T>::Iterator& DynamicArray<T>::Iterator::operator++() {
   ++ptr;
   return *this;
}

template <typename T>
typename DynamicArray<T>::Iterator DynamicArray<T>::Iterator::operator++(int) {
   Iterator tmp = *this;
   ++(*this);
   return tmp;
}

template <typename T>
typename DynamicArray<T>::Iterator DynamicArray<T>::begin() {
   return Iterator(data);
}

template <typename T>
typename DynamicArray<T>::Iterator DynamicArray<T>::end() {
   return Iterator(data + size);
}