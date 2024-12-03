#include "BattleVisitor.h"
#include <ConsoleLogger.h>
#include <gtest/gtest.h>
#include "NPCFactory.h"

TEST(BattleVisitorTest, FightInRange) {
   std::vector<std::shared_ptr<NPC>> npcs = {
       NPCFactory::createNPC("Knight", "Arthur", 0, 0),
       NPCFactory::createNPC("Elf", "Legolas", 3, 4)};

   BattleVisitor battle(5.0, npcs);
   battle.visit(*npcs[0]);

   EXPECT_EQ(npcs.size(), 0);
}

TEST(BattleVisitorTest, NoFightOutOfRange) {
   std::vector<std::shared_ptr<NPC>> npcs = {
       NPCFactory::createNPC("Knight", "Arthur", 0, 0),
       NPCFactory::createNPC("Elf", "Legolas", 10, 10)};

   BattleVisitor battle(5.0, npcs);
   battle.visit(*npcs[0]);

   EXPECT_EQ(npcs.size(), 2);
}

TEST(BattleVisitorTest, ObserverNotifications) {
   std::vector<std::shared_ptr<NPC>> npcs = {
       NPCFactory::createNPC("Knight", "Arthur", 0, 0),
       NPCFactory::createNPC("Elf", "Legolas", 3, 4)};

   BattleVisitor battle(5.0, npcs);
   auto consoleLogger = std::make_shared<ConsoleLogger>();
   battle.addObserver(consoleLogger);

   testing::internal::CaptureStdout();
   battle.visit(*npcs[0]);
   std::string output = testing::internal::GetCapturedStdout();

   EXPECT_NE(output.find("Arthur (Knight) fought Legolas (Elf)"),
             std::string::npos);
}
