#include "Array.h"

template <class T>
Array<T>::Array()
    : s(0), capacity(1), arr(std::make_unique<std::shared_ptr<T>[]>(s)) {}

template <class T>
Array<T>::Array(const Array &other)
    : s(other.s),
      capacity(other.capacity),
      arr(std::make_unique<std::shared_ptr<T>[]>(other.s)) {
   for (size_t i = 0; i < s; ++i) {
      arr[i] = std::make_shared<T>(*other.arr[i]);
   }
}

template <class T>
Array<T>::Array(Array &&other) noexcept
    : s(other.s), capacity(other.capacity), arr(std::move(other.arr)) {
   other.s = 0;
   other.capacity = 0;
}

template <class T>
size_t Array<T>::size() const {
   return s;
}

template <class T>
void Array<T>::clear() {
   delete[] s;
   s = 0;
   capacity = 1;
   arr = nullptr;
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other) {
   if (this != &other) {
      copy(other);
   }
}

template <class T>
void Array<T>::copy(const Array &other) {
   s = other.s;
   capacity = other.capacity;
   arr = std::make_unique<std::shared_ptr<T>[]>(other.s);
   std::copy(other.getPoints(), other.getPoints() + s, arr);
}

template <class T>
Array<T> &Array<T>::operator=(Array &&other) noexcept {
   if (this != &other) {
      delete[] arr;
      s = other.s;
      arr = other.arr;
      other.s = 0;
      other.arr = nullptr;
   }
   return *this;
}

template <class T>
void Array<T>::append(std::shared_ptr<T> item) {
   if (s == capacity) {
      resize(capacity * 2);
   }
   arr[s++] = item;
}

template <class T>
void Array<T>::remove(size_t i) {
   if (i >= s) {
      throw std::out_of_range("Out of range");
   }
   for (size_t i = i; i < s - 1; i++) {
      arr[i] = std::move(arr[i + 1]);
   }
   s--;
}

template <class T>
std::shared_ptr<T> &Array<T>::operator[](size_t i) {
   if (i >= s) {
      throw std::out_of_range("Out of range");
   }
   return arr[i];
}

template <class T>
void Array<T>::resize(size_t new_cap) {
   auto new_arr = std::make_unique<std::shared_ptr<T>[]>(new_cap);
   for (size_t i = 0; i < s; i++) {
      new_arr[i] = std::move(arr[i]);
   }

   arr = std::move(new_arr);
   capacity = new_cap;
}
