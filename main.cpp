#include <iostream>
#include "Figure.h"
#include "Rectangle.h"
#include "Rhomb.h"
#include "Trapezoid.h"

using namespace std;

int main() {
   cout << "nah, i'd win" << endl;
   Figure** figures = new Figure*[3];
   Rectangle rectangle;
   Rhomb rhomb;
   Trapezoid trapezoid;

   cout << "Введите координаты прямоугольника: " << endl;
   cin >> rectangle;
   figures[0] = &rectangle;
   cout << "Введите координаты ромба: " << endl;
   cin >> rhomb;
   figures[1] = &rhomb;
   cout << "Введите координаты трапеции: " << endl;
   cin >> trapezoid;
   figures[2] = &trapezoid;

   double sumArea = 0;
   
   for (int i = 0; i < 3; i++) {
      Figure* figure = figures[i];
      sumArea += double(*figure);
      cout << *figure << endl
           << "площадь: " << double(*figure) << endl
           << "центр: " << *(*figure).center() << endl
           << endl;
   }
   cout << "Общая площадь: " << sumArea << endl;
}