#include <iostream>
#include "./src/Array.cpp"
#include "./src/Figure.cpp"
#include "./src/Point.cpp"
#include "./src/Rectangle.cpp"
#include "./src/Rhomb.cpp"
#include "./src/Trapezoid.cpp"

using namespace std;

template <class T>
void printFigures(Array<T> figures) {
   for (int i = 0; i < 3; i++) {
      auto& figure = *figures[i];
      cout << figure << endl
           << "площадь: " << double(figure) << endl
           << "центр: " << *(figure).center() << endl
           << endl;
   }
}

int main() {
   cout << "nah, i'd win" << endl;
   Array<Figure<double>> arr;
   Rectangle<double> rectangle;
   Rhomb<double> rhomb;
   Trapezoid<double> trapezoid;

   cout << "Введите координаты прямоугольника: " << endl;
   cin >> rectangle;
   arr.append(std::make_shared<Rectangle<double>>(rectangle));

   cout << "Введите координаты ромба: " << endl;
   cin >> rhomb;
   arr.append(std::make_shared<Rhomb<double>>(rhomb));

   cout << "Введите координаты трапеции: " << endl;
   cin >> trapezoid;
   arr.append(std::make_shared<Trapezoid<double>>(trapezoid));

   printFigures(arr);

   double sumArea = 0;
   for (int i = 0; i < 3; i++) {
      const std::shared_ptr<Figure<double>> figure = arr[i];
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
   // Figure<double> fig = *arr[i];
   // cout << arr[i] << fig << endl;
   arr.remove(i);
   printFigures(arr);
}