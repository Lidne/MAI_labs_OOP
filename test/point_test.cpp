#include "../src/Point.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include "../src/Array.cpp"
#include "../src/Figure.cpp"
#include "../src/Rectangle.cpp"
#include "../src/Rhomb.cpp"
#include "../src/Trapezoid.cpp"

TEST(PointTest, ConstructorTest) {
   Point<double> p2(1.2, 2.4);

   ASSERT_EQ(p2.x, 1.2);
   ASSERT_EQ(p2.y, 2.4);
}

TEST(PointTest, AbsTest) {
   Point<double> p2(3.0, 4.0);

   double abs = p2.abs();

   ASSERT_EQ(abs, 5.0);
}

TEST(PointTest, SumTest) {
   Point<double> p1(1.0, -1.0);
   Point<double> p2(3.0, 4.0);

   Point<double> sum = p1 + p2;

   ASSERT_EQ(sum, Point<double>(4.0, 3.0));
}

TEST(PointTest, SubTest) {
   Point<double> p1(1.0, -1.0);
   Point<double> p2(3.0, 4.0);

   Point<double> sub = p2 - p1;

   ASSERT_EQ(sub, Point<double>(2.0, 5.0));
}

TEST(PointTest, ScalarMultTest) {
   Point<double> p1(1.0, -1.0);
   Point<double> p2(3.0, 4.0);

   double mult = p2 * p1;

   ASSERT_EQ(mult, -1.0);
}