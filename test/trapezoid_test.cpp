#include "Trapezoid.h"
#include <gtest/gtest.h>
#include "Point.h"

TEST(TrapezoidConstructorTest, ListConstructor) {
   Trapezoid trapezoid(
       {Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0), Point(8.0, 0.0)});

   Point* points = trapezoid.getPoints();

   ASSERT_EQ(points[0], Point(0.0, 0.0));
   ASSERT_EQ(points[1], Point(0.0, 3.0));
}

TEST(TrapezoidConstructorTest, ListConstructorErrors1) {
   ASSERT_THROW(Trapezoid({Point(2.3, 2.1), Point(1.5, 5.1)}),
                std::invalid_argument);
}

TEST(TrapezoidConstructorTest, ListConstructorErrors2) {
   ASSERT_THROW(Trapezoid({Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0),
                           Point(5.0, 0.0)}),
                std::invalid_argument);
}

TEST(TrapezoidGeometryTest, AreaTest) {
   Trapezoid trapezoid{Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0),
                       Point(8.0, 0.0)};
   
   double area = double(trapezoid);

   ASSERT_EQ(area, 19.5);
}

TEST(TrapezoidGeometryTest, CenterTest) {
   Trapezoid trapezoid{Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0),
                       Point(7.0, 0.0)};

   Point center = *trapezoid.center();

   ASSERT_EQ(center, Point(3.0, 1.5));
}