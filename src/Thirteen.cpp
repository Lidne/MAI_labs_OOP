#include "Thirteen.h"

Thirteen::Thirteen() : digits(nullptr), length(0) {}

Thirteen::Thirteen(const size_t& n, unsigned char t = 0)
    : digits(new unsigned char[n]), length(n) {
   for (int i = 0; i < n; i++) {
      digits[i] = t;
   }
}

Thirteen::Thirteen(const std::initializer_list<unsigned char>& t)
    : digits(new unsigned char[t.size()]), length(t.size()) {
   size_t i = 0;
   for (unsigned char c : t) {
      digits[i] = c;
      i++;
   }
}

Thirteen::~Thirteen() { delete digits; }

void Thirteen::print() const {
   for (int i = 0; i < length; i++) {
      std::cout << digits[i];
   }
   std::cout << std::endl;
}

size_t Thirteen::size() const { return length; }
