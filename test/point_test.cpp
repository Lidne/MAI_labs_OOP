#include "Point.h"
#include <gtest/gtest.h>

TEST(PointTest, ConstructorTest) {
   Point p2(1.2, 2.4);

   ASSERT_EQ(p2.x, 1.2);
   ASSERT_EQ(p2.y, 2.4);
}

TEST(PointTest, AbsTest) {
   Point p2(3.0, 4.0);

   double abs = p2.abs();

   ASSERT_EQ(abs, 5.0);
}

TEST(PointTest, SumTest) {
   Point p1(1.0, -1.0);
   Point p2(3.0, 4.0);

   Point sum = p1 + p2;

   ASSERT_EQ(sum, Point(4.0, 3.0));
}

TEST(PointTest, SubTest) {
   Point p1(1.0, -1.0);
   Point p2(3.0, 4.0);

   Point sub = p2 - p1;

   ASSERT_EQ(sub, Point(2.0, 5.0));
}

TEST(PointTest, ScalarMultTest) {
   Point p1(1.0, -1.0);
   Point p2(3.0, 4.0);

   double mult = p2 * p1;

   ASSERT_EQ(mult, -1.0);
}