#pragma once

typedef struct {
   int first;
   int second;
} Pair;
bool is_equal(Pair pair1, Pair pair2);

Pair closest_pair_tonum(int upper_limit);
bool is_perfect_square(int num);