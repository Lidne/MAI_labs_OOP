#include <iostream>
#include "Figure.h"
using namespace std;

int main() {
   cout << "nah, i'd win" << endl;
   Figure some = Figure({Point{1.2, 2.1}, Point{2.2, 1.4}});
   some.print();
}