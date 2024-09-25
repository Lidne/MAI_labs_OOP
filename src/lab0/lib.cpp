// Copyright 2023 SomeName
#include "../../include/lib.h"
#include <iostream>

Pair closest_pair_tonum(int upper_limit) {
   for (int i = upper_limit - 1; i > 0; --i) {
      for (int j = upper_limit - 1; j > 0; --j) {
        //  std::cout << i << " " << j << " " << is_perfect_square(i + j) << " "
        //            << is_perfect_square(i - j) << std::endl;
         if (is_perfect_square(i + j) && is_perfect_square(i - j)) {
            return Pair{i, j};
         }
      }
   }
   return Pair{0, 0};
}

bool is_perfect_square(int num) {
   if (num == 1) return true;
   for (int i = 1; i <= num / 2; ++i) {
      if (i * i == num) return true;
   }
   return false;
}

bool is_equal(Pair pair1, Pair pair2) {
   return pair1.first == pair2.first && pair1.second == pair2.second;
}
