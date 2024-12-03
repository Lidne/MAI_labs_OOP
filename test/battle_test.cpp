#include <gtest/gtest.h>
#include "Druid.h"
#include "Elf.h"
#include "Knight.h"

TEST(BattleTest, KnightFightsElf) {
   Knight knight("Arthur", 50, 50);
   Elf elf("Legolas", 100, 100);
   EXPECT_FALSE(knight.fight(elf));
}

TEST(BattleTest, ElfFightsDruid) {
   Elf elf("Legolas", 50, 50);
   Druid druid("Merlin", 100, 100);
   EXPECT_FALSE(elf.fight(druid));
}

TEST(BattleTest, DruidFightsDruid) {
   Druid druid1("Merlin", 50, 50);
   Druid druid2("Gandalf", 100, 100);
   EXPECT_FALSE(druid1.fight(druid2));
}