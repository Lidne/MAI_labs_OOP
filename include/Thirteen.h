#include <iostream>
#include <string>

class Thirteen {
  public:
   Thirteen();
   Thirteen(const size_t& n, unsigned char t);
   Thirteen(const std::initializer_list<unsigned char>& t);
   Thirteen(const std::string& t);
   Thirteen(const Thirteen& other);
   Thirteen(Thirteen&& other) noexcept;
   virtual ~Thirteen() noexcept;
   void print() const;
   size_t size() const;
   Thirteen& operator=(const Thirteen& other);
   Thirteen& operator=(Thirteen&& other) noexcept;

   Thirteen& operator+=(const Thirteen& other);
   Thirteen& operator-=(const Thirteen& other);
   Thirteen& operator*=(const Thirteen& other);

   Thirteen operator+(const Thirteen& other) const;
   Thirteen operator-(const Thirteen& other) const;
   Thirteen operator*(const Thirteen& other) const;

   bool operator==(const Thirteen& other) const;
   bool operator!=(const Thirteen& other) const;
   bool operator<(const Thirteen& other) const;
   bool operator>(const Thirteen& other) const;
   bool operator<=(const Thirteen& other) const;
   bool operator>=(const Thirteen& other) const;

  private:
   unsigned char* digits;
   size_t length;
   void clear();
   void removeLeadingZeros();
   bool validate(const std::string& t);
   bool validate(const std::initializer_list<unsigned char>& t);
   void deepCopy(const Thirteen& other);
};