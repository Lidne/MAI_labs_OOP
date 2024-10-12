#include "Point.h"
#include <gtest/gtest.h>

TEST(PointTest, ConstructorTest) {
   Point p1;
   Point p2(1.2, 2.4);

   ASSERT_EQ(p1.x, 0.0);
   ASSERT_EQ(p1.y, 0.0);
   ASSERT_EQ(p2.x, 1.2);
   ASSERT_EQ(p2.y, 2.4);
}

TEST(PointTest, AbsTest) {
   Point p1;
   Point p2(3.0, 4.0);

   ASSERT_EQ(p1.abs(), 0.0);
   ASSERT_EQ(p2.abs(), 5.0);
}

TEST(PointTest, ArithmeticsTest) {
   Point p1(1.0, -1.0);
   Point p2(3.0, 4.0);

   ASSERT_EQ(p1 + p2, Point(4.0, 3.0));
   ASSERT_EQ(p2 - p1, Point(2.0, 5.0));
   ASSERT_EQ(p2 * p1, -1.0);
}