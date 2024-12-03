#include "NPC.h"
#include <gtest/gtest.h>

TEST(NPCTest, CreateKnight) {
   Knight knight("Arthur", 50, 50);
   EXPECT_EQ(knight.getType(), "Knight");
}

TEST(NPCTest, CreateElf) {
   Elf elf("Legolas", 100, 100);
   EXPECT_EQ(elf.getType(), "Elf");
}

TEST(NPCTest, CreateDruid) {
   Druid druid("Merlin", 200, 200);
   EXPECT_EQ(druid.getType(), "Druid");
}

TEST(NPCTest, DistanceCalculation) {
   Knight knight("Arthur", 0, 0);
   Elf elf("Legolas", 3, 4);
   EXPECT_DOUBLE_EQ(knight.distanceTo(elf), 5.0);
}