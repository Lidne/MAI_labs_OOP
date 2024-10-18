#include "Figure.h"
#include <gtest/gtest.h>
#include "Rectangle.h"
#include "Rhomb.h"
#include "Trapezoid.h"

TEST(FigureConstructorTest, EmptyConstructor) {
   Figure figure;

   ASSERT_EQ(figure.size(), 0);
}

TEST(FigureConstructorTest, UninitializedConstructor) {
   Figure figure(3);

   ASSERT_EQ(figure.size(), 3);
}

TEST(FigureConstructorTest, ListConstructor) {
   Figure figure({Point(2.3, 2.1), Point(1.5, 5.1)});

   Point* points = figure.getPoints();
   size_t size = figure.size();

   ASSERT_EQ(points[0], Point(2.3, 2.1));
   ASSERT_EQ(points[1], Point(1.5, 5.1));
}

TEST(FigureGeometryTest, AreaTest1) {
   Figure square{Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0),
                 Point(5.0, 0.0)};

   double area = double(square);

   ASSERT_EQ(area, 15.0);
}

TEST(FigureGeometryTest, AreaTest2) {
   Figure trapezia{Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0),
                   Point(8.0, 0.0)};

   double area = double(trapezia);

   ASSERT_EQ(area, 19.5);
}

TEST(FigureGeometryTest, CenterTest1) {
   Figure triangle{Point(0.0, 0.0), Point(2.0, 3.0), Point(4.0, 0.0)};

   Point p = *triangle.center();

   ASSERT_EQ(p, Point({2.0, 1.0}));
}

TEST(FigureGeometryTest, CenterTest2) {
   Figure trapezia{Point(0.0, 0.0), Point(0.0, 3.0), Point(5.0, 3.0),
                   Point(7.0, 0.0)};

   Point p = *trapezia.center();

   ASSERT_EQ(p, Point({3.0, 1.5}));
}

TEST(FigureCopyTest, CopyTest) {
   Figure figure({Point(2.3, 2.1)});
   Figure figure2;

   figure2 = figure;
   Point* points = figure2.getPoints();

   ASSERT_EQ(points[0], Point(2.3, 2.1));
}

TEST(FigureCopyTest, MoveTest) {
   Figure figure({Point(2.3, 2.1)});
   Figure figure2;
   Point* points1 = figure.getPoints();

   figure2 = std::move(figure);
   Point* points2 = figure2.getPoints();

   ASSERT_EQ(points1, points2);
}