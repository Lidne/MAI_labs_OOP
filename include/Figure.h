#include <iostream>

typedef struct Point {
   double x, y;
};

class Figure {
   Point* points;
   size_t length;

  public:
   Figure();
   Figure(const std::initializer_list<Point>& t);
   virtual ~Figure() noexcept;
   void print() const;
};