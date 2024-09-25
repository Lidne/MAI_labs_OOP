#include <gtest/gtest.h>
#include "../include/lib.h"

TEST(IsEqualTest, GeneralTest1) {
   Pair pair1 = Pair{1, 1};
   Pair pair2 = Pair{1, 1};

   ASSERT_TRUE(is_equal(pair1, pair2));
}

TEST(IsEqualTest, GeneralTest2) {
   Pair pair1 = Pair{123124, 1};
   Pair pair2 = Pair{1, 412};

   ASSERT_FALSE(is_equal(pair1, pair2));
}

TEST(IsPerfectSquareTest, GeneralTest) {
   int num1 = 4;
   int num2 = 16;
   int num3 = 1;
   int num4 = -1;
   int num5 = -16;

   ASSERT_TRUE(is_perfect_square(num1));
   ASSERT_TRUE(is_perfect_square(num2));
   ASSERT_TRUE(is_perfect_square(num3));
   ASSERT_FALSE(is_perfect_square(num4));
   ASSERT_FALSE(is_perfect_square(num5));
}

TEST(ClosestPairToNumTest, ExampleTest1) {
   Pair pair = Pair{5, 4};
   int num = 10;
   Pair returnedPair = closest_pair_tonum(num);

   ASSERT_TRUE(is_equal(pair, returnedPair));
}

TEST(ClosestPairToNumTest, ExampleTest2) {
   Pair pair = Pair{29, 20};
   int num = 30;
   Pair returnedPair = closest_pair_tonum(num);

   ASSERT_TRUE(is_equal(pair, returnedPair));
}

TEST(ClosestPairToNumTest, ExampleTest3) {
   Pair pair = Pair{45, 36};
   int num = 50;
   Pair returnedPair = closest_pair_tonum(num);

   ASSERT_TRUE(is_equal(pair, returnedPair));
}

TEST(ClosestPairToNumTest, NegativeValuesTest) {
   Pair pair = Pair{0, 0};
   int num = -10;
   Pair returnedPair = closest_pair_tonum(num);

   ASSERT_TRUE(is_equal(pair, returnedPair));
}

TEST(ClosestPairToNumTest, ZeroValueTest) {
   Pair pair = Pair{0, 0};
   int num = 0;
   Pair returnedPair = closest_pair_tonum(num);

   ASSERT_TRUE(is_equal(pair, returnedPair));
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}