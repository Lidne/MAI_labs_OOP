#include "Rhomb.h"
#include <gtest/gtest.h>

TEST(RhombConstructorTest, ListConstructor) {
   Rhomb rhomb{Point{0.0, 2.0}, Point{1.0, 0.0}, Point{0.0, -2.0},
               Point{-1.0, 0.0}};

   Point* points = rhomb.getPoints();

   ASSERT_EQ(rhomb.size(), 4);
   ASSERT_NE(points, nullptr);
   ASSERT_EQ(points[0].x, 0.0);
   ASSERT_EQ(points[0].y, 2.0);
   ASSERT_EQ(points[1].x, 1.0);
   ASSERT_EQ(points[1].y, 0.0);
}

TEST(RhombConstructorTest, ListConstructorErrors) {
   ASSERT_THROW(Rhomb({Point{2.3, 2.1}, Point{1.5, 5.1}}),
                std::invalid_argument);
   ASSERT_THROW(Rhomb({Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0},
                       Point{8.0, 0.0}}),
                std::invalid_argument);
}

TEST(RhombGeometryTest, AreaTest) {
   Rhomb rhomb{Point{0.0, 2.0}, Point{1.0, 0.0}, Point{0.0, -2.0},
               Point{-1.0, 0.0}};

   ASSERT_EQ(rhomb.area(), 4.0);
   ASSERT_EQ(double(rhomb), 4.0);
}

TEST(RhombGeometryTest, CenterTest) {
   Rhomb rhomb{Point{0.0, 2.0}, Point{1.0, 0.0}, Point{0.0, -2.0},
               Point{-1.0, 0.0}};

   ASSERT_EQ(*rhomb.center(), Point({0.0, 0.0}));
}