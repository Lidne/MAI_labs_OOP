#include "../src/Rhomb.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include "../src/Array.cpp"
#include "../src/Figure.cpp"
#include "../src/Point.cpp"
#include "../src/Rectangle.cpp"
#include "../src/Trapezoid.cpp"

TEST(RhombConstructorTest, ListConstructor) {
   Rhomb<double> rhomb{Point<double>(0.0, 2.0), Point<double>(1.0, 0.0),
                       Point<double>(0.0, -2.0), Point<double>(-1.0, 0.0)};

   auto& points = rhomb.getPoints();

   ASSERT_EQ(points[0], Point<double>(0.0, 2.0));
   ASSERT_EQ(points[1], Point<double>(1.0, 0.0));
}

TEST(RhombConstructorTest, ListConstructorErrors1) {
   ASSERT_THROW(Rhomb({Point<double>(2.3, 2.1), Point<double>(1.5, 5.1)}),
                std::invalid_argument);
}

TEST(RhombConstructorTest, ListConstructorErrors2) {
   ASSERT_THROW(Rhomb({Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
                       Point<double>(5.0, 3.0), Point<double>(8.0, 0.0)}),
                std::invalid_argument);
}

TEST(RhombGeometryTest, AreaTest) {
   Rhomb<double> rhomb{Point<double>(0.0, 2.0), Point<double>(1.0, 0.0),
                       Point<double>(0.0, -2.0), Point<double>(-1.0, 0.0)};

   double area = double(rhomb);

   ASSERT_EQ(area, 4.0);
}

TEST(RhombGeometryTest, CenterTest) {
   Rhomb<double> rhomb{Point<double>(0.0, 2.0), Point<double>(1.0, 0.0),
                       Point<double>(0.0, -2.0), Point<double>(-1.0, 0.0)};

   Point<double> center = *rhomb.center();

   ASSERT_EQ(center, Point<double>(0.0, 0.0));
}