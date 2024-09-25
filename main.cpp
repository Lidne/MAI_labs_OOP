#include <iostream>
#include "lib.h"

int main() {
   int upperLimit;
   std::cout << "Input number: ";
   std::cin >> upperLimit;
   Pair pair = closest_pair_tonum(upperLimit);
   std::cout << "Closest pair: {" << pair.first << ", " << pair.second << "}."
             << std::endl;
}