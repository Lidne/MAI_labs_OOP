#include "Thirteen.h"
#include <gtest/gtest.h>

TEST(ThirteenTest, BasicConstructor) {
   Thirteen obj1 = Thirteen();
   ASSERT_FALSE(obj1.size());
}

TEST(ThirteenTest, ListConstructor) {
   Thirteen obj1 = Thirteen({'1', '2', '3'});
   ASSERT_EQ(obj1.size(), (size_t)3);
}