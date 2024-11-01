#include "../src/Figure.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include "../src/Array.cpp"
#include "../src/Point.cpp"
#include "../src/Rectangle.cpp"
#include "../src/Rhomb.cpp"
#include "../src/Trapezoid.cpp"

TEST(FigureConstructorTest, EmptyConstructor) {
   Figure<double> figure;

   ASSERT_EQ(figure.size(), 0);
}

TEST(FigureConstructorTest, UninitializedConstructor) {
   Figure<double> figure(3);

   ASSERT_EQ(figure.size(), 3);
}

TEST(FigureConstructorTest, ListConstructor) {
   Figure figure({Point<double>(2.3, 2.1), Point<double>(1.5, 5.1)});

   auto& points = figure.getPoints();
   size_t size = figure.size();

   ASSERT_EQ(points[0], Point<double>(2.3, 2.1));
   ASSERT_EQ(points[1], Point<double>(1.5, 5.1));
}

TEST(FigureGeometryTest, AreaTest1) {
   Figure<double> square{Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
                         Point<double>(5.0, 3.0), Point<double>(5.0, 0.0)};

   double area = double(square);

   ASSERT_EQ(area, 15.0);
}

TEST(FigureGeometryTest, AreaTest2) {
   Figure<double> trapezia{Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
                           Point<double>(5.0, 3.0), Point<double>(8.0, 0.0)};

   double area = double(trapezia);

   ASSERT_EQ(area, 19.5);
}

TEST(FigureGeometryTest, CenterTest1) {
   Figure<double> triangle{Point<double>(0.0, 0.0), Point<double>(2.0, 3.0),
                           Point<double>(4.0, 0.0)};

   Point p = *triangle.center();

   ASSERT_EQ(p, Point<double>({2.0, 1.0}));
}

TEST(FigureGeometryTest, CenterTest2) {
   Figure<double> trapezia{Point<double>(0.0, 0.0), Point<double>(0.0, 3.0),
                           Point<double>(5.0, 3.0), Point<double>(7.0, 0.0)};

   Point<double> p = *trapezia.center();

   ASSERT_EQ(p, Point<double>({3.0, 1.5}));
}

TEST(FigureCopyTest, CopyTest) {
   Figure<double> figure({Point<double>(2.3, 2.1)});
   Figure<double> figure2;

   figure2 = figure;
   auto& points = figure2.getPoints();

   ASSERT_EQ(points[0], Point<double>(2.3, 2.1));
}

TEST(FigureCopyTest, MoveTest) {
   Figure<double> figure({Point(2.3, 2.1)});
   Figure<double> figure2(1);
   auto& points1 = figure.getPoints();

   figure2 = std::move(figure);
   figure2.print();
   auto& points2 = figure2.getPoints();

   ASSERT_EQ(points1, points2);
}