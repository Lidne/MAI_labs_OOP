#include "../src/Trapezoid.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include "../src/Array.cpp"
#include "../src/Figure.cpp"
#include "../src/Point.cpp"
#include "../src/Rectangle.cpp"
#include "../src/Rhomb.cpp"

TEST(TrapezoidConstructorTest, ListConstructor) {
   Trapezoid trapezoid({Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
                        Point<double>(5.0, 3.0), Point<double>(8.0, 0.0)});

   auto& points = trapezoid.getPoints();

   ASSERT_EQ(points[0], Point<double>(0.0, 0.0));
   ASSERT_EQ(points[1], Point<double>(0.0, 3.0));
}

TEST(TrapezoidConstructorTest, ListConstructorErrors1) {
   ASSERT_THROW(Trapezoid({Point<double>(2.3, 2.1), Point<double>(1.5, 5.1)}),
                std::invalid_argument);
}

TEST(TrapezoidConstructorTest, ListConstructorErrors2) {
   ASSERT_THROW(Trapezoid({Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
                           Point<double>(5.0, 3.0), Point<double>(5.0, 0.0)}),
                std::invalid_argument);
}

TEST(TrapezoidGeometryTest, AreaTest) {
   Trapezoid<double> trapezoid{Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
                               Point<double>(5.0, 3.0),
                               Point<double>(8.0, 0.0)};

   double area = double(trapezoid);

   ASSERT_EQ(area, 19.5);
}

TEST(TrapezoidGeometryTest, CenterTest) {
   Trapezoid<double> trapezoid{Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
                               Point<double>(5.0, 3.0),
                               Point<double>(7.0, 0.0)};

   Point<double> center = *trapezoid.center();

   ASSERT_EQ(center, Point<double>(3.0, 1.5));
}