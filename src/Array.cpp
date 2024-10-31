#include "Array.h"

template <Number T>
Array<T>::Array()
    : s(0), capacity(16), arr(std::make_unique<std::shared_ptr<T[]>>(s)) {}

template <Number T>
Array<T>::Array(const Array &other)
    : s(other.s),
      capacity(other.capacity),
      arr(std::make_unique<std::shared_ptr<T[]>>(other.s)) {
   for (size_t i = 0; i < size; ++i) {
      arr[i] = std::make_shared<T>(*other.arr[i]);
   }
}

template <Number T>
Array<T>::Array(Array &&other) noexcept
    : s(other.s), capacity(other.capacity), arr(std::move(other.arr)) {
   other.s = 0;
}

template <Number T>
size_t Array<T>::size() const {
   return s;
}

template <Number T>
Array<T> &Array<T>::operator=(const Array &other) {
   if (this != &other) {
      copy(other);
   }
}

template <Number T>
void Array<T>::copy(const Array &other) {
   s = other.s;
   arr = std::make_unique<std::shared_ptr<T[]>>(other.s);
   std::copy(other.getPoints(), other.getPoints() + s, arr);
}

template <Number T>
Array<T> &Array<T>::operator=(Array &&other) noexcept {}

template <Number T>
void Array<T>::append(std::shared_ptr<T> item) {
   if (s == capacity) {
      resize(capacity * 2);
   }
   arr[size++] = std::move(item);
}

template <Number T>
void Array<T>::remove(size_t index) {
   if (index >= size) {
      throw std::out_of_range("Index out of range");
   }
   for (size_t i = index; i < size - 1; ++i) {
      data[i] = std::move(data[i + 1]);
   }
   --size;
}

template <Number T>
std::shared_ptr<T> &Array<T>::operator[](size_t i) {
   if (i >= s) {
      throw std::out_of_range("Out of range");
   }
   return arr[i];
}
