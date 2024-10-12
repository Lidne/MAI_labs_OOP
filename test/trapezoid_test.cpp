#include "Trapezoid.h"
#include <gtest/gtest.h>

TEST(TrapezoidConstructorTest, ListConstructor) {
   Trapezoid trapezoid(
       {Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0}, Point{8.0, 0.0}});

   Point* points = trapezoid.getPoints();

   ASSERT_EQ(trapezoid.size(), 4);
   ASSERT_NE(points, nullptr);
   ASSERT_EQ(points[0].x, 0.0);
   ASSERT_EQ(points[0].y, 0.0);
   ASSERT_EQ(points[1].x, 0.0);
   ASSERT_EQ(points[1].y, 3.0);
}

TEST(TrapezoidConstructorTest, ListConstructorErrors) {
   ASSERT_THROW(Trapezoid({Point{2.3, 2.1}, Point{1.5, 5.1}}),
                std::invalid_argument);
   ASSERT_THROW(Trapezoid({Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0},
                           Point{5.0, 0.0}}),
                std::invalid_argument);
}

TEST(TrapezoidGeometryTest, AreaTest) {
   Trapezoid trapezoid{Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0},
                       Point{8.0, 0.0}};

   ASSERT_EQ(trapezoid.area(), 19.5);
   ASSERT_EQ(double(trapezoid), 19.5);
}

TEST(TrapezoidGeometryTest, CenterTest) {
   Trapezoid trapezoid{Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0},
                       Point{7.0, 0.0}};

   ASSERT_EQ(*trapezoid.center(), Point({3.0, 1.5}));
}