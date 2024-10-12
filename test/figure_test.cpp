#include "Figure.h"
#include <gtest/gtest.h>
#include "Rectangle.h"
#include "Rhomb.h"
#include "Trapezoid.h"

TEST(FigureConstructorTest, EmptyConstructor) {
   Figure figure;

   ASSERT_EQ(figure.size(), 0);
   ASSERT_EQ(figure.getPoints(), nullptr);
}

TEST(FigureConstructorTest, UninitializedConstructor) {
   Figure figure(3);

   ASSERT_EQ(figure.size(), 3);
   ASSERT_NE(figure.getPoints(), nullptr);
}

TEST(FigureConstructorTest, ListConstructor) {
   Figure figure({Point{2.3, 2.1}, Point{1.5, 5.1}});

   Point* points = figure.getPoints();

   ASSERT_EQ(figure.size(), 2);
   ASSERT_NE(points, nullptr);
   ASSERT_EQ(points[0].x, 2.3);
   ASSERT_EQ(points[0].y, 2.1);
   ASSERT_EQ(points[1].x, 1.5);
   ASSERT_EQ(points[1].y, 5.1);
}

TEST(FigureGeometryTest, AreaTest) {
   Figure square{Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0},
                 Point{5.0, 0.0}};
   Figure trapezia{Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0},
                   Point{8.0, 0.0}};

   ASSERT_EQ(square.area(), 15.0);
   ASSERT_EQ(trapezia.area(), 19.5);
   ASSERT_EQ(double(square), 15.0);
   ASSERT_EQ(double(trapezia), 19.5);
}

TEST(FigureGeometryTest, CenterTest) {
   Figure triangle{Point{0.0, 0.0}, Point{2.0, 3.0}, Point{4.0, 0.0}};
   Figure trapezia{Point{0.0, 0.0}, Point{0.0, 3.0}, Point{5.0, 3.0},
                   Point{7.0, 0.0}};

   ASSERT_EQ(*triangle.center(), Point({2.0, 1.0}));
   ASSERT_EQ(*trapezia.center(), Point({3.0, 1.5}));
}

TEST(FigureCopyTest, CopyTest) {
   Figure figure({Point{2.3, 2.1}});
   Figure figure2;

   figure2 = figure;
   Point* points = figure2.getPoints();

   ASSERT_EQ(figure2.size(), 1);
   ASSERT_NE(points, nullptr);
   ASSERT_EQ(points[0].x, 2.3);
   ASSERT_EQ(points[0].y, 2.1);
}

TEST(FigureCopyTest, MoveTest) {
   Figure figure({Point{2.3, 2.1}});
   Figure figure2;
   Point* points1 = figure.getPoints();

   figure2 = std::move(figure);
   Point* points2 = figure2.getPoints();

   ASSERT_EQ(figure2.size(), 1);
   ASSERT_NE(points1, nullptr);
   ASSERT_NE(points2, nullptr);
   ASSERT_EQ(points1, points2);
   ASSERT_EQ(points2[0].x, 2.3);
   ASSERT_EQ(points2[0].y, 2.1);
}