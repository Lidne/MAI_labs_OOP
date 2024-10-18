#include "Rectangle.h"
#include <gtest/gtest.h>
#include "Point.h"

TEST(RectangleConstructorTest, ListConstructor) {
   Rectangle rectangle(
       {Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0), Point(5.0, 0.0)});

   Point* points = rectangle.getPoints();

   ASSERT_EQ(points[0], Point(0.0, 0.0));
   ASSERT_EQ(points[1], Point(0.0, 3.0));
}

TEST(RectangleConstructorTest, ListConstructorErrors1) {
   ASSERT_THROW(Rectangle({Point(2.3, 2.1), Point(1.5, 5.1)}),
                std::invalid_argument);
}

TEST(RectangleConstructorTest, ListConstructorErrors2) {
   ASSERT_THROW(Rectangle({Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0),
                           Point(8.0, 0.0)}),
                std::invalid_argument);
}

TEST(RectangleGeometryTest, AreaTest) {
   Rectangle rectangle{Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0),
                       Point(5.0, 0.0)};

   double area = double(rectangle);

   ASSERT_EQ(area, 15.0);
}

TEST(RectangleGeometryTest, CenterTest) {
   Rectangle rectangle{Point(0.0, 0.0), Point(0.0, 4.0), Point(6.0, 4.0),
                       Point(6.0, 0.0)};

   Point center = *rectangle.center();

   ASSERT_EQ(center, Point(3.0, 2.0));
}