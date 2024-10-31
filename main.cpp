#include <iostream>
#include "Figure.h"
#include "Rectangle.h"
#include "Rhomb.h"
#include "Trapezoid.h"

using namespace std;

template <Number T>
void printFigures(Figure<T>** figures) {
   for (int i = 0; i < 3; i++) {
      const Figure<T>* figure = figures[i];
      if (figure != nullptr) {
         cout << *figure << endl
              << "площадь: " << double(*figure) << endl
              << "центр: " << *(*figure).center() << endl
              << endl;
      }
   }
}

int main() {
   cout << "nah, i'd win" << endl;
   Figure<double>** figures = new Figure<double>*[3];
   Rectangle<double>* rectangle = new Rectangle<double>();
   Rhomb<double>* rhomb = new Rhomb<double>();
   Trapezoid<double>* trapezoid = new Trapezoid<double>();

   cout << "Введите координаты прямоугольника: " << endl;
   cin >> *rectangle;
   figures[0] = rectangle;
   cout << "Введите координаты ромба: " << endl;
   cin >> *rhomb;
   figures[1] = rhomb;
   cout << "Введите координаты трапеции: " << endl;
   cin >> *trapezoid;
   figures[2] = trapezoid;

   printFigures(figures);

   double sumArea = 0;
   for (int i = 0; i < 3; i++) {
      const Figure<double>* figure = figures[i];
      sumArea += double(*figure);
   }

   cout << "Общая площадь: " << sumArea << endl
        << "Удалить фигуру по индексу: ";

   size_t i;
   cin >> i;

   if (i > 2 || i < 0) {
      cout << "Индекс за пределами массива" << endl;
      return 0;
   }

   cout << figures[i] << *figures[i] << endl;
   delete figures[i];
   figures[i] = nullptr;
   printFigures(figures);
}