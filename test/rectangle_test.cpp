#include "../src/Rectangle.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include "../src/Array.cpp"
#include "../src/Figure.cpp"
#include "../src/Point.cpp"
#include "../src/Rhomb.cpp"
#include "../src/Trapezoid.cpp"

TEST(RectangleConstructorTest, ListConstructor) {
   Rectangle<double> rectangle(
       {Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
        Point<double>(5.0, 3.0), Point<double>(5.0, 0.0)});

   auto& points = rectangle.getPoints();

   ASSERT_EQ(points[0], Point<double>(0.0, 0.0));
   ASSERT_EQ(points[1], Point<double>(0.0, 3.0));
}

TEST(RectangleConstructorTest, ListConstructorErrors1) {
   ASSERT_THROW(
       Rectangle<double>({Point<double>(2.3, 2.1), Point<double>(1.5, 5.1)}),
       std::invalid_argument);
}

TEST(RectangleConstructorTest, ListConstructorErrors2) {
   ASSERT_THROW(
       Rectangle<double>({Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
                          Point<double>(5.0, 3.0), Point<double>(8.0, 0.0)}),
       std::invalid_argument);
}

TEST(RectangleGeometryTest, AreaTest) {
   Rectangle<double> rectangle{Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
                               Point<double>(5.0, 3.0),
                               Point<double>(5.0, 0.0)};

   double area = double(rectangle);

   ASSERT_EQ(area, 15.0);
}

TEST(RectangleGeometryTest, CenterTest) {
   Rectangle<double> rectangle{Point<double>(0.0, 0.0), Point<double>(0.0, 4.0),
                               Point<double>(6.0, 4.0),
                               Point<double>(6.0, 0.0)};

   Point<double> center = *rectangle.center();

   ASSERT_EQ(center, Point<double>(3.0, 2.0));
}