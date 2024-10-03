#include "Thirteen.h"

Thirteen::Thirteen() : digits(nullptr), length(0) {}

Thirteen::Thirteen(const size_t& n, unsigned char t = 0)
    : digits(new unsigned char[n]), length(n) {
   for (int i = 0; i < n; i++) {
      digits[i] = t;
   }
}

Thirteen::Thirteen(const std::initializer_list<unsigned char>& t) {
   if (!validate(t)) {
      throw std::invalid_argument("Invalid number format");
   }

   length = t.size();
   digits = new unsigned char[t.size()];
   size_t i = 0;

   for (unsigned char c : t) {
      if (c >= '0' && c <= '9') {
         digits[length - i - 1] = c - '0';
      } else if (c >= 'A' && c <= 'Z') {
         digits[length - i - 1] = c - 'A' + 10;
      }
      i++;
   }
}

Thirteen::Thirteen(const std::string& t) {
   if (!validate(t)) {
      throw std::invalid_argument("Invalid number format");
   }

   length = t.size();
   digits = new unsigned char[t.size()];
   unsigned char c;

   for (int i = 0; i < t.length(); i++) {
      c = t[i];
      if (c >= '0' && c <= '9') {
         digits[length - i - 1] = c - '0';
      } else if (c >= 'A' && c <= 'Z') {
         digits[length - i - 1] = c - 'A' + 10;
      }
   }
}

Thirteen::Thirteen(const Thirteen& other) { deepCopy(other); }

Thirteen::Thirteen(Thirteen&& other) noexcept
    : length(other.length), digits(other.digits) {
   other.length = 0;
   other.digits = nullptr;
}

void Thirteen::clear() {
   delete[] digits;
   length = 0;
   digits = nullptr;
}

Thirteen::~Thirteen() { clear(); }

void Thirteen::print() const {
   std::cout << "[ ";
   for (int i = 0; i < length; i++) {
      std::cout << digits[i];
   }
   std::cout << " ]" << std::endl;
}

size_t Thirteen::size() const { return length; }

void Thirteen::removeLeadingZeros() {
   while (digits[length - 1] == 0 && length > 1) {
      --length;
   }
}

bool Thirteen::validate(const std::string& t) {
   for (unsigned char c : t) {
      if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'B'))) {
         return false;
      }
   }
   return true;
}

bool Thirteen::validate(const std::initializer_list<unsigned char>& t) {
   for (unsigned char c : t) {
      if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'B'))) {
         return false;
      }
   }
   return true;
}

void Thirteen::deepCopy(const Thirteen& other) {
   length = other.length;
   digits = new unsigned char[length];
   std::copy(other.digits, other.digits + other.length, digits);
}

Thirteen& Thirteen::operator=(const Thirteen& other) {
   if (this != &other) {
      clear();
      deepCopy(other);
   }
   return *this;
}

Thirteen& Thirteen::operator=(Thirteen&& other) noexcept {
   if (this != &other) {
      delete[] digits;
      length = other.length;
      digits = other.digits;
      other.length = 0;
      other.digits = nullptr;
   }
   return *this;
}

Thirteen& Thirteen::operator+=(const Thirteen& other) {
   *this = *this + other;
   return *this;
}

Thirteen& Thirteen::operator-=(const Thirteen& other) {
   *this = *this - other;
   return *this;
}

Thirteen& Thirteen::operator*=(const Thirteen& other) {
   *this = *this * other;
   return *this;
}

Thirteen Thirteen::operator+(const Thirteen& other) const {}