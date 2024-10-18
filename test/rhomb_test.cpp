#include "Rhomb.h"
#include <gtest/gtest.h>
#include "Point.h"

TEST(RhombConstructorTest, ListConstructor) {
   Rhomb rhomb{Point(0.0, 2.0), Point(1.0, 0.0), Point(0.0, -2.0),
               Point(-1.0, 0.0)};

   Point* points = rhomb.getPoints();

   ASSERT_EQ(points[0], Point(0.0, 2.0));
   ASSERT_EQ(points[1], Point(1.0, 0.0));
}

TEST(RhombConstructorTest, ListConstructorErrors1) {
   ASSERT_THROW(Rhomb({Point(2.3, 2.1), Point(1.5, 5.1)}),
                std::invalid_argument);
}

TEST(RhombConstructorTest, ListConstructorErrors2) {
   ASSERT_THROW(Rhomb({Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0),
                       Point(8.0, 0.0)}),
                std::invalid_argument);
}

TEST(RhombGeometryTest, AreaTest) {
   Rhomb rhomb{Point(0.0, 2.0), Point(1.0, 0.0), Point(0.0, -2.0),
               Point(-1.0, 0.0)};

   double area = double(rhomb);

   ASSERT_EQ(area, 4.0);
}

TEST(RhombGeometryTest, CenterTest) {
   Rhomb rhomb{Point(0.0, 2.0), Point(1.0, 0.0), Point(0.0, -2.0),
               Point(-1.0, 0.0)};

   Point center = *rhomb.center();

   ASSERT_EQ(center, Point(0.0, 0.0));
}