#include <iostream>
#include <string>

class Thirteen {
  public:
   Thirteen();
   Thirteen(const size_t& n, unsigned char t = 0);
   Thirteen(const std::initializer_list<unsigned char>& t);
   Thirteen(const std::string& t);
   Thirteen(const Thirteen& other);
   Thirteen(Thirteen&& other) noexcept;
   virtual ~Thirteen() noexcept;
   void print() const;
   size_t size() const;

  private:
   unsigned char* digits;
   size_t length;
};