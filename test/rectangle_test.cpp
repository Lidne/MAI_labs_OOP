#include "Rectangle.h"
#include <gtest/gtest.h>

TEST(RectangleConstructorTest, ListConstructor) {
   Rectangle rectangle(
       {Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0}, Point{5.0, 0.0}});

   Point* points = rectangle.getPoints();

   ASSERT_EQ(rectangle.size(), 4);
   ASSERT_NE(points, nullptr);
   ASSERT_EQ(points[0].x, 0.0);
   ASSERT_EQ(points[0].y, 0.0);
   ASSERT_EQ(points[1].x, 0.0);
   ASSERT_EQ(points[1].y, 3.0);
}

TEST(RectangleConstructorTest, ListConstructorErrors) {
   ASSERT_THROW(Rectangle({Point{2.3, 2.1}, Point{1.5, 5.1}}),
                std::invalid_argument);
   ASSERT_THROW(Rectangle({Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0},
                           Point{8.0, 0.0}}),
                std::invalid_argument);
}

TEST(RectangleGeometryTest, AreaTest) {
   Rectangle rectangle{Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0},
                       Point{5.0, 0.0}};

   ASSERT_EQ(rectangle.area(), 15.0);
   ASSERT_EQ(double(rectangle), 15.0);
}

TEST(RectangleGeometryTest, CenterTest) {
   Rectangle rectangle{Point{0.0, 0.0}, Point{0.0, 4.0}, Point{6.0, 4.0},
                       Point{6.0, 0.0}};

   ASSERT_EQ(*rectangle.center(), Point({3.0, 2.0}));
}