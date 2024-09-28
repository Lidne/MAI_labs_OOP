#include <iostream>
#include "Thirteen.h"

using namespace std;

int main() {
   Thirteen num = Thirteen();
   num.print();
   Thirteen num1 = Thirteen({1, 2, 3});
   num1.print();
}